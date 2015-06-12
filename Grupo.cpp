/*
 * Grupo.cpp
 *
 *  Created on: Jun 11, 2015
 *      Author: marccio
 */

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
