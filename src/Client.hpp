#pragma once

#include <iostream>

class Client {
public:
    Client(int id) : id(id) {}

    void receiveData(int data) {
        std::cout << "Client " << id << " received data: " << data << "\n";
    }

private:
    int id;
};