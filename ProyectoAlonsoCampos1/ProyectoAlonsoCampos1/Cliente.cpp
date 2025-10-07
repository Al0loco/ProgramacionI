#include "Cliente.h"
#include "Instructor.h"
#include "Medicion.h"
#include "ClaseGrupal.h"
#include "Rutina.h"
#include <iostream>
using namespace std;

// Constructor por defecto
Cliente::Cliente() {
    cedula = new string("0000000000");
    nombre = new string("Sin nombre");
    telefono = new string("0000000000");
    correo = new string("sin correo");
    fechaNacimiento = new string("01/01/2000");
    sexo = new char('U'); // U = desconocido
    fechaInscripcion = new string("01/01/2000");
    instructor = nullptr;
    rutinaActual = nullptr;

    // reservar memoria para máximo 10 mediciones
    mediciones = new Medicion*[10];
    for (int i = 0; i < 10; i++) {
        mediciones[i] = nullptr;
    }

    // reservar memoria para máximo 3 clases grupales
    clasesMatriculadas = new ClaseGrupal*[3];
    for (int i = 0; i < 3; i++) {
        clasesMatriculadas[i] = nullptr;
    }
}

// Constructor con parámetros
Cliente::Cliente(string* _cedula, string* _nombre, string* _telefono, string* _correo,
                 string* _fechaNacimiento, char* _sexo, string* _fechaInscripcion) {
    cedula = new string(*_cedula);
    nombre = new string(*_nombre);
    telefono = new string(*_telefono);
    correo = new string(*_correo);
    fechaNacimiento = new string(*_fechaNacimiento);
    sexo = new char(*_sexo);
    fechaInscripcion = new string(*_fechaInscripcion);
    instructor = nullptr;
    rutinaActual = nullptr;

    mediciones = new Medicion*[10];
    for (int i = 0; i < 10; i++) {
        mediciones[i] = nullptr;
    }

    clasesMatriculadas = new ClaseGrupal*[3];
    for (int i = 0; i < 3; i++) {
        clasesMatriculadas[i] = nullptr;
    }
}

// Destructor
Cliente::~Cliente() {
    delete cedula;
    delete nombre;
    delete telefono;
    delete correo;
    delete fechaNacimiento;
    delete sexo;
    delete fechaInscripcion;

    // liberar mediciones (pero no las instancias, para evitar doble delete)
    delete[] mediciones;

    // liberar clases (pero no las instancias, para evitar doble delete)
    delete[] clasesMatriculadas;

    // liberar rutina si fue creada
    delete rutinaActual;
}

// Setters
void Cliente::setCedula(string* _cedula) { *cedula = *_cedula; }
void Cliente::setNombre(string* _nombre) { *nombre = *_nombre; }
void Cliente::setTelefono(string* _telefono) { *telefono = *_telefono; }
void Cliente::setCorreo(string* _correo) { *correo = *_correo; }
void Cliente::setFechaNacimiento(string* _fecha) { *fechaNacimiento = *_fecha; }
void Cliente::setSexo(char* _sexo) { *sexo = *_sexo; }
void Cliente::setFechaInscripcion(string* _fecha) { *fechaInscripcion = *_fecha; }
void Cliente::setInstructor(Instructor* _instructor) { instructor = _instructor; }
void Cliente::setRutina(Rutina* _rutina) { rutinaActual = _rutina; }

// Getters
string* Cliente::getCedula() { return cedula; }
string* Cliente::getNombre() { return nombre; }
string* Cliente::getTelefono() { return telefono; }
string* Cliente::getCorreo() { return correo; }
string* Cliente::getFechaNacimiento() { return fechaNacimiento; }
char* Cliente::getSexo() { return sexo; }
string* Cliente::getFechaInscripcion() { return fechaInscripcion; }
Instructor* Cliente::getInstructor() { return instructor; }
Rutina* Cliente::getRutina() { return rutinaActual; }

// Funciones adicionales

// Agregar una medición (máx. 10)
bool Cliente::addMedicion(Medicion* m) {
    // se recorre cada posición del arreglo de mediciones
    int i = 0;
    while (i < 10) {
        // se verifica si la posición está vacía
        if (mediciones[i] == nullptr) {
            // se coloca la nueva medición en esa posición
            mediciones[i] = m;
            // se devuelve true porque se agregó con éxito
            return true;
        }
        // se pasa a la siguiente posición
        i++;
    }

    // si se termina el recorrido, significa que no había espacio
    cout << "No se pueden agregar más mediciones (máx. 10)." << endl;
    return false;
}


// Obtener historial de mediciones
Medicion** Cliente::getHistorial() {
    return mediciones;
}

// Asignar instructor
void Cliente::asignarInstructor(Instructor* i) {
    instructor = i;
}

// Asignar rutina
void Cliente::asignarRutina(Rutina* r) {
    rutinaActual = r;
}

// Ver rutina actual
Rutina* Cliente::verRutina() {
    return rutinaActual;
}

// Matricular en una clase grupal (máx. 3)
bool Cliente::matricularClase(ClaseGrupal* c) {
    // se empieza desde la primera posición del arreglo
    int i = 0;

    // se recorre el arreglo mientras no se llegue al final
    while (i < 3) {
        // se revisa si la posición está vacía
        if (clasesMatriculadas[i] == nullptr) {
            // se coloca la nueva clase en esa posición
            clasesMatriculadas[i] = c;
            // se devuelve true porque se agregó con éxito
            return true;
        }
        // se pasa a la siguiente posición
        i++;
    }
    // si se termina el recorrido, significa que ya hay 3 clases ocupadas
    cout << "No se pueden matricular más clases (máx. 3)." << endl;
    return false;
}

