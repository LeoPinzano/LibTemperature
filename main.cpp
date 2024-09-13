#include "libTemp.h"
#include <iostream>
#include <unistd.h>

int main() {
    TemperatureSensor sensor;

    while (true) {
        float temperature = sensor.readTemperature();
        if (temperature != -1) { // Si la lecture a réussi
            std::cout << "Température : " << temperature << "°C" << std::endl;
        }
        sleep(1); // Attendre 1 seconde entre chaque lecture
    }

    return 0;
}

