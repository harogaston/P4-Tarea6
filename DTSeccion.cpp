/*
 * DTSeccion.cpp
 *
 *  Created on: Jun 1, 2015
 *      Author: marccio
 */

#include "DTSeccion.h"

DTSeccion::DTSeccion() {
	nombre = "";
	interno = "";
}

DTSeccion::DTSeccion(string nombre, string interno) {
	this->nombre = nombre;
	this->interno = interno;
}

DTSeccion::~DTSeccion() {
}

string DTSeccion::getNombre() {
	return nombre;
}

string DTSeccion::getInterno() {
	return interno;
}