void Cliente::generarReporteMedicion(int indiceMedicion, bool haceEjercicio) {
    // validar índice
    if (indiceMedicion < 0 || indiceMedicion >= 10 || mediciones[indiceMedicion] == nullptr) {
        cout << "Medición no encontrada en el índice indicado." << endl;
        return;
    }

    Medicion* m = mediciones[indiceMedicion];

    cout << "===== REPORTE DE MEDICION =====" << endl;
    cout << "Cliente: " << *nombre << " | Cedula: " << *cedula << endl;
    cout << "Sexo: " << *sexo << " | Fecha Nacimiento: " << *fechaNacimiento << endl;
    cout << "Instructor: " << (instructor ? *instructor->getNombre() : "No asignado") << endl;
    cout << "Fecha de medicion: " << *m->getFecha() << endl;

    // mostrar valores sin formateo especial
    cout << "Peso: " << *m->getPeso() << " kg" << endl;
    cout << "Estatura: " << *m->getEstatura() << " m" << endl;

    float imc = m->calcularIMC();
    cout << "IMC: " << imc << " (" << m->clasificacionIMC() << ")" << endl;

    // calcular vasos de agua
    int vasosAgua = static_cast<int>(*m->getPeso() / 7);
    cout << "Recomendacion de agua: " << vasosAgua << " vasos de 250ml por dia" << endl;

    // calcular proteínas
    float proteinas = 0.0f;
    if (*sexo == 'M') { // hombre
        if (haceEjercicio) {
            proteinas = *m->getPeso() * 2.0f; // promedio entre 1.7 y 2.5
        } else {
            proteinas = *m->getPeso() * 0.8f;
        }
    } else if (*sexo == 'F') { // mujer
        if (haceEjercicio) {
            proteinas = *m->getPeso() * 1.7f; // promedio entre 1.6 y 1.8
        } else {
            proteinas = *m->getPeso() * 0.8f;
        }
    }
    cout << "Recomendacion de proteinas: " << proteinas << " gramos por dia" << endl;

    cout << "===============================" << endl;
}

// Mostrar historial de mediciones ordenado por fecha (sin STL)
void Cliente::mostrarHistorialMediciones() {
    // contar cuántas mediciones existen
    int cantidad = 0;
    for (int i = 0; i < 10; i++) {
        if (mediciones[i] != nullptr) {
            cantidad++;
        }
    }

    // si no hay mediciones, se informa
    if (cantidad == 0) {
        cout << "El cliente " << *nombre << " no tiene mediciones registradas." << endl;
        return;
    }

    // crear un arreglo auxiliar dinámico para copiar las mediciones existentes
    Medicion** lista = new Medicion*[cantidad];
    int aux = 0;
    for (int i = 0; i < 10; i++) {
        if (mediciones[i] != nullptr) {
            lista[aux] = mediciones[i];
            aux++;
        }
    }

    // ordenar con burbuja por fecha (comparando strings dd/mm/aaaa)
    for (int i = 0; i < cantidad - 1; i++) {
        for (int j = 0; j < cantidad - i - 1; j++) {
            if (*lista[j]->getFecha() > *lista[j+1]->getFecha()) {
                // intercambiar posiciones
                Medicion* temp = lista[j];
                lista[j] = lista[j+1];
                lista[j+1] = temp;
            }
        }
    }

    // mostrar las mediciones ordenadas
    cout << "===== HISTORIAL DE MEDICIONES DE " << *nombre << " =====" << endl;
    for (int i = 0; i < cantidad; i++) {
        Medicion* m = lista[i];
        cout << (i+1) << ". Fecha: " << *m->getFecha()
             << " | Peso: " << *m->getPeso()
             << " | Estatura: " << *m->getEstatura()
             << " | IMC: " << m->calcularIMC()
             << " (" << m->clasificacionIMC() << ")" << endl;
    }
    cout << "==============================================" << endl;

    // liberar el arreglo auxiliar (no las mediciones, porque no son propiedad de este método)
    delete[] lista;
}

// Mostrar la rutina actual del cliente
void Cliente::mostrarRutina() {
    cout << "===== RUTINA DEL CLIENTE " << *nombre << " =====" << endl;

    if (rutina == nullptr) {
        cout << "El cliente no tiene una rutina asignada actualmente." << endl;
    } else {
        rutina->mostrarEjercicios();
    }

    cout << "==============================================" << endl;
}

// Mostrar las clases grupales en las que está matriculado el cliente
void Cliente::listarClases() {
    cout << "===== CLASES DE " << *nombre << " =====" << endl;

    if (numClases == 0) { // si no está matriculado en ninguna clase
        cout << "El cliente no esta matriculado en ninguna clase grupal." << endl;
    } else {
        for (int i = 0; i < numClases; i++) { // se recorren las clases
            cout << (i+1) << ". Codigo: " << *clases[i]->getCodigo() // se muestra la información básica
                 << " | Tipo: " << *clases[i]->getTipo()
                 << " | Horario: " << *clases[i]->getHorario()
                 << " | Instructor: " << *clases[i]->getInstructor()->getNombre()
                 << endl;
        }
    }

    cout << "==============================================" << endl;
}




