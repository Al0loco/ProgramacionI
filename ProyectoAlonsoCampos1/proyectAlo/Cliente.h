#pragma once
#include <iostream>
using namespace std;
// Forward declarations para evitar inclusiones circulares
class Instructor;
class Medicion;
class ClaseGrupal;
class Rutina;

class Cliente {
private:
    string* cedula;
    string* nombre;
    string* telefono;
    string* correo;
    string* fechaNacimiento;
    char* sexo;
    string* fechaInscripcion;
    Instructor* instructor;
    Medicion** mediciones;        // máx 10
    ClaseGrupal** clasesMatriculadas; // máx 3
    Rutina* rutinaActual;
public:
// Constructores y destructores
    Cliente();
    Cliente(string*, string*, string*, string*, string*, char*, string*);
    ~Cliente();
// Funciones set
    void setCedula(string*);
    void setNombre(string*);
    void setTelefono(string*);
    void setCorreo(string*);
    void setFechaNacimiento(string*);
    void setSexo(char*);
    void setFechaInscripcion(string*);
    void setInstructor(Instructor*);
    void setRutina(Rutina*);
// Funciones get
    string* getCedula();
    string* getNombre();
    string* getTelefono();
    string* getCorreo();
    string* getFechaNacimiento();
    char* getSexo();
    string* getFechaInscripcion();
    Instructor* getInstructor();
    Rutina* getRutina();
// Funciones accionales
    bool addMedicion(Medicion*);
    Medicion** getHistorial();
    void asignarInstructor(Instructor*);
    void asignarRutina(Rutina*);
    Rutina* verRutina();
};
