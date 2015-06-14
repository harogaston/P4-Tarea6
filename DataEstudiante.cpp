/*******************************************************************************
 * Programación 4 - Laboratorio 6 - Año 2015
 *
 * Profesor: Pablo Milanese
 * Grupo: 17
 * Integrantes: Juan Pablo Copello - jpcopel@gmail.com
 * 			Gastón Haro - harogaston@gmail.com
 * 			Sofia Honty - sofisho@gmail.com
 * 			Marccio Silva - marcciosilva@gmail.com
 *
 * Archivo: DataEstudiante.cpp
 *******************************************************************************/

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
	for (set<DTCarrera*>::iterator it = carreras->begin() ;
			it != carreras->end() ; it++) {
		delete * it;
	}
	carreras->clear();
	delete carreras;
	for (set<DTAsignaturaSalvada*>::iterator it = asignaturasSalvadas->begin() ;
				it != asignaturasSalvadas->end() ; it++) {
			delete * it;
		}
	asignaturasSalvadas->clear();
	delete asignaturasSalvadas;
	for (set<DTAplicacion*>::iterator it = aplicaciones->begin() ;
				it != aplicaciones->end() ; it++) {
			delete * it;
		}
	aplicaciones->clear();
	delete aplicaciones;
	delete(fechaNac);
}
