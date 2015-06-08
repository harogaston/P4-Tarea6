/*
 * Estudiante.cpp
 *
 *  Created on: Jun 6, 2015
 *      Author: marccio
 */

#include "Estudiante.h"

Estudiante::Estudiante(string cedula, string nombre, string apellido,
		Date* fecha_nac, int telefono) {
	this->cedula = cedula;
	this->nombre = nombre;
	this->apellido = apellido;
	this->fecha_nac = fecha_nac;
	this->telefono = telefono;
	creditosObtenidos = 0;
	contratos = NULL;
	salvadas = NULL;
	carreras = NULL;
	notificaciones = NULL;
	aplicaciones = NULL;
}

void Estudiante::asignarCargo(FirmaContrato* f) {
	contratos->insert(f);
}

void Estudiante::cancelarContrato(FirmaContrato* f) {
	for (set<FirmaContrato*>::iterator it = contratos->begin() ;
			it != contratos->end() ; it++) {
		if ((*it)->getOferta()->getNumeroDeExpediente() == f->getOferta()->getNumeroDeExpediente()) {
			contratos->erase(it);
			break;
		}
	}
}

DTEstudiante* Estudiante::crearDT() {
	DTEstudiante * dt = new DTEstudiante(
			cedula,
			nombre,
			apellido,
			fecha_nac,
			telefono,
			this->getCreditosObtenidos());
	return dt;
}

string Estudiante::getCedula() {
	return cedula;
}

void Estudiante::cancelarAplica(Aplica* a) {
	for (set<Aplica*>::iterator it = aplicaciones->begin() ;
			it != aplicaciones->end() ; it++) {
		if ((*it)->getDatosAplicacion()->getExpedienteOferta() ==
				a->getDatosAplicacion()->getExpedienteOferta()) {
			aplicaciones->erase(it);
			break;
		}
	}
}

bool Estudiante::esNoInscripto(int exp) {
	//retorna true si el estudiante no esta inscripto a la oferta laboral (exp)
	for (set<Aplica*>::iterator it = aplicaciones->begin() ;
			it != aplicaciones->end() ; it++) {
		if ((*it)->yaEstaInscripto(exp)) return false;
	}
	return true;
}

void Estudiante::asignarAplicacion(Aplica* a) {
	aplicaciones->insert(a);
}

DataEstudiante* Estudiante::consultarDatosEstudiante() {
	set<DTCarrera*> * setCarreras = NULL;
	for (set<Carrera*>::iterator it = carreras->begin() ;
			it != carreras->end() ; it++) {
		DTCarrera * dt = (*it)->crearDT();
		setCarreras->insert(dt);
	}
	set<DTAsignaturaSalvada*> * setSalvadas = NULL;
	for (set<Salva*>::iterator it = salvadas->begin() ;
			it != salvadas->end() ; it++) {
		DTAsignaturaSalvada * dt = (*it)->getDatosAprobacionAsignatura();
		setSalvadas->insert(dt);
	}
	set<DTAplicacion*> * setAplicaciones = NULL;
	for (set<Aplica*>::iterator it = aplicaciones->begin() ;
			it != aplicaciones->end() ; it++) {
		DTAplicacion * dt = (*it)->getDatosAplicacion();
		setAplicaciones->insert(dt);
	}
	DataEstudiante * dtOut = DataEstudiante(
			nombre,
			apellido,
			fecha_nac,
			telefono,
			this->getCreditosObtenidos(),
			setCarreras,
			setSalvadas,
			setAplicaciones);
	return dtOut;
}

bool Estudiante::esCandidato(set<string>* asignaturasRequeridas) {
	bool candidato = true;
	for (set<string>::iterator it1 = asignaturasRequeridas->begin() ;
			it1 != asignaturasRequeridas->end() ; it1++) {
		bool asignaturaEncontrada = false;
		for (set<Salva*>::iterator it2 = salvadas->begin() ; it2 != salvadas->end() ; it2++) {
			if ((*it2)->getDatosAprobacionAsignatura()->getNombre() == (*it1)) {
				asignaturaEncontrada = true;
				break;
			}
		}
		if (not asignaturaEncontrada) return false;
	}
	return true;
}

void Estudiante::notificar(Notificacion* n) {

}

void Estudiante::modificarDatosEstudiante(string cedula, string nombre,
		string apellido, Date* fecha, int telefono) {
	this->cedula = cedula;
	this->nombre = nombre;
	this->apellido = apellido;
	this->fecha_nac = fecha;
	this->telefono = telefono;
}

void Estudiante::addCarrera(Carrera* c) {
	carreras->insert(c);
}

void Estudiante::quitCarrera(Carrera* c) {
	for (set<Carrera*>::iterator it = carreras->begin() ;
			it != carreras->end() ; it++) {
		if (c->getCodigo() == (*it)->getCodigo()) {
			carreras->erase(it);
			break;
		}
	}
}

bool Estudiante::asignaturaEnCarrera(string a) {
	for (set<Carrera*>::iterator it = carreras->begin() ;
			it != carreras->end() ; it++) {
		if ((*it)->asignaturaEnCarrera(a)) return true;
	}
	return false;
}

void Estudiante::addSalva(Salva* s) {
	creditosObtenidos += s->getAsignatura()->getCreditos();
	salvadas->insert(s);
}

void Estudiante::quitAsignatura(Salva* s) {
	for (set<Salva*>::iterator it = salvadas->begin() ;
			it != salvadas->end() ; it++) {
		if (s->getAsignatura()->getCodigo() == (*it)->getAsignatura()->getCodigo()) {
			salvadas->erase(it);
			break;
		}
	}
}

Estudiante::~Estudiante() {
}

string Estudiante::getNombre() {
	return nombre;
}

string Estudiante::getApellido() {
	return apellido;
}

string Estudiante::getFechaNacimiento() {
	return fecha_nac;
}

int Estudiante::getTelefono() {
	return telefono;
}

int Estudiante::getCreditosObtenidos() {
	return creditosObtenidos;
}

set<FullDTOferta*>* Estudiante::mostrarNotificacionesDeEstudiante() {
	set<FullDTOferta*> * setOut = NULL;
	for (set<Notificacion*>::iterator it = notificaciones->begin() ; it != notificaciones->end ; it++) {
		setOut->insert((*it)->mostrarNotificacion());
	}
	return setOut;
}
