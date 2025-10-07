#include "ClaseGrupal.h"
#include "Cliente.h"
#include "Instructor.h"

// =======================
// CONSTRUCTORES Y DESTRUCTOR
// =======================

// Constructor por defecto: inicializa todo con valores "vac�os"
ClaseGrupal::ClaseGrupal() {
    codigo = new int(0);              // c�digo de la clase (ej: 101)
    tipo = new string("N/A");         // tipo de clase (CrossFit, Yoga, etc.)
    capacidad = new int(0);           // cupo m�ximo de clientes
    salon = new string("N/A");        // sal�n donde se imparte
    horario = new string("N/A");      // horario de la clase
    instructor = nullptr;             // a�n no hay instructor asignado
    matriculados = new Cliente * [15];
    for (int i = 0; i < 15; i++) {
        matriculados[i] = nullptr;
    }
    // a�n no hay arreglo de clientes
}

// Constructor con par�metros: crea la clase con datos reales
ClaseGrupal::ClaseGrupal(int* codigo, string* tipo, int* capacidad, string* salon, string* horario, Instructor* instructor) {
    // Se copian los valores recibidos en memoria din�mica
    this->codigo = new int(*codigo);
    this->tipo = new string(*tipo);
    this->capacidad = new int(*capacidad);
    this->salon = new string(*salon);
    this->horario = new string(*horario);
    this->instructor = instructor;

    // Se crea un arreglo din�mico de punteros a Cliente con tama�o = capacidad
    matriculados = new Cliente * [*capacidad];
    for (int i = 0; i < *capacidad; i++) {
        matriculados[i] = nullptr; // todos los espacios empiezan vac�os
    }
}

// Destructor: libera toda la memoria reservada din�micamente
ClaseGrupal::~ClaseGrupal() {
    delete codigo;
    delete tipo;
    delete capacidad;
    delete salon;
    delete horario;
    delete[] matriculados; // se libera el arreglo de clientes
}

// =======================
// SETTERS
// =======================

void ClaseGrupal::setCodigo(int* c) { *codigo = *c; }
void ClaseGrupal::setTipo(string* t) { *tipo = *t; }
void ClaseGrupal::setCapacidad(int* cap) { *capacidad = *cap; }
void ClaseGrupal::setSalon(string* s) { *salon = *s; }
void ClaseGrupal::setHorario(string* h) { *horario = *h; }
void ClaseGrupal::setInstructor(Instructor* inst) { instructor = inst; }

// Agrega un cliente en el primer espacio vac�o del arreglo
void ClaseGrupal::setMatriculado(Cliente* cli) {
    for (int i = 0; i < *capacidad; i++) {
        if (matriculados[i] == nullptr) {
            matriculados[i] = cli;
            break;
        }
    }
}

// =======================
// GETTERS
// =======================

int* ClaseGrupal::getCodigo() { return codigo; }
string* ClaseGrupal::getTipo() { return tipo; }
int* ClaseGrupal::getCapacidad() { return capacidad; }
string* ClaseGrupal::getSalon() { return salon; }
string* ClaseGrupal::getHorario() { return horario; }
Instructor* ClaseGrupal::getInstructor() { return instructor; }
Cliente** ClaseGrupal::getMatriculados() { return matriculados; }

// =======================
// FUNCIONES ACCIONALES
// =======================

// Matricular un cliente en la clase si hay cupo disponible
bool ClaseGrupal::matricular(Cliente* cli) {
    for (int i = 0; i < *capacidad; i++) {
        if (matriculados[i] == nullptr) { // encontr� un espacio libre
            matriculados[i] = cli;
            return true; // matr�cula exitosa
        }
    }
    return false; // no hab�a cupos
}

// Calcular cu�ntos cupos quedan disponibles
int ClaseGrupal::cuposDisponibles() {
    int ocupados = 0;
    for (int i = 0; i < *capacidad; i++) {
        if (matriculados[i] != nullptr) {
            ocupados++;
        }
    }
    return *capacidad - ocupados;
}