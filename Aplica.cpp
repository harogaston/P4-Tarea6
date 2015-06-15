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
	set<Entrevista*>::iterator it = entrevistas->begin();
	while (not entrevistas->empty()) {
		Entrevista * e = *it;
		entrevistas->erase(it);
		delete e;
		it++;
	}
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
