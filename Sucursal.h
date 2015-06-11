/*
 * Sucursal.h
 *
 *  Created on: Jun 7, 2015
 *      Author: marccio
 */

#ifndef SUCURSAL_H_
#define SUCURSAL_H_

#include <string>
#include <set>
#include <map>

#include "DTSeccion.h"
#include "DTSucursal.h"
#include "DataOferta.h"
#include "OfertaLaboral.h"
#include "Seccion.h"

class Empresa;

using namespace std;

class Sucursal {
private:
	string nombre;
	string telefono;
	string direccion;
	Empresa * empresa;
	map<string, Seccion*> * secciones;
public:
	Sucursal(string nombre,
			string telefono,
			string direccion,
			Empresa * empresa );			
	~Sucursal();
	void agregarSeccion(string idSec, Seccion* s);
	DTSucursal * crearDT();
	set<DTSeccion*> * listarSecciones();
	bool seleccionarSeccion(string idSec);
	OfertaLaboral * crearOferta(string idSec, DataOferta * dataOferta);
	DTAplicacion * getDatosSucursal();
	string getNombreEmpresa();
	string getNombre();
	string getDireccion();
	string getTelefono();
};

#include "Empresa.h"

#endif /* SUCURSAL_H_ */
