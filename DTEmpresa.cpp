/*
 * DTEmpresa.cpp
 *
 *  Created on: Jun 1, 2015
 *      Author: marccio
 */

#include "DTEmpresa.h"

DTEmpresa::DTEmpresa() {
}

DTEmpresa::DTEmpresa(int rut, string nombre) {
	this->RUT = rut;
	this->nombre = nombre;
}

string DTEmpresa::getNombre() {
	return nombre;
}

int DTEmpresa::getRUT() {
	return rut;
}

DTEmpresa::~DTEmpresa() {
}
