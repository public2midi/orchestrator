//
// Created by Benjamin Rozière on 10/01/2018.
//

#ifndef ORCHESTRA_ORCHSTREAMWRITERCOMPONENT_H
#define ORCHESTRA_ORCHSTREAMWRITERCOMPONENT_H


#include <iosfwd>
#include <ostream>
#include <DSPatch.h>

class OrchStreamWriterComponent : public DspComponent {

public:
    OrchStreamWriterComponent(std::ostream&);

protected:
    void Process_(DspSignalBus &bus, DspSignalBus &signalBus) override;

private:
    std::ostream& outputStream;
};


#endif //ORCHESTRA_ORCHSTREAMWRITERCOMPONENT_H
