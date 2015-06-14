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
 * Archivo: DTEmpresa.cpp
 *******************************************************************************/

#include "DTEmpresa.h"

DTEmpresa::DTEmpresa(string RUT, string nombre) {
	this->RUT = RUT;
	this->nombre = nombre;
}

string DTEmpresa::getNombre() {
	return nombre;
}

string DTEmpresa::getRUT() {
	return RUT;
}

DTEmpresa::~DTEmpresa() {
}
