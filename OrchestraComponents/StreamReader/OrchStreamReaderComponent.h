//
// Created by Benjamin Rozière on 10/01/2018.
//

#ifndef ORCHESTRA_ORCHSTREAMREADERCOMPONENT_H
#define ORCHESTRA_ORCHSTREAMREADERCOMPONENT_H


#include <DSPatch.h>

class OrchStreamReaderComponent : public DspComponent {

public:
    OrchStreamReaderComponent(std::istream &);

protected:
    void Process_(DspSignalBus &bus, DspSignalBus &signalBus) override;

private:
    std::istream& inputStream;
};

class OrchStreamReaderPlugin : public DspPlugin {
public:
    std::map<std::string, DspParameter> GetCreateParams() const {
        return std::map<std::string, DspParameter>();
    }

    DspComponent *Create(std::map<std::string, DspParameter> &params) const {
        return new OrchStreamReaderComponent(std::cin);
    }
};

EXPORT_DSPPLUGIN(OrchStreamReaderPlugin)

#endif //ORCHESTRA_ORCHSTREAMREADERCOMPONENT_H
