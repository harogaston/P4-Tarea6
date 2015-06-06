/*
 * DTAsignaturaSalvada.cpp
 *
 *  Created on: Jun 2, 2015
 *      Author: marccio
 */

#include "DTAsignaturaSalvada.h"

DTAsignaturaSalvada::DTAsignaturaSalvada() {
}

DTAsignaturaSalvada::DTAsignaturaSalvada(string codigo, string nombre,
		Date * fecha, int nota) {
	this->codigo = codigo;
	this->nombre = nombre;
	this->fecha = fecha;
	this->nota = nota;
}

DTAsignaturaSalvada::~DTAsignaturaSalvada() {
}

string DTAsignaturaSalvada::getCodigo() {
	return codigo;
}

string DTAsignaturaSalvada::getNombre() {
	return nombre;
}

Date * DTAsignaturaSalvada::getFecha() {
	return fecha;
}

int DTAsignaturaSalvada::getNota() {
	return nota;
}
