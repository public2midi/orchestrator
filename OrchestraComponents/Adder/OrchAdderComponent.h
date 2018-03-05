//
// Created by Benjamin Rozière on 10/01/2018.
//

#ifndef ORCHESTRA_ORCHADDERCOMPONENT_H
#define ORCHESTRA_ORCHADDERCOMPONENT_H


#include <DSPatch.h>

class OrchAdderComponent : public DspComponent {


public:
    OrchAdderComponent();

protected:
    void Process_(DspSignalBus &, DspSignalBus &) override;
};

class OrchAdderPlugin : public DspPlugin {

    std::map<std::string, DspParameter> GetCreateParams() const {
        return std::map<std::string, DspParameter>();
    }

    DspComponent *Create(std::map<std::string, DspParameter> &params) const {
        return new OrchAdderComponent();
    }
};

EXPORT_DSPPLUGIN(OrchAdderPlugin)

#endif //ORCHESTRA_ORCHADDERCOMPONENT_H
