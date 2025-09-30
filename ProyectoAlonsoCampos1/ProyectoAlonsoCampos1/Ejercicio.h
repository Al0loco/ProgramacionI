#pragma once
#include <iostream>
using namespace std;

class Ejercicio {
private:
    int* id;
    string* nombre;
    string* zonaMuscular;
    string* descripcion;
public:
// Constructores y destructores
    Ejercicio();
    Ejercicio(int*, string*, string*, string*);
    ~Ejercicio();
// Funciones set
    void setId(int*);
    void setNombre(string*);
    void setZonaMuscular(string*);
    void setDescripcion(string*);
// Funciones get
    int* getId();
    string* getNombre();
    string* getZonaMuscular();
    string* getDescripcion();
};
