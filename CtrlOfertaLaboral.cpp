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
	asignaturas = NULL;
	inscriptos = NULL;
	dtO = NULL;
	Empresas = NULL;
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
}

bool CtrlOfertaLaboral::seleccionarOfertaFinalizada(int numExp) {
}

set<DTEstudiante*>* CtrlOfertaLaboral::listarInscriptos() {
}

bool CtrlOfertaLaboral::seleccionarEstudiante(string cedula) {
}

void CtrlOfertaLaboral::asignarCargo(float sueldo) {
}

bool CtrlOfertaLaboral::agendarEntrevista(Date* fecha) {
}

void CtrlOfertaLaboral::crearEntrevista() {
}

set<DTEmpresa*>* CtrlOfertaLaboral::listarEmpresas() {
}

bool CtrlOfertaLaboral::seleccionarEmpresa(string rut) {
}

set<DTSucursal*>* CtrlOfertaLaboral::listarSucursales() {
}

bool CtrlOfertaLaboral::seleccionarSucursal(string idSuc) {
}

set<DTSeccion*>* CtrlOfertaLaboral::listarSecciones() {
}

bool CtrlOfertaLaboral::seleccionarSeccion(string idSec) {
}

bool CtrlOfertaLaboral::chequearExpedienteDisponible(int numExp) {
}

bool CtrlOfertaLaboral::chequearAsignaturas(DataOferta* dtO) {
}

bool CtrlOfertaLaboral::chequearCandidatos() {
}

set<set<string> *>* CtrlOfertaLaboral::listarEstrategias() {
}

void CtrlOfertaLaboral::actualizarRequerimientos(int criterio) {
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
	this->Empresas->insert(pair<string, Empresa*>(RUT, e));
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
