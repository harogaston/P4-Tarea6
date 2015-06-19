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
 * Archivo: ICtrlOfertaLaboral.h
 *******************************************************************************/

#ifndef ICTRLOFERTALABORAL_H_
#define ICTRLOFERTALABORAL_H_

//STL
#include <set>
#include <string>

//Datatypes
#include "DTEmpresa.h"
#include "DTAsignatura.h"
#include "DTSucursal.h"
#include "DTOferta.h"
#include "DTSeccion.h"
#include "DataOferta.h"

using namespace std;

class ICtrlOfertaLaboral {
public:
	virtual ~ICtrlOfertaLaboral() {};

	// operaciones
	virtual set<DTOferta*> * obtenerOfertasTodas()= 0;
	virtual bool seleccionarOferta(int numExp)= 0;
	virtual void darDeBaja()= 0;
	virtual set<DTOferta*> * listarOfertasFinalizadas()= 0;
	virtual bool seleccionarOfertaFinalizada(int numExp)= 0;
	virtual set<DTEstudiante*> * listarInscriptos()= 0;
	virtual bool seleccionarEstudiante(string cedula)= 0;
	virtual void asignarCargo(float sueldo)= 0;
	virtual bool agendarEntrevista(Date * fecha)= 0;
	virtual void crearEntrevista()= 0;
	virtual set<DTEmpresa*> * listarEmpresas()= 0;
	virtual bool seleccionarEmpresa(string rut)= 0;
	virtual set<DTSucursal*> * listarSucursales()= 0;
	virtual bool seleccionarSucursal(string idSuc)= 0;
	virtual set<DTSeccion*> * listarSecciones()= 0;
	virtual bool seleccionarSeccion(string idSec)= 0;
	virtual bool chequearExpedienteDisponible(int numExp)= 0;
	virtual bool chequearAsignaturas(DataOferta* dtO)= 0;
	virtual bool chequearCandidatos()= 0;
	virtual void actualizarRequerimientos(int criterio)= 0;
	virtual void confirmarCreacionOferta()= 0;

	// main
	virtual void addEmpresa(string RUT, string name)= 0;
	virtual void addSucursal(string RUT, string idSuc, int tel, string ubic)= 0;
	virtual void addSeccion(string RUT, string idSuc, string idSec, int interno)= 0;
	virtual void setRUT(string RUT)= 0;
	virtual void setIdSuc(string idSuc)= 0;
	virtual void setIdSec(string idSec)= 0;
	virtual void setNumExp (int Exp)= 0;
	virtual void setDataOferta(DataOferta * dtOL)= 0;
	virtual set<DTAsignatura*>* listarAsignaturas()= 0;
};


#endif /* ICTRLOFERTALABORAL_H_ */
