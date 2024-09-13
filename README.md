# LibTemperature (MCP9808)

Ce projet utilise un capteur de température MCP9808 avec une connexion I2C, piloté par une Raspberry Pi et la bibliothèque `wiringPi` afin de lire les données de température et les affiche dans le terminal.

## Contenu du projet

- `main.cpp` : Le fichier principal qui lance la boucle pour lire les données de température à partir du capteur.
- `TemperatureSensor.h` : Le fichier header qui contient la déclaration de la classe `TemperatureSensor`.
- `TemperatureSensor.cpp` : Le fichier d'implémentation pour la classe `TemperatureSensor`.
- `CMakeLists.txt` : Le fichier de configuration pour la compilation avec CMake.

## Prérequis

Avant de commencer, assurez-vous d'avoir les éléments suivants installés :

- Une Raspberry Pi (ou tout autre système compatible avec I2C et `wiringPi`).
- [CMake](https://cmake.org/install/) version 3.10 ou supérieure.
- [wiringPi](http://wiringpi.com/) installé sur votre Raspberry Pi pour la communication I2C.

### Installation de `wiringPi`

Si `wiringPi` n'est pas déjà installé, vous pouvez l'installer avec la commande suivante :

```bash
sudo apt-get install wiringpi
