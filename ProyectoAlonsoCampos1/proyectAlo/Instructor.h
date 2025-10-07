#pragma once
#include <iostream>
using namespace std;

// Forward declarations para evitar inclusiones circulares
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

    string** especialidades;   // arreglo dinámico de especialidades
    int numEspecialidades;     // cuántas especialidades tiene
public:
    // Constructores y destructor
    Instructor();
    Instructor(string*, string*, string*, string*, string*);
    ~Instructor();

    // Setters
    void setCedula(string*);
    void setNombre(string*);
    void setTelefono(string*);
    void setCorreo(string*);
    void setFechaNacimiento(string*);

    // Getters
    string* getCedula();
    string* getNombre();
    string* getTelefono();
    string* getCorreo();
    string* getFechaNacimiento();

    // Funciones adicionales
    void addEspecialidad(string*);          // agrega una especialidad
    bool generarMedicion(Cliente*, Medicion*); // crea una medición para un cliente
    Rutina* generarRutina(Cliente*);        // genera una rutina para un cliente
    bool tieneEspecialidad(string* esp); // verifica si tiene una especialidad dada
    void generarRutina(Cliente* cliente, Sucursal* sucursal); // genera una rutina personalizada para un cliente basado en la batería de ejercicios de la sucursal


};
