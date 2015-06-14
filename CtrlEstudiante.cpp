/*
 * CtrlEstudiante.cpp
 *
 *  Created on: Jun 11, 2015
 *      Author: marccio
 */

#include "CtrlEstudiante.h"

set<DTEstudiante*>* CtrlEstudiante::listarEstudiantes() {
	ManejadorBedelia * mb = ManejadorBedelia::getInstance();

	return mb->listarEstudiantes();
}

bool CtrlEstudiante::seleccionarEstudiante(string cedula) {
}

DataEstudiante* CtrlEstudiante::consultarDatosEstudiante() {
}

set<FullDTOferta*>* CtrlEstudiante::mostrarNotificacionesDeEstudiante(
		string cedula) {
}

void CtrlEstudiante::modificarEstudiante(string nombre, string apellido,
		Date* fecha, int tel) {
}

void CtrlEstudiante::addCarrera(string idCarrera) {
}

void CtrlEstudiante::quitCarrera(string idCarrera) {
}

void CtrlEstudiante::addAsignatura(Date* fecha, int nota, string idAs) {
}

void CtrlEstudiante::quitAsignatura(string idAs) {
}
