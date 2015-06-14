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
 * Archivo: Entrevista.cpp
 *******************************************************************************/

#include "Entrevista.h"

Entrevista::Entrevista(Date * fecha) {
	this->fecha = fecha;
}

Entrevista::~Entrevista() {
	delete fecha;
}

Date* Entrevista::getFecha() {
	return fecha;
}
