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
#include "Fabrica.h"

CtrlEstudiante::CtrlEstudiante() {
	Fabrica * f = Fabrica::getInstance();
	ManejadorBedelia * mb = ManejadorBedelia::getInstance();
	listadoEstudiantes = mb->listarEstudiantes();
	cedula = "";
}

CtrlEstudiante::~CtrlEstudiante() {
	for (set<DTEstudiante*>::iterator it = listadoEstudiantes->begin() ;
			it != listadoEstudiantes->end() ; it++) {
		delete * it;
	}
	listadoEstudiantes->clear();
}

set<DTEstudiante*>* CtrlEstudiante::listarEstudiantes() {
	ManejadorBedelia * mb = ManejadorBedelia::getInstance();
	this->listadoEstudiantes = mb->listarEstudiantes(); // se guarda el listado en memoria
	return this->listadoEstudiantes;
}

bool CtrlEstudiante::seleccionarEstudiante(string cedula) {
	bool encontre = false;
	set<DTEstudiante*>::iterator it = listadoEstudiantes->begin();
	while( it != listadoEstudiantes->end() && not encontre) {
		if (cedula == (*it)->getCedula()) {
			encontre = true;
			this->cedula = cedula;
		}
		it++;
	}
	if (encontre) cout << endl << "Estudiante encontrado!!!!" << endl;
	else cout << endl << "Estudiante NO encontrado!!!!" << endl;
	return encontre;
}

DataEstudiante* CtrlEstudiante::consultarDatosEstudiante() {
	ManejadorBedelia * mb = ManejadorBedelia::getInstance();
	return mb->consultarDatosEstudiante(this->cedula);
}

set<FullDTOferta*>* CtrlEstudiante::mostrarNotificacionesDeEstudiante() {
	ManejadorBedelia * mb = ManejadorBedelia::getInstance();
	return mb->mostrarNotificacionesDeEstudiante(cedula);
}

void CtrlEstudiante::modificarEstudiante(string nombre, string apellido, Date* fecha, int tel) {
	ManejadorBedelia * mb = ManejadorBedelia::getInstance();
	mb->modificarEstudiante(this->cedula, nombre, apellido, fecha, tel);
}

void CtrlEstudiante::addCarrera(string idCarrera) {
	ManejadorBedelia * mb = ManejadorBedelia::getInstance();
	mb->addCarrera(this->cedula, idCarrera);
}

void CtrlEstudiante::quitCarrera(string idCarrera) {
	ManejadorBedelia * mb = ManejadorBedelia::getInstance();
	mb->quitCarrera(this->cedula, idCarrera);
}

void CtrlEstudiante::addAsignatura(Date* fecha, int nota, string codigo) {
	ManejadorBedelia * mb = ManejadorBedelia::getInstance();
	mb->addAsignatura(this->cedula, fecha, nota, codigo);
}

void CtrlEstudiante::quitAsignatura(string codigo) {
	ManejadorBedelia * mb = ManejadorBedelia::getInstance();
	mb->quitAsignatura(codigo, this->cedula);
}
