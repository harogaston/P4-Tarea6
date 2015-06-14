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
 * Archivo: DTCarrera.cpp
 *******************************************************************************/

#include "DTCarrera.h"

DTCarrera::DTCarrera() {
	codigo = "";
	nombre = "";
}

DTCarrera::DTCarrera(string codigo, string nombre) {
	this->codigo = codigo;
	this->nombre = nombre;
}

DTCarrera::~DTCarrera() {
}

string DTCarrera::getCodigo() {
	return codigo;
}

string DTCarrera::getNombre() {
	return nombre;
}
