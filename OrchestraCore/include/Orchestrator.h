//
// Created by Benjamin Rozière on 04/03/2018.
//

#ifndef ORCHESTRA_ORCHESTRATOR_H
#define ORCHESTRA_ORCHESTRATOR_H


#include <dspatch/DspCircuit.h>

class Orchestrator {
private:
    DspCircuit *_circuit;
public:
    Orchestrator();

    void start(void);
    void stop(void);

    virtual ~Orchestrator();
};


#endif //ORCHESTRA_ORCHESTRATOR_H
