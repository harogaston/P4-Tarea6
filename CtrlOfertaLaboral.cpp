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
 * Archivo: CtrlOfertaLaboral.cpp
 *******************************************************************************/

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <stdexcept>

#include "CtrlOfertaLaboral.h"

//CtrlOfertaLaboral::CtrlOfertaLaboral() {
//}

CtrlOfertaLaboral * CtrlOfertaLaboral::instancia = NULL;

CtrlOfertaLaboral * CtrlOfertaLaboral::getInstance(){
	if (instancia == NULL)
		instancia = new CtrlOfertaLaboral();
	return instancia;
}

CtrlOfertaLaboral::CtrlOfertaLaboral() {
	numExp = 0;
	fecha = FechaSistema::getInstance()->getFecha();
	asignaturas = new set<string>;
	inscriptos = new set<DTEstudiante*>;
	dtO = NULL;
	Empresas = new map<string, Empresa*>;
	ofertas = new set<DTOferta*>;
}

CtrlOfertaLaboral::~CtrlOfertaLaboral() {
}

set<DTOferta*>* CtrlOfertaLaboral::obtenerOfertasTodas() {
	ManejadorOfertaLaboral * mol = ManejadorOfertaLaboral::getInstance();
	return mol->listarOfertasTodas();
}

bool CtrlOfertaLaboral::seleccionarOferta(int numExp) {
	ManejadorOfertaLaboral * mol = ManejadorOfertaLaboral::getInstance();
	this->numExp = numExp;
	return mol->seleccionarOferta(numExp);
}

void CtrlOfertaLaboral::darDeBaja() {
	ManejadorOfertaLaboral * mol = ManejadorOfertaLaboral::getInstance();
	mol->darDeBaja(this->numExp);
}

set<DTOferta*>* CtrlOfertaLaboral::listarOfertasFinalizadas() {
	ManejadorOfertaLaboral * mol = ManejadorOfertaLaboral::getInstance();
	this->ofertas = mol->listarOfertasFinalizadas();
	return this->ofertas;
}

bool CtrlOfertaLaboral::seleccionarOfertaFinalizada(int numExp) {
	this->numExp = numExp;
	for (set<DTOferta*>::iterator it = ofertas->begin() ;
			it != ofertas->end() ; it++) {
		if (numExp == (*it)->getNumeroDeExpediente()) return true;
	}
	return false;
}

set<DTEstudiante*>* CtrlOfertaLaboral::listarInscriptos() {
	ManejadorOfertaLaboral * mol = ManejadorOfertaLaboral::getInstance();
	this->inscriptos = mol->listarInscriptos(this->numExp);
	return this->inscriptos;
}

bool CtrlOfertaLaboral::seleccionarEstudiante(string cedula) {
	this->cedula = cedula;
	for (set<DTEstudiante*>::iterator it = inscriptos->begin() ;
			it != inscriptos->end() ; it++) {
		if (cedula == (*it)->getCedula()) return true;
	}
	return false;
}

void CtrlOfertaLaboral::asignarCargo(float sueldo) {
	FirmaContrato * fir = new FirmaContrato(sueldo);
	ManejadorOfertaLaboral * mol = ManejadorOfertaLaboral::getInstance();
	OfertaLaboral * of = mol->asignarCargo(fir, this->numExp);
	ManejadorBedelia * mb = ManejadorBedelia::getInstance();
	Estudiante * e = mb->asignarCargo(fir, this->cedula);
	fir->setEstudiante(e);
}

bool CtrlOfertaLaboral::agendarEntrevista(Date* fecha) {
}

void CtrlOfertaLaboral::crearEntrevista() {
}

set<DTEmpresa*> * CtrlOfertaLaboral::listarEmpresas() {
	set<DTEmpresa*> * setOut = new set<DTEmpresa*>;
	map<string, Empresa*>::iterator it;
	for (it = Empresas->begin() ; it != Empresas->end() ; it++) {
		DTEmpresa * dt = (*it).second->crearDT();
		setOut->insert(dt);
	};
	return setOut;
}

bool CtrlOfertaLaboral::seleccionarEmpresa(string rut) {
	this->rut = rut;
	map<string,Empresa*>::iterator it;
	it=this->Empresas->find(rut);
	return (it != this->Empresas->end());
}

