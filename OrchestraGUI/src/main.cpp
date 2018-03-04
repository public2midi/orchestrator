//
// Created by Benjamin Rozière on 09/01/2018.
//

#include <iostream>
#include <Orchestrator.h>

int main() {

    Orchestrator orchestrator;

    orchestrator.start();
    getchar();
    orchestrator.stop();

    return EXIT_SUCCESS;
}
