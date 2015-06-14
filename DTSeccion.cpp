/*******************************************************************************
 * Programación 4 - Laboratorio 6 - Año 2015
 *
 * Profesor: Pablo Milanese
 * Grupo: 17
 * Integrantes: Juan Pablo Copello - jpcopel@gmail.com
 * 			Gastón Haro - harogaston@gmail.com
 * 			Sofia Honty - sofisho@gmail.com
 * 			Marccio Silva - marcciosilva@gmail.com
 *
 * Archivo: DTSeccion.cpp
 *******************************************************************************/

#include "DTSeccion.h"

DTSeccion::DTSeccion() {
	idSec = "";
	interno = 99;
}

DTSeccion::DTSeccion(string idSec, int interno) {
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
