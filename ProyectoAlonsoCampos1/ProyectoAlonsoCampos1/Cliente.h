
#include <string>
#include "Instructor.h"
#include "Medicion.h"
#include "ClaseGrupal.h"
#include "Rutina.h"

class Cliente {
private:
    // Datos personales
    std::string* cedula;
    std::string* nombre;
    std::string* telefono;
    std::string* correo;
    std::string* fechaNacimiento;
    char* sexo;
    std::string* fechaInscripcion;

    // Relaciones con otras clases
    Instructor* instructor;
    Rutina* rutinaActual;

    // Arreglos de asociaciones
    Medicion** mediciones;           // máx. 10 mediciones
    ClaseGrupal** clasesMatriculadas; // máx. 3 clases
    int numClases = 0;               // cantidad actual de clases

public:
    // Constructores y destructor
    Cliente();
    Cliente(std::string* _cedula, std::string* _nombre, std::string* _telefono,
        std::string* _correo, std::string* _fechaNacimiento,
        char* _sexo, std::string* _fechaInscripcion);
    ~Cliente();

    // Setters
    void setCedula(std::string* _cedula);
    void setNombre(std::string* _nombre);
    void setTelefono(std::string* _telefono);
    void setCorreo(std::string* _correo);
    void setFechaNacimiento(std::string* _fecha);
    void setSexo(char* _sexo);
    void setFechaInscripcion(std::string* _fecha);
    void setInstructor(Instructor* _instructor);
    void setRutina(Rutina* _rutina);

    // Getters
    std::string* getCedula();
    std::string* getNombre();
    std::string* getTelefono();
    std::string* getCorreo();
    std::string* getFechaNacimiento();
    char* getSexo();
    std::string* getFechaInscripcion();
    Instructor* getInstructor();
    Rutina* getRutina();

    // Funciones adicionales
    bool addMedicion(Medicion* m);
    Medicion** getHistorial();

    void asignarInstructor(Instructor* i);
    void asignarRutina(Rutina* r);
    Rutina* verRutina();

    bool matricularClase(ClaseGrupal* c);

    void generarReporteMedicion(int indiceMedicion, bool haceEjercicio);
    void mostrarHistorialMediciones();
    void mostrarRutina();
    void listarClases();
};
