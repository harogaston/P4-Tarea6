/*
 * Empresa.h
 *
 *  Created on: Jun 6, 2015
 *      Author: marccio
 */

#ifndef EMPRESA_H_
#define EMPRESA_H_

#include <map>
#include <set>
#include <string>

#include "DTSeccion.h"
#include "DTSucursal.h"
#include "Sucursal.h"
#include "DTEmpresa.h"


class DataOferta;
class DTAplicacion;
class DTEmpresa;
class OfertaLaboral;

using namespace std;

class Empresa {
private:
	int rut;
	string nombre;
	map<string, Sucursal*> * sucursales;
public:
	Empresa(int rut, string nombre, map<string, Sucursal*> * sucursales);
	~Empresa();
	DTEmpresa * crearDT();
	set<DTSucursal*> * listarSucursales();
	bool seleccionarSucursal(string idSuc);
	set<DTSeccion*>* listarSecciones(string idSec);
	bool seleccionarSeccion(string idSuc, string idSec);
	OfertaLaboral * crearOferta(string idSuc, string idSec, DataOferta* dtO);
	DTAplicacion * getDatosEmpresa();
	int getRut();
	string getNombre();
};

#endif /* EMPRESA_H_ */
