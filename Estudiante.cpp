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
 * Archivo: Estudiante.cpp
 *******************************************************************************/

#include "Estudiante.h"
#include <iostream>

Estudiante::Estudiante(string cedula, string nombre, string apellido,
		Date* fecha_nac, int telefono, int creditosObtenidos) {
	this->cedula = cedula;
	this->nombre = nombre;
	this->apellido = apellido;
	this->fecha_nac = fecha_nac;
	this->telefono = telefono;
	this->creditosObtenidos = creditosObtenidos;
	contratos = NULL;
	salvadas = NULL;
	carreras = NULL;
	notificaciones = NULL;
	aplicaciones = NULL;
}

Estudiante::~Estudiante() {
	/*
	for (set<FirmaContrato*>::iterator it = contratos->begin() ;
			it != contratos->end() ; it++) {
		delete * it;
	}
	*/
	contratos->clear();
	delete contratos;
	for (set<Notificacion*>::iterator it = notificaciones->begin() ;
			it != notificaciones->end() ; it++) {
		delete * it;
	}
	notificaciones->clear();
	delete notificaciones;
	salvadas->clear();
	delete salvadas;

}

string Estudiante::getCedula() {
	return cedula;
}

string Estudiante::getNombre() {
	return nombre;
}

string Estudiante::getApellido() {
	return apellido;
}

Date * Estudiante::getFechaNacimiento() {
	return fecha_nac;
}

int Estudiante::getTelefono() {
	return telefono;
}

int Estudiante::getCreditosObtenidos() {
	return creditosObtenidos;
}

DTEstudiante* Estudiante::crearDT() {
	DTEstudiante * dt = new DTEstudiante(
			cedula,
			nombre,
			apellido,
			fecha_nac,
			telefono,
			creditosObtenidos);
	return dt;
}

DataEstudiante* Estudiante::consultarDatosEstudiante() { ///REVISAR! Ahora usa un map de carreras
	set<DTCarrera*> * setCarreras = NULL;
	for (map<string, Carrera*>::iterator it = carreras->begin();
			it != carreras->end(); it++) {
		DTCarrera * dt = (*it).second->crearDT();
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
		DTAplicacion * dt = (*it)->crearDT();
		setAplicaciones->insert(dt);
	}
	DataEstudiante * dtOut = new DataEstudiante(
			cedula,
			nombre,
			apellido,
			fecha_nac,
			telefono,
			creditosObtenidos,
			setCarreras,
			setSalvadas,
			setAplicaciones);
	return dtOut;
}

set<FullDTOferta*>* Estudiante::mostrarNotificaciones() {
	set<FullDTOferta*> * setOut = NULL;
	for (set<Notificacion*>::iterator it = notificaciones->begin() ; it != notificaciones->end() ; it++) {
		setOut->insert((*it)->mostrarNotificacion());
	}
	return setOut;
}

void Estudiante::cancelarContrato(FirmaContrato* f) {
	bool termine = false;
	set<FirmaContrato*>::iterator it = contratos->begin();
	while (it != contratos->end() && not termine) {
		if (*(*it) == *f) { //Si se les ocurre otra forma de comparar el f y el (*it) vamo arriba
			contratos->erase(it);
			termine = true;
		}
		it++;
	}
}

void Estudiante::cancelarAplica(Aplica* a) {
	bool termine = false;
	set<Aplica*>::iterator it = aplicaciones->begin();
	while (it != aplicaciones->end() && not termine) {
		if ( (*it)->crearDT()->getExpedienteOferta() == a->crearDT()->getExpedienteOferta() ) {
			aplicaciones->erase(it);
			termine = true;
		}
		it++;
	}
}

bool Estudiante::estaInscripto(int exp) {
	for (set<Aplica*>::iterator it = aplicaciones->begin() ;
			it != aplicaciones->end() ; it++) {
		if ((*it)->estaInscripto(exp)) return true;
	}
	return false;
}

void Estudiante::asignarAplicacion(Aplica* a) {
	aplicaciones->insert(a);
}

void Estudiante::asociarContrato(FirmaContrato * fir) {
	contratos->insert(fir);
}

void Estudiante::modificarEstudiante(string nombre, string apellido,
		Date * fecha, int telefono) {
	this->nombre = nombre;
	this->apellido = apellido;
	this->fecha_nac = fecha;
	this->telefono = telefono;
}

void Estudiante::addCarrera(Carrera* c) {
	carreras->insert(pair<string, Carrera*>(c->getCodigo(),c));
}

void Estudiante::quitCarrera(Carrera* c) {
	if (not carreras->empty()) {
		map<string, Carrera*>::iterator it = carreras->find(c->getCodigo());
		carreras->erase(it);
	}
}

void Estudiante::addSalvada(Salva* s) {
	creditosObtenidos += s->getAsignatura()->getCreditos();
	salvadas->insert(s);
}

bool Estudiante::esCandidato(set<string>* asignaturasRequeridas) {
	//bool candidato = true;
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

set<DTAsignaturaSalvada*>* Estudiante::listarSalvadas() {
	set<DTAsignaturaSalvada*>* setOut = NULL;
	for (set<Salva*>::iterator it = salvadas->begin() ;
			it != salvadas->end() ; it++) {
		DTAsignaturaSalvada * dt = (*it)->getDatosAprobacionAsignatura();
		setOut->insert(dt);
	}
	return setOut;
}

bool Estudiante::asignaturaEnCarrera(string codigo) {
	for(map<string, Carrera*>::iterator it1 = carreras->begin(); it1 != carreras->end(); it1++) {
		Carrera * c = it1->second;
		if (c->asignaturaEnCarrera(codigo)) return true;
	}
	return false;
}

void Estudiante::agregarCreditos(int creditos) {
	creditosObtenidos += creditos;
}

void Estudiante::quitarCreditos(int creditos) {
	creditosObtenidos -= creditos;
	if (creditosObtenidos < 0) creditosObtenidos = 0;
}

void Estudiante::quitAsignatura(Salva* s) {
/*	for (set<Salva*>::iterator it = salvadas->begin() ;
			it != salvadas->end() ; it++) {
		if (s->getAsignatura()->getCodigo() == (*it)->getAsignatura()->getCodigo()) {
			delete * it;
			salvadas->erase(it);
			break;
		}
	}*/

	bool termine = false;
	set<Salva*>::iterator it = salvadas->begin();
	while (it != salvadas->end() && not termine) {
		if (s->getAsignatura()->getCodigo() == (*it)->getAsignatura()->getCodigo() ) {
			salvadas->erase(it);
			termine = true;
		}
		it++;
	}
}

void Estudiante::notificar(Notificacion * notificacion, set<string> * asignaturas) {
	if (this->esCandidato(asignaturas)) notificaciones->insert(notificacion);
}
