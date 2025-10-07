#include "Sucursal.h"


// Se define tamaño máximo para los arreglos dinámicos de punteros
const int MAX_INSTRUCTORES = 12;   // Se establece límite en sucursal 
const int MAX_CLIENTES     = 150;  
const int MAX_CLASES       = 8;  

// Constructor por defecto
Sucursal::Sucursal() {
    // reservar memoria para el código de la sucursal
    // codigo de sucursal significa un identificador único
    codigo = new int(0);
    // reservar memoria para la provincia
    provincia = new string("Sin provincia");
    // reservar memoria para el cantón
    canton = new string("Sin canton");
    // reservar memoria para el correo
    correo = new string("sin-correo@ejemplo.com");
    // reservar memoria para el teléfono
    telefono = new string("00000000");

    // reservar memoria para el arreglo dinámico de instructores
    instructores = new Instructor*[MAX_INSTRUCTORES];
    // Se inicializa cada posición del arreglo de instructores en nullptr
    for (int i = 0; i < MAX_INSTRUCTORES; i++) instructores[i] = nullptr;

    // reservar memoria para el arreglo dinámico de clientes
    clientes = new Cliente*[MAX_CLIENTES];
    // Se inicializa cada posición del arreglo de clientes en nullptr
    for (int i = 0; i < MAX_CLIENTES; i++) clientes[i] = nullptr;

    // reservar memoria para el arreglo dinámico de clases
    clases = new ClaseGrupal*[MAX_CLASES];
    // Se nicializa cada posición del arreglo de clases en nullptr
    for (int i = 0; i < MAX_CLASES; i++) clases[i] = nullptr;
}

// Constructor con parámetros
Sucursal::Sucursal(int* _codigo, string* _provincia, string* _canton, string* _correo, string* _telefono) {
    // copiar el valor de código dentro de una nueva dirección de memoria
    codigo = new int(*_codigo);
    // copiar la provincia dentro de una nueva dirección de memoria
    provincia = new string(*_provincia);
    // copiar el cantón dentro de una nueva dirección de memoria
    canton = new string(*_canton);
    // copiar el correo dentro de una nueva dirección de memoria
    correo = new string(*_correo);
    // copiar el teléfono dentro de una nueva dirección de memoria
    telefono = new string(*_telefono);

    // reservar memoria para el arreglo dinámico de instructores
    instructores = new Instructor*[MAX_INSTRUCTORES];
    // inicializar cada posición del arreglo de instructores en nullptr
    for (int i = 0; i < MAX_INSTRUCTORES; i++) instructores[i] = nullptr;

    // reservar memoria para el arreglo dinámico de clientes
    clientes = new Cliente*[MAX_CLIENTES];
    // inicializar cada posición del arreglo de clientes en nullptr
    for (int i = 0; i < MAX_CLIENTES; i++) clientes[i] = nullptr;

    // reservar memoria para el arreglo dinámico de clases
    clases = new ClaseGrupal*[MAX_CLASES];
    // inicializar cada posición del arreglo de clases en nullptr
    for (int i = 0; i < MAX_CLASES; i++) clases[i] = nullptr;
}

// Destructor
Sucursal::~Sucursal() {
    delete codigo;
    delete provincia;
    delete canton;
    delete correo;
    delete telefono;

    // no liberar los objetos apuntados por instructores para evitar doble liberación (no asumir propiedad)
    // liberar únicamente el arreglo de punteros a instructores
    delete[] instructores;

    // no liberar los objetos apuntados por clientes para evitar doble liberación (no asumir propiedad)
    // liberar únicamente el arreglo de punteros a clientes
    delete[] clientes;

    // no liberar los objetos apuntados por clases para evitar doble liberación (no asumir propiedad)
    // liberar únicamente el arreglo de punteros a clases
    delete[] clases;
}

// Setter de código
void Sucursal::setCodigo(int* _codigo) {
    // asignar el valor recibido al contenido de la dirección de memoria de código
    *codigo = *_codigo;
}

