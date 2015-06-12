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
		map<string, Asignatura*>* asignaturasRequeridas,
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
	this->asignaturasRequeridas = asignaturasRequeridas;
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
	//exp y tit
	DTOferta * dt = new DTOferta(numero_de_expediente, titulo);
	return dt;
}

void OfertaLaboral::cancelar() {
	for (set<FirmaContrato*>::iterator it = contratos->begin() ;
			it != contratos->end() ; it++) {
		(*it)->cancelar();
		delete((*it));
		contratos->erase(it);
	}
	for (set<Aplica*>::iterator it = aplicaciones->begin() ;
			it != aplicaciones->end() ; it++) {
		(*it)->cancelar();
		delete((*it));
		aplicaciones->erase(it);
	}
}

bool OfertaLaboral::esOfertaActiva() {
	FechaSistema * f = FechaSistema::getInstance();
	return (f->getFecha() <= fin_llamado);
}

FullDTOferta* OfertaLaboral::getFullDatos() {
	int cantidadInscriptos = 0;
	//calculo cantidad inscriptos a la oferta
	for (set<Aplica*>::iterator it = aplicaciones->begin() ;
			it != aplicaciones->end() ; it++) {
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

void OfertaLaboral::asignarCargo(FirmaContrato* f) {
	contratos->insert(f);
}

DTAplicacion* OfertaLaboral::getDatosOL() {
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
		setOut->insert((*it)->getEstudiante());
	}
	return setOut;
}

void OfertaLaboral::ingresarDatosOferta(DataOfertaRestringida* dtOR) {
	titulo = dtOR->getTitulo();
	descripcion = dtOR->getDescripcion();
	horas_semanales = dtOR->getHorasSemanales();
	sueldo_min = dtOR->getSueldoMin();
	sueldo_max = dtOR->getSueldoMax();
	comienzo_llamado = dtOR->getComienzoLlamado();
	fin_llamado = dtOR->getFinLlamado();
	puestos_disponibles = dtOR->getPuestosDisponibles();
}

bool OfertaLaboral::seleccionarAsignatura(string accion, string codigo) {
	if (accion == "agregar") {
		return (asignaturasRequeridas->find(codigo) == asignaturasRequeridas->end());
	} else if (accion == "quitar") {
		return (asignaturasRequeridas->find(codigo) != asignaturasRequeridas->end());
	} else throw invalid_argument("La acción a realizar no existe.\n");
}
