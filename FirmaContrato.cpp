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
 * Archivo: FirmaContrato.cpp
 *******************************************************************************/

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

void FirmaContrato::setEstudiante(Estudiante * e) {
	this->estudiante = e;
}

void FirmaContrato::cancelar() {
	estudiante->cancelarContrato(this);
	estudiante = NULL;
}
