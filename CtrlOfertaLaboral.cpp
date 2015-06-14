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
		instancia = new CtrlOfertaLaboral;
	return instancia;
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
		string Descripcion, int Horas_Semanales, float Sueldo_Min,
		float Sueldo_Max, Date* Comienzo_Llamado, Date* Fin_Llamado,
		int Puestos_Disponibles) {
}

void CtrlOfertaLaboral::addEmpresa(int RUT, string name) {
	Empresa * e = new Empresa(RUT, name);
	this->Empresas->insert(pair<int, Empresa*>(RUT, e));
}

void CtrlOfertaLaboral::addSucursal(int RUT, string idSuc, int tel,
		string ubic) {
	map<int, Empresa*>::iterator it = Empresas->find(RUT);
	if (it != Empresas->end()) {
		Empresa * emp = (*it).second;
		Sucursal * suc = new Sucursal(idSuc, tel, ubic, emp);
		emp->agregarSucursal(idSuc, suc);
	} else throw std::invalid_argument("Esa empresa no existe.\n");

}

void CtrlOfertaLaboral::addSeccion(int RUT, string idSuc, string idSec,
		int interno) {
	map<int, Empresa*>::iterator it = Empresas->find(RUT);
		if (it != Empresas->end()) {
			Empresa * emp = (*it).second;
			emp->agregarSeccion(idSuc, interno, idSec);
		} else throw std::invalid_argument("Esa empresa no existe.\n");
}

void CtrlOfertaLaboral::setRUT(int RUT) {
}

void CtrlOfertaLaboral::setIdSuc(string idSuc) {
}

void CtrlOfertaLaboral::setIdSec(string idSec) {
}

void CtrlOfertaLaboral::setNumExp(int Exp) {
}

void CtrlOfertaLaboral::setDataOferta(DataOferta dtOL) {
}