set<DTSucursal*>* CtrlOfertaLaboral::listarSucursales() {
	map<string, Empresa*>::iterator it = Empresas->find(rut);
	if (it != Empresas->end()) {
		return (*it).second->listarSucursales();
	}
	return NULL;
}

bool CtrlOfertaLaboral::seleccionarSucursal(string idSuc) {
	this->idSuc = idSuc;
	map<string, Empresa*>::iterator it = Empresas->find(rut);
	if (it != Empresas->end()) {
		Empresa * emp = (*it).second;
		return (emp->seleccionarSucursal(idSuc));
	}
	return false;
}

set<DTSeccion*>* CtrlOfertaLaboral::listarSecciones() {
	map<string, Empresa*>::iterator it = Empresas->find(rut);
	if (it != Empresas->end()) {
		Empresa * emp = (*it).second;
		return emp->listarSecciones(idSuc);
	}
	return NULL;
}

bool CtrlOfertaLaboral::seleccionarSeccion(string idSec) {
	this->idSec = idSec;
	map<string, Empresa*>::iterator it = Empresas->find(rut);
	if (it != Empresas->end()) {
		Empresa * emp = (*it).second;
		return emp->seleccionarSeccion(idSuc, idSec);
	}
	return false;
}

bool CtrlOfertaLaboral::chequearExpedienteDisponible(int numExp) {

}

bool CtrlOfertaLaboral::chequearAsignaturas(DataOferta* dtO) {
}

bool CtrlOfertaLaboral::chequearCandidatos() {
}

void CtrlOfertaLaboral::actualizarRequerimientos(int criterio) {
	ManejadorBedelia * mb = ManejadorBedelia::getInstance();
	DataOferta * dtNuevo = new DataOferta(
			dtO->getNumeroDeExpediente(),
			dtO->getTitulo(),
			dtO->getDescripcion(),
			dtO->getHorasSemanales(),
			dtO->getSueldoMin(),
			dtO->getSueldoMax(),
			dtO->getComienzoLlamado(),
			dtO->getFinLlamado(),
			dtO->getPuestosDisponibles(),
			mb->actualizarRequerimientos(criterio, dtO->getAsignaturasRequeridas()));
	delete dtO;
	dtO = dtNuevo;
}

void CtrlOfertaLaboral::confirmarCreacionOferta() {
	map<string, Empresa*>::iterator it = Empresas->find(rut);
	if (it != Empresas->end()) {
		OfertaLaboral * o = (*it).second->crearOferta(dtO, idSuc, idSec);
		ManejadorOfertaLaboral * mol = ManejadorOfertaLaboral::getInstance();
		mol->agregarOfertaLaboral(o);
		ManejadorBedelia * mb = ManejadorBedelia::getInstance();
		mb->agregarAsignaturas(o, dtO->getAsignaturasRequeridas());
		mb->notificarObservers(o, dtO->getAsignaturasRequeridas());
	}
}

void CtrlOfertaLaboral::addEmpresa(string RUT, string name) {
	Empresa * e = new Empresa(RUT, name);
	Empresas->insert(std::pair<string, Empresa*>(RUT, e));
}

void CtrlOfertaLaboral::addSucursal(string RUT, string idSuc, int tel,
		string ubic) {
	map<string, Empresa*>::iterator it = Empresas->find(RUT);
	if (it != Empresas->end()) {
		Empresa * emp = (*it).second;
		Sucursal * suc = new Sucursal(idSuc, tel, ubic, emp);
		emp->agregarSucursal(idSuc, suc);
	} else throw std::invalid_argument("Esa empresa no existe.\n");

}

void CtrlOfertaLaboral::addSeccion(string RUT, string idSuc, string idSec,
		int interno) {
	map<string, Empresa*>::iterator it = Empresas->find(RUT);
		if (it != Empresas->end()) {
			Empresa * emp = (*it).second;
			emp->agregarSeccion(idSuc, interno, idSec);
		} else throw std::invalid_argument("Esa empresa no existe.\n");
}

void CtrlOfertaLaboral::setRUT(string RUT) {
}

void CtrlOfertaLaboral::setIdSuc(string idSuc) {
	this->idSuc = idSuc;
}

void CtrlOfertaLaboral::setIdSec(string idSec) {
	this->idSec = idSec;
}

void CtrlOfertaLaboral::setNumExp(int Exp) {
	numExp = Exp;
}

void CtrlOfertaLaboral::setDataOferta(DataOferta * dtOL) {
	dtO = dtOL;
}
