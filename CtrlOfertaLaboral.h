/*
 * CtrlOfertaLaboral.h
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

class CtrlOfertaLaboral {
	private: 
	 //Colecciones que almacena
		map<int, *Empresa> Empresas;
	// Atributos que recuerda
		int RUT, numExp;
		string idSuc, idSec, ci; 
		DataOferta dtO;
		Date : d;
		set(DTEstudiante) inscriptos;
		CtrlOfertaLaboral instance;
	public:	 
		static CtrlOfertaLaboral * getInstance();
		set<DTEmpresa> listarEmpresas();
		bool seleccionarEmpresa(int RUT);
		set<DTSucursal> listarSucursales();
		bool seleccionarSucursal(string idSuc);
		set<DTSeccion> listarSecciones();
		bool seleccionarSeccion(string idSec);
		bool chequearExpedienteDisponible(int);
		bool chequearAsignaturas(DataOferta);
		void confirmarCreacionOferta();
		set<DTOferta> obtenerOfertasTodas();
		bool seleccionarOferta(int numExp);
		void darDeBaja();
		set<DTOferta> listarOfertasFinalizadas();
		bool seleccionarOfertaFinalizada(int numExp);
		set<DTEstudiante> listarInscriptos();
		bool seleccionarEstudiante(string ci);
		bool agendarEntrevista(Date d);
		void crearEntrevista();
			
		void addEmpresa(int RUT, string name);
		void addSucursal(int RUT, string idSuc, int tel, string ubic);
		void addSeccion(int RUT, string idSuc, string idSec, int interno);
		void setRUT(int RUT);
		void setIdSuc(string idSuc);
		void setIdSec(string idSec);
		void setNumExp (int Exp);
		void setDataOferta(DataOferta dtOL);
}
