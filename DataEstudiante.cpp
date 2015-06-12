/*
 * DataEstudiante.cpp
 *
 *  Created on: Jun 2, 2015
 *      Author: marccio
 */

#include "DataEstudiante.h"

DataEstudiante::DataEstudiante(string cedula, string nombre, string apellido,
		Date * fechaNac, int telefono, int creditosObtenidos,
		set<DTCarrera*> * carreras,
		set<DTAsignaturaSalvada*> * asignaturasSalvadas,
		set<DTAplicacion*> * aplicaciones) {
	this->cedula = cedula;
	this->nombre = nombre;
	this->apellido = apellido;
	this->fechaNac = fechaNac;
	this->telefono = telefono;
	this->creditosObtenidos = creditosObtenidos;
	this->carreras = carreras;
	this->asignaturasSalvadas = asignaturasSalvadas;
	this->aplicaciones = aplicaciones;
}

string DataEstudiante::getCedula() {
	return this->cedula;
}

string DataEstudiante::getNombre() {
	return this->nombre;
}

string DataEstudiante::getApellido() {
	return this->apellido;
}

Date * DataEstudiante::getFechaNac() {
	return this->fechaNac;
}

int DataEstudiante::getTelefono() {
	return this->telefono;
}

int DataEstudiante::getCreditosObtenidos() {
	return this->creditosObtenidos;
}

set<DTCarrera*> * DataEstudiante::getCarreras() {
	return this->carreras;
}

set<DTAsignaturaSalvada*> * DataEstudiante::getAsignaturasSalvadas() {
	return this->asignaturasSalvadas;
}

set<DTAplicacion*> * DataEstudiante::getAplicaciones() {
	return this->aplicaciones;
}

DataEstudiante::~DataEstudiante() {
	//solo vacia los contenedores, los punteros tienen que borrarse afuera si no C++ llora
	carreras->erase(carreras->begin(), carreras->end());
	asignaturasSalvadas->erase(asignaturasSalvadas->begin(), asignaturasSalvadas->end());
	aplicaciones->erase(aplicaciones->begin(), aplicaciones->end());
	delete(fechaNac);
}
