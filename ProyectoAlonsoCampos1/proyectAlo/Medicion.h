#pragma once
#include <iostream>
using namespace std;

class Medicion {
private:
    string* fecha;
    // datos necesarios para calcular el IMC
    float* peso;
    float* estatura;
    float* pctGrasa;
    float* pctMusculo;
    int* edadMetabolica;
    float* pctGrasaVisceral;
    // otras mediciones
    float* cintura;
    float* cadera;
    float* pecho;
    float* muslo;
public:
// Constructores y destructores
    Medicion();
    Medicion(string*, float*, float*, float*, float*, int*, float*, float*, float*, float*, float*);
    ~Medicion();
// Funciones set
    void setFecha(string*);
    void setPeso(float*);
    void setEstatura(float*);
    void setPctGrasa(float*);
    void setPctMusculo(float*);
    void setEdadMetabolica(int*);
    void setPctGrasaVisceral(float*);
    void setCintura(float*);
    void setCadera(float*);
    void setPecho(float*);
    void setMuslo(float*);
// Funciones get
    string* getFecha();
    float* getPeso();
    float* getEstatura();
    float* getPctGrasa();
    float* getPctMusculo();
    int* getEdadMetabolica();
    float* getPctGrasaVisceral();
    float* getCintura();
    float* getCadera();
    float* getPecho();
    float* getMuslo();
// Funciones accionales
    float calcularIMC();
    string clasificacionIMC();
};
