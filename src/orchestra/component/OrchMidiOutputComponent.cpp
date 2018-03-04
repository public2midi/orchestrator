//
// Created by Benjamin Rozière on 03/03/2018.
//

#include "OrchMidiOutputComponent.h"
#include "../midi/midi.h"

OrchMidiOutputKeyComponent::OrchMidiOutputKeyComponent(): midiOut(new RtMidiOut()) {

    AddInput_();

    midiOut->openVirtualPort();

    unsigned int nPorts = midiOut->getPortCount();

    if (nPorts == 0) {
        std::cerr << "No ports available\n";
        delete midiOut;
        midiOut = nullptr;
    }
}

void OrchMidiOutputKeyComponent::Process_(DspSignalBus &input, DspSignalBus &) {

    unsigned char key;

    std::vector<unsigned char> midiMessage;

    if (input.GetValue(0, key)) {
        midiMessage.push_back(MidiCommand::NOTE_ON);
        midiMessage.push_back(key);
        midiMessage.push_back(90);
        midiOut->sendMessage(&midiMessage);
    }

}


