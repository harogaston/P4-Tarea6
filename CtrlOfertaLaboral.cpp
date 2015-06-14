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
