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
	int telefono;
	string direccion;
public:
	DTSucursal(string nombre, int telefono, string direccion);
	~DTSucursal();
	string getDireccion();
	string getNombre();
	int getTelefono();
};

#endif /* DTSUCURSAL_H_ */