// Setter de provincia
void Sucursal::setProvincia(string* _provincia) {
    // asignar el valor recibido al contenido de la dirección de memoria de provincia
    *provincia = *_provincia;
}

// Setter de cantón
void Sucursal::setCanton(string* _canton) {
    // asignar el valor recibido al contenido de la dirección de memoria de cantón
    *canton = *_canton;
}

// Setter de correo
void Sucursal::setCorreo(string* _correo) {
    // asignar el valor recibido al contenido de la dirección de memoria de correo
    *correo = *_correo;
}

// Setter de teléfono
void Sucursal::setTelefono(string* _telefono) {
    // asignar el valor recibido al contenido de la dirección de memoria de teléfono
    *telefono = *_telefono;
}

// Método para agregar un instructor al arreglo dinámico
void Sucursal::setInstructor(Instructor* inst) {
    // recorrer el arreglo para encontrar la primera posición libre
    for (int i = 0; i < MAX_INSTRUCTORES; i++) {
        // verificar si la posición actual está vacía
        if (instructores[i] == nullptr) {
            // colocar el puntero al instructor en la primera posición libre
            instructores[i] = inst;
            // finalizar la búsqueda al insertar correctamente
            return;
        }
    }
}

// Método para agregar un cliente al arreglo 
void Sucursal::setCliente(Cliente* cli) {
    // recorrer el arreglo para encontrar la primera posición libre
    for (int i = 0; i < MAX_CLIENTES; i++) {
        // verificar si la posición actual está vacía
        if (clientes[i] == nullptr) {
            // colocar el puntero al cliente en la primera posición libre
            clientes[i] = cli;
            // finalizar la búsqueda al insertar correctamente
            return;
        }
    }
    // No espacio disponible 
    printf("No se pueden agregar más clientes. Límite alcanzado.\n");
}

// Método para agregar una clase grupal al arreglo dinámico
void Sucursal::setClase(ClaseGrupal* cls) {
    // recorrer el arreglo para encontrar la primera posición libre
    for (int i = 0; i < MAX_CLASES; i++) {
        // verificar si la posición actual está vacía
        if (clases[i] == nullptr) {
            // colocar el puntero a la clase grupal en la primera posición libre
            clases[i] = cls;
            // finalizar la búsqueda al insertar correctamente
            return;
        }
    }
    printf("No se pueden agregar más clases. Límite alcanzado.\n");
}

// Getters
int* Sucursal::getCodigo() {
    // devolver el puntero al código almacenado
    return codigo;
}

string* Sucursal::getProvincia() {
    // devolver el puntero a la provincia almacenada
    return provincia;
}

string* Sucursal::getCanton() {
    // devolver el puntero al cantón almacenado
    return canton;
}

string* Sucursal::getCorreo() {
    // devolver el puntero al correo almacenado
    return correo;
}

string* Sucursal::getTelefono() {
    // devolver el puntero al teléfono almacenado
    return telefono;
}
s
Instructor** Sucursal::getInstructores() {
    // devolver el puntero al arreglo dinámico de instructores
    return instructores;
}

Cliente** Sucursal::getClientes() {
    // devolver el puntero al arreglo dinámico de clientes
    return clientes;
}

ClaseGrupal** Sucursal::getClases() {
    // devolver el puntero al arreglo dinámico de clases grupales
    return clases;
}

Cliente* Sucursal::getClientePorCedula(string cedula) {
    for (int i = 0; i < MAX_CLIENTES; i++) {
        if (clientes[i] != nullptr && *clientes[i]->getCedula() == cedula) {
            return clientes[i];
        }
    }
    return nullptr;
}

Instructor* Sucursal::getInstructorPorCedula(string cedula) {
    for (int i = 0; i < MAX_INSTRUCTORES; i++) { // recorrer el arreglo de instructores
        if (instructores[i] != nullptr && *instructores[i]->getCedula() == cedula) {
            return instructores[i];
        }
    }
    return nullptr;
}

