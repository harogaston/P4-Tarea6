/*
 * DTEmpresa.cpp
 *
 *  Created on: Jun 1, 2015
 *      Author: marccio
 */

#include "DTEmpresa.h"

DTEmpresa::DTEmpresa(int RUT, string nombre) {
	this->RUT = RUT;
	this->nombre = nombre;
}

string DTEmpresa::getNombre() {
	return nombre;
}

int DTEmpresa::getRUT() {
	return RUT;
}

DTEmpresa::~DTEmpresa() {
}
