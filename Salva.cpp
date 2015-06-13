/*
 * Salva.cpp
 *
 *  Created on: Jun 6, 2015
 *      Author: marccio
 */

#include "Salva.h"
#include <stddef.h>

Salva::Salva(Date* fecha, int nota) {
	this->fecha = fecha;
	this->nota = nota;
	asignatura = NULL;
	estudiante = NULL;
}

Salva::~Salva() {
	delete fecha;
}

Estudiante* Salva::getEstudiante() {
	return estudiante;
}

Asignatura* Salva::getAsignatura() {
	return asignatura;
}

DTAsignaturaSalvada* Salva::getDatosAprobacionAsignatura() {
	DTAsignaturaSalvada * dt = new DTAsignaturaSalvada(
			asignatura->getCodigo(),
			asignatura->getNombre(),
			fecha,
			nota);
	return dt;
}

bool Salva::estaSalvada(string ci) {
	return (ci == estudiante->getCedula());
}

void Salva::asociarAsignaturaEstudiante(Asignatura* a, Estudiante* e) {
	asignatura = a;
	estudiante = e;
}
