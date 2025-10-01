#include "Medicion.h"

// Constructor por defecto
Medicion::Medicion() {
    fecha = new string("01/01/2000"); // se pone una fecha por defecto para evitar punteros nulos
    peso = new float(0.0f);
    estatura = new float(1.0f); // se pone 1.0 para evitar división por cero en el cálculo del IMC
    pctGrasa = new float(0.0f);
    pctMusculo = new float(0.0f);
    edadMetabolica = new int(0);
    pctGrasaVisceral = new float(0.0f);
    cintura = new float(0.0f);
    cadera = new float(0.0f);
    pecho = new float(0.0f);
    muslo = new float(0.0f);
}

// Constructor con parámetros
Medicion::Medicion(string* _fecha, float* _peso, float* _estatura,
    float* _pctGrasa, float* _pctMusculo, int* _edadMetabolica,
    float* _pctGrasaVisceral, float* _cintura, float* _cadera,
    float* _pecho, float* _muslo) {
    fecha = new string(*_fecha);
    peso = new float(*_peso);
    estatura = new float(*_estatura);
    pctGrasa = new float(*_pctGrasa);
    pctMusculo = new float(*_pctMusculo);
    edadMetabolica = new int(*_edadMetabolica);
    pctGrasaVisceral = new float(*_pctGrasaVisceral);
    cintura = new float(*_cintura);
    cadera = new float(*_cadera);
    pecho = new float(*_pecho);
    muslo = new float(*_muslo);
}

// Destructor
Medicion::~Medicion() {
    delete fecha;
    delete peso;
    delete estatura;
    delete pctGrasa;
    delete pctMusculo;
    delete edadMetabolica;
    delete pctGrasaVisceral;
    delete cintura;
    delete cadera;
    delete pecho;
    delete muslo;
}

// Setters
void Medicion::setFecha(string* _fecha) { *fecha = *_fecha; }
void Medicion::setPeso(float* _peso) { *peso = *_peso; }
void Medicion::setEstatura(float* _estatura) { *estatura = *_estatura; }
void Medicion::setPctGrasa(float* _pctGrasa) { *pctGrasa = *_pctGrasa; }
void Medicion::setPctMusculo(float* _pctMusculo) { *pctMusculo = *_pctMusculo; }
void Medicion::setEdadMetabolica(int* _edad) { *edadMetabolica = *_edad; }
void Medicion::setPctGrasaVisceral(float* _pct) { *pctGrasaVisceral = *_pct; }
void Medicion::setCintura(float* _cintura) { *cintura = *_cintura; }
void Medicion::setCadera(float* _cadera) { *cadera = *_cadera; }
void Medicion::setPecho(float* _pecho) { *pecho = *_pecho; }
void Medicion::setMuslo(float* _muslo) { *muslo = *_muslo; }

// Getters
string* Medicion::getFecha() { return fecha; }
float* Medicion::getPeso() { return peso; }
float* Medicion::getEstatura() { return estatura; }
float* Medicion::getPctGrasa() { return pctGrasa; }
float* Medicion::getPctMusculo() { return pctMusculo; }
int* Medicion::getEdadMetabolica() { return edadMetabolica; }
float* Medicion::getPctGrasaVisceral() { return pctGrasaVisceral; }
float* Medicion::getCintura() { return cintura; }
float* Medicion::getCadera() { return cadera; }
float* Medicion::getPecho() { return pecho; }
float* Medicion::getMuslo() { return muslo; }

// Método para calcular IMC
float Medicion::calcularIMC() {
    if (*estatura <= 0) return 0.0f;
    return *peso / ((*estatura) * (*estatura));
}

// Método para clasificar IMC
string Medicion::clasificacionIMC() {
    float imc = calcularIMC();
    if (imc < 16.0) return "Delgadez severa";
    else if (imc <= 16.99) return "Delgadez moderada";
    else if (imc <= 18.49) return "Delgadez leve";
    else if (imc <= 24.99) return "Normal";
    else if (imc <= 29.99) return "Pre-obesidad";
    else if (imc <= 34.99) return "Obesidad leve";
    else if (imc <= 39.99) return "Obesidad media";
    else return "Obesidad mórbida";
}