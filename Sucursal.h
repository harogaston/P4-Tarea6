/*
 * Sucursal.h
 *
 *  Created on: Jun 7, 2015
 *      Author: marccio
 */

#ifndef SUCURSAL_H_
#define SUCURSAL_H_

// STL
#include <string>
#include <set>
#include <map>

// DataTypes
#include "DTSeccion.h"
#include "DTSucursal.h"
#include "DataOferta.h"

// Clases
class Seccion;
class Empresa;

using namespace std;

class Sucursal {
private:
	string nombre;
	int telefono;
	string direccion;
	Empresa * empresa;
	map<string, Seccion*>* secciones;

public:
	Sucursal(string nombre,
			int telefono,
			string direccion,
			Empresa * empresa );

	// getters
	string getNombre();
	int getTelefono();
	string getDireccion();

	//operaciones
	string getNombreEmpresa();
	DTAplicacion* getDatosSucursal();
	DTSucursal * crearDT();
	set<DTSeccion*> * listarSecciones();
	bool seleccionarSeccion(string idSec);
	OfertaLaboral * crearOferta(DataOferta * dataOferta, string idSec);

	//auxiliares
	void agregarSeccion(string idSec, Seccion* s);

};

#include "Empresa.h"
#include "Seccion.h"

#endif /* SUCURSAL_H_ */
