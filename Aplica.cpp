/*
 * Aplica.cpp
 *
 *  Created on: Jun 7, 2015
 *      Author: marccio
 */

#include "Aplica.h"

Aplica::Aplica() {
	fecha = FechaSistema::getInstance()->getFecha();
	estudiante = NULL;
	oferta = NULL;
	entrevistas = NULL;
}

Aplica::~Aplica() {
	this->cancelar();
}

DTAplicacion* Aplica::getDatosAplicacion() {
	return oferta->getDatosOL();
}

void Aplica::cancelar() {
	for( set<Entrevista*>::iterator it = entrevistas->begin();
			it != entrevistas->end(); ++it ) {
	    delete *it;
	}
	entrevistas->clear();
	delete entrevistas;
	estudiante->cancelarAplica(this);
	delete estudiante;
}

bool Aplica::estaInscripto(int numExp) {
	return (numExp == oferta->getNumeroDeExpediente());
}

DTEstudiante* Aplica::getDTEstudiante() {
	return estudiante->crearDT();
}

void Aplica::crearEntrevista(Date* d) {
	Entrevista * e = new Entrevista(d);
	entrevistas->insert(e);
}

/*
Aplica* Aplica::getAplicacionEstudiante(string ci) {
	if (ci == estudiante->getCedula()) return this;
	else return NULL;
}
*/
