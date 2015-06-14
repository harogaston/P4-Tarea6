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
 * Archivo: Sucursal.h
 *******************************************************************************/

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
#include "DTAplicacion.h"

// Clases
class Seccion;
class Empresa;
class OfertaLaboral;

using namespace std;

class Sucursal {
private:
	string nombre;
	int telefono;
	string direccion;

	Empresa * empresa;
	map<string, Seccion*> * secciones;

public:
	Sucursal(string nombre,
			int telefono,
			string direccion,
			Empresa * empresa);
	~Sucursal();
	// getters
	string getNombre();
	int getTelefono();
	string getDireccion();

	// operaciones
	string getNombreEmpresa();
	DTAplicacion* getDatosSucursal();
	DTSucursal* crearDT();
	set<DTSeccion*>* listarSecciones();
	bool seleccionarSeccion(string idSec);
	OfertaLaboral* crearOferta(DataOferta * dtO, string idSec);

	// main
	void agregarSeccion(string idSec, Seccion* s);

};

#include "Empresa.h"
#include "Seccion.h"
#include "OfertaLaboral.h"

#endif /* SUCURSAL_H_ */
