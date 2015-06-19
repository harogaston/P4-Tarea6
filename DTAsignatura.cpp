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
 * Archivo: DTAsignatura.cpp
 *******************************************************************************/

#include "DTAsignatura.h"

DTAsignatura::DTAsignatura() {
}

DTAsignatura::DTAsignatura(string codigo, string nombre) {
	this->codigo = codigo;
	this->nombre = nombre;
}

DTAsignatura::~DTAsignatura() {
}

string DTAsignatura::getCodigo() {
	return codigo;
}

string DTAsignatura::getNombre() {
	return nombre;
}
