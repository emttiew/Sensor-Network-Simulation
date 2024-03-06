#include <vector>

#include "Sensor.hpp"
#include "Client.hpp"

int main() {
    MainNode mainNode(10);

    std::vector<Sensor> sensors;
    for (int i = 0; i < 5; ++i) {
        sensors.push_back(Sensor(i, mainNode));
    }

    for (Sensor& sensor : sensors) {
        sensor.start();
    }

    mainNode.start();

    std::vector<Client> clients;
    for (int i = 0; i < 3; ++i) {
        clients.push_back(Client(i));
    }

    for (Client& client : clients)
    {
        mainNode.addClient(client);
    }

    while (true) {}

    return 0;
}