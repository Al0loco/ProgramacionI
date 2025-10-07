#ifndef POWERLAB_H
#define POWERLAB_H

#include "Sucursal.h"

class PowerLab {
private:
    Sucursal* sucursales[30]; // máximo 30 sucursales
    int numSucursales;

public:
    PowerLab();

    // Getters
    int getNumSucursales() { return numSucursales; }
    Sucursal* getSucursal(int index) { return sucursales[index]; }


    // Gestión de sucursales
    bool agregarSucursal(Sucursal* s);
    void listarSucursales();

    // Búsquedas globales
    void buscarCliente(string cedula);
    void buscarInstructor(string cedula);
    void buscarClase(string codigoClase);
};

#endif
