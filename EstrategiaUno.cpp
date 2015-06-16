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

#include "EstrategiaUno.h"
#include "DTAsignaturaSalvada.h"


EstrategiaUno::EstrategiaUno() {
}

EstrategiaUno::~EstrategiaUno() {
}

set<string>* EstrategiaUno::actualizarRequerimientos(
		map<string, Estudiante*> * estudiantes,
		set<string> * asignaturasRequeridas,
		map<string, Asignatura*> * asignaturas) {
	set<string> * setOut = new set<string>;
	if (not estudiantes->empty()) {
		map<string, Estudiante*>::iterator it = estudiantes->begin();
		DataEstudiante * dt = (*it).second->consultarDatosEstudiante();
		set<DTAsignaturaSalvada*> * setSalvadas = dt->getAsignaturasSalvadas();
		for (set<DTAsignaturaSalvada*>::iterator it = setSalvadas->begin() ; it != setSalvadas->end() ; it++) {
			setOut->insert((*it)->getNombre());
		}
		delete setSalvadas;
	}
	return setOut;
}
