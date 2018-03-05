//
// Created by Benjamin Rozière on 04/03/2018.
//

#include <iostream>

#include "Orchestrator.h"

Orchestrator::Orchestrator(): _circuit(new DspCircuit()) {

    /*auto writer = new OrchStreamWriterComponent(std::cout);

    auto mqttCmp = new OrchMqttSourceComponent("/test");

    _circuit->AddComponent(mqttCmp, "mqtt");

    _circuit->AddComponent(writer, "Writer");

    _circuit->ConnectOutToIn(mqttCmp, 0, writer, 0);*/
}

void Orchestrator::start(void) {
    _circuit->StartAutoTick();
}

void Orchestrator::stop(void) {
    _circuit->StopAutoTick();
}

Orchestrator::~Orchestrator() {
    stop();

    delete _circuit;
    _circuit = nullptr;
}

bool Orchestrator::is_running() const {
    return _running;
}

DspCircuit *Orchestrator::get_circuit() const {
    return _circuit;
}



