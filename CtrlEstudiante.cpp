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
 * Archivo: CtrlEstudiante.cpp
 *******************************************************************************/

#include "CtrlEstudiante.h"

CtrlEstudiante::CtrlEstudiante() {
	listadoEstudiantes = NULL;
	cedula = "";
}

CtrlEstudiante::~CtrlEstudiante() {
}

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
