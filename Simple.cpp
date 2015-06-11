/*
 * Simple.cpp
 *
 *  Created on: Jun 11, 2015
 *      Author: marccio
 */

#include "Simple.h"

Simple::Simple() {
}

Simple::~Simple() {
}

set<string>* Simple::actualizarRequerimientos(
		map<string, Estudiante*> * estudiantes,
		set<string> * asignaturasRequeridas,
		map<string, Asignatura*> * asignaturas) {
	set<string> * setOut = NULL;
	if (not estudiantes->empty()) {
		map<string, Estudiante*>::iterator it = estudiantes->begin();
		DataEstudiante * dt = (*it).second->consultarDatosEstudiante();
		setOut = dt->getAsignaturasSalvadas();
	}
	return setOut;
}
