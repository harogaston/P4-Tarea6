/*
 * CtrlOfertaLaboral.h
 *
 *  Created on: Jun 9, 2015
 *      Author: sofi
 */

#ifndef CTRLOFERTALABORAL_H_
#define CTRLOFERTALABORAL_H_

// STL
#include <map>
#include <set>
#include <string>

// DataTypes
#include "DataOferta.h"
#include "Date.h"
#include "DTEmpresa.h"
#include "DTEstudiante.h"
#include "DTOferta.h"
#include "DTSeccion.h"
#include "DTSucursal.h"

// Clases
#include "Empresa.h"
#include "Seccion.h"
#include "Sucursal.h"
#include "ICtrlOfertaLaboral.h"

using namespace std;

class CtrlOfertaLaboral : public ICtrlOfertaLaboral {
private:
	static CtrlOfertaLaboral * instance;
	CtrlOfertaLaboral();
	int numExp;
	string cedula;
	Date * fecha;
	int rut;
	string idSuc;
	string idSec;
	DataOferta* dtO;
	CtrlOfertaLaboral();
	map<int, Empresa*> * Empresas;
	set<DTEstudiante*> * inscriptos;

public:
	static CtrlOfertaLaboral * getInstance();

	// operaciones
	set<DTOferta*> * obtenerOfertasTodas();
	bool seleccionarOferta(int numExp);
	void darDeBaja();
	set<DTOferta*> * listarOfertasFinalizadas();
	bool seleccionarOfertaFinalizada(int numExp);
	set<DTEstudiante*> * listarInscriptos();
	bool seleccionarEstudiante(string cedula);
	void asignarCargo(float sueldo);
	bool agendarEntrevista(Date * fecha);
	void crearEntrevista();
	set<DTEmpresa*> * listarEmpresas();
	bool seleccionarEmpresa(int rut);
	set<DTSucursal*> * listarSucursales();
	bool seleccionarSucursal(string idSuc);
	set<DTSeccion*> * listarSecciones();
	bool seleccionarSeccion(string idSec);
	bool chequearExpedienteDisponible(int numExp);
	bool chequearAsignaturas(DataOferta* dtO);
	bool chequearCandidatos();
	set<set<string>*> * listarEstrategias();
	void actualizarRequerimientos(int criterio);
	void confirmarCreacionOferta();

	// main
	void addEmpresa(int RUT, string name);
	void addSucursal(int RUT, string idSuc, int tel, string ubic);
	void addSeccion(int RUT, string idSuc, string idSec, int interno);
	void setRUT(int RUT);
	void setIdSuc(string idSuc);
	void setIdSec(string idSec);
	void setNumExp (int Exp);
	void setDataOferta(DataOferta dtOL);
};

#endif /* CTRLOFERTALABORAL_H_ */