ClaseGrupal* Sucursal::getClasePorCodigo(string codigoClase) {
    for (int i = 0; i < numClases; i++) { // recorrer el arreglo de clases para buscar por código
        if (*clasesGrupales[i]->getCodigo() == codigoClase) {
            return clasesGrupales[i];
        }
    }
    return nullptr;
}


// Reporte IMC por sucursal
void Sucursal::reporteIMC() {
    cout << "===== REPORTE IMC DE SUCURSAL " << *codigo << " =====" << endl;

    // contadores por categoría
    int delgSevera = 0, delgModerada = 0, delgLeve = 0;
    int normal = 0, preObesidad = 0, obesLeve = 0, obesMedia = 0, obesMorbida = 0;

    // recorrer todos los clientes de la sucursal
    for (int i = 0; i < MAX_CLIENTES; i++) {
        if (clientes[i] != nullptr) {
            // obtener la última medición del cliente
            Medicion** historial = clientes[i]->getHistorial();
            Medicion* ultima = nullptr;

            for (int j = 9; j >= 0; j--) { // buscar desde el final hacia atrás
                if (historial[j] != nullptr) {
                    ultima = historial[j];
                    break;
                }
            }

            if (ultima != nullptr) {
                string clasif = ultima->clasificacionIMC();

                // clasificar según el resultado
                if (clasif == "Delgadez severa") delgSevera++;
                else if (clasif == "Delgadez moderada") delgModerada++;
                else if (clasif == "Delgadez leve") delgLeve++;
                else if (clasif == "Normal") normal++;
                else if (clasif == "Pre-obesidad") preObesidad++;
                else if (clasif == "Obesidad leve") obesLeve++;
                else if (clasif == "Obesidad media") obesMedia++;
                else if (clasif == "Obesidad morbida") obesMorbida++;
            }
        }
    }

    // mostrar resultados
    cout << "Delgadez severa: " << delgSevera << endl;
    cout << "Delgadez moderada: " << delgModerada << endl;
    cout << "Delgadez leve: " << delgLeve << endl;
    cout << "Normal: " << normal << endl;
    cout << "Pre-obesidad: " << preObesidad << endl;
    cout << "Obesidad leve: " << obesLeve << endl;
    cout << "Obesidad media: " << obesMedia << endl;
    cout << "Obesidad morbida: " << obesMorbida << endl;

    cout << "==============================================" << endl;
}

// Listar todos los clientes de la sucursal
void Sucursal::listarClientes() {
    cout << "===== CLIENTES DE LA SUCURSAL " << *codigo << " =====" << endl;

    bool hayClientes = false; // flag para saber si se encuentra algún cliente

    // recorrer el arreglo de clientes
    for (int i = 0; i < MAX_CLIENTES; i++) {
        if (clientes[i] != nullptr) { // si la posición no está vacía
            // mostrar información del cliente
            hayClientes = true;
            cout << "- Cedula: " << *clientes[i]->getCedula()
                 << " | Nombre: " << *clientes[i]->getNombre()
                 << " | Telefono: " << *clientes[i]->getTelefono()
                 << " | Correo: " << *clientes[i]->getCorreo()
                 << " | Fecha Inscripcion: " << *clientes[i]->getFechaInscripcion()
                 << " | Instructor: "
                 << (clientes[i]->getInstructor() ? *clientes[i]->getInstructor()->getNombre() : "No asignado")
                 << endl;
        }
    }

    if (!hayClientes) { // si no se encontró ningún cliente
        cout << "No hay clientes registrados en esta sucursal." << endl;
    }

    cout << "==============================================" << endl;
}

