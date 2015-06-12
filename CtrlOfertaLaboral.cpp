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
#include "DataOferta.h"
#include "Date.h"
#include "DTEmpresa.h"
#include "DTEstudiante.h"
#include "DTOferta.h"
#include "DTSeccion.h"
#include "DTSucursal.h"
#include "Empresa.h"
#include "Seccion.h"
#include "Sucursal.h"

	/*
	 //Colecciones que almacena
		map<int, Empresa*> Empresas;
	// Atributos que recuerda
		int RUT, numExp;
		string idSuc, idSec, ci; 
		DataOferta dtO;
		Date : d;
		set(DTEstudiante) inscriptos;
		CtrlOfertaLaboral instance; */
		
	ctrlOfertaLaboral * ctrlOL::instance = NULL;
	ctrlOfertaLaboral::ctrlOL(){
		
	}
	ctrlOfertaLaboral * ctrlOL::getInstance(){
		if (instance==NULL)
			instance= new CtrlOfertaLaboral();
		return instance;
	}
	set<DTEmpresa> CtrlOfertaLaboral::listarEmpresas() {
		
	};
	bool CtrlOfertaLaboral::seleccionarEmpresa(int RUT){
		
	};
	set<DTSucursal> CtrlOfertaLaboral::listarSucursales(){
		
	};
	bool CtrlOfertaLaboral::seleccionarSucursal(string idSuc){
		
	};
	set<DTSeccion> CtrlOfertaLaboral::listarSecciones(){
		
	};
	bool CtrlOfertaLaboral::seleccionarSeccion(string idSec){
		
	};
	bool chequearExpedienteDisponible(int) {
		
	};
	bool chequearAsignaturas(DataOferta) {
		
	};
		
	void CtrlOfertaLaboral::confirmarCreacionOferta(){
		
	};
	set<DTOferta> CtrlOfertaLaboral::obtenerOfertasTodas(){
		
	};
	bool CtrlOfertaLaboral::seleccionarOferta(int numExp) {
		
	}; 
	void CtrlOfertaLaboral::darDeBaja() {
		
	};
	set<DTOferta> CtrlOfertaLaboral::listarOfertasFinalizadas() {
		
	};
	bool CtrlOfertaLaboral::seleccionarOfertaFinalizada(int numExp) {
		
	};
	set<DTEstudiante.h> CtrlOfertaLaboral::listarInscriptos() {
		
	};
	bool CtrlOfertaLaboral::seleccionarEstudiante(string ci) {
		
	};
	bool CtrlOfertaLaboral::agendarEntrevista(Date d) {
		
	};
	void CtrlOfertaLaboral::crearEntrevista() {
		
	};
		
	void CtrlOfertaLaboral::addEmpresa(RUT, name) {
		*Empresa emp new Empresa(RUT, name);
		this->Empresas[RUT] = emp;
	};
	void CtrlOfertaLaboral::addSucursal(RUT, idSuc, tel, ubic) {
		*Sucursal suc new Sucursal(idSuc, tel, ubic, this->Empresas[RUT]);
		this->Empresas[RUT]->agregarSucursal(string idSuc, Sucursal* s);
	};
	void CtrlOfertaLaboral::addSeccion(int RUT, string idSuc, string idSec, int interno) {
		*Seccion sec new Seccion(idSec, interno, this->Empresas[RUT]->Sucursales[idSuc]);
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
