//
// Created by Benjamin Rozière on 04/03/2018.
//

#include <iostream>
#include "OrchMidiTextToKeyComponent.h"

OrchMidiTextToKeyComponent::OrchMidiTextToKeyComponent() {
    AddInput_();
    AddOutput_();
}

void OrchMidiTextToKeyComponent::Process_(DspSignalBus &input, DspSignalBus &output) {

    std::string keyName;
    MidiKey key;

    if (input.GetValue(0, keyName)) {
        try {
            key = keyMap.at(keyName);
            output.SetValue(0, key);
        }
        catch (std::exception const &e) {
            std::cerr << "[Circuit]Key " << keyName << " is not playable!\n";
        }
    }
}

std::unordered_map<std::string, MidiKey> OrchMidiTextToKeyComponent::keyMap{
        {"A0",  MidiKey::A0},
        {"Bb0", MidiKey::Bb0},
        {"B0",  MidiKey::B0},
        {"C1",  MidiKey::C1},
        {"Db1", MidiKey::Db1},
        {"D1",  MidiKey::D1},
        {"Eb1", MidiKey::Eb1},
        {"E1",  MidiKey::E1},
        {"F1",  MidiKey::F1},
        {"Gb1", MidiKey::Gb1},
        {"G1",  MidiKey::G1},
        {"Ab1", MidiKey::Ab1},
        {"A1",  MidiKey::A1},
        {"Bb1", MidiKey::Bb1},
        {"B1",  MidiKey::B1},
        {"C2",  MidiKey::C2},
        {"Db2", MidiKey::Db2},
        {"D2",  MidiKey::D2},
        {"Eb2", MidiKey::Eb2},
        {"E2",  MidiKey::E2},
        {"F2",  MidiKey::F2},
        {"Gb2", MidiKey::Gb2},
        {"G2",  MidiKey::G2},
        {"Ab2", MidiKey::Ab2},
        {"A2",  MidiKey::A2},
        {"Bb2", MidiKey::Bb2},
        {"B2",  MidiKey::B2},
        {"C3",  MidiKey::C3},
        {"Db3", MidiKey::Db3},
        {"D3",  MidiKey::D3},
        {"Eb3", MidiKey::Eb3},
        {"E3",  MidiKey::E3},
        {"F3",  MidiKey::F3},
        {"Gb3", MidiKey::Gb3},
        {"G3",  MidiKey::G3},
        {"Ab3", MidiKey::Ab3},
        {"A3",  MidiKey::A3},
        {"Bb3", MidiKey::Bb3},
        {"B3",  MidiKey::B3},
        {"C4",  MidiKey::C4},
        {"Db4", MidiKey::Db4},
        {"D4",  MidiKey::D4},
        {"Eb4", MidiKey::Eb4},
        {"E4",  MidiKey::E4},
        {"F4",  MidiKey::F4},
        {"Gb4", MidiKey::Gb4},
        {"G4",  MidiKey::G4},
        {"Ab4", MidiKey::Ab4},
        {"A4",  MidiKey::A4},
        {"Bb4", MidiKey::Bb4},
        {"B4",  MidiKey::B4},
        {"C5",  MidiKey::C5},
        {"Db5", MidiKey::Db5},
        {"D5",  MidiKey::D5},
        {"Eb5", MidiKey::Eb5},
        {"E5",  MidiKey::E5},
        {"F5",  MidiKey::F5},
        {"Gb5", MidiKey::Gb5},
        {"G5",  MidiKey::G5},
        {"Ab5", MidiKey::Ab5},
        {"A5",  MidiKey::A5},
        {"Bb5", MidiKey::Bb5},
        {"B5",  MidiKey::B5},
        {"C6",  MidiKey::C6},
        {"Db6", MidiKey::Db6},
        {"D6",  MidiKey::D6},
        {"Eb6", MidiKey::Eb6},
        {"E6",  MidiKey::E6},
        {"F6",  MidiKey::F6},
        {"Gb6", MidiKey::Gb6},
        {"G6",  MidiKey::G6},
        {"Ab6", MidiKey::Ab6},
        {"A6",  MidiKey::A6},
        {"Bb6", MidiKey::Bb6},
        {"B6",  MidiKey::B6},
        {"C7",  MidiKey::C7},
        {"Db7", MidiKey::Db7},
        {"D7",  MidiKey::D7},
        {"Eb7", MidiKey::Eb7},
        {"E7",  MidiKey::E7},
        {"F7",  MidiKey::F7},
        {"Gb7", MidiKey::Gb7},
        {"G7",  MidiKey::G7},
        {"Ab7", MidiKey::Ab7},
        {"A7",  MidiKey::A7},
        {"Bb7", MidiKey::Bb7},
        {"B7",  MidiKey::B7},
        {"C8",  MidiKey::C8}
};