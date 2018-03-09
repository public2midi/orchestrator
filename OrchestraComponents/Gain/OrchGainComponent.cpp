//
// Created by Benjamin Rozière on 05/03/2018.
//

#include "OrchGainComponent.h"

OrchGainComponent::OrchGainComponent(float _gain) {
    AddInput_();
    AddOutput_();

    _gain = AddParameter_("gain", DspParameter(DspParameter::Float, 1, std::make_pair(0, 10)));
}

float OrchGainComponent::get_gain() const {
    return *GetParameter_(_gain)->GetFloat();
}

void OrchGainComponent::set_gain(float gain) {
    SetParameter_(_gain, DspParameter(DspParameter::Float, gain));
}

void OrchGainComponent::Process_(DspSignalBus &input, DspSignalBus &output) {

    if(!input.GetValue(0, _stream)) {
        _stream.assign(_stream.size(), 0);
    }

    for (size_t i = 0; i < _stream.size(); i++) {
        _stream[i] *= get_gain();
     }

    output.SetValue(0, _stream);
}

bool OrchGainComponent::ParameterUpdating_(int index, DspParameter const &parameter) {
    if (index == _gain) {
        set_gain(*parameter.GetFloat());
        return true;
    }

    return false;
}
