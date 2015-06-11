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
	int RUT;
	string nombre;
public:
	DTEmpresa(int rut, string nombre);
	string getNombre();
	int getRUT();
	~DTEmpresa();
};

#endif /* DTEMPRESA_H_ */
