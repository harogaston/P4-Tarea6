/*
 * ManejadorBedelia.cpp
 *
 *  Created on: Jun 11, 2015
 *      Author: marccio
 */

#include "ManejadorBedelia.h"

#include "Grupo.h"
#include "Simple.h"

#include <stdexcept>

ManejadorBedelia * ManejadorBedelia::getInstance(){
	if (instancia == NULL)
		instancia = new ManejadorBedelia;
	return instancia;
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
	set<DTEstudiante*> * setOut = NULL;
	for (map<string, Estudiante*>::iterator it = estudiantes->begin() ;
			it != estudiantes->end() ; it++) {
		bool esNoInscripto = (*it).second->esNoInscripto(exp);
		if (esNoInscripto){
			string ci = (*it).second->getCedula();
			ManejadorOfertaLaboral * mol = ManejadorOfertaLaboral::getInstance();
			bool posible = mol->esElegible(ci);
			if (posible) {
				DTEstudiante * dt = (*it).second->crearDT();
				setOut->insert(dt);
			}
		}
	}
	return setOut;
}

Estudiante* ManejadorBedelia::getEstudiante(string ci) {
	map<string, Estudiante*>::iterator it = estudiantes->find(ci);
	if (it != estudiantes->end()) return (*it);
	else throw std::invalid_argument("Ese estudiante no existe.\n");
}

set<DTEstudiante*>* ManejadorBedelia::listarEstudiantes() {
	set<DTEstudiante*> * estudiantes = NULL;
	for (map<string, Estudiante*>::iterator it = estudiantes->begin() ;
			it != estudiantes->end() ; it++) {
		DTEstudiante * dt = (*it).second->crearDT();
		estudiantes->insert(dt);
	}
	return estudiantes;
}

DataEstudiante* ManejadorBedelia::consultarDatosEstudiante(string ci) {
	DataEstudiante * dtOut = NULL;
	map<string, Estudiante*>::iterator it = estudiantes->find(ci);
	if (it != estudiantes->end()) {
		dtOut = (*it).second->consultarDatosEstudiante();
	}
	return dtOut;
}

Estudiante* ManejadorBedelia::asignarCargo(FirmaContrato* fir, string ci) {
	map<string, Estudiante*>::iterator it = estudiantes->find(ci);
	if (it != estudiantes->end()) {
		(*it).second->asignarCargo(fir);
		return (*it);
	} else throw std::invalid_argument("Cedula no valida.\n");
}

void ManejadorBedelia::modDatosEstudiante(
		string cedula,
		string nombre,
		string apellido,
		Date * d,
		int tel) {
	map<string, Estudiante*>::iterator it = estudiantes->find(cedula);
	if (it != estudiantes->end()) (*it).second->modificarDatosEstudiante(
			cedula,
			nombre,
			apellido,
			d,
			tel
			);
}

void ManejadorBedelia::addCarrera(string idCar, string ci) {
	set<Carrera*>::iterator it = carreras->find(idCar);
	if (it != carreras->end()) {
		set<Estudiante*>::iterator it1 = estudiantes->find(ci);
		if (it1 != estudiantes->end()) {
			(*it1)->addCarrera((*it));
		}
	}
}

void ManejadorBedelia::quitCarrera(string idCar, string ci) {
	set<Carrera*>::iterator it = carreras->find(idCar);
	if (it != carreras->end()) {
		set<Estudiante*>::iterator it1 = estudiantes->find(ci);
		if (it1 != estudiantes->end()) {
			(*it1)->quitCarrera((*it));
		}
	}
}

void ManejadorBedelia::addAsignatura(string ci, Date* d, int nota,
		string idAs) {
	map<string, Asignatura*>::iterator it = asignaturas->find(idAs);
	if (it != asignaturas->end()) {
		bool esValida = not (*it).second->fueSalvada(ci);
		map<string, Estudiante*>::iterator it1 = estudiantes->find(ci);
		if (it1 != estudiantes->end()) {
			bool enCarrera = (*it1).second->asignaturaEnCarrera(idAs);
			if (enCarrera) {
				Salva * s = new Salva(d, nota);
				s->vincularConAsignaturayEstudiante((*it).second, (*it1).second);
				(*it).second->addSalva(s); //linkeo con asignatura
				(*it).second->addSalva(s); //linkeo con estudiante
			}
		}
	}
}

void ManejadorBedelia::quitAsignatura(string idAs, string ci) {
	map<string, Asignatura*>::iterator it = asignaturas->find(idAs);
	if (it != asignaturas->end()) {
		bool esValida = (*it).second->fueSalvada(ci);
		if (esValida) {
			Salva * s = (*it).second->getSalvada(ci);
			map<string, Estudiante*>::iterator it1 = estudiantes->find(ci);
			if (it1 != estudiantes->end()) {
				(*it1).second->quitAsignatura(s);
			}
			delete s;
		}
	}
}

bool ManejadorBedelia::existeAsignatura(string idAs) {
	return (asignaturas->find(idAs) != asignaturas->end());
}

set<FullDTOferta*>* ManejadorBedelia::mostrarNotificacionesDeEstudiante(
		string ci) {
	set<FullDTOferta*> * setOut = NULL;
	map<string, Estudiante*>::iterator it = estudiantes->find(ci);
	if (it != estudiantes->end()) {
		setOut = (*it).second->mostrarNotificacionesDeEstudiante();
	}
	return setOut;
}

void ManejadorBedelia::crearCarrera(string idC, string nombre) {
	Carrera * c = new Carrera(idC, nombre, NULL);
	carreras->insert(pair<string, Carrera*>(idC, c));
}

void ManejadorBedelia::crearAsignatura(string codigo, string nombre,
		int creditos) {
	Asignatura * a = new Asignatura(codigo, nombre, creditos);
	asignaturas->insert(pair<string, Asignatura*>(codigo, a));
}

void ManejadorBedelia::asociarAsignaturaACarrera(string idAs, string idC) {
	map<string, Carrera*>::iterator it = carreras->find(idC);
	map<string, Asignatura*>::iterator it1 = asignaturas->find(idAs);
	if (it != carreras->end() && it1 != asignaturas->end())
		(*it).second->addAsignatura((*it1).second);
}

void ManejadorBedelia::crearEstudiante(string ci, string nom, string ap,
		Date* fecha_nac, int telefono, int cred) {
	Estudiante * e = new Estudiante(ci, nom, ap, fecha_nac, telefono, cred);
	estudiantes->insert(pair<string, Estudiante*>(ci, e));
}

void ManejadorBedelia::asociarEstudianteACarrera(string ci, string idC) {
	map<string, Carrera*>::iterator it = carreras->find(idC);
	map<string, Estudiante*>::iterator it1 = estudiantes->find(ci);
	if (it != carreras->end() && it1 != estudiantes->end())
		(*it1).second->addCarrera((*it).second);
}
