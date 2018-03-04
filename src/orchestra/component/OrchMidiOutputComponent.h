//
// Created by Benjamin Rozière on 03/03/2018.
//

#ifndef ORCHESTRA_ORCHMIDIOUTPUTCOMPONENT_H
#define ORCHESTRA_ORCHMIDIOUTPUTCOMPONENT_H

#include <dspatch/DspComponent.h>
#include "../midi/RtMidi.h"

class OrchMidiOutputKeyComponent: public DspComponent {
public:
    OrchMidiOutputKeyComponent();

protected:
    void Process_(DspSignalBus &bus, DspSignalBus &signalBus) override;

private:
    RtMidiOut *midiOut;




};


#endif //ORCHESTRA_ORCHMIDIOUTPUTCOMPONENT_H
