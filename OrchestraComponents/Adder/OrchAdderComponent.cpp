//
// Created by Benjamin Rozière on 10/01/2018.
//

#include "OrchAdderComponent.h"

OrchAdderComponent::OrchAdderComponent() {
    AddInput_("Input1");
    AddInput_("Input2");

    AddOutput_("Output1");
}

void OrchAdderComponent::Process_(DspSignalBus &inputs, DspSignalBus &outputs) {

    int input1 = 0;
    int input2 = 0;

    if (inputs.GetValue("Input1", input1) && inputs.GetValue("Input2", input2)) {
        outputs.SetValue("Output1", input1 + input2);
    }

}
