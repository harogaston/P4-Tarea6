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
 * Archivo: CtrlOfertaActiva.cpp
 *******************************************************************************/

#include "CtrlOfertaActiva.h"

using namespace std;


CtrlOfertaActiva::CtrlOfertaActiva() {
	this->numExp = 99;
	this->cedula = "";
	this->codigo = "";
	this->noInscriptos = new set<DTEstudiante*>;
}

set<FullDTOferta*>* CtrlOfertaActiva::listarOfertasActivas() {
	ManejadorOfertaLaboral * mol = ManejadorOfertaLaboral::getInstance();
	return mol->listarOfertasActivas();
}

bool CtrlOfertaActiva::seleccionarOfertaActiva(int numExp) {
	ManejadorOfertaLaboral * mol = ManejadorOfertaLaboral::getInstance();
	this->numExp = numExp;
	return mol->seleccionarOfertaActiva(numExp);
}

set<DTEstudiante*>* CtrlOfertaActiva::listarNoInscriptos() {
	ManejadorBedelia * mb = ManejadorBedelia::getInstance();

	return mb->listarNoInscriptos(this->numExp);
}

bool CtrlOfertaActiva::seleccionarEstudiante(string cedula) {
	this->cedula = cedula;
	for (set<DTEstudiante*>::iterator it = noInscriptos->begin() ;
			it != noInscriptos->end() ; it++) {
		if (cedula == (*it)->getCedula()) return true;
	}
	return false;
}

void CtrlOfertaActiva::inscribirEstudiante() {
	ManejadorBedelia * mb = ManejadorBedelia::getInstance();
	Estudiante * e = mb->getEstudiante(this->cedula);
	ManejadorOfertaLaboral * mol = ManejadorOfertaLaboral::getInstance();
	OfertaLaboral * of = mol->getOfertaLaboral(this->numExp);
	Aplica * ap = new Aplica();
	ap->setEstudiante(e);
	ap->setOferta(of);
	e->asignarAplicacion(ap);
	of->asignarAplicacion(ap);
}

void CtrlOfertaActiva::modificarOferta(DataOfertaRestringida* dtOR) {
	ManejadorOfertaLaboral * mol = ManejadorOfertaLaboral::getInstance();
	mol->modificarOferta(this->numExp, dtOR);
}

bool CtrlOfertaActiva::seleccionarAsignatura(bool accion, string codigo) { //accion = 0 quitar, accion = 1 agregar
	this->codigo = codigo;
	ManejadorOfertaLaboral * mol = ManejadorOfertaLaboral::getInstance();
	bool sA = mol->seleccionarAsignatura(accion,codigo,this->numExp);
	bool okAsignatura = false;
	if (accion && sA){
		ManejadorBedelia * mb = ManejadorBedelia::getInstance();
		okAsignatura = mb->existeAsignatura(codigo);
	}
	return ((accion && okAsignatura) || (not accion && sA));
}

void CtrlOfertaActiva::agregarAsignaturaRequerida() {
	ManejadorOfertaLaboral * mol = ManejadorOfertaLaboral::getInstance();
	mol->agregarAsignatura(this->codigo, this->numExp);
}

void CtrlOfertaActiva::quitarAsignaturaRequerida() {
	ManejadorOfertaLaboral * mol = ManejadorOfertaLaboral::getInstance();
	mol->quitarAsignatura(this->codigo, this->numExp);
}

CtrlOfertaActiva::~CtrlOfertaActiva() {
}
