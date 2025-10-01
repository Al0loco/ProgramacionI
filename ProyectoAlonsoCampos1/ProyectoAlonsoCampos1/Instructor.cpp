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
// Constructor con parámetros
Instructor::Instructor(string* cedula, string* nombre, string* telefono, string* correo, string* fechaNacimiento) {
	this->cedula = cedula;
	this->nombre = nombre;
	this->telefono = telefono;
	this->correo = correo;
	this->fechaNacimiento = fechaNacimiento;
}
Instructor::~Instructor() {
	delete cedula;
	delete nombre;
	delete telefono;
	delete correo;
	delete fechaNacimiento;
}
void Instructor::setCedula(string*) {
	*cedula = *cedula;
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
void Instructor::addEspecialidad(string*) {

}
bool Instructor::generarMedicion(Cliente*, Medicion*) {

}
Rutina* Instructor::generarRutina(Cliente*) {

}
