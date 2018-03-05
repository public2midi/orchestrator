//
// Created by Benjamin Rozière on 05/03/2018.
//

#ifndef ORCHESTRA_ORCHGAINCOMPONENT_H
#define ORCHESTRA_ORCHGAINCOMPONENT_H


#include <dspatch/DspComponent.h>
#include <dspatch/DspPlugin.h>

class OrchGainComponent : public DspComponent {
private:
    int _gain; //Float container
    std::vector<float> _stream;

public:

    OrchGainComponent(float _gain = 1);

    void set_gain(float _gain);
    float get_gain() const;

protected:
    void Process_(DspSignalBus &bus, DspSignalBus &signalBus) override;

    bool ParameterUpdating_(int i, DspParameter const &parameter) override;

};

class OrchGainPlugin : public DspPlugin {

    std::map<std::string, DspParameter> GetCreateParams() const {
        std::map<std::string, DspParameter> params;

        params["gain"] = DspParameter(DspParameter::Float, 1, std::make_pair(0, 10));
        return params;

    }

    DspComponent *Create(std::map<std::string, DspParameter> &params) const {

        float const* gain = params["gain"].GetFloat();

        if (gain) {
            return new OrchGainComponent(*gain);
        } else {
            return new OrchGainComponent();
        }
    }
};


EXPORT_DSPPLUGIN(OrchGainPlugin)

#endif //ORCHESTRA_ORCHGAINCOMPONENT_H
