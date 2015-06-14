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
	string idSuc;
	int telefono;
	string direccion;

public:
	DTSucursal(string idSuc, int telefono, string direccion);
	~DTSucursal();

	string getIdSuc();
	int getTelefono();
	string getDireccion();
};

#endif /* DTSUCURSAL_H_ */
