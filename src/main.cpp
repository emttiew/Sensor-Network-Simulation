#include <vector>

#include "Sensor.hpp"
#include "TemperatureSensor.hpp"
#include "HumiditySensor.hpp"
#include "Client.hpp"

int main() {
    MainNode mainNode(10);

    std::vector<sensor::SensorPtr> sensors;
    for (int i = 0; i < 2; ++i) {
        sensors.push_back(std::make_shared<sensor::TemperatureSensor>(i, mainNode));
    }

    for (int i = 0; i < 2; ++i) {
        sensors.push_back(std::make_shared<sensor::HumiditySensor>(i, mainNode));
    }

    for (sensor::SensorPtr const& sensor : sensors) {
        sensor->start();
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