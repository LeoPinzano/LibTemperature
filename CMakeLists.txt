# Version minimale requise de CMake
cmake_minimum_required(VERSION 3.10)

# Nom du projet
project(TemperatureSensorProject)

# Spécification du standard C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Ajout des fichiers sources pour l'exécutable
add_executable(libTemp main.cpp libTemp.cpp)

# Inclure le fichier header
target_include_directories(libTemp PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Lier la bibliothèque WiringPi
target_link_libraries(libTemp wiringPi)

