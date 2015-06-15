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
 * Archivo: ManejadorOfertaLaboral.cpp
 *******************************************************************************/

#include "ManejadorOfertaLaboral.h"

ManejadorOfertaLaboral * ManejadorOfertaLaboral::instancia = NULL;

ManejadorOfertaLaboral::ManejadorOfertaLaboral() {
	ofertas = new map<int, OfertaLaboral*>;
}

ManejadorOfertaLaboral * ManejadorOfertaLaboral::getInstance(){
	if (instancia == NULL)
		instancia = new ManejadorOfertaLaboral();
	return instancia;
};

set<FullDTOferta*>* ManejadorOfertaLaboral::listarOfertasActivas() {
	set<FullDTOferta*>* salida;

	for (map<int, OfertaLaboral*>::iterator it = ofertas->begin(); it != ofertas->end(); ++it) {
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

	for (map<int, OfertaLaboral*>::iterator it = ofertas->begin(); it != ofertas->end(); ++it) {
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
	it = ofertas->find(numExp);

	return (it != ofertas->end());
}

bool ManejadorOfertaLaboral::seleccionarOfertaFinalizada(int numExp) {
}

bool ManejadorOfertaLaboral::seleccionarOfertaActiva(int numExp) {
	map<int, OfertaLaboral*>::iterator it;
	it = ofertas->find(numExp);
	if (it != ofertas->end()) {
		return it->second->esActiva();
	}
	return false;
}

void ManejadorOfertaLaboral::darDeBaja(int numExp) {
	map<int, OfertaLaboral*>::iterator it;
	it = ofertas->find(numExp);

	if (it != ofertas->end()){
		OfertaLaboral* of = it->second;
		ofertas->erase(it);
		of->cancelar();
		delete of;
	}
}

bool ManejadorOfertaLaboral::esElegible(int numExp, string cedula) {
	map<int, OfertaLaboral*>::iterator it;
	it = ofertas->find(numExp);

	if (it != ofertas->end()){
		return it->second->esElegible(cedula);
	}
	return false;
}

OfertaLaboral* ManejadorOfertaLaboral::getOfertaLaboral(int numExp) {
	map<int, OfertaLaboral*>::iterator it = ofertas->find(numExp);
	if (it =! ofertas->end()) return (*it).second;
	else throw std::invalid_argument("El número de expediente ingresado no coinicide"
									" con ninguna oferta laboral presente en el sistema.\n");

	map<string, Estudiante*>::iterator it = estudiantes->find(cedula);
		if (it != estudiantes->end()) return (*it).second;
		else throw std::invalid_argument("Ese estudiante no existe.\n");
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
