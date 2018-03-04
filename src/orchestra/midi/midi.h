//
// Created by Benjamin Rozière on 03/03/2018.
//

#ifndef ORCHESTRA_MIDI_H
#define ORCHESTRA_MIDI_H

//Midimessages are (in bits) [4: Cmd][4: Chan/Sys_msg cmd]...[8: data]...
//To assign a command to a channel use MidiCommand | MidiChannel (eg. NOTE_ON | CHAN_3)


enum MidiCommand {
    NOTE_OFF = 0x80,
    NOTE_ON = 0x90,
    AFTERTOUCH = 0xA0,
    CONT_CTRL = 0xB0,
    PATCH_CHANGE = 0xC0,
    CHAN_PRESSURE = 0xD0,
    PITCH_BEND = 0xE0,
    SYS_MSG = 0xF0
};

enum MidiChannel {
    CHAN_1 = 0x00,
    CHAN_2 = 0x01,
    CHAN_3 = 0x02,
    CHAN_4 = 0x03,
    CHAN_5 = 0x04,
    CHAN_6 = 0x05,
    CHAN_7 = 0x06,
    CHAN_8 = 0x07,
    CHAN_9 = 0x08,
    CHAN_10 = 0x09,
    CHAN_11 = 0x0A,
    CHAN_12 = 0x0B,
    CHAN_13 = 0x0C,
    CHAN_14 = 0x0D,
    CHAN_15 = 0x0E,
    CHAN_16 = 0x0F
};

enum MidiKey {

};



#endif //ORCHESTRA_MIDI_H
