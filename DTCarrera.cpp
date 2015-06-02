/*
 * DTCarrera.cpp
 *
 *  Created on: Jun 2, 2015
 *      Author: marccio
 */

#include "DTCarrera.h"

DTCarrera::DTCarrera() {
	codigo = "";
	nombre = "";
}

DTCarrera::DTCarrera(string codigo, string nombre) {
	this->codigo = codigo;
	this->nombre = nombre;
}

DTCarrera::~DTCarrera() {
}

string DTCarrera::getCodigo() {
	return codigo;
}

string DTCarrera::getNombre() {
	return nombre;
}
