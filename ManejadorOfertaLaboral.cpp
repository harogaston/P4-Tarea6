#include "ManejadorOfertaLaboral.h"

ManejadorOfertaLaboral * ManejadorOfertaLaboral::instancia = NULL;

ManejadorOfertaLaboral::ManejadorOfertaLaboral() {
}

ManejadorOfertaLaboral * ManejadorOfertaLaboral::getInstance(){
	if (instancia == NULL)
		instancia = new ManejadorOfertaLaboral();
	return instancia;
};

set<FullDTOferta*>* ManejadorOfertaLaboral::listarOfertasActivas() {
	set<FullDTOferta*>* salida;

	for (map<int, OfertaLaboral*>::iterator it = Ofertas->begin(); it != Ofertas->end(); ++it) {
		OfertaLaboral* of = it->second;
		if (of->esActiva()) {
			FullDTOferta * temp = of->getFullDatos();
			salida->insert(temp);
		}
	}

	return salida;
}

set<DTOferta*>* ManejadorOfertaLaboral::listarOfertasTodas() {
	set<DTOferta*>* salida;

	for (map<int, OfertaLaboral*>::iterator it = Ofertas->begin(); it != Ofertas->end(); ++it) {
		OfertaLaboral* of = it->second;
		DTOferta * temp = of->crearDT();
		salida->insert(temp);
	}

	return salida;
}

set<DTOferta*>* ManejadorOfertaLaboral::listarOfertasFinalizadas() {
}

bool ManejadorOfertaLaboral::seleccionarOferta(int numExp) {
	map<int, OfertaLaboral*>::iterator it;
	it = Ofertas->find(numExp);

	return (it != Ofertas->end());
}

bool ManejadorOfertaLaboral::seleccionarOfertaFinalizada(int numExp) {
}

bool ManejadorOfertaLaboral::seleccionarOfertaActiva(int numExp) {
}

void ManejadorOfertaLaboral::darDeBaja(int numExp) {
	map<int, OfertaLaboral*>::iterator it;
	it = Ofertas->find(numExp);

	if (it != Ofertas->end()){
		OfertaLaboral* of = it->second;
		Ofertas->erase(it);
		of->cancelar();
		delete of;
	}
}

bool ManejadorOfertaLaboral::esElegible(int numExp, string cedula) {
}

OfertaLaboral* ManejadorOfertaLaboral::getOfertaLaboral(int numExp) {
}

void ManejadorOfertaLaboral::modificarOferta(int numExp,
		DataOfertaRestringida dataOferta) {
}

bool ManejadorOfertaLaboral::seleccionarAsignatura(bool accion, string cod,
		int numExp) {
}

void ManejadorOfertaLaboral::agregarAsignatura(string cod, int numExp) {
}

void ManejadorOfertaLaboral::quitarAsignatura(string cod, int numExp) {
}

set<DTEstudiante*>* ManejadorOfertaLaboral::listarInscriptos(int numExp) {
}

OfertaLaboral* ManejadorOfertaLaboral::asignarCargo(FirmaContrato* fir,int numExp) {
}

bool ManejadorOfertaLaboral::agendarEntrevista(Date* fecha, int numExp) {
}

void ManejadorOfertaLaboral::crearEntrevista(int numExp, string cedula,
		Date* fecha) {
}

bool ManejadorOfertaLaboral::chequearExpedienteDisponible(int numExp) {
}

void ManejadorOfertaLaboral::agregarOfertaLaboral(OfertaLaboral* of) {
}

void ManejadorOfertaLaboral::asociarAsignaturaAOferta(OfertaLaboral* of,
		Asignatura* asignatura) {
}
