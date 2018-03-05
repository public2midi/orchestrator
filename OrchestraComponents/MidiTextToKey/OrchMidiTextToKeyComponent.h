//
// Created by Benjamin Rozière on 04/03/2018.
//

#ifndef ORCHESTRA_ORCHMIDITEXTTOKEYCOMPONENT_H
#define ORCHESTRA_ORCHMIDITEXTTOKEYCOMPONENT_H


#include <dspatch/DspComponent.h>
#include <unordered_map>
#include <midi.h>

class OrchMidiTextToKeyComponent: public DspComponent {

private:
     static std::unordered_map<std::string, MidiKey> keyMap;

public:
    OrchMidiTextToKeyComponent();

protected:
    void Process_(DspSignalBus &bus, DspSignalBus &signalBus) override;
};


#endif //ORCHESTRA_ORCHMIDITEXTTOKEYCOMPONENT_H
