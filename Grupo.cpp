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
 * Archivo: Grupo.cpp
 *******************************************************************************/

#include "Grupo.h"

Grupo::Grupo() {
}

Grupo::~Grupo() {
}

set<string>* Grupo::actualizarRequerimientos(
		map<string, Estudiante*> * estudiantes,
		set<string> * asignaturasRequeridas,
		map<string, Asignatura*> * asignaturas) {
	set<string> * setOut = NULL;
	for (set<string>::iterator it = asignaturasRequeridas->begin() ;
			it != asignaturasRequeridas->end() ; it++) {
		map<string, Asignatura*>::iterator it1 = asignaturas->find((*it));
		if ((*it1).second->tieneAprobaciones()) {
			setOut->insert((*it));
			return setOut;
		}
	}
	return setOut;
}
