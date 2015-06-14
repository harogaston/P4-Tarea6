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
 * Archivo: Simple.cpp
 *******************************************************************************/

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
