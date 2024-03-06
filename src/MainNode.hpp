#pragma once

#include <boost/circular_buffer.hpp>
#include <mutex>
#include <thread>
#include <condition_variable>

#include "Client.hpp"

class MainNode {
public:
    explicit MainNode(int bufferSize) : buffer(bufferSize) {}

    void receiveData(int data) {
        std::lock_guard<std::mutex> lock(mutex);

        buffer.push_back(data);
        condVar.notify_one();
    }

    void start() {
        std::thread notifyThread(&MainNode::notifyClients, this);
        notifyThread.detach();
    }

     void addClient(Client& client) {
        clients.push_back(client);
    }

private:
    boost::circular_buffer<int> buffer;
    std::mutex mutex;
    std::condition_variable condVar;
    std::vector<std::reference_wrapper<Client>> clients;

    void notifyClients() {
        while (true) {
            std::unique_lock<std::mutex> lock(mutex);

            condVar.wait(lock);

            for (int data : buffer) {
                for (Client& client : clients) {
                    client.receiveData(data);
                }
            }
            buffer.clear();
        }
    }
};