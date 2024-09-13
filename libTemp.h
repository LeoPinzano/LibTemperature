#ifndef LIBTEMP_H
#define LIBTEMP_H

class TemperatureSensor {
private:
    int device;

public:
    // Constructeur pour initialiser l'I2C avec l'adresse du capteur
    TemperatureSensor();

    // Méthode pour lire la température depuis le capteur
    float readTemperature();
};

#endif // LIBTEMP_H
