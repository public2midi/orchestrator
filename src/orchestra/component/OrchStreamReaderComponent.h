//
// Created by Benjamin Rozière on 10/01/2018.
//

#ifndef ORCHESTRA_ORCHSTREAMREADERCOMPONENT_H
#define ORCHESTRA_ORCHSTREAMREADERCOMPONENT_H


#include <iosfwd>
#include <DSPatch.h>

class OrchStreamReaderComponent : public DspComponent {

public:
    OrchStreamReaderComponent(std::istream &);

protected:
    void Process_(DspSignalBus &bus, DspSignalBus &signalBus) override;

private:
    std::istream& inputStream;
};


#endif //ORCHESTRA_ORCHSTREAMREADERCOMPONENT_H
