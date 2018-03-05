//
// Created by Benjamin Rozière on 10/01/2018.
//

#ifndef ORCHESTRA_ORCHSTREAMWRITERCOMPONENT_H
#define ORCHESTRA_ORCHSTREAMWRITERCOMPONENT_H


#include <iosfwd>
#include <ostream>
#include <DSPatch.h>
#include <iostream>

class OrchStreamWriterComponent : public DspComponent {

public:
    OrchStreamWriterComponent(std::ostream&);

protected:
    void Process_(DspSignalBus &bus, DspSignalBus &signalBus) override;

private:
    std::ostream& outputStream;
};

class OrchStreamWriterPlugin : public DspPlugin {
public:
    std::map<std::string, DspParameter> GetCreateParams() const {
        return std::map<std::string, DspParameter>();
    }

    DspComponent *Create(std::map<std::string, DspParameter> &params) const {
        return new OrchStreamWriterComponent(std::cout);
    }
};

EXPORT_DSPPLUGIN(OrchStreamWriterPlugin)

#endif //ORCHESTRA_ORCHSTREAMWRITERCOMPONENT_H
