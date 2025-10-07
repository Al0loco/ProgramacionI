#include "Rutina.h"
#include "Ejercicio.h"
#include <iostream>
using namespace std;

// Se define max de ejercicios por zona 
const int MAX_EJERCICIOS = 3;

// Constructor por defecto
Rutina::Rutina() {
    // Se inicializan los arreglos de ejercicios
    ejerciciosPecho   = new Ejercicio*[MAX_EJERCICIOS];
    ejerciciosBiceps  = new Ejercicio*[MAX_EJERCICIOS];
    ejerciciosPiernas = new Ejercicio*[MAX_EJERCICIOS];
    ejerciciosEspalda = new Ejercicio*[MAX_EJERCICIOS];

    // Se inicializan todos en nullptr para indicar que están vacíos
    for (int i = 0; i < MAX_EJERCICIOS; i++) {
        ejerciciosPecho[i]   = nullptr;
        ejerciciosBiceps[i]  = nullptr;
        ejerciciosPiernas[i] = nullptr;
        ejerciciosEspalda[i] = nullptr;
    }
}

// Destructor
Rutina::~Rutina() {
    // Se libera memoria de cada arreglo de ejercicios
    for (int i = 0; i < MAX_EJERCICIOS; i++) {
        delete ejerciciosPecho[i];
        delete ejerciciosBiceps[i];
        delete ejerciciosPiernas[i];
        delete ejerciciosEspalda[i];
    }
    delete[] ejerciciosPecho;
    delete[] ejerciciosBiceps;
    delete[] ejerciciosPiernas;
    delete[] ejerciciosEspalda;
}

// Función para agregar un ejercicio a la zona indicada
void Rutina::agregarEjercicioZona(string zona, Ejercicio* e) {
    Ejercicio** lugar = nullptr;

    if (zona == "pecho") {
        lugar = ejerciciosPecho;
    } else if (zona == "bíceps") {
        lugar = ejerciciosBiceps;
    } else if (zona == "piernas") {
        lugar = ejerciciosPiernas;
    } else if (zona == "espalda") {
        lugar = ejerciciosEspalda;
    } else {
        cout << "Zona no válida: " << zona << endl;
        return; // zona inválida cuando no sea ninguna de las anteriores 
    }

    // Buscar el primer espacio libre en el arreglo
    for (int i = 0; i < MAX_EJERCICIOS; i++) {
        if (lugar[i] == nullptr) {
            lugar[i] = e; // se asigna el ejercicio al primer espacio que este libre
            cout << "Ejercicio agregado a " << zona << endl;
            return;
        }
    }

    cout << "No se pueden agregar más ejercicios para la zona: " << zona << endl;
}

// Mostrar todos los ejercicios de la rutina
void Rutina::mostrarEjercicios() {
    if (numEjercicios == 0) {
        cout << "La rutina no tiene ejercicios." << endl;
        return;
    }

    for (int i = 0; i < numEjercicios; i++) {
        cout << (i+1) << ". " << *ejercicios[i]->getNombre()
             << " | Zona: " << *ejercicios[i]->getZona()
             << " | Descripcion: " << *ejercicios[i]->getDescripcion()
             << endl;
    }
}