// Mostrar detalle de un cliente específico por cédula
void Sucursal::detalleCliente(string cedulaBuscada) {
    cout << "===== DETALLE DE CLIENTE EN SUCURSAL " << *codigo << " =====" << endl;

    bool encontrado = false;

    for (int i = 0; i < MAX_CLIENTES; i++) { // recorrer el arreglo de clientes
        if (clientes[i] != nullptr && *clientes[i]->getCedula() == cedulaBuscada) {  // si se encuentra el cliente
            encontrado = true; // marcar como encontrado

            cout << "Cedula: " << *clientes[i]->getCedula() << endl;
            cout << "Nombre: " << *clientes[i]->getNombre() << endl;
            cout << "Telefono: " << *clientes[i]->getTelefono() << endl;
            cout << "Correo: " << *clientes[i]->getCorreo() << endl;
            cout << "Fecha de nacimiento: " << *clientes[i]->getFechaNacimiento() << endl;
            cout << "Sexo: " << *clientes[i]->getSexo() << endl;
            cout << "Fecha de inscripcion: " << *clientes[i]->getFechaInscripcion() << endl;
            cout << "Sucursal: " << *codigo << endl;
            cout << "Instructor asignado: "
                 << (clientes[i]->getInstructor() ? *clientes[i]->getInstructor()->getNombre() : "No asignado")
                 << endl; // operador ternario para verificar si hay instructor asignado

            break; // ya encontramos al cliente, no seguimos buscando
        }
    }

    if (!encontrado) {
        cout << "No se encontro un cliente con la cedula " << cedulaBuscada << " en esta sucursal." << endl;
    }

    cout << "==============================================" << endl;
}

// Listar todos los clientes de la sucursal que tienen asignado un instructor específico
void Sucursal::listarClientesPorInstructor(string cedulaInstructor) {
    cout << "===== CLIENTES DEL INSTRUCTOR " << cedulaInstructor // cedulaInstructor es el parámetro que recibe la función
         << " EN SUCURSAL " << *codigo << " =====" << endl; // *codigo es el atributo de la sucursal

    bool hayClientes = false; // flag para saber si se encuentra algún cliente

    // recorrer todos los clientes de la sucursal
    for (int i = 0; i < MAX_CLIENTES; i++) {
        if (clientes[i] != nullptr && clientes[i]->getInstructor() != nullptr) { // si la posición no está vacía y tiene instructor asignado
            // verificar si el instructor asignado al cliente coincide con el buscado
            if (*clientes[i]->getInstructor()->getCedula() == cedulaInstructor) {
                hayClientes = true;
                cout << "- Cedula: " << *clientes[i]->getCedula()
                     << " | Nombre: " << *clientes[i]->getNombre()
                     << " | Telefono: " << *clientes[i]->getTelefono()
                     << " | Correo: " << *clientes[i]->getCorreo()
                     << " | Fecha Inscripcion: " << *clientes[i]->getFechaInscripcion()
                     << endl;
            }
        }
    }

    if (!hayClientes) {
        cout << "No hay clientes asignados a este instructor en esta sucursal." << endl;
    }

    cout << "==============================================" << endl;
}

// Listar todos los instructores de la sucursal
void Sucursal::listarInstructores() {
    cout << "===== INSTRUCTORES DE LA SUCURSAL " << *codigo << " =====" << endl;

    bool hayInstructores = false;

    // recorrer el arreglo dinámico de instructores
    for (int i = 0; i < MAX_INSTRUCTORES; i++) {
        if (instructores[i] != nullptr) {
            hayInstructores = true;

            cout << "- Cedula: " << *instructores[i]->getCedula()
                 << " | Nombre: " << *instructores[i]->getNombre()
                 << " | Telefono: " << *instructores[i]->getTelefono()
                 << " | Correo: " << *instructores[i]->getCorreo()
                 << " | Fecha Nacimiento: " << *instructores[i]->getFechaNacimiento()
                 << endl;

            // mostrar especialidades del instructor
            cout << "  Especialidades: ";
            bool tieneEspecialidad = false;
            for (int j = 0; j < instructores[i]->getNumEspecialidades(); j++) { // getNumEspecialidades() es un método que retorna el número de especialidades
                cout << *instructores[i]->getEspecialidad(j); // getEspecialidad(j) es un método que retorna la especialidad en la posición j
                if (j < instructores[i]->getNumEspecialidades() - 1) cout << ", "; // si no es la última, poner coma
                tieneEspecialidad = true;
            }
            if (!tieneEspecialidad) cout << "Ninguna";
            cout << endl;
        }
    }

    if (!hayInstructores) {
        cout << "No hay instructores registrados en esta sucursal." << endl;
    }

    cout << "==============================================" << endl;
}

