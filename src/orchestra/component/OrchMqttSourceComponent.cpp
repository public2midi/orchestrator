//
// Created by Benjamin Rozière on 23/01/2018.
//

#include <iostream>
#include "OrchMqttSourceComponent.h"


OrchMqttSourceComponent::OrchMqttSourceComponent(const char* host, const char* topic) : _host(host),  _topic(topic) {
    AddOutput_();

    mosqpp::lib_init();
    this->connect_async(_host.c_str());
}

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

OrchMqttSourceComponent::~OrchMqttSourceComponent() {
    this->disconnect();
    this->loop_stop();
}

void OrchMqttSourceComponent::on_connect(int i) {
    std::cout << "[MQTT]Connected !" << std::endl;
    this->subscribe(nullptr, "/#");
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
