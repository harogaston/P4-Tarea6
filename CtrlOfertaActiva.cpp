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

void CtrlOfertaActiva::quitarAsignaturaRequerida() {
}
