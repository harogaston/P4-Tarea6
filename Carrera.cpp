/*
 * Carrera.cpp
 *
 *  Created on: Jun 2, 2015
 *      Author: Sofia
 */

#include "Carrera.h"

using namespace std;

	Carrera::Carrera(string codigo, string nombre) {
		this->codigo = codigo;
		this->nombre = nombre;
		asignaturas = NULL;
}
;

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

DTCarrera* Carrera::crearDT() {
	DTCarrera * dt = new DTCarrera(codigo, nombre);
	return dt;
}

bool Carrera::asignaturaEnCarrera(string idAs) {
	//devuelve true si la asignatura esta en el set
	return (asignaturas->find(idAs) != asignaturas->end());
}

void Carrera::addAsignatura(Asignatura* a) {
	asignaturas->insert(pair<string, Asignatura*>(a->getCodigo(), a));
}
