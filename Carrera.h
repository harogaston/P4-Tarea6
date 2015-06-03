/*
 * Carrera.h
 *
 *  Created on: Jun 2, 2015
 *      Author: Sofia
 */

#ifndef CARRERA_H_
#define CARRERA_H_


#include "DTCarrera.h"

using namespace std;

class Carrera {
private:
	string codigo;
	string nombre;
public:
	Carrera(string codigo, string nombre);
	virtual ~Carrera();
	DTCarrera crearDT();
};

#endif /* CARRERA_H_ */