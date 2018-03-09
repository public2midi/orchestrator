//
// Created by Benjamin Rozière on 03/03/2018.
//

#ifndef ORCHESTRA_ORCHMIDIOUTPUTCOMPONENT_H
#define ORCHESTRA_ORCHMIDIOUTPUTCOMPONENT_H

#include <dspatch/DspComponent.h>
#include <RtMidi.h>
#include <dspatch/DspPlugin.h>

class OrchMidiOutputKeyComponent: public DspComponent {
public:
    OrchMidiOutputKeyComponent();

    virtual ~OrchMidiOutputKeyComponent();

protected:
    void Process_(DspSignalBus &bus, DspSignalBus &signalBus) override;

private:
    RtMidiOut *midiOut;

    int _channel;
    int _velocity;
};

class OrchMidiOutputKeyPlugin : public DspPlugin {
public:
    std::map<std::string, DspParameter> GetCreateParams() const {
        return std::map<std::string, DspParameter>();
    }

    DspComponent *Create(std::map<std::string, DspParameter> &params) const {
        return new OrchMidiOutputKeyComponent();
    }
};

EXPORT_DSPPLUGIN(OrchMidiOutputKeyPlugin)

#endif //ORCHESTRA_ORCHMIDIOUTPUTCOMPONENT_H
