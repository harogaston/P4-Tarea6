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
 * Archivo: CtrlOfertaLaboral.h
 *******************************************************************************/

#ifndef CTRLOFERTALABORAL_H_
#define CTRLOFERTALABORAL_H_

// STL
#include <map>
#include <set>
#include <string>
#include <iostream>

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
#include "FirmaContrato.h"
#include "Seccion.h"
#include "Sucursal.h"
#include "ICtrlOfertaLaboral.h"
#include "ManejadorOfertaLaboral.h"
#include "ManejadorBedelia.h"

using namespace std;

class CtrlOfertaLaboral : public ICtrlOfertaLaboral {
private:
	static CtrlOfertaLaboral * instancia;
	CtrlOfertaLaboral();

	int numExp;
	string cedula;
	Date * fecha;
	string rut;
	string idSuc;
	string idSec;
	set<string> * asignaturas;
	set<DTEstudiante*> * inscriptos;
	DataOferta * dtO;
	map<string, Empresa*> * Empresas;
	set<DTOferta*> * ofertas;

public:
	static CtrlOfertaLaboral * getInstance();
	~CtrlOfertaLaboral();

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
	bool seleccionarEmpresa(string rut);
	set<DTSucursal*> * listarSucursales();
	bool seleccionarSucursal(string idSuc);
	set<DTSeccion*> * listarSecciones();
	bool seleccionarSeccion(string idSec);
	bool chequearExpedienteDisponible(int numExp);
	bool chequearAsignaturas(DataOferta* dtO);
	bool chequearCandidatos();
	void actualizarRequerimientos(int criterio);
	void confirmarCreacionOferta();

	// main
	void addEmpresa(string RUT, string name);
	void addSucursal(string RUT, string idSuc, int tel, string ubic);
	void addSeccion(string RUT, string idSuc, string idSec, int interno);
	void setRUT(string RUT);
	void setIdSuc(string idSuc);
	void setIdSec(string idSec);
	void setNumExp (int Exp);
	void setDataOferta(DataOferta * dtOL);
};

#endif /* CTRLOFERTALABORAL_H_ */
