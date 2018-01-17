//
// Created by Benjamin Rozière on 09/01/2018.
//

#include <thread>
#include <random>

#include "MockSensor.h"

#define DEFAULT_SENSOR 2
#define MAX_MOCK_SENSOR 50

int main(int argc, char **argv) {

    std::vector<MockSensor*> sensors;
    std::vector<std::thread*> threads;

    int nbSensors = DEFAULT_SENSOR;

    if (argc > 1) {
        nbSensors = atoi(argv[1]);
    }

    for (int i = 0; i < nbSensors; i++) {

        auto *s = new MockSensor(std::cerr);

        sensors.push_back(s);

        auto *t = new std::thread(&MockSensor::run, *s);

        threads.push_back(t);
    }

    getchar();

    return 0;
}