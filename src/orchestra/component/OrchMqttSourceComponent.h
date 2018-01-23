//
// Created by Benjamin Rozière on 23/01/2018.
//

#ifndef ORCHESTRA_ORCHMQTTSOURCECOMPONENT_H
#define ORCHESTRA_ORCHMQTTSOURCECOMPONENT_H


#include <dspatch/DspComponent.h>
#include <mosquittopp.h>
#include <queue>

class OrchMqttSourceComponent : public DspComponent, public mosqpp::mosquittopp {


public:
    OrchMqttSourceComponent(const char* host, const char* topic);

    virtual ~OrchMqttSourceComponent();

    /* API from mosquitto lib */
    void on_connect(int i) override;

    void on_disconnect(int i) override;

    void on_publish(int i) override;

    void on_message(const struct mosquitto_message *message) override;

    void on_subscribe(int i, int i1, const int *pInt) override;

    void on_unsubscribe(int i) override;

    void on_log(int i, const char *string) override;

    void on_error() override;

protected:
    void Process_(DspSignalBus &bus, DspSignalBus &signalBus) override;

private:
    bool _started = false;

    std::string _topic;
    std::string _host;

    std::queue<std::string> _msgQueue;
};


#endif //ORCHESTRA_ORCHMQTTSOURCECOMPONENT_H
