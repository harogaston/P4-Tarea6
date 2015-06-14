/*
 * DTSeccion.cpp
 *
 *  Created on: Jun 1, 2015
 *      Author: marccio
 */

#include "DTSeccion.h"

DTSeccion::DTSeccion() {
	idSec = "";
	interno = 99;
}

DTSeccion::DTSeccion(string idSec, string interno) {
	this->idSec = idSec;
	this->interno = interno;
}

DTSeccion::~DTSeccion() {
}

string DTSeccion::getIdSec() {
	return idSec;
}

int DTSeccion::getInterno() {
	return interno;
}
