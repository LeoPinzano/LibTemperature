# LibTemperature (MCP9808)

Ce projet utilise un capteur de température MCP9808 avec une connexion I2C, piloté par une Raspberry Pi et la bibliothèque `wiringPi` afin de lire les données de température et les affiche dans le terminal.

## Contenu du projet

- `main.cpp` : Le fichier principal qui lance la boucle pour lire les données de température à partir du capteur.
- `libTemp.h` : Le fichier header qui contient la déclaration de la classe `TemperatureSensor`.
- `libTemp.cpp` : Le fichier d'implémentation pour la classe `TemperatureSensor`.
- `CMakeLists.txt` : Le fichier de configuration pour la compilation avec CMake.

## Prérequis

### Matériel

- Une Raspberry Pi (ou tout autre système compatible avec I2C et `wiringPi`).
- Un capteur température MCP9808

### Logiciel

- [CMake](https://cmake.org/install/) version 3.10 ou supérieure.
- [wiringPi](http://wiringpi.com/) installé sur votre Raspberry Pi pour la communication I2C.

#### Installation de `wiringPi`

Si `wiringPi` n'est pas déjà installé, vous pouvez l'installer avec les commandes suivantes :

```bash
# fetch the source
sudo apt install git
git clone https://github.com/WiringPi/WiringPi.git
cd WiringPi

# build the package
./build debian
mv debian-template/wiringpi-3.0-1.deb .

# install i
sudo apt install ./wiringpi-3.0-1.deb

