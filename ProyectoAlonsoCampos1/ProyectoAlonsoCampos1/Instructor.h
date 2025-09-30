#pragma once
#include <iostream>
using namespace std;

class Cliente;
class Medicion;
class Rutina;

class Instructor {
private:
    string* cedula;
    string* nombre;
    string* telefono;
    string* correo;
    string* fechaNacimiento;
    string** especialidades; // arreglo dinámico
    // especialidades son arreglo dinámico porque un instructor puede tener múltiples especialidades y no se sabe cuántas tendrá en tiempo de compilación.
public:
// Constructores y destructores
    Instructor();
    Instructor(string*, string*, string*, string*, string*);
    ~Instructor();
// Funciones set
    void setCedula(string*);
    void setNombre(string*);
    void setTelefono(string*);
    void setCorreo(string*);
    void setFechaNacimiento(string*);
// Funciones get
    string* getCedula();
    string* getNombre();
    string* getTelefono();
    string* getCorreo();
    string* getFechaNacimiento();
//  Funciones accionales
    void addEspecialidad(string*);
    bool generarMedicion(Cliente*, Medicion*);
    Rutina* generarRutina(Cliente*);
};
