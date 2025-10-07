#include <iostream>
#include <string>
#include "PowerLab.h"
#include "Sucursal.h"
#include "Cliente.h"
#include "Instructor.h"
#include "ClaseGrupal.h"
#include "Ejercicio.h"
using namespace std;

// sub menú de cliente para manejar opciones específicas del cliente
void menuCliente(Cliente* cliente) {
    int opcion = -1;
    do {
        cout << "\n===== MENU CLIENTE " << *cliente->getNombre() << " =====" << endl;
        cout << "1. Ver detalle del cliente" << endl;
        cout << "2. Ver historial de mediciones" << endl;
        cout << "3. Ver rutina actual" << endl;
        cout << "4. Ver clases matriculadas" << endl;
        cout << "0. Volver" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: cliente->mostrarDetalle(); break;
            case 2: cliente->mostrarHistorial(); break;
            case 3: cliente->mostrarRutina(); break;
            case 4: cliente->listarClases(); break;
            case 0: cout << "Volviendo..." << endl; break;
            default: cout << "Opcion invalida." << endl;
        }
    } while (opcion != 0);
}

// sub menú de sucursal para manejar opciones específicas de la sucursal
void menuSucursal(Sucursal* sucursal) {
    int opcion = -1;
    do {
        cout << "\n===== MENU SUCURSAL " << *sucursal->getCodigo() << " =====" << endl;
        cout << "1. Listar clientes" << endl;
        cout << "2. Detalle de cliente" << endl;
        cout << "3. Listar instructores" << endl;
        cout << "4. Listar clases grupales" << endl;
        cout << "5. Crear clase grupal" << endl;
        cout << "6. Matricular cliente en clase" << endl;
        cout << "7. Reporte IMC por sucursal" << endl;
        cout << "8. Listar bateria de ejercicios" << endl;
        cout << "9. Agregar ejercicio a bateria" << endl;
        cout << "0. Volver al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: sucursal->listarClientes(); break;
            case 2: {
                string cedula;
                cout << "Ingrese cedula del cliente: ";
                cin >> cedula;
                Cliente* c = sucursal->getClientePorCedula(cedula);
                if (c) menuCliente(c);
                else cout << "Cliente no encontrado." << endl;
                break;
            }
            case 3: sucursal->listarInstructores(); break;
            case 4: sucursal->listarClasesGrupales(); break;
            case 5: {
                string codigo, tipo, salon, horario, cedulaInstructor;
                int capacidad;
                cout << "Codigo de la clase: "; cin >> codigo;
                cout << "Tipo de clase (CrossFit, HIIT, TRX, Pesas, Spinning, Cardio, Yoga, Zumba): ";
                cin >> tipo;
                cout << "Capacidad maxima: "; cin >> capacidad;
                cout << "Salon: "; cin >> salon;
                cout << "Horario: "; cin >> horario;
                cout << "Cedula del instructor: "; cin >> cedulaInstructor;
                sucursal->crearClaseGrupal(codigo, tipo, capacidad, salon, horario, cedulaInstructor);
                break;
            }
            case 6: {
                string cedulaCliente, codigoClase;
                cout << "Cedula del cliente: "; cin >> cedulaCliente;
                cout << "Codigo de la clase: "; cin >> codigoClase;
                sucursal->matricularClienteEnClase(cedulaCliente, codigoClase);
                break;
            }
            case 7: sucursal->reporteIMC(); break;
            case 8: sucursal->listarEjercicios(); break;
            case 9: {
                string nombre, zona, descripcion;
                cout << "Nombre del ejercicio: "; cin >> nombre;
                cout << "Zona del cuerpo: "; cin >> zona;
                cout << "Descripcion: "; cin.ignore(); getline(cin, descripcion);
                Ejercicio* e = new Ejercicio(nombre, zona, descripcion);
                sucursal->agregarEjercicio(e);
                break;
            }
            case 0: cout << "Volviendo al menu principal..." << endl; break;
            default: cout << "Opcion invalida." << endl;
        }
    } while (opcion != 0);
}

// --------- MENU PRINCIPAL ------------
int main() {
    PowerLab sistema;  // Sistema principal de PowerLab

    int opcion = -1; // -1 ya que 0 es salir y del 1...6 son opciones válidas
    do {
        cout << "\n===== MENU PRINCIPAL POWERLAB =====" << endl;
        cout << "1. Agregar sucursal" << endl;
        cout << "2. Listar sucursales" << endl;
        cout << "3. Entrar a una sucursal" << endl;
        cout << "4. Buscar cliente global" << endl;
        cout << "5. Buscar instructor global" << endl;
        cout << "6. Buscar clase global" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                string codigo, direccion;
                cout << "Ingrese codigo de la sucursal: ";
                cin >> codigo;
                cout << "Ingrese direccion de la sucursal: ";
                cin.ignore();
                getline(cin, direccion);
                Sucursal* nueva = new Sucursal(codigo, direccion);
                nueva->inicializarBateria(100); // se inicializa bateria de ejercicios con capacidad 100
                sistema.agregarSucursal(nueva);
                break;
            }
            case 2: sistema.listarSucursales(); break;
            case 3: {
                sistema.listarSucursales();
                int indice;
                cout << "Ingrese el numero de la sucursal a gestionar: ";
                cin >> indice;
                if (indice > 0 && indice <= sistema.getNumSucursales()) {
                    menuSucursal(sistema.getSucursal(indice-1));
                } else {
                    cout << "Indice invalido." << endl;
                }
                break;
            }
            case 4: {
                string cedula;
                cout << "Ingrese cedula del cliente: ";
                cin >> cedula;
                sistema.buscarCliente(cedula);
                break;
            }
            case 5: {
                string cedula;
                cout << "Ingrese cedula del instructor: ";
                cin >> cedula;
                sistema.buscarInstructor(cedula);
                break;
            }
            case 6: {
                string codigoClase;
                cout << "Ingrese codigo de la clase: ";
                cin >> codigoClase;
                sistema.buscarClase(codigoClase);
                break;
            }
            case 0: cout << "Saliendo del sistema PowerLab..." << endl; break;
            default: cout << "Opcion invalida." << endl;
        }
    } while (opcion != 0);

    return 0;
}
