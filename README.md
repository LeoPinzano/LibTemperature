# Projet Capteur de Température (MCP9808)

## Description

Ce projet permet de lire la température en temps réel depuis un capteur **MCP9808** connecté à une **Raspberry Pi** via une interface **I2C**. Il utilise la bibliothèque `wiringPi` pour gérer la communication avec le capteur et affiche les valeurs en degrés Celsius.

Le projet repose principalement sur une classe `libTemp` qui encapsule la logique de lecture du capteur.

## Structure du projet

Le projet contient les fichiers suivants :

- **`libTemp.h`** : Déclaration de la classe `libTemp`.
- **`libTemp.cpp`** : Implémentation de la classe `libTemp`.
- **`main.cpp`** : Programme principal qui utilise la classe pour lire la température du capteur et l'afficher.
- **`CMakeLists.txt`** : Fichier CMake pour compiler le projet.

## Contributeurs

- **Léo** : Développeur principal de la classe `libTemp` et intégration avec la bibliothèque `wiringPi`.
- **Pier-André** : Concepteur du diagramme de séquence et configuration de la carte Raspberry.

## Diagrame de séquence

![diag_seq_capt_temp](https://github.com/user-attachments/assets/b5e01db1-c2e3-4408-ac18-049ea37bd5bd)


## Fonctionnalités

- **Classe `libTemp`** :
  
- Lecture continue de la température via le capteur MCP9808.
- Gestion des erreurs de communication I2C.
- Affichage des valeurs de température en temps réel dans le terminal.
- Prise en charge des températures négatives.

### Détails de la classe :
  - Constructeur pour initialiser le capteur avec son adresse I2C (par défaut : `0x18`).
  - Méthode `readTemperature()` pour récupérer la température en degrés Celsius, en tenant compte des valeurs négatives.
  
## Installation et Compilation

### Prérequis

- Une Raspberry Pi ou autre système compatible I2C.
- Le capteur MCP9808 connecté aux broches I2C de la Raspberry Pi.
- Les bibliothèques suivantes doivent être installées :

  - **[wiringPi](https://github.com/WiringPi/WiringPi)** : Gestion des communications I2C sur Raspberry Pi.
  - **[CMake](https://cmake.org/)** : Outil de compilation pour construire le projet.

### Étapes

#### Installation de `wiringPi`

``` bash
# fetch the source
sudo apt install git
git clone https://github.com/WiringPi/WiringPi.git
cd WiringPi

# build the package
./build debian
mv debian-template/wiringpi-3.0-1.deb .

# install it
sudo apt install ./wiringpi-3.0-1.deb
```
#### Installation de `CMake`

``` bash
sudo apt install cmake
```

#### Cloner et compiler le projet

1. Clonez ce dépôt sur votre machine locale :
    ```bash
    git clone https://github.com/votre-utilisateur/LibTemperature.git
    cd LibTemperature
    ```

2. Créez un répertoire de build et compilez le projet avec CMake :
    ```bash
    mkdir build
    cd build
    cmake ..
    make
    ```

3. Exécutez le programme compilé :
    ```bash
    ./libTemp
    ```

## Utilisation

Le programme interroge en continu le capteur MCP9808 toutes les secondes et affiche la température dans le terminal. Voici un exemple de sortie :

```
Température : 23.5°C
Température : 23.6°C
Température : 23.7°C
```

Si le capteur est mal connecté ou s'il y a une erreur de communication, le programme affichera un message d'erreur dans le terminal. Assurez-vous que le capteur est bien branché sur les broches I2C de la Raspberry Pi et que l'adresse I2C utilisée est correcte.

## Dépannage

- **Erreur : "Aucun capteur détecté"** :
  - Vérifiez que le capteur est correctement connecté aux broches I2C (SDA, SCL) de la Raspberry Pi.
  - Assurez-vous que l'adresse I2C du capteur est correcte. L'adresse par défaut est `0x18`, mais elle peut être modifiée.
  - Utilisez la commande `i2cdetect -y 1` pour vérifier si le capteur est détecté sur le bus I2C.

- **Erreur de compilation** :
  - Assurez-vous que `wiringPi` et `CMake` sont correctement installés.
