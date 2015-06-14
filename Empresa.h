/*
 * Empresa.h
 *
 *  Created on: Jun 6, 2015
 *      Author: marccio
 */

#ifndef EMPRESA_H_
#define EMPRESA_H_

// STL
#include <map>
#include <set>
#include <string>

// DataTypes
#include "DTSeccion.h"
#include "DTSucursal.h"
#include "DTEmpresa.h"
#include "DataOferta.h"
#include "DTAplicacion.h"

// Clases
#include "Sucursal.h"
#include "OfertaLaboral.h"

using namespace std;

class Empresa {
private:
	int rut;
	string nombre;

	map<string, Sucursal*>* sucursales;

public:
	Empresa(int rut, string nombre);
	~Empresa();

	// getters
	int getRut();
	string getNombre();

	// operaciones
	DTEmpresa* crearDT();
	set<DTSucursal*>* listarSucursales();
	bool seleccionarSucursal(string idSuc);
	set<DTSeccion*>* listarSecciones(string idSuc);
	bool seleccionarSeccion(string idSuc, string idSec);
	OfertaLaboral* crearOferta(DataOferta * dtO, string idSuc, string idSec);

	// operaciones auxiliares
	void agregarSucursal(string idSuc, Sucursal* s);
};

#endif /* EMPRESA_H_ */
