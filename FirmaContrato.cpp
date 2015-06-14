/*
 * FirmaContrato.cpp
 *
 *  Created on: Jun 6, 2015
 *      Author: marccio
 */

#include "FirmaContrato.h"

FirmaContrato::FirmaContrato(float sueldo) {
	fecha = FechaSistema::getInstance()->getFecha();
	this->sueldo = sueldo;
	estudiante = NULL;
}

FirmaContrato::~FirmaContrato() {
}

Date* FirmaContrato::getFecha() {
	return fecha;
}

float FirmaContrato::getSueldo() {
	return sueldo;
}

Estudiante* FirmaContrato::getEstudiante() {
	return estudiante;
}

void FirmaContrato::cancelar() {
	estudiante->cancelarContrato(this);
	estudiante = NULL;
}
