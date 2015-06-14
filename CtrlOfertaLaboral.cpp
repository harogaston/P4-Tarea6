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

set<DTEmpresa*> * CtrlOfertaLaboral::listarEmpresas() {
	return NULL;
};
bool CtrlOfertaLaboral::seleccionarEmpresa(int RUT){
	return 0;
};
set<DTSucursal*> * CtrlOfertaLaboral::listarSucursales(){
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
set<DTOferta*> * CtrlOfertaLaboral::listarOfertasFinalizadas() {
	return NULL;
};
bool CtrlOfertaLaboral::seleccionarOfertaFinalizada(int numExp) {
	return 0;
};

set<DTEstudiante*> * CtrlOfertaLaboral::listarInscriptos() {
	return NULL;
};
bool CtrlOfertaLaboral::seleccionarEstudiante(string ci) {
	return 0;
};
bool CtrlOfertaLaboral::agendarEntrevista(Date * d) {
 return 0;
};
void CtrlOfertaLaboral::crearEntrevista() {

};

void CtrlOfertaLaboral::addEmpresa(int RUT, string name) {
	Empresa * e = new Empresa(RUT, name);
	this->Empresas->insert(pair<int, Empresa*>(RUT, e));
};
void CtrlOfertaLaboral::addSucursal(int RUT, string idSuc, int tel, string ubic) {
	Sucursal * suc = new Sucursal(idSuc, tel, ubic, this->Empresas[RUT]);
	Empresa * emp = this->Empresas[RUT];
	emp->agregarSucursal(idSuc, suc);
};
void CtrlOfertaLaboral::addSeccion(int RUT, string idSuc, string idSec, int interno) {
	Empresa * emp = this->Empresas[RUT];
	Sucursal * suc = emp->sucursales[idSuc];
	Seccion * sec = new Seccion(idSec, interno, suc);
	suc->agregarSeccion(idSec, sec);
};
void CtrlOfertaLaboral::setRUT(int RUT) {
	this->rut = RUT;
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
