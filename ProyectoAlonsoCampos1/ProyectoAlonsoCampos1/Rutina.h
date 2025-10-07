#ifndef RUTINA_H
#define RUTINA_H

#include <string>

class Ejercicio;

class Rutina {
private:
    static const int MAX_EJERCICIOS = 3;

    // Arreglos de punteros a Ejercicio por zona muscular
    Ejercicio** ejerciciosPecho;
    Ejercicio** ejerciciosBiceps;
    Ejercicio** ejerciciosPiernas;
    Ejercicio** ejerciciosEspalda;

    // Este arreglo parece referirse a todos los ejercicios, pero no está definido en tu .cpp
    // Lo declaro aquí por coherencia con mostrarEjercicios()
    Ejercicio** ejercicios;
    int numEjercicios;

public:
    // Constructor y destructor
    Rutina();
    ~Rutina();

    // Métodos
    void agregarEjercicioZona(std::string zona, Ejercicio* e);
    void mostrarEjercicios();
};

#endif // RUTINA_H