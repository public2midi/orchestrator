//
// Created by Benjamin Rozière on 10/01/2018.
//

#include "OrchStreamWriterComponent.h"

OrchStreamWriterComponent::OrchStreamWriterComponent(std::ostream &outputStream) : outputStream(outputStream) {
    AddInput_();
}

void OrchStreamWriterComponent::Process_(DspSignalBus &inputs, DspSignalBus &) {

    std::string val;

    if (inputs.GetValue(0, val)) {
        this->outputStream << val << std::endl;
    }
}

