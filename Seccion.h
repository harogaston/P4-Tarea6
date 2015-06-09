/*
 * Seccion.h
 *
 *  Created on: Jun 7, 2015
 *      Author: marccio
 */

#ifndef SECCION_H_
#define SECCION_H_

#include <string>
#include "DataOferta.h"
#include "OfertaLaboral.h"
#include "Sucursal.h"

using namespace std;

class Seccion {
private:
	string nombre;
	int interno;
	set<OfertaLaboral*> * ofertas;
	Sucursal * sucursal;
public:
	Seccion(string nombre,
			int interno,
			set<OfertaLaboral*> * ofertas,
			Sucursal * sucursal);
	~Seccion();
	string getNombre();
	int getInterno();
	OfertaLaboral * crearOferta(DataOferta * dataOferta);
	DTSeccion * crearDT();
	DTAplicacion * getDatosSeccion();
	string getUbicacion();
	string getNombreEmpresa();
};

#endif /* SECCION_H_ */
