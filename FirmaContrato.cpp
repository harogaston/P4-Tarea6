/*
 * FirmaContrato.cpp
 *
 *  Created on: Jun 6, 2015
 *      Author: marccio
 */

#include "FirmaContrato.h"

FirmaContrato::FirmaContrato(Date* fecha, float sueldo) {
	this->fecha = fecha;
	this->sueldo = NULL;
	this->estudiante = NULL;
	this->oferta = NULL;
}

FirmaContrato::~FirmaContrato() {
}

Date* FirmaContrato::getFecha() {
	return fecha;
}

float FirmaContrato::getSueldo() {
	return sueldo;
}

void FirmaContrato::cancelar() {
	estudiante->cancelarContrato(this);
	estudiante = NULL;
}

void FirmaContrato::asociarAOfertayEstudiante(OfertaLaboral* o, Estudiante* e) {
	estudiante = e;
	oferta = o;
	o->asignarCargo(this);
	e->asignarCargo(this);
}
