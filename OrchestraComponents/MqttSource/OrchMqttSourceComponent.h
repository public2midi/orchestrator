//
// Created by Benjamin Rozière on 23/01/2018.
//

#ifndef ORCHESTRA_ORCHMQTTSOURCECOMPONENT_H
#define ORCHESTRA_ORCHMQTTSOURCECOMPONENT_H


#include <dspatch/DspComponent.h>

#include <queue>
#include <cpp/mosquittopp.h>
#include <dspatch/DspPlugin.h>

class OrchMqttSourceComponent : public DspComponent, public mosqpp::mosquittopp {


public:
    static const int mqttDefaultPort = 1883;

    explicit OrchMqttSourceComponent(std::string topic);

    OrchMqttSourceComponent(std::string topic, std::string host, int port);

    virtual ~OrchMqttSourceComponent();

    int get_port() const;
    void set_port(int port);

    const std::string get_topic() const;
    void set_topic(std::string topic);

    const std::string get_host() const;
    void set_host(std::string host);

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

    bool ParameterUpdating_(int i, DspParameter const &parameter) override;

private:
    int _topic; //std::string
    int _host; //std::string
    int _port; //int

    bool _started = false;
    std::queue<std::string> _msgQueue;
};

class OrchMqttSourcePlugin : public DspPlugin {

    std::map<std::string, DspParameter> GetCreateParams() const {
        std::map<std::string, DspParameter> params;
        params["topic"] = DspParameter(DspParameter::String, "/topic");
        params["host"] = DspParameter(DspParameter::String, "localhost");
        params["port"] = DspParameter(DspParameter::Int, 1883);

        return params;
    }

    DspComponent *Create(std::map<std::string, DspParameter> &params) const {
        std::string const* topic = params["topic"].GetString();
        std::string const* host = params["host"].GetString();
        int const* port = params["port"].GetInt();

        if(host || port) {
            return new OrchMqttSourceComponent(*topic, *host, *port);
        } else {
            return new OrchMqttSourceComponent(*topic);
        }
    }
};

EXPORT_DSPPLUGIN(OrchMqttSourcePlugin)

#endif //ORCHESTRA_ORCHMQTTSOURCECOMPONENT_H
