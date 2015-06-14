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

CtrlOfertaLaboral * CtrlOfertaLaboral::getInstance(){
	if (instancia == NULL)
		instancia = new CtrlOfertaLaboral();
	return instancia;
}

set<DTEmpresa> CtrlOfertaLaboral::listarEmpresas() {
	return NULL;
};
bool CtrlOfertaLaboral::seleccionarEmpresa(int RUT){
	return 0;
};
set<DTSucursal> * CtrlOfertaLaboral::listarSucursales(){
	return NULL;
};
bool CtrlOfertaLaboral::seleccionarSucursal(string idSuc){
	return 0;
};
set<DTSeccion*> * CtrlOfertaLaboral::listarSecciones(){
	return NULL;
};
bool CtrlOfertaLaboral::seleccionarSeccion(string idSec){
	return 0;
};
bool CtrlOfertaLaboral::chequearExpedienteDisponible(int) {
	return 0;
};
bool CtrlOfertaLaboral::chequearAsignaturas(DataOferta* dtO) {
	return 0;
};
set<set<string>*> * CtrlOfertaLaboral::listarEstrategias(){
	return NULL;
};
void CtrlOfertaLaboral::actualizarRequerimientos(int criterio){

};
void CtrlOfertaLaboral::confirmarCreacionOferta(){

};
set<DTOferta*> * CtrlOfertaLaboral::obtenerOfertasTodas(){
	return NULL;
};
bool CtrlOfertaLaboral::seleccionarOferta(int numExp) {
	return NULL;
};
void CtrlOfertaLaboral::darDeBaja() {

};
set<DTOferta> CtrlOfertaLaboral::listarOfertasFinalizadas() {

};
bool CtrlOfertaLaboral::seleccionarOfertaFinalizada(int numExp) {
	return 0;
};

set<DTEstudiante.h> CtrlOfertaLaboral::listarInscriptos() {
	return NULL;
};
bool CtrlOfertaLaboral::seleccionarEstudiante(string ci) {

};
bool CtrlOfertaLaboral::agendarEntrevista(Date d) {

};
void CtrlOfertaLaboral::crearEntrevista() {

};

void CtrlOfertaLaboral::addEmpresa(RUT, name) {
	*Empresa emp = new Empresa(RUT, name);
	this->Empresas[RUT] = emp;
};
void CtrlOfertaLaboral::addSucursal(RUT, idSuc, tel, ubic) {
	*Sucursal suc = new Sucursal(idSuc, tel, ubic, this->Empresas[RUT]);
	this->Empresas[RUT]->agregarSucursal(string idSuc, Sucursal* s);
};
void CtrlOfertaLaboral::addSeccion(int RUT, string idSuc, string idSec, int interno) {
	*Seccion sec = new Seccion(idSec, interno, this->Empresas[RUT]->Sucursales[idSuc]);
	this->Empresas[RUT]->Sucursales[idSuc]->agregarSeccion(string idSec, Seccion* s);
};
void CtrlOfertaLaboral::setRUT(int RUT) {
	this->RUT = RUT;
};
void CtrlOfertaLaboral::setIdSuc(string idSuc) {
	this->idSuc = idSuc;
};
void CtrlOfertaLaboral::setIdSec(string idSec) {
	this->idSec = idSec;
};
void CtrlOfertaLaboral::setNumExp (int Exp) {
	this->numExp = Exp;
};
void CtrlOfertaLaboral::setDataOferta(DataOferta dtOL) {
	this->dtO = dtOL;
};
}