// Listar instructores de la sucursal por especialidad
void Sucursal::listarInstructoresPorEspecialidad(string especialidadBuscada) {
    cout << "===== INSTRUCTORES CON ESPECIALIDAD " << especialidadBuscada
         << " EN SUCURSAL " << *codigo << " =====" << endl;

    bool hayInstructores = false;

    for (int i = 0; i < MAX_INSTRUCTORES; i++) {
        if (instructores[i] != nullptr) {
            // revisar todas las especialidades del instructor
            for (int j = 0; j < instructores[i]->getNumEspecialidades(); j++) {
                if (*instructores[i]->getEspecialidad(j) == especialidadBuscada) {
                    hayInstructores = true;
                    cout << "- Cedula: " << *instructores[i]->getCedula()
                         << " | Nombre: " << *instructores[i]->getNombre()
                         << " | Telefono: " << *instructores[i]->getTelefono()
                         << " | Correo: " << *instructores[i]->getCorreo()
                         << endl;
                    break; // ya se encontró la especialidad, no seguir revisando
                }
            }
        }
    }

    if (!hayInstructores) {
        cout << "No hay instructores con la especialidad " << especialidadBuscada
             << " en esta sucursal." << endl;
    }

    cout << "==============================================" << endl;
}

// Inicializar la batería de ejercicios con capacidad máxima
void Sucursal::inicializarBateria(int capacidadMax) {
    maxEjercicios = capacidadMax;
    numEjercicios = 0;
    bateriaEjercicios = new Ejercicio*[maxEjercicios];
    for (int i = 0; i < maxEjercicios; i++) {
        bateriaEjercicios[i] = nullptr;
    }
}

// Agregar un ejercicio a la batería
bool Sucursal::agregarEjercicio(Ejercicio* e) {
    if (numEjercicios < maxEjercicios) {
        bateriaEjercicios[numEjercicios] = e; // se agrega el ejercicio en la siguiente posición libre
        numEjercicios++; // se incrementa el contador de ejercicios
        return true;
    } else {
        cout << "No se pueden agregar mas ejercicios a la bateria (capacidad maxima alcanzada)." << endl;
        return false; // no se pudo agregar el ejercicio
    }
}

// Listar todos los ejercicios de la batería
void Sucursal::listarEjercicios() {
    cout << "===== BATERIA DE EJERCICIOS DE SUCURSAL " << *codigo << " =====" << endl;

    if (numEjercicios == 0) {
        cout << "No hay ejercicios registrados en la bateria." << endl;
    } else {
        for (int i = 0; i < numEjercicios; i++) { // recorrer solo las posiciones con ejercicios
            cout << (i+1) << ". " << *bateriaEjercicios[i]->getNombre() //  getNombre() es un método que retorna el nombre del ejercicio
                 << " | Zona: " << *bateriaEjercicios[i]->getZona() // getZona() es un método que retorna la zona del ejercicio
                 << " | Descripcion: " << *bateriaEjercicios[i]->getDescripcion() // getDescripcion() es un método que retorna la descripción del ejercicio
                 << endl;
        }
    }

    cout << "==============================================" << endl;
}

