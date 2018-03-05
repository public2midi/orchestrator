//
// Created by Benjamin Rozière on 03/03/2018.
//

#ifndef ORCHESTRA_ORCHMIDIKEYPRODUCER_H
#define ORCHESTRA_ORCHMIDIKEYPRODUCER_H


#include <dspatch/DspComponent.h>

class OrchMidiKeyProducer: public DspComponent {
public:
    OrchMidiKeyProducer(unsigned char key);

protected:
    void Process_(DspSignalBus &bus, DspSignalBus &signalBus) override;

private:
    unsigned char key;
};


#endif //ORCHESTRA_ORCHMIDIKEYPRODUCER_H
