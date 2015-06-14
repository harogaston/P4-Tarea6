/*
 * OfertaLaboral.cpp
 *
 *  Created on: Jun 1, 2015
 *      Author: marccio
 */

#include "OfertaLaboral.h"
#include "FechaSistema.h"
#include <stdexcept>

OfertaLaboral::OfertaLaboral(
		int numero_de_expediente,
		string titulo,
		string descripcion,
		int horas_semanales,
		float sueldo_min,
		float sueldo_max,
		Date * comienzo_llamado,
		Date * fin_llamado,
		int puestos_disponibles,
		set<string>* setAsignaturas,
		Seccion * seccion) {
	this->numero_de_expediente = numero_de_expediente;
	this->titulo = titulo;
	this->descripcion = descripcion;
	this->horas_semanales = horas_semanales;
	this->sueldo_min = sueldo_min;
	this->sueldo_max = sueldo_max;
	this->comienzo_llamado = comienzo_llamado;
	this->fin_llamado = fin_llamado;
	this->puestos_disponibles = puestos_disponibles;
	this->asignaturasRequeridas = new map<string, Asignatura*>;
		ManejadorBedelia * mb = ManejadorBedelia::getInstance();
		if (mb->validarAsignaturas(setAsignaturas)) {
			for (set<string>::iterator it = setAsignaturas->begin(); it != setAsignaturas->end(); ++it) {
				Asignatura * a = mb->getAsignatura(*it);
				this->asignaturasRequeridas->insert(pair<string,Asignatura*>(a->getCodigo(),a));
			}
		}
	this->contratos = NULL;
	this->aplicaciones = NULL;
	this->seccion = seccion;
}

OfertaLaboral::~OfertaLaboral() {
}

Date* OfertaLaboral::getComienzoLlamado() {
	return comienzo_llamado;
}

void OfertaLaboral::setComienzoLlamado(Date* comienzoLlamado) {
	comienzo_llamado = comienzoLlamado;
}

string OfertaLaboral::getDescripcion() {
	return descripcion;
}

void OfertaLaboral::setDescripcion(string descripcion) {
	this->descripcion = descripcion;
}

Date* OfertaLaboral::getFinLlamado() {
	return fin_llamado;
}

void OfertaLaboral::setFinLlamado(Date* finLlamado) {
	fin_llamado = finLlamado;
}

int OfertaLaboral::getHorasSemanales() {
	return horas_semanales;
}

void OfertaLaboral::setHorasSemanales(int horasSemanales) {
	horas_semanales = horasSemanales;
}

int OfertaLaboral::getNumeroDeExpediente() {
	return numero_de_expediente;
}

void OfertaLaboral::setNumeroDeExpediente(int numeroDeExpediente) {
	numero_de_expediente = numeroDeExpediente;
}

int OfertaLaboral::getPuestosDisponibles() {
	return puestos_disponibles;
}

void OfertaLaboral::setPuestosDisponibles(int puestosDisponibles) {
	puestos_disponibles = puestosDisponibles;
}

float OfertaLaboral::getSueldoMax() {
	return sueldo_max;
}

void OfertaLaboral::setSueldoMax(float sueldoMax) {
	sueldo_max = sueldoMax;
}

float OfertaLaboral::getSueldoMin() {
	return sueldo_min;
}

void OfertaLaboral::setSueldoMin(float sueldoMin) {
	sueldo_min = sueldoMin;
}

string OfertaLaboral::getTitulo() {
	return titulo;
}

void OfertaLaboral::setTitulo(string titulo) {
	this->titulo = titulo;
}

void OfertaLaboral::agregarAsignatura(Asignatura* a) {
	asignaturasRequeridas->insert(pair<string, Asignatura*>(a->getCodigo(), a));
}

DTOferta* OfertaLaboral::crearDT() {
	DTOferta * dt = new DTOferta(numero_de_expediente, titulo);
	return dt;
}

void OfertaLaboral::cancelar() {
	set<FirmaContrato*>::iterator it1 = contratos->begin();
	while (not contratos->empty()) {
		FirmaContrato * fir = *it1;
		contratos->erase(it1);
		fir->cancelar();
		delete fir;
		it1++;
	}

	set<Aplica*>::iterator it2 = aplicaciones->begin();
	while (not aplicaciones->empty()) {
		Aplica * a = *it2;
		aplicaciones->erase(it2);
		a->cancelar();
		delete a;
		it2++;
	}

	this->seccion->cancelarOferta(this);
}

