/*
 * DTEmpresa.cpp
 *
 *  Created on: Jun 1, 2015
 *      Author: marccio
 */

#include "DTEmpresa.h"

DTEmpresa::DTEmpresa() {
	rut = 0;
	nombre = "Null";
}

DTEmpresa::DTEmpresa(int rut, string nombre) {
	this->rut = rut;
	this->nombre = nombre;
}

string DTEmpresa::getNombre() {
	return nombre;
}

int DTEmpresa::getRut() {
	return rut;
}

DTEmpresa::~DTEmpresa() {
}
