/*
 * Asignatura.cpp
 *
 *  Created on: Jun 2, 2015
 *      Author: sofia
 */

#include "Asignatura.h"

#include <iostream>

Asignatura::Asignatura(string codigo, string nombre, int creditos) {
	this->codigo = codigo;
	this->nombre = nombre;
	this->creditos = creditos;
	this->salvantes = NULL;
}

Asignatura::~Asignatura() {
	for (set<Salva*>::iterator it = salvantes->begin() ; it != salvantes->end() ; it++) {
		delete((*it));
		salvantes->erase(it);
	}
}

void Asignatura::asociarAsignaturaOferta(OfertaLaboral * of) {
	of->agregarAsignatura(this);
}

bool Asignatura::fueSalvada(string ci) {
	for (set<Salva*>::iterator it = salvantes->begin() ; it != salvantes->end() ; it++) {
		if ((*it)->estaSalvada(ci)) return true;
	}
	return false;
}

DTAsignaturaSalvada * Asignatura::getDatosAprobacionAsignatura() {
	DTAsignaturaSalvada * dt = new DTAsignaturaSalvada(codigo, nombre, NULL, NULL);
	//fecha y nota se agregan desde la instancia de Salva, a la vuelta
	return dt;
}

void Asignatura::addSalva(Salva* s) {
	salvantes->insert(s);
}

string Asignatura::getCodigo() {
	return codigo;
}

string Asignatura::getNombre() {
	return nombre;
}

int Asignatura::getCreditos() {
	return creditos;
}

Salva * Asignatura::getSalvada(string ci) {
	//pre: se asume que fueSalvada retorna true previamente
	Salva * s = NULL;
	for (set<Salva*>::iterator it = salvantes->begin() ; it != salvantes->end() ; it++) {
		if ((*it)->estaSalvada(ci)){
			s = (*it)->getSalvada();
			salvantes->erase(it);
		}
	}
	return s;
}

bool Asignatura::tieneAprobaciones() {
	return (not salvantes->empty());
}
