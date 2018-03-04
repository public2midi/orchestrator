//
// Created by Benjamin Rozière on 09/01/2018.
//

#include <iostream>

#include <DSPatch.h>

#include "component/OrchSumComponent.h"
#include "component/OrchStreamReaderComponent.h"
#include "component/OrchStreamWriterComponent.h"
#include "component/OrchMqttSourceComponent.h"
#include "component/OrchMidiOutputComponent.h"
#include "component/OrchMidiKeyProducer.h"
#include "component/OrchMidiTextToKeyComponent.h"

int main() {

    DspCircuit circuit;

    OrchStreamWriterComponent writer(std::cout);
    OrchMqttSourceComponent mqttCmp("/test");
    OrchMidiTextToKeyComponent producer;
    OrchMidiOutputKeyComponent midiOutput;

    circuit.AddComponent(mqttCmp, "mqtt");
    circuit.AddComponent(writer, "Writer");
    circuit.AddComponent(producer, "Producer");
    circuit.AddComponent(midiOutput, "Output");

    circuit.ConnectOutToIn(mqttCmp, 0, producer, 0);
    circuit.ConnectOutToIn(producer, 0, writer, 0);
    circuit.ConnectOutToIn(producer, 0, midiOutput, 0);

    circuit.StartAutoTick();
    getchar();
    circuit.StopAutoTick();

    DSPatch::Finalize();

    return EXIT_SUCCESS;
}
