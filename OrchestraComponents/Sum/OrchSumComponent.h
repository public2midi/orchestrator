//
// Created by Benjamin Rozière on 10/01/2018.
//

#ifndef ORCHESTRA_ORCHSUMCOMPONENT_H
#define ORCHESTRA_ORCHSUMCOMPONENT_H


#include <DSPatch.h>

class OrchSumComponent : public DspComponent {

public:
    OrchSumComponent();

protected:
    void Process_(DspSignalBus &bus, DspSignalBus &signalBus) override;

private:
    long int sum;

};


#endif //ORCHESTRA_ORCHSUMCOMPONENT_H
