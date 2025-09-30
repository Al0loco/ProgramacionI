#pragma once
#include <iostream>
using namespace std;

class Cliente;
class Instructor;

class ClaseGrupal {
private:
    int* codigo;
    string* tipo;
    int* capacidad;
    string* salon;
    string* horario;
    Instructor* instructor;
    Cliente** matriculados; // arreglo dinámico
public:
// Constructores y destructores
    ClaseGrupal();
    ClaseGrupal(int*, string*, int*, string*, string*, Instructor*);
    ~ClaseGrupal();
// Funciones set
    void setCodigo(int*);
    void setTipo(string*);
    void setCapacidad(int*);
    void setSalon(string*);
    void setHorario(string*);
    void setInstructor(Instructor*);
    void setMatriculado(Cliente*);
// Funciones get
    int* getCodigo();
    string* getTipo();
    int* getCapacidad();
    string* getSalon();
    string* getHorario();
    Instructor* getInstructor();
    Cliente** getMatriculados();
// Funciones accionales
    bool matricular(Cliente*);
    int cuposDisponibles();
};