// Crear una nueva clase grupal en la sucursal
bool Sucursal::crearClaseGrupal(string codigo, string tipo, int capacidad, string salon, string horario, string cedulaInstructor) {
    // Validar límite de clases
    if (numClases >= 8) {
        cout << "No se pueden crear mas clases grupales en esta sucursal (maximo 8)." << endl;
        return false;
    }

    // Buscar instructor por cédula
    Instructor* inst = nullptr;
    for (int i = 0; i < MAX_INSTRUCTORES; i++) {
        if (instructores[i] != nullptr && *instructores[i]->getCedula() == cedulaInstructor) {
            inst = instructores[i];
            break;
        }
    }

    if (inst == nullptr) {
        cout << "Instructor con cedula " << cedulaInstructor << " no encontrado en esta sucursal." << endl;
        return false;
    }

    // Validar que el instructor tenga la especialidad correspondiente
    bool tieneEspecialidad = false;
    for (int j = 0; j < inst->getNumEspecialidades(); j++) {
        if (*inst->getEspecialidad(j) == tipo) {
            tieneEspecialidad = true;
            break;
        }
    }

    if (!tieneEspecialidad) {
        cout << "El instructor no tiene la especialidad requerida para impartir la clase de " << tipo << "." << endl;
        return false;
    }

    // Crear la clase grupal
    clasesGrupales[numClases] = new ClaseGrupal(codigo, tipo, capacidad, salon, horario, inst); // se pasa el instructor al constructor
    numClases++; // incrementar el contador de clases

    cout << "Clase grupal de " << tipo << " creada exitosamente en la sucursal " << *codigo << "." << endl;
    return true;
}

// Listar todas las clases grupales de la sucursal
void Sucursal::listarClasesGrupales() {
    cout << "===== CLASES GRUPALES DE LA SUCURSAL " << *codigo << " =====" << endl;

    if (numClases == 0) {
        cout << "No hay clases grupales registradas en esta sucursal." << endl;
    } else {
        for (int i = 0; i < numClases; i++) {
            cout << (i+1) << ". Codigo: " << *clasesGrupales[i]->getCodigo()
                 << " | Tipo: " << *clasesGrupales[i]->getTipo()
                 << " | Salon: " << *clasesGrupales[i]->getSalon()
                 << " | Horario: " << *clasesGrupales[i]->getHorario()
                 << " | Capacidad: " << clasesGrupales[i]->getCapacidad()
                 << " | Cupos disponibles: " << clasesGrupales[i]->getCuposDisponibles()
                 << " | Instructor: " << *clasesGrupales[i]->getInstructor()->getNombre()
                 << endl;
        }
    }

    cout << "==============================================" << endl;
}

// Matricular un cliente en una clase grupal de la sucursal
bool Sucursal::matricularClienteEnClase(string cedulaCliente, string codigoClase) {
    // Buscar cliente
    Cliente* cli = nullptr; // puntero para el cliente encontrado
    for (int i = 0; i < MAX_CLIENTES; i++) {
        if (clientes[i] != nullptr && *clientes[i]->getCedula() == cedulaCliente) { // si se encuentra el cliente
            cli = clientes[i]; //   
            break;
        }
    }
    if (cli == nullptr) {
        cout << "Cliente con cedula " << cedulaCliente << " no encontrado en esta sucursal." << endl;
        return false;
    }

    // Buscar clase grupal
    ClaseGrupal* clase = nullptr; // puntero para la clase encontrada
    for (int j = 0; j < numClases; j++) { // recorrer solo las clases creadas
        if (*clasesGrupales[j]->getCodigo() == codigoClase) {
            clase = clasesGrupales[j]; // se asigna la clase encontrada
            break;
        }
    }
    if (clase == nullptr) {
        cout << "Clase con codigo " << codigoClase << " no encontrada en esta sucursal." << endl;
        return false;
    }

    // Validar que el cliente no supere el máximo de 3 clases
    if (cli->getNumClases() >= 3) {
        cout << "El cliente ya esta matriculado en el maximo de 3 clases." << endl;
        return false;
    }

    // Validar cupos disponibles en la clase
    if (clase->getCuposDisponibles() <= 0) {
        cout << "La clase " << *clase->getTipo() << " ya esta llena, no se puede matricular mas clientes." << endl;
        return false;
    }

    // Matricular al cliente en la clase
    bool okClase = clase->agregarCliente(cli);
    bool okCliente = cli->matricularClase(clase);

    if (okClase && okCliente) {
        cout << "Cliente " << *cli->getNombre() << " matriculado exitosamente en la clase " << *clase->getTipo() << "." << endl;
        return true;
    } else {
        cout << "Error al matricular al cliente en la clase." << endl;
        return false;
    }
}







