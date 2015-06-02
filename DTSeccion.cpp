/*
 * DTSeccion.cpp
 *
 *  Created on: Jun 1, 2015
 *      Author: marccio
 */

#include "DTSeccion.h"

DTSeccion::DTSeccion() {
	nombre = "";
	interno = 0;
}

DTSeccion::DTSeccion(string nombre, int interno) {
	this->nombre = nombre;
	this->interno = interno;
}

DTSeccion::~DTSeccion() {
}

string DTSeccion::getNombre() {
	return nombre;
}

int DTSeccion::getInterno() {
	return interno;
}
