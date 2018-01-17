//
// Created by Benjamin Rozière on 09/01/2018.
//

#include <iostream>

#include <DSPatch.h>

#include "component/OrchSumComponent.h"
#include "component/OrchStreamReaderComponent.h"
#include "component/OrchStreamWriterComponent.h"

int main() {

    DspCircuit circuit;

    OrchStreamReaderComponent reader(std::cin);

    OrchSumComponent sum;

    OrchStreamWriterComponent writer(std::cout);

    circuit.AddComponent(reader, "Reader");
    circuit.AddComponent(sum, "Sum");
    circuit.AddComponent(writer, "Writer");

    circuit.ConnectOutToIn(reader, 0, sum, 0);
    circuit.ConnectOutToIn(sum, 0, writer, 0);

    for (int i = 0; i < 10; i++) {
        circuit.Tick();
    }

    getchar();

    DSPatch::Finalize();

    return EXIT_SUCCESS;
}
