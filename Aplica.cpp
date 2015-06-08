/*
 * Aplica.cpp
 *
 *  Created on: Jun 7, 2015
 *      Author: marccio
 */

#include "Aplica.h"

Aplica::Aplica(Date* f, Estudiante* e, OfertaLaboral* o) {
	fecha = f;
	estudiante = e;
	oferta = o;
	entrevistas = NULL;
}

Aplica::~Aplica() {
	for (set<Entrevista*>::iterator it = entrevistas->begin() ; it != entrevistas->end() ; it++) {
		Entrevista * e = (*it);
		entrevistas->erase(it);
		delete(e);
	}
}

void Aplica::cancelar() {
	for (set<Entrevista*>::iterator it = entrevistas->begin() ; it != entrevistas->end() ; it++) {
		Entrevista * e = (*it);
		entrevistas->erase(it);
		delete(e);
	}
	estudiante->cancelarAplica(this);
}

bool Aplica::yaEstaInscripto(int exp) {
	return (exp == oferta->getNumeroDeExpediente());
}

DTAplicacion* Aplica::getDatosAplicacion() {
	return oferta->getDatosOL();
}

DTEstudiante* Aplica::getEstudiante() {
	return estudiante->crearDT();
}

Aplica* Aplica::getAplicacionEstudiante(string ci) {
	if (ci == estudiante->getCedula()) return this;
	else return NULL;
}

void Aplica::crearEntrevista(Date* d) {
	Entrevista * e = new Entrevista(d);
	entrevistas->insert(e);
}
