#pragma once

#include <thread>
#include <random>
#include <chrono>

#include "MainNode.hpp"

class Sensor {
public:
    Sensor(int id, MainNode& mainNode) : id(id), mainNode(mainNode) {}

    void start() {
        std::thread dataThread(&Sensor::generateData, this);
        dataThread.detach();
    }

private:
    int id;
    MainNode& mainNode;

    void generateData() {
        while (true) {
            // Generate random data
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> distr(1, 100);
            int data = distr(gen);

            mainNode.receiveData(data);
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
};