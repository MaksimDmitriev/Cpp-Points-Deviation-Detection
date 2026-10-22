#include <iostream>
#include <memory>

struct Sensor {
    double temperature = 25.0;

    ~Sensor() {
        std::cout << "Sensor destroyed\n";
    }
};

int main() {
    // The robot owns the sensor.
    auto robotSensor = std::make_shared<Sensor>();

    // The dashboard observes it without owning it.
    std::weak_ptr<Sensor> dashboardSensor = robotSensor;

    // Temporarily acquire ownership to safely access the sensor.
    if (auto sensor = dashboardSensor.lock()) {
        std::cout << sensor->temperature << '\n';
    } // Temporary shared_ptr destroyed; robot still owns the sensor.

    robotSensor.reset(); // Last owner gone: sensor destroyed.

    if (auto sensor = dashboardSensor.lock()) {
        std::cout << sensor->temperature << '\n';
    } else {
        std::cout << "Sensor disconnected\n";
    }
}