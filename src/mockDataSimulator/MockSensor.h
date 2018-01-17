//
// Created by Benjamin Rozière on 09/01/2018.
//

#ifndef ORCHESTRA_MOCKSENSOR_H
#define ORCHESTRA_MOCKSENSOR_H

#include <iostream>

class MockSensor {

private:
    static int NEXT_INT;

    int id;
    std::ostream& output;

public:
    explicit MockSensor();
    explicit MockSensor(int);
    explicit MockSensor(std::ostream&);
    MockSensor(int, std::ostream&);

    int getId();
    void run();
};


#endif //ORCHESTRA_MOCKSENSOR_H
