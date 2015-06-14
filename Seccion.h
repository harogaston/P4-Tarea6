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
 * Archivo: Seccion.h
 *******************************************************************************/

#ifndef SECCION_H_
#define SECCION_H_

// STL
#include <string>

// DataTypes
#include "DataOferta.h"
#include "DTSeccion.h"

// Clases
#include "Sucursal.h"
class OfertaLaboral;

using namespace std;

class Seccion {
private:
	string nombre;
	int interno;

	map<int, OfertaLaboral*> * ofertas;
	Sucursal * sucursal;

public:
	Seccion(string nombre, int interno, Sucursal * sucursal);
	~Seccion();

	// getters
	string getNombre();
	int getInterno();

	// operaciones
	string getUbicacion();
	string getNombreEmpresa();
	DTAplicacion * getDatosSeccion();
	void cancelarOferta(OfertaLaboral * oferta);
	DTSeccion * crearDT();
	OfertaLaboral * crearOferta(DataOferta * dtO);
};

#include "OfertaLaboral.h"

#endif /* SECCION_H_ */
