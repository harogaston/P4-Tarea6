/*
 * DTEmpresa.h
 *
 *  Created on: Jun 1, 2015
 *      Author: marccio
 */

#ifndef DTEMPRESA_H_
#define DTEMPRESA_H_

#include <string>

using namespace std;

class DTEmpresa {
private:
	int rut;
	string nombre;
public:
	DTEmpresa();
	DTEmpresa(int rut, string nombre);
	string getNombre();
	int getRut();
	virtual ~DTEmpresa();
};

#endif /* DTEMPRESA_H_ */
