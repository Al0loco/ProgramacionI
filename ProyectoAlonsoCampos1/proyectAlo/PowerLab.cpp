#include "Powerlab.h"
#include <iostream>
using namespace std;

Powerlab::Powerlab() {
    numSucursales = 0;
    for (int i = 0; i < 30; i++) {
        sucursales[i] = nullptr;
    }
}

// Agregar una nueva sucursal
bool Powerlab::agregarSucursal(Sucursal* s) {
    if (numSucursales < 30) {
        sucursales[numSucursales] = s;
        numSucursales++;
        cout << "Sucursal agregada exitosamente." << endl;
        return true;
    } else {
        cout << "No se pueden agregar mas sucursales (maximo 30)." << endl;
        return false;
    }
}

// Listar todas las sucursales
void Powerlab::listarSucursales() {
    cout << "===== LISTADO DE SUCURSALES =====" << endl;
    if (numSucursales == 0) {
        cout << "No hay sucursales registradas." << endl;
    } else {
        for (int i = 0; i < numSucursales; i++) {
            cout << (i+1) << ". Codigo: " << *sucursales[i]->getCodigo()
                 << " | Direccion: " << *sucursales[i]->getDireccion()
                 << endl;
        }
    }
    cout << "=================================" << endl;
}

// Buscar cliente en todas las sucursales
void Powerlab::buscarCliente(string cedula) {
    cout << "===== BUSQUEDA DE CLIENTE " << cedula << " =====" << endl;
    bool encontrado = false;

    for (int i = 0; i < numSucursales; i++) {
        Cliente* c = sucursales[i]->getClientePorCedula(cedula);
        if (c != nullptr) {
            encontrado = true;
            cout << "Encontrado en sucursal " << *sucursales[i]->getCodigo() << endl;
            c->mostrarDetalle(); // método que ya implementamos en Cliente
        }
    }

    if (!encontrado) {
        cout << "Cliente no encontrado en ninguna sucursal." << endl;
    }
    cout << "=================================" << endl;
}

// Buscar instructor en todas las sucursales
void Powerlab::buscarInstructor(string cedula) {
    cout << "===== BUSQUEDA DE INSTRUCTOR " << cedula << " =====" << endl;
    bool encontrado = false;

    for (int i = 0; i < numSucursales; i++) {
        Instructor* inst = sucursales[i]->getInstructorPorCedula(cedula);
        if (inst != nullptr) {
            encontrado = true;
            cout << "Encontrado en sucursal " << *sucursales[i]->getCodigo() << endl;
            inst->mostrarDetalle();
        }
    }

    if (!encontrado) {
        cout << "Instructor no encontrado en ninguna sucursal." << endl;
    }
    cout << "=================================" << endl;
}

// Buscar clase grupal en todas las sucursales
void Powerlab::buscarClase(string codigoClase) {
    cout << "===== BUSQUEDA DE CLASE " << codigoClase << " =====" << endl;
    bool encontrado = false;

    for (int i = 0; i < numSucursales; i++) {
        ClaseGrupal* clase = sucursales[i]->getClasePorCodigo(codigoClase);
        if (clase != nullptr) {
            encontrado = true;
            cout << "Encontrada en sucursal " << *sucursales[i]->getCodigo() << endl;
            clase->mostrarDetalle();
        }
    }

    if (!encontrado) {
        cout << "Clase no encontrada en ninguna sucursal." << endl;
    }
    cout << "=================================" << endl;
}
