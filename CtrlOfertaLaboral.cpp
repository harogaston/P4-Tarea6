/*
 * CtrlOfertaLaboral.cpp
 *
 *  Created on: Jun 9, 2015
 *      Author: sofi
 */

#include <iostream>
#include <map>
#include <set>
#include <string>

#include "CtrlOfertaLaboral.h"

CtrlOfertaLaboral * CtrlOfertaLaboral::instancia = NULL;

CtrlOfertaLaboral * CtrlOfertaLaboral::getInstance(){
	if (instancia == NULL)
		instancia = new CtrlOfertaLaboral();
	return instancia;
}

CtrlOfertaLaboral::CtrlOfertaLaboral() {
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

bool CtrlOfertaLaboral::seleccionarEmpresa(int rut) {
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

void CtrlOfertaLaboral::confirmarCreacionOferta(string Titulo,
string Descripcion, int Horas_Semanales, float Sueldo_Min, float Sueldo_Max,
Date* Comienzo_Llamado, Date* Fin_Llamado, int Puestos_Disponibles) {
}

void CtrlOfertaLaboral::addEmpresa(int RUT, string name) {
	*Empresa emp = new Empresa(RUT, name);
	this->Empresas[RUT] = emp;
}
void CtrlOfertaLaboral::addSucursal(int RUT, string idSuc, int tel, string ubic) {
	*Sucursal suc = new Sucursal(idSuc, tel, ubic, this->Empresas[RUT]);
	this->Empresas[RUT]->agregarSucursal(string idSuc, Sucursal* s);
}
void CtrlOfertaLaboral::addSeccion(int RUT, string idSuc, string idSec, int interno) {
	*Seccion sec = new Seccion(idSec, interno, this->Empresas[RUT]->Sucursales[idSuc]);
	this->Empresas[RUT]->Sucursales[idSuc]->agregarSeccion(string idSec, Seccion* s);
}
void CtrlOfertaLaboral::setRUT(int RUT) {
	this->RUT = RUT;
}
void CtrlOfertaLaboral::setIdSuc(string idSuc) {
	this->idSuc = idSuc;
}
void CtrlOfertaLaboral::setIdSec(string idSec) {
	this->idSec = idSec;
}
void CtrlOfertaLaboral::setNumExp (int Exp) {
	this->numExp = Exp;
}
void CtrlOfertaLaboral::setDataOferta(DataOferta dtOL) {
	this->dtO = dtOL;
}

}
