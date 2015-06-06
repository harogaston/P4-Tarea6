/*
 * DTAsignatura.cpp
 *
 *  Created on: Jun 6, 2015
 *      Author: marccio
 */

#include "DTAsignatura.h"

DTAsignatura::DTAsignatura(string codigo, string nombre, int creditos) {
	this->codigo = codigo;
	this->nombre = nombre;
	this->creditos = creditos;
}

DTAsignatura::~DTAsignatura() {
}

string DTAsignatura::getCodigo() {
	return this->codigo;
}

string DTAsignatura::getNombre() {
	return this->nombre;
}

int DTAsignatura::getCreditos() {
	return this->creditos;
}
