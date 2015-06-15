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
 * Archivo: Asignatura.cpp
 *******************************************************************************/

#include "Asignatura.h"

Asignatura::Asignatura(string codigo, string nombre, int creditos) {
	this->codigo = codigo;
	this->nombre = nombre;
	this->creditos = creditos;
	this->salvantes = NULL;
}

Asignatura::~Asignatura() {
	for (set<Salva*>::iterator it = salvantes->begin() ; it != salvantes->end() ; it++) {
		delete * it;
	}
	salvantes->clear();
	delete salvantes;
}

string Asignatura::getCodigo() {
	return codigo;
}

string Asignatura::getNombre() {
	return nombre;
}

int Asignatura::getCreditos() {
	return creditos;
}

bool Asignatura::fueSalvada(string cedula) {
	for (set<Salva*>::iterator it = salvantes->begin() ; it != salvantes->end() ; it++) {
		if ((*it)->fueSalvada(cedula)) return true;
	}
	return false;
}

bool Asignatura::tieneAprobaciones() {
	return (not salvantes->empty());
}

void Asignatura::addSalvada(Salva* s) {
	salvantes->insert(s);
}

Salva * Asignatura::getSalvada(string cedula) {
	//pre: se asume que fueSalvada retorna true previamente
	for (set<Salva*>::iterator it = salvantes->begin() ; it != salvantes->end() ; it++) {
		if ((*it)->fueSalvada(cedula)){
			Salva * s = *it;
			salvantes->erase(it);
			return (s);
		}
	}
	return NULL;
}

//NO BORRAR

/*
void Asignatura::asociarAsignaturaOferta(OfertaLaboral * of) {
	of->agregarAsignatura(this);
}
*/

/*
DTAsignaturaSalvada * Asignatura::getDatosAprobacionAsignatura() {
	DTAsignaturaSalvada * dt = new DTAsignaturaSalvada(codigo, nombre, NULL, NULL);
	//fecha y nota se agregan desde la instancia de Salva, a la vuelta
	return dt;
}
*/
