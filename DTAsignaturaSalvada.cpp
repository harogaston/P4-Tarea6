/*
 * DTAsignaturaSalvada.cpp
 *
 *  Created on: Jun 2, 2015
 *      Author: marccio
 */

#include "DTAsignaturaSalvada.h"

DTAsignaturaSalvada::DTAsignaturaSalvada() {
	codigo = "";
	nombre = "";
	fecha = NULL;
	nota = 0;
}

DTAsignaturaSalvada::DTAsignaturaSalvada(string codigo, string nombre,
		Date& fecha, int nota) {
	this->codigo = codigo;
	this->nombre = nombre;
	this->fecha = &fecha;
	this->nota = nota;
}

DTAsignaturaSalvada::~DTAsignaturaSalvada() {
	delete(fecha);
}

string DTAsignaturaSalvada::getCodigo() {
	return codigo;
}

string DTAsignaturaSalvada::getNombre() {
	return nombre;
}

Date* DTAsignaturaSalvada::getFecha() {
	return fecha;
}

int DTAsignaturaSalvada::getNota() {
	return nota;
}
