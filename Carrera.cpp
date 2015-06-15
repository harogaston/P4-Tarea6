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
 * Archivo: Carrera.cpp
 *******************************************************************************/

#include "Carrera.h"

using namespace std;

Carrera::Carrera(string codigo, string nombre) {
	this->codigo = codigo;
	this->nombre = nombre;
	asignaturas = NULL;
}

Carrera::~Carrera() {
	/*
	for (map<string, Asignatura*>::iterator it = asignaturas->begin() ;
			it != asignaturas->end() ; it++) {
		delete (*it).second;
	}
	*/
	asignaturas->clear(); //hay que ver cuando se elimina una asignatura
	delete asignaturas;
}

string Carrera::getCodigo() {
	return codigo;
}

string Carrera::getNombre() {
	return nombre;
}

map<string, Asignatura*>* Carrera::getAsignaturas() {
	return asignaturas;
}

DTCarrera* Carrera::crearDT() {
	DTCarrera * dt = new DTCarrera(codigo, nombre);
	return dt;
}

bool Carrera::asignaturaEnCarrera(string codigo) {
	//devuelve true si la asignatura esta en el set
	return (asignaturas->find(codigo) != asignaturas->end());
}

void Carrera::addAsignatura(Asignatura* a) {
	asignaturas->insert(pair<string, Asignatura*>(a->getCodigo(), a));
}
