/*
 * ManejadorBedelia.cpp
 *
 *  Created on: Jun 11, 2015
 *      Author: marccio
 */

#include "ManejadorBedelia.h"

#include "Grupo.h"
#include "Simple.h"

ManejadorBedelia * ManejadorBedelia::instance = NULL;

ManejadorBedelia * ManejadorBedelia::getInstance(){
	if (instance==NULL)
		instance= new ManejadorBedelia;
	return instance;
}

bool ManejadorBedelia::validarAsignaturas(set<string>* asignaturas) {
	//si en mi coleccion de asignaturas estan todas las pasadas por parametro
	//retorno TRUE
	for (set<string>::iterator it = asignaturas->begin() ;
			it != asignaturas->end() ; it++ ) {
		//si no se encuentra
		if (not (this->asignaturas->find((*it)) != this->asignaturas->end()))
			return false;
	}
	return true;
}

void ManejadorBedelia::agregarAsignaturas(OfertaLaboral* of,
		set<string>* asignaturas) {
	for (map<string, Asignatura*>::iterator it = asignaturas->begin() ;
			it != asignaturas->end() ; it++) {
		(*it).second->asociarAsignaturaOferta(of);
	}
}

bool ManejadorBedelia::existenCandidatos(set<string> * asignaturas) {
	for (map<string, Estudiante*>::iterator it = estudiantes->begin() ;
			it != estudiantes->end() ; it++) {
		//si alguno es candidato devuelvo TRUE
		if ((*it).second->esCandidato(asignaturas)) return true;
	}
	return false;
}

set<string>* ManejadorBedelia::getEstrategiaGrupo(set<string> * asignaturasRequeridas) {
	strategy = new Grupo();
	return strategy->actualizarRequerimientos(estudiantes, asignaturasRequeridas, asignaturas);
}

set<string>* ManejadorBedelia::getEstrategiaSimple(set<string> * asignaturasRequeridas) {
	strategy = new Simple();
	return strategy->actualizarRequerimientos(estudiantes, NULL, NULL);
}

void ManejadorBedelia::actualizarRequerimientos(
		set<string> * asignaturas,
		DataOferta * dtO) {
	ManejadorOfertaLaboral * m = ManejadorOfertaLaboral::getInstance();
	DataOferta * dt = m->crearDataOferta(
			dtO->getNumeroDeExpediente(),
			dtO->getTitulo(),
			dtO->getDescripcion(),
			dtO->getHorasSemanales(),
			dtO->getSueldoMin(),
			dtO->getSueldoMax(),
			dtO->getComienzoLlamado(),
			dtO->getFinLlamado(),
			dtO->getPuestosDisponibles(),
			asignaturas);
	delete dtO;
	dtO = dt;
}

void ManejadorBedelia::notificarObservers(OfertaLaboral * oferta,
		set<string> * asignaturas) {
	Notificacion * n = new Notificacion(oferta);
	for (set<IObserver*>::iterator it = observadores->begin() ;
			it != observadores->end() ; it++) {
		(*it)->notificar(n, asignaturas);
	}
}

void ManejadorBedelia::agregar(IObserver* ob) {
	observadores->insert(ob);
}

void ManejadorBedelia::quitar(IObserver* ob) {
	bool found = false;
	set<IObserver*>::iterator it = observadores->begin();
	while (not found) {
		if ((*it) == ob) {
			observadores->erase(it);
			found = true;
		}
	}
}

set<DTEstudiante*>* ManejadorBedelia::listarNoInscriptos(int exp) {
}

Estudiante* ManejadorBedelia::getEstudiante(string ci) {
}

set<DTEstudiante*>* ManejadorBedelia::listarEstudiantes() {
}

DataEstudiante* ManejadorBedelia::consultarDatosEstudiante(string ci) {
}

Estudiante* ManejadorBedelia::asignarCargo(FirmaContrato* fir, string ci) {
}

void ManejadorBedelia::modDatosEstudiante(string nombre, string apellido,
		Date* d, int tel) {
}

void ManejadorBedelia::addCarrera(string idCar, string ci) {
}

void ManejadorBedelia::quitCarrera(string idCar, string ci) {
}

void ManejadorBedelia::addAsignatura(string ci, Date* d, int nota,
		string idAs) {
}

void ManejadorBedelia::quitAsignatura(string idAs, string ci) {
}

bool ManejadorBedelia::existeAsignatura(string idAs) {
}

set<FullDTOferta*>* ManejadorBedelia::mostrarNotificacionesDeEstudiante(
		string ci) {
}

Carrera* ManejadorBedelia::crearCarrera(string idC, string nombre) {
}

Asignatura* ManejadorBedelia::crearAsignatura(string codigo, string nombre,
		int creditos) {
}

void ManejadorBedelia::asociarAsignaturaACarrera(string idAs, string idC) {
}

void ManejadorBedelia::crearEstudiante(string ci, string nom, string ap,
		Date* fecha_nac, int telefono, int cred) {
}

void ManejadorBedelia::asociarEstudianteACarrera(string ci, string idC) {
}
