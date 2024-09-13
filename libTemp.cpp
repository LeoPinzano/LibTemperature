#include "libTemp.h"
#include <wiringPiI2C.h>
#include <iostream>
#include <unistd.h>

#define MCP9808_I2CADDR 0x18  // Adresse I2C par défaut du capteur
#define MCP9808_REG_TEMP 0x05 // Registre pour lire la température

// Constructeur
TemperatureSensor::TemperatureSensor() {
    // Initialiser l'I2C avec l'adresse du capteur
    device = wiringPiI2CSetup(MCP9808_I2CADDR);
    if (device == -1) {
        std::cerr << "Erreur : Impossible de se connecter au capteur MCP9808" << std::endl;
        exit(1);
    }
}

// Méthode pour lire la température
float TemperatureSensor::readTemperature() {
    // Lire les 16 bits de température
    int tempRaw = wiringPiI2CReadReg16(device, MCP9808_REG_TEMP);
    if (tempRaw == -1) {
        std::cerr << "Erreur de lecture du capteur MCP9808" << std::endl;
        return -1; // Code d'erreur
    }

    // Remettre les octets dans l'ordre correct (parfois nécessaire avec I2C)
    tempRaw = ((tempRaw << 8) & 0xFF00) | ((tempRaw >> 8) & 0x00FF);

    // Extraire les bits de température
    int UpperByte = (tempRaw & 0x0FF0) >> 4; // 12 bits de température significative
    int LowerByte = tempRaw & 0x000F; // 4 bits moins significatifs

    // Déterminer si la température est négative
    bool isNegative = (tempRaw & 0x1000) != 0;

    float temperature;
    if (!isNegative) {
        // Température positive
        temperature = UpperByte + (LowerByte / 16.0);
    } else {
        // Température négative
        temperature = 256 - (UpperByte + (LowerByte / 16.0));
    }

    return temperature;
}

