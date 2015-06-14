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
 * Archivo: Empresa.h
 *******************************************************************************/

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

	// main
	void agregarSucursal(string idSuc, Sucursal* s);
	void agregarSeccion(string idSuc, int interno, string idSec);

};

#endif /* EMPRESA_H_ */
