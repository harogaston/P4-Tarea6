/*
 * DTEstudiante.cpp
 *
 *  Created on: Jun 2, 2015
 *      Author: marccio
 */

#include "DTEstudiante.h"


DTEstudiante::DTEstudiante() {
}

DTEstudiante::DTEstudiante(string cedula, string nombre, string apellido,
		Date * fechaNac, int telefono, int creditosObtenidos) {
	this->cedula = cedula;
	this->nombre = nombre;
	this->apellido = apellido;
	this->fechaNac = fechaNac;
	this->telefono = telefono;
	this->creditosObtenidos = creditosObtenidos;
}

DTEstudiante::~DTEstudiante() {
}

string DTEstudiante::getCedula() {
	return this->cedula;
}

string DTEstudiante::getNombre() {
	return this->nombre;
}

string DTEstudiante::getApellido() {
	return this->apellido;
}

Date * DTEstudiante::getFechaNac() {
	return this->fechaNac;
}

int DTEstudiante::getTelefono() {
	return this->telefono;
}

int DTEstudiante::getCreditosObtenidos() {
	return this->creditosObtenidos;
}
