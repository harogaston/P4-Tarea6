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
 * Archivo: Aplica.cpp
 *******************************************************************************/

#include "Aplica.h"

Aplica::Aplica() {
	fecha = FechaSistema::getInstance()->getFecha();
	estudiante = NULL;
	oferta = NULL;
	entrevistas = new set<Entrevista*>;
}

Aplica::~Aplica() {
}

DTAplicacion* Aplica::crearDT() {
	return oferta->getDatosAplicacion();
}

void Aplica::cancelar() {
	set<Entrevista*>::iterator it1 = entrevistas->begin();
	while (it1 != entrevistas->end()) {
		Entrevista * e = *it1;
		delete e;
		it1++;
	}
	entrevistas->clear();
	estudiante->cancelarAplica(this);
}

bool Aplica::estaInscripto(int numExp) {
	return (numExp == oferta->getNumeroDeExpediente());
}

DTEstudiante* Aplica::getDTEstudiante() {
	return estudiante->crearDT();
}

void Aplica::setEstudiante(Estudiante* e) {
	this->estudiante = e;
}

void Aplica::setOferta(OfertaLaboral* o) {
	this->oferta = o;
}

void Aplica::crearEntrevista(Date* fecha) {
	Entrevista * e = new Entrevista(fecha);
	entrevistas->insert(e);
}

/*
 Aplica* Aplica::getAplicacionEstudiante(string ci) {
 if (ci == estudiante->getCedula()) return this;
 else return NULL;
 }
 */
