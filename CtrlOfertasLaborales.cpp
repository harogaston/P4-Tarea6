/*
 * CtrlOfertasLaborales.cpp
 *
 *  Created on: Jun 11, 2015
 *      Author: marccio
 */

#include "CtrlOfertasLaborales.h"

CtrlOfertasLaborales::CtrlOfertasLaborales() {
}

CtrlOfertasLaborales::~CtrlOfertasLaborales() {
}

set<DTEmpresa*>* CtrlOfertasLaborales::listarEmpresas() {
}

bool CtrlOfertasLaborales::seleccionarEmpresa(int RUT) {
}

set<DTSucursal*>* CtrlOfertasLaborales::listarSucursales() {
}

bool CtrlOfertasLaborales::seleccionarSucursal(string idSuc) {
}

set<DTSeccion*>* CtrlOfertasLaborales::listarSecciones() {
}

bool CtrlOfertasLaborales::seleccionarSeccion(string idSec) {
}

bool CtrlOfertasLaborales::chequearOfertaLaboral(DataOferta* dtO) {
}

void CtrlOfertasLaborales::confirmarCreacionOferta() {
}

set<DTOferta*>* CtrlOfertasLaborales::obtenerOfertasTodas() {
}

bool CtrlOfertasLaborales::seleccionarOferta(int numExp) {
}

void CtrlOfertasLaborales::darDeBaja() {
}

set<DTOferta*>* CtrlOfertasLaborales::listarOfertasFinalizadas() {
}

bool CtrlOfertasLaborales::seleccionarOfertaFinalizada(int numExp) {
}

set<DTEstudiante*>* CtrlOfertasLaborales::listarInscriptos() {
}

bool CtrlOfertasLaborales::seleccionarEstudiante(string ci) {
}

bool CtrlOfertasLaborales::agendarEntrevista(Date* d) {
}

void CtrlOfertasLaborales::crearEntrevista() {
}

void CtrlOfertasLaborales::addEmpresa(int rut, string nombre) {
}

void CtrlOfertasLaborales::addSucursal(int rutEmpresa, string nombreSuc,
		string telefono, string direccionSuc) {
}

void CtrlOfertasLaborales::addSeccion(int rutEmpresa, string nombreSucursal,
		string nombreSeccion, string interno) {
}

void CtrlOfertasLaborales::setRUT(int RUT) {
}

void CtrlOfertasLaborales::setIdSuc(string idSuc) {
}

void CtrlOfertasLaborales::setIdSec(string idSec) {
}

void CtrlOfertasLaborales::setNumExp(int Exp) {
}

void CtrlOfertasLaborales::setDataOferta(DataOferta* dtOL) {
}
/*
	 //Colecciones que almacena
		map<int, Empresa*> Empresas;
	// Atributos que recuerda
		int RUT, numExp;
		string idSuc, idSec, ci;
		DataOferta dtO;
		Date : d;
		set(DTEstudiante) inscriptos;
		CtrlOfertasLaborales instance; */


/*
	void CtrlOfertasLaborales::addEmpresa(RUT, name) {
 *Empresa emp new Empresa(RUT, name);
		this->Empresas[RUT] = emp;
	};
	void CtrlOfertasLaborales::addSucursal(RUT, idSuc, tel, ubic) {
 *Sucursal suc new Sucursal(idSuc, tel, ubic, this->Empresas[RUT]);
		this->Empresas[RUT]->agregarSucursal(string idSuc, Sucursal* s);
	};
	void CtrlOfertasLaborales::addSeccion(integer RUT, string idSuc, string idSec, integer interno) {
 *Seccion sec new Seccion(idSec, interno, this->Empresas[RUT]->Sucursales[idSuc]);
		this->Empresas[RUT]->Sucursales[idSuc]->agregarSeccion(string idSec, Seccion* s);
	};
 */


