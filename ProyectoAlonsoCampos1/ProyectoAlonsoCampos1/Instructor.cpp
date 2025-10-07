#include "Instructor.h"
#include "Cliente.h"
#include "Medicion.h"
#include "Rutina.h"

// Definimos un máximo de especialidades por simplicidad
const int MAX_ESPECIALIDADES = 10;

// Constructor por defecto	
Instructor::Instructor() {
	cedula = new string("0000000000");
	nombre = new string("Sin nombre");	
	telefono = new string("0000000000");	
	correo = new string("sin correo");	
	fechaNacimiento = new string("01/01/2000");	

// Inicializar arreglo de especialidades
	especialidades = new string*[MAX_ESPECIALIDADES];
	for (int i = 0; i < MAX_ESPECIALIDADES; i++) {
		especialidades[i] = nullptr;
	}
	numEspecialidades = 0; // Inicializar contador de especialidades
 // lo que hace este metodo es reservar memoria para los atributos de tipo string y para el arreglo de especialidades
}

// Constructor con parámetros
Instructor::Instructor(string* cedula, string* nombre, string* telefono, string* correo, string* fechaNacimiento) {
	this->cedula = cedula;
	this->nombre = nombre;
	this->telefono = telefono;
	this->correo = correo;
	this->fechaNacimiento = fechaNacimiento;

	especialidades = new string*[MAX_ESPECIALIDADES];
    for (int i = 0; i < MAX_ESPECIALIDADES; i++) {
        especialidades[i] = nullptr;
    }
    numEspecialidades = 0;
}

Instructor::~Instructor() {
	delete cedula;
	delete nombre;
	delete telefono;
	delete correo;
	delete fechaNacimiento;

	// Liberar memoria de especialidades 
	for (int i = 0; i < numEspecialidades; i++) {
		delete especialidades[i];
	}
	delete[] especialidades; // Liberar el arreglo din�mico
}

// Métodos get y set
	
void Instructor::setCedula(string* _cedula) {
    *cedula = *_cedula;
}
void Instructor::setNombre(string*) {
	*nombre = *nombre;
}
void Instructor::setTelefono(string*) {
	*telefono = *telefono;
}
void Instructor::setCorreo(string*) {
		*correo = *correo;
}
void Instructor::setFechaNacimiento(string*) {
	*fechaNacimiento = *fechaNacimiento;
}
string* Instructor::getCedula() {
	return cedula;
}


string* Instructor::getNombre() {
		return nombre;
}
string* Instructor::getTelefono() {
	return telefono;
}
string* Instructor::getCorreo() {
		return correo;
}
string* Instructor::getFechaNacimiento() {
		return fechaNacimiento;
}

// Otros métodos
void Instructor::addEspecialidad(string* esp) {
	if (numEspecialidades < MAX_ESPECIALIDADES) {
		especialidades[numEspecialidades] = new string(*esp); // Asignar nueva especialidad
		numEspecialidades++;
	} else {
		cout << "No se pueden agregar más especialidades. Límite alcanzado." << endl;
	}
}

// Generar medición para un cliente
bool Instructor::generarMedicion(Cliente* c, Medicion* m) {
	if (c == nullptr || m == nullptr)
		return false; // Validar punteros nulos
		return c ->addMedicion(m); // Agregar la medición al cliente
	}


Rutina* Instructor::generarRutina(Cliente* c) {
	if (c == nullptr) return nullptr; // validar ptr nulo 
	// crear rutina básica y asignarla 
	Rutina* rutina = new Rutina();
	c->setRutina(rutina);
	return rutina;
}

bool Instructor::tieneEspecialidad(string* esp) {
    for (int i = 0; i < numEspecialidades; i++) {
        if (*especialidades[i] == *esp) {
            // se devuelve true si se encuentra coincidencia
            return true;
        }
    }
    // se devuelve false si no se encuentra la especialidad
    return false;
}

// Generar una rutina para un cliente a partir de la batería de ejercicios de la sucursal
void Instructor::generarRutina(Cliente* cliente, Sucursal* sucursal) {
    if (cliente == nullptr || sucursal == nullptr) {
        cout << "Error: cliente o sucursal no validos." << endl;
        return;
    }

    // Crear una nueva rutina vacía
    Rutina* nuevaRutina = new Rutina();

    cout << "Generando rutina para el cliente: " << *cliente->getNombre() << endl;
    cout << "Seleccione ejercicios de la bateria de la sucursal." << endl;

    // Mostrar batería de ejercicios disponible
    sucursal->listarEjercicios();

    // Pedir al usuario que seleccione ejercicios
    int opcion;
    do {
        cout << "Ingrese el numero del ejercicio que desea agregar (0 para terminar): ";
        cin >> opcion; // leer opción del usuario

        if (opcion > 0 && opcion <= sucursal->getNumEjercicios()) { // validar opción
            Ejercicio* elegido = sucursal->getEjercicio(opcion - 1); // obtener ejercicio (asumiendo que hay un método getEjercicio)
            nuevaRutina->agregarEjercicioZona(elegido); // agregar ejercicio a la rutina
            cout << "Ejercicio agregado: " << *elegido->getNombre() << endl; // asumiendo que Ejercicio tiene getNombre()
        } else if (opcion != 0) {
            cout << "Opcion invalida." << endl;
        }
    } while (opcion != 0); // repetir hasta que el usuario ingrese 0

    // Asignar la rutina al cliente (reemplaza la anterior)
    cliente->setRutina(nuevaRutina);

    cout << "Rutina generada exitosamente para " << *cliente->getNombre() << endl;
}


