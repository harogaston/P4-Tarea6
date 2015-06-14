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

set<FullDTOferta*>* CtrlOfertaActiva::listarOfertasActivas() {
	ManejadorOfertaLaboral * mol = ManejadorOfertaLaboral::getInstance();

	return mol->listarOfertasActivas();
}

bool CtrlOfertaActiva::seleccionarOfertaActiva(int numExp) {
}

set<DTEstudiante*>* CtrlOfertaActiva::listarNoInscriptos() {
}

bool CtrlOfertaActiva::seleccionarEstudiante(string cedula) {
}

void CtrlOfertaActiva::inscribirEstudiante() {
}

void CtrlOfertaActiva::modificarOferta(DataOfertaRestringida* dtOR) {
}

bool CtrlOfertaActiva::seleccionarAsignatura(bool accion, string cod) {
}

void CtrlOfertaActiva::agregarAsignaturaRequerida() {
}

CtrlOfertaActiva::CtrlOfertaActiva() {
}

CtrlOfertaActiva::~CtrlOfertaActiva() {
}

void CtrlOfertaActiva::quitarAsignaturaRequerida() {
}
