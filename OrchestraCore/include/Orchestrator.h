//
// Created by Benjamin Rozière on 04/03/2018.
//

#ifndef ORCHESTRA_ORCHESTRATOR_H
#define ORCHESTRA_ORCHESTRATOR_H


#include <dspatch/DspCircuit.h>

class Orchestrator {
private:
    DspCircuit *_circuit;
    bool _running;

public:
    Orchestrator();

    void start(void);
    void stop(void);

    bool is_running() const;
    DspCircuit *get_circuit() const;

    virtual ~Orchestrator();
};


#endif //ORCHESTRA_ORCHESTRATOR_H
