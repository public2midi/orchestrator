//
// Created by Benjamin Rozière on 09/01/2018.
//

#include <iostream>

#include <DSPatch.h>

#include "component/OrchSumComponent.h"
#include "component/OrchStreamReaderComponent.h"
#include "component/OrchStreamWriterComponent.h"
#include "component/OrchMqttSourceComponent.h"

int main() {

    DspCircuit circuit;

    //OrchStreamReaderComponent reader(std::cin);

    //OrchSumComponent sum;

    OrchStreamWriterComponent writer(std::cout);

    OrchMqttSourceComponent mqttCmp("localhost", "/test");

    circuit.AddComponent(mqttCmp, "mqtt");

    //circuit.AddComponent(reader, "Reader");
    //circuit.AddComponent(sum, "Sum");
    circuit.AddComponent(writer, "Writer");

    circuit.ConnectOutToIn(mqttCmp, 0, writer, 0);
    //circuit.ConnectOutToIn(sum, 0, writer, 0);

    circuit.StartAutoTick();
    getchar();
    circuit.StopAutoTick();

    DSPatch::Finalize();

    return EXIT_SUCCESS;
}
