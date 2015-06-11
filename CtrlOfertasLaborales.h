/*
 * CtrlOfertasLaborales.h
 *
 *  Created on: Jun 11, 2015
 *      Author: marccio
 */

#ifndef CTRLOFERTASLABORALES_H_
#define CTRLOFERTASLABORALES_H_

#include "DataOferta.h"
#include "DTEmpresa.h"
#include "DTEstudiante.h"
#include "DTOferta.h"
#include "DTSeccion.h"
#include "DTSucursal.h"
#include "Empresa.h"

class CtrlOfertasLaborales {
private:
	//Colecciones que almacena
	map<int, Empresa*> * empresas;
	// Atributos que recuerda
	int RUT, numExp;
	string idSuc, idSec, ci;
	DataOferta * dtO;
	Date * d;
	set<DTEstudiante*> * inscriptos;
	CtrlOfertasLaborales * instance;
public:
	CtrlOfertasLaborales();
	~CtrlOfertasLaborales();
	set<DTEmpresa*> * listarEmpresas();
	bool seleccionarEmpresa(int RUT);
	set<DTSucursal*> * listarSucursales();
	bool seleccionarSucursal(string idSuc);
	set<DTSeccion*> * listarSecciones();
	bool seleccionarSeccion(string idSec);
	bool chequearOfertaLaboral(DataOferta * dtO);
	void confirmarCreacionOferta();
	set<DTOferta*> * obtenerOfertasTodas();
	bool seleccionarOferta(int numExp);
	void darDeBaja();
	set<DTOferta*> * listarOfertasFinalizadas();
	bool seleccionarOfertaFinalizada(int numExp);
	set<DTEstudiante*> * listarInscriptos();
	bool seleccionarEstudiante(string ci);
	bool agendarEntrevista(Date * d);
	void crearEntrevista();

	void addEmpresa(int rut, string nombre);
	void addSucursal(int rutEmpresa, string nombreSuc, int telefono, string direccionSuc);
	void addSeccion(int rutEmpresa, string nombreSucursal, string nombreSeccion, int interno);
	void setRUT(int RUT);
	void setIdSuc(string idSuc);
	void setIdSec(string idSec);
	void setNumExp (int Exp);
	void setDataOferta(DataOferta * dtOL);
};

#endif /* CTRLOFERTASLABORALES_H_ */
