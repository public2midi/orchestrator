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
    A0 = 21,
    Bb0 = 22,
    B0 = 23,
    C1 = 24,
    Db1 = 25,
    D1 = 26,
    Eb1 = 27,
    E1 = 28,
    F1 = 29,
    Gb1 = 30,
    G1 = 31,
    Ab1 = 32,
    A1 = 33,
    Bb1 = 34,
    B1 = 35,
    C2 = 36,
    Db2 = 37,
    D2 = 38,
    Eb2 = 39,
    E2 = 40,
    F2 = 41,
    Gb2 = 42,
    G2 = 43,
    Ab2 = 44,
    A2 = 45,
    Bb2 = 46,
    B2 = 47,
    C3 = 48,
    Db3 = 49,
    D3 = 50,
    Eb3 = 51,
    E3 = 52,
    F3 = 53,
    Gb3 = 54,
    G3 = 55,
    Ab3 = 56,
    A3 = 57,
    Bb3 = 58,
    B3 = 59,
    C4 = 60,
    Db4 = 61,
    D4 = 62,
    Eb4 = 63,
    E4 = 64,
    F4 = 65,
    Gb4 = 66,
    G4 = 67,
    Ab4 = 68,
    A4 = 69,
    Bb4 = 70,
    B4 = 71,
    C5 = 72,
    Db5 = 73,
    D5 = 74,
    Eb5 = 75,
    E5 = 76,
    F5 = 77,
    Gb5 = 78,
    G5 = 79,
    Ab5 = 80,
    A5 = 81,
    Bb5 = 82,
    B5 = 83,
    C6 = 84,
    Db6 = 85,
    D6 = 86,
    Eb6 = 87,
    E6 = 88,
    F6 = 89,
    Gb6 = 90,
    G6 = 91,
    Ab6 = 92,
    A6 = 93,
    Bb6 = 94,
    B6 = 95,
    C7 = 96,
    Db7 = 97,
    D7 = 98,
    Eb7 = 99,
    E7 = 100,
    F7 = 101,
    Gb7 = 102,
    G7 = 103,
    Ab7 = 104,
    A7 = 105,
    Bb7 = 106,
    B7 = 107,
    C8 = 108,
    NOK = 0
};

#endif //ORCHESTRA_MIDI_H
