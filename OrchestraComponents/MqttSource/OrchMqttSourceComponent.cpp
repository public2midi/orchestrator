//
// Created by Benjamin Rozière on 23/01/2018.
//

#include <iostream>
#include "OrchMqttSourceComponent.h"

OrchMqttSourceComponent::OrchMqttSourceComponent(const std::string topic, const std::string host, int port) {
    AddOutput_();

    _host = AddParameter_("host", DspParameter(DspParameter::String, host));
    _topic = AddParameter_("topic", DspParameter(DspParameter::String, topic));
    _port = AddParameter_("port", DspParameter(DspParameter::Int, port));

    mosqpp::lib_init();
    this->connect_async(get_host().c_str(), get_port());
}

OrchMqttSourceComponent::OrchMqttSourceComponent(const std::string topic) : OrchMqttSourceComponent(topic, "localhost", mqttDefaultPort) {}

void OrchMqttSourceComponent::Process_(DspSignalBus &, DspSignalBus &out) {

    if (!_started) {
        this->loop_start();
        _started = true;
    }

    if (!_msgQueue.empty()) {
        out.SetValue(0, _msgQueue.front());
        _msgQueue.pop();
    }
}

bool OrchMqttSourceComponent::ParameterUpdating_(int index, DspParameter const &param) {
    if (index == _topic) {
        set_topic(*param.GetString());
        return true;
    } else if (index == _host) {
        set_host(*param.GetString());
        return true;
    } else if (index == _port) {
        set_port(*param.GetInt());
        return true;
    }

    return false;
}

OrchMqttSourceComponent::~OrchMqttSourceComponent() {
    this->disconnect();
    this->loop_stop();
}

int OrchMqttSourceComponent::get_port() const {
    return *GetParameter_(_port)->GetInt();
}

void OrchMqttSourceComponent::set_port(int port) {
    SetParameter_(_port, DspParameter(DspParameter::Int, port));

    this->disconnect();
    this->connect_async(get_host().c_str(), get_port());
}

const std::string OrchMqttSourceComponent::get_topic() const {
    return *GetParameter_(_topic)->GetString();
}

void OrchMqttSourceComponent::set_topic(const std::string topic) {
    std::string oldTopic = get_topic();

    SetParameter_(_topic, DspParameter(DspParameter::String, topic));

    this->unsubscribe(nullptr, oldTopic.c_str());
    this->subscribe(nullptr, get_topic().c_str());
}

const std::string OrchMqttSourceComponent::get_host() const {
    return *GetParameter_(_host)->GetString();
}

void OrchMqttSourceComponent::set_host(const std::string host) {
    SetParameter_(_host, DspParameter(DspParameter::String, host));

    this->disconnect();
    this->connect_async(get_host().c_str(), get_port());
}

/* ========== MQTT Callbacks ===================================== */
void OrchMqttSourceComponent::on_connect(int i) {
    std::cout << "[MQTT]Connected !" << std::endl;
    this->subscribe(nullptr, get_topic().c_str());
}

void OrchMqttSourceComponent::on_disconnect(int i) {
    std::cout << "[MQTT]Disconected !" << std::endl;
}

void OrchMqttSourceComponent::on_publish(int i) {
    std::cout << "[MQTT]Published !" << std::endl;
}

void OrchMqttSourceComponent::on_message(const struct mosquitto_message *message) {
    std::cout << "[MQTT]Got msg !" << std::endl;
    _msgQueue.push(std::string(static_cast<char *>(message->payload), static_cast<size_t>(message->payloadlen)));
}

void OrchMqttSourceComponent::on_subscribe(int i, int i1, const int *pInt) {
    std::cout << "[MQTT]Subscribed !" << std::endl;
}

void OrchMqttSourceComponent::on_unsubscribe(int i) {
    std::cout << "[MQTT]Unsubscribed !" << std::endl;
}

void OrchMqttSourceComponent::on_log(int i, const char *string) {
    std::cout << "[MQTT]#" << i << ":" << string << std::endl;
}

void OrchMqttSourceComponent::on_error() {
    std::cerr << "Error in mqtt" << std::endl;
}