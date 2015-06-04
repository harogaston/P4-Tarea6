/*
 * DTCarrera.h
 *
 *  Created on: Jun 2, 2015
 *      Author: marccio
 */

#ifndef DTCARRERA_H_
#define DTCARRERA_H_

#include <string>

using namespace std;

class DTCarrera {
private:
	string codigo;
	string nombre;
public:
	DTCarrera();
	DTCarrera(string codigo, string nombre);
	~DTCarrera();
	string getCodigo();
	string getNombre();
};

#endif /* DTCARRERA_H_ */
