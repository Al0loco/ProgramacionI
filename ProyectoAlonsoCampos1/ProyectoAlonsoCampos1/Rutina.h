#pragma once
#include <iostream>
using namespace std;

class Ejercicio;

class Rutina {
private:
// Arreglos dinámicos para cada zona porque una rutina puede tener múltiples ejercicios por zona y no se sabe cuántos en tiempo de compilación.
    Ejercicio** ejerciciosPecho;
    Ejercicio** ejerciciosBiceps;
    Ejercicio** ejerciciosPiernas;
    Ejercicio** ejerciciosEspalda;
public:
// Constructores y destructores
    Rutina();
    ~Rutina();
// Funciones accionales
    void agregarEjercicioZona(string, Ejercicio*);
};
