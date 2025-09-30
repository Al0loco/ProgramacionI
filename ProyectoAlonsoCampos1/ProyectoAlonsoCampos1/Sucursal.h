#pragma once
#include <iostream>
using namespace std;
// Forward declarations para evitar inclusiones circulares
// inclusiones circulares: cuando dos o más archivos de encabezado se incluyen mutuamente, lo que puede causar errores de compilación.
class Instructor;   
class Cliente;      
class ClaseGrupal;  

class Sucursal {
private:
    int* codigo;
    string* provincia;
    string* canton;
    string* correo;
    string* telefono;
    // arreglo dinámico: un arreglo cuyo tamaño puede cambiar durante la ejecución del programa.
    Instructor** instructores;   // arreglo dinámico de instructores
    Cliente** clientes;          // arreglo dinámico de clientes
    ClaseGrupal** clases;        // arreglo dinámico de clases
public:
    Sucursal();
    Sucursal(int*, string*, string*, string*, string*);
    ~Sucursal();

    void setCodigo(int*);
    void setProvincia(string*);
    void setCanton(string*);
    void setCorreo(string*);
    void setTelefono(string*);
    void setInstructor(Instructor*);
    void setCliente(Cliente*);
    void setClase(ClaseGrupal*);

    int* getCodigo();
    string* getProvincia();
    string* getCanton();
    string* getCorreo();
    string* getTelefono();
    Instructor** getInstructores();
    Cliente** getClientes();
    ClaseGrupal** getClases();
};
