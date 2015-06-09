/*
 * CtrlOfertasLaborales.h
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

using namespace std;

class CtrlOfertasLaborales {
	private: 
	 //Colecciones que almacena
		map<int, *Empresa> Empresas;
	// Atributos que recuerda
		int RUT, numExp;
		string idSuc, idSec, ci; 
		DataOferta dtO;
		Date : d;
		set(DTEstudiante) inscriptos;
		CtrlOfertasLaborales instance;
	public:	 
		static CtrlOfertasLaborales * getInstance();
		set<DTEmpresa> listarEmpresas();
		bool seleccionarEmpresa(integer RUT);
		set<DTSucursal> listarSucursales();
		bool seleccionarSucursal(string idSuc);
		set<DTSeccion> listarSecciones();
		bool seleccionarSeccion(string idSec);
		bool chequearOfertaLaboral(DataOferta dtO);
		void confirmarCreacionOferta();
		set<DTOferta> obtenerOfertasTodas();
		bool seleccionarOferta(integer numExp);
		void darDeBaja();
		set<DTOferta> listarOfertasFinalizadas();
		bool seleccionarOfertaFinalizada(integer numExp);
		set<DTEstudiante.h> listarInscriptos();
		bool seleccionarEstudiante(string ci);
		bool agendarEntrevista(Date d);
		void crearEntrevista();
			
		void addEmpresa(integer RUT, string name);
		void addSucursal(integer RUT, string idSuc, integer tel, string ubic);
		void addSeccion(integer RUT, string idSuc, string idSec, integer interno);
		void setRUT(integer RUT);
		void setIdSuc(string idSuc);
		void setIdSec(string idSec);
		void setNumExp (int Exp);
		void setDataOferta(DataOferta dtOL);
}