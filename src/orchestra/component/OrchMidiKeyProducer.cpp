//
// Created by Benjamin Rozière on 03/03/2018.
//

#include <iostream>
#include "OrchMidiKeyProducer.h"

OrchMidiKeyProducer::OrchMidiKeyProducer(unsigned char key) : key(key) {
    AddInput_();
    AddOutput_();
}

void OrchMidiKeyProducer::Process_(DspSignalBus &input, DspSignalBus &output) {

    std::string val;

    if (input.GetValue(0, val))
    {
        output.SetValue(0, key);
    }

}


