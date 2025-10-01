#include "Instructor.h"
// Constructor por defecto	
Instructor::Instructor() {
	cedula = new string("0000000000");
	nombre = new string("Sin nombre");	
	telefono = new string("0000000000");	
	correo = new string("sin correo");	
	fechaNacimiento = new string("01/01/2000");	
	especialidades = nullptr; // inicializar el arreglo dinámico como nulo
}
Instructor::Instructor(string*, string*, string*, string*, string*) {

}
Instructor::~Instructor() {

}
void Instructor::setCedula(string*) {

}
void Instructor::setNombre(string*) {

}
void Instructor::setTelefono(string*) {

}
void Instructor::setCorreo(string*) {

}
void Instructor::setFechaNacimiento(string*) {

}
string* Instructor::getCedula() {

}
string* Instructor::getNombre() {

}
string* Instructor::getTelefono() {

}
string* Instructor::getCorreo() {

}
string* Instructor::getFechaNacimiento() {

}
void Instructor::addEspecialidad(string*) {

}
bool Instructor::generarMedicion(Cliente*, Medicion*) {

}
Rutina* Instructor::generarRutina(Cliente*) {

}
