#include "Ejercicio.h"
#include <cstring> // c style string 

// Constructor por defecto
Ejercicio::Ejercicio() {
    id = new int(0);
    nombre = new string("Sin nombre");
    zonaMuscular = new string("General");
    descripcion = new string("Sin descripcion");
}

// Constructor con parámetros
Ejercicio::Ejercicio(int* _id, string* _nombre, string* _zonaMuscular, string* _descripcion) {
    id = new int(*_id);
    nombre = new string(*_nombre);
    zonaMuscular = new string(*_zonaMuscular);
    descripcion = new string(*_descripcion);
}

// Destructor
Ejercicio::~Ejercicio() {
    delete id;
    delete nombre;
    delete zonaMuscular;
    delete descripcion;
}

// Setters
void Ejercicio::setId(int* _id) { *id = *_id; }
void Ejercicio::setNombre(string* _nombre) { *nombre = *_nombre; }
void Ejercicio::setZonaMuscular(string* _zona) { *zonaMuscular = *_zona; }
void Ejercicio::setDescripcion(string* _desc) { *descripcion = *_desc; }

// Getters
int* Ejercicio::getId() { return id; }
string* Ejercicio::getNombre() { return nombre; }
string* Ejercicio::getZonaMuscular() { return zonaMuscular; }
string* Ejercicio::getDescripcion() { return descripcion; }