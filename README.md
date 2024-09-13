Voici le `README.md` pour ton projet basé sur l'exemple que tu as fourni :

---

# Projet Capteur de Température (MCP9808)

## Description

Ce projet en C++ permet de lire les données de température à partir d'un capteur MCP9808 via une connexion I2C. Il utilise la bibliothèque `wiringPi` pour gérer les communications I2C sur une Raspberry Pi. Le capteur est interrogé en continu et la température est affichée en degrés Celsius dans le terminal.

Le projet repose principalement sur une classe `libTemp` qui encapsule la logique de lecture du capteur.

## Fonctionnalités

- **Classe `libTemp`** :
  - Représente un capteur de température MCP9808 connecté via I2C.
  - Utilise `wiringPi` pour la communication I2C avec le capteur.
  - Permet la lecture de la température sous forme de flottant (en °C).
  - Gère les erreurs de communication et vérifie la connexion au capteur lors de l'initialisation.

### Détails de la classe :
  - Constructeur pour initialiser le capteur avec son adresse I2C (par défaut : `0x18`).
  - Méthode `readTemperature()` pour récupérer la température en degrés Celsius, en tenant compte des valeurs négatives.
  
## Installation et Compilation

### Prérequis

Avant de commencer, assurez-vous d'avoir les éléments suivants installés :

- Une Raspberry Pi (ou tout autre système compatible I2C).
- La bibliothèque [wiringPi](http://wiringpi.com/) pour gérer les communications I2C.
- [CMake](https://cmake.org/) pour la compilation.

### Étapes

1. Clonez ce dépôt sur votre machine locale :
    ```bash
    git clone https://github.com/votre-utilisateur/temperature-sensor-mcp9808.git
    cd temperature-sensor-mcp9808
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

Si le capteur n'est pas détecté ou si une erreur de communication survient, un message d'erreur sera affiché dans la console.

## Structure du projet

Le projet contient les fichiers suivants :

- **`libTemp.h`** : Déclaration de la classe `libTemp`.
- **`libTemp.cpp`** : Implémentation de la classe `libTemp`.
- **`main.cpp`** : Programme principal qui utilise la classe pour lire la température du capteur et l'afficher.

## Contributeurs

- **Léo** : Développeur principal de la classe `libTemp` et intégration avec la bibliothèque `wiringPi`.
- **Pier-André** : Concepteur du diagramme de séquence et configuration de la carte Raspberry.

## Diagrame de séquence

![alt text](https://github.com/LeoPinzano/LibTemperature/blob/main/diag_seq_capt_temp.png)