bool OfertaLaboral::esActiva() {
	FechaSistema * f = FechaSistema::getInstance();
	return (f->getFecha() <= fin_llamado && f->getFecha() >= this->comienzo_llamado);
}

bool OfertaLaboral::esFinalizada() {
	return (not this->esActiva());
}

FullDTOferta* OfertaLaboral::getFullDatos() {
	int cantidadInscriptos = 0;

	//calculo cantidad inscriptos a la oferta
	for (set<Aplica*>::iterator it = aplicaciones->begin();	it != aplicaciones->end(); it++) {
		cantidadInscriptos++;
	}

	FullDTOferta * dt = new FullDTOferta(
			numero_de_expediente,
			titulo,
			descripcion,
			horas_semanales,
			sueldo_min,
			sueldo_max,
			comienzo_llamado,
			fin_llamado,
			puestos_disponibles,
			seccion->getNombreEmpresa(),
			seccion->getUbicacion(),
			cantidadInscriptos);
	return dt;
}

bool OfertaLaboral::esElegible(string ci) {
	for (map<string, Asignatura*>::iterator it = asignaturasRequeridas->begin() ;
			it != asignaturasRequeridas->end() ; it++) {
		if ((*it).second->fueSalvada(ci)) return true;
	}
	return false;
}

void OfertaLaboral::asignarAplicacion(Aplica* a) {
	aplicaciones->insert(a);
}

void OfertaLaboral::asociarContrato(FirmaContrato* f) {
	contratos->insert(f);
}

DTAplicacion* OfertaLaboral::getDatosAplicacion() {
	DTAplicacion * dapReducido = seccion->getDatosSeccion();
	DTAplicacion * dap = new DTAplicacion(
			numero_de_expediente,
			titulo,
			dapReducido->getRutEmpresa(),
			dapReducido->getEmpresa(),
			dapReducido->getSucursal(),
			dapReducido->getTelefonoSuc(),
			dapReducido->getDireccionSuc(),
			dapReducido->getSeccion(),
			dapReducido->getInternoSeccion());
	delete dapReducido;
	return dap;
}

set<DTEstudiante*>* OfertaLaboral::listarInscriptos() {
	set<DTEstudiante*> * setOut = NULL;
	for (set<Aplica*>::iterator it = aplicaciones->begin() ;
			it != aplicaciones->end() ; it++) {
		setOut->insert((*it)->getDTEstudiante());
	}
	return setOut;
}

void OfertaLaboral::modificarOferta(DataOfertaRestringida* dtOR) {
	titulo = dtOR->getTitulo();
	descripcion = dtOR->getDescripcion();
	horas_semanales = dtOR->getHorasSemanales();
	sueldo_min = dtOR->getSueldoMin();
	sueldo_max = dtOR->getSueldoMax();
	comienzo_llamado = dtOR->getComienzoLlamado();
	fin_llamado = dtOR->getFinLlamado();
	puestos_disponibles = dtOR->getPuestosDisponibles();
}

bool OfertaLaboral::seleccionarAsignatura(bool accion, string codigo) {
	if (accion) {
		return (asignaturasRequeridas->find(codigo) == asignaturasRequeridas->end());
	} else {
		return (asignaturasRequeridas->find(codigo) != asignaturasRequeridas->end());
	}
}

void OfertaLaboral::quitarAsignaturaRequerida(string codigo) {
	asignaturasRequeridas->erase(codigo);
}

bool OfertaLaboral::agendarEntrevista(Date* fecha) {
	//verifica si es posible agendar una entrevista
	return (fecha > fin_llamado);
}

bool OfertaLaboral::crearEntrevista(string cedula, Date* fecha) {
	for (set<Aplica*>::iterator it = aplicaciones->begin() ;
			it != aplicaciones->end() ; it++) {
		DTEstudiante * dt = (*it)->getDTEstudiante();
		if (dt->getCedula() == cedula) {
			(*it)->crearEntrevista(fecha);
			return true;
		}
	}
	return false;
}
