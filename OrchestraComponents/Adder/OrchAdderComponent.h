//
// Created by Benjamin Rozière on 10/01/2018.
//

#ifndef ORCHESTRA_ORCHADDERCOMPONENT_H
#define ORCHESTRA_ORCHADDERCOMPONENT_H


#include <DSPatch.h>

class OrchAdderComponent : public DspComponent {


public:
    OrchAdderComponent();

protected:
    void Process_(DspSignalBus &, DspSignalBus &) override;
};


#endif //ORCHESTRA_ORCHADDERCOMPONENT_H
