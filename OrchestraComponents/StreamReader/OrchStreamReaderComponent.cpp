//
// Created by Benjamin Rozière on 10/01/2018.
//
#include <iostream>
#include "OrchStreamReaderComponent.h"

OrchStreamReaderComponent::OrchStreamReaderComponent(std::istream &inputStream) : inputStream(inputStream) {
    AddOutput_();
}

void OrchStreamReaderComponent::Process_(DspSignalBus &, DspSignalBus &outputs) {

    std::string line;
    std::getline(inputStream, line);

    std::string token = line.substr(line.find(';'), line.size());

    outputs.SetValue(0, std::stoi(token));
}
