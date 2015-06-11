/*
 * CtrlOfertasLaborales.cpp
 *
 *  Created on: Jun 9, 2015
 *      Author: sofi
 */

#include <iostream>
#include <map>
#include <set>
#include <string>

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

class CtrlOfertasLaborales {
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
		
	CtrlOfertasLaborales * ctrlOL::instance = NULL;
	CtrlOfertasLaborales::ctrlOL(){
		
	}
	CtrlOfertasLaborales * ctrlOL::getInstance(){
		if (instance==NULL)
			instance= new CtrlOfertasLaborales();
		return instance;
	}
	set<DTEmpresa> CtrlOfertasLaborales::listarEmpresas() {
		
	};
	bool CtrlOfertasLaborales::seleccionarEmpresa(integer RUT){
		
	};
	set<DTSucursal> CtrlOfertasLaborales::listarSucursales(){
		
	};
	bool CtrlOfertasLaborales::seleccionarSucursal(string idSuc){
		
	};
	set<DTSeccion> CtrlOfertasLaborales::listarSecciones(){
		
	};
	bool CtrlOfertasLaborales::seleccionarSeccion(string idSec){
		
	};
	bool chequearExpedienteDisponible(int) {
		
	};
	bool chequearAsignaturas(DataOferta) {
		
	};
		
	void CtrlOfertasLaborales::confirmarCreacionOferta(){
		
	};
	set<DTOferta> CtrlOfertasLaborales::obtenerOfertasTodas(){
		
	};
	bool CtrlOfertasLaborales::seleccionarOferta(integer numExp) {
		
	}; 
	void CtrlOfertasLaborales::darDeBaja() {
		
	};
	set<DTOferta> CtrlOfertasLaborales::listarOfertasFinalizadas() {
		
	};
	bool CtrlOfertasLaborales::seleccionarOfertaFinalizada(integer numExp) {
		
	};
	set<DTEstudiante.h> CtrlOfertasLaborales::listarInscriptos() {
		
	};
	bool CtrlOfertasLaborales::seleccionarEstudiante(string ci) {
		
	};
	bool CtrlOfertasLaborales::agendarEntrevista(Date d) {
		
	};
	void CtrlOfertasLaborales::crearEntrevista() {
		
	};
		
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
	void CtrlOfertasLaborales::setRUT(integer RUT) {
		this->RUT = RUT;
	};
	void CtrlOfertasLaborales::setIdSuc(string idSuc) {
		this->idSuc = idSuc;
	};
	void CtrlOfertasLaborales::setIdSec(string idSec) {
		this->idSec = idSec;
	};
	void CtrlOfertasLaborales::setNumExp (int Exp) {
		this->numExp = Exp;
	};
	void CtrlOfertasLaborales::setDataOferta(DataOferta dtOL) {
		this->dtO = dtOL;
	};
}  