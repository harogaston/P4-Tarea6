/*
 * Carrera.cpp
 *
 *  Created on: Jun 2, 2015
 *      Author: Sofia
 */

#include "Carrera.h"

using namespace std;

	Carrera::Carrera(string codigo, string nombre, map<string, Asignatura*> * asignaturas) {
		this->codigo = codigo;
		this->nombre = nombre;
		this->asignaturas = asignaturas;
}
;

Carrera::~Carrera() {
}

DTCarrera* Carrera::crearDT() {
	DTCarrera * dt = new DTCarrera(codigo, nombre);
	return dt;
}

bool Carrera::asignaturaEnCarrera(string idAs) {
	//devuelve true si la asignatura esta en el set
	return (asignaturas->find(idAs) != asignaturas->end());
}

string Carrera::getCodigo() {
	return codigo;
}

string Carrera::getNombre() {
	return nombre;
}

void Carrera::addAsignatura(Asignatura* a) {
	asignaturas->insert(pair<string, Asignatura*>(a->getCodigo(), a));
}
