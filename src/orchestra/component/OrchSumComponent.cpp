//
// Created by Benjamin Rozière on 10/01/2018.
//

#include "OrchSumComponent.h"

OrchSumComponent::OrchSumComponent() : sum(0) {
    AddInput_();

    AddOutput_();
}

void OrchSumComponent::Process_(DspSignalBus &inputs, DspSignalBus &outputs) {

    int value;

    if (!inputs.GetValue(0, value)) {
        this->sum += value;
        outputs.SetValue(0, this->sum);
    }

}

