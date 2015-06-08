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

bool Salva::estaSalvada(string ci) {
	return (ci == estudiante->getCedula());
}

Salva* Salva::getSalvada() {
	return this;
}

DTAsignaturaSalvada* Salva::getDatosAprobacionAsignatura() {
	DTAsignaturaSalvada * dtReducido = asignatura->getDatosAprobacionAsignatura();
	DTAsignaturaSalvada * dt = new DTAsignaturaSalvada(
			dtReducido->getCodigo(),
			dtReducido->getNombre(),
			fecha,
			nota);
	delete dtReducido;
	return dt;
}

void Salva::vincularConAsignaturayEstudiante(Asignatura* a, Estudiante* e) {
	//operacion potencialmente al pedo ya que el constructor podría hacer esto
	asignatura = a;
	estudiante = e;
}
