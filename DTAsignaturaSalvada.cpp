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
 * Archivo: DTAsignaturaSalvada.cpp
 *******************************************************************************/

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
	delete fecha;
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
