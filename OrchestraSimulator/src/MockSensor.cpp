//
// Created by Benjamin Rozière on 09/01/2018.
//

#include <random>
#include <iostream>
#include <thread>
#include <mutex>

#include "../include/MockSensor.h"

std::mutex cout_mu;

int MockSensor::NEXT_INT = 0;

void MockSensor::run() {
    thread_local std::random_device rd;

    thread_local std::mt19937 engine(rd());

    thread_local std::uniform_int_distribution<int> dist(0, 10);

    while (true) {
        int val = dist(engine);
        cout_mu.lock();
        this->output << this->id << ";" << val << std::endl;
        cout_mu.unlock();
        std::this_thread::sleep_for(std::chrono::seconds(val));
    }
}

int MockSensor::getId() {
    return this->id;
}

MockSensor::MockSensor() : MockSensor(NEXT_INT++, std::cout) {}

MockSensor::MockSensor(int id) : MockSensor(id, std::cout) {}

MockSensor::MockSensor(int id, std::ostream& str) : id(id), output(str) {}

MockSensor::MockSensor(std::ostream& str) : MockSensor(NEXT_INT++, str) {}
