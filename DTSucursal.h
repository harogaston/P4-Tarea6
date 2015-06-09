/*
 * DTSucursal.h
 *
 *  Created on: Jun 1, 2015
 *      Author: marccio
 */

#ifndef DTSUCURSAL_H_
#define DTSUCURSAL_H_

#include <string>

using namespace std;

class DTSucursal {
private:
	string nombre;
	string telefono;
	string direccion;
public:
	DTSucursal();
	DTSucursal(string nombre, string telefono, string direccion);
	~DTSucursal();
	string getDireccion();
	string getNombre();
	string getTelefono();
};

#endif /* DTSUCURSAL_H_ */
