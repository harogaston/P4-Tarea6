/*
 * Carrera.h
 *
 *  Created on: Jun 2, 2015
 *      Author: Sofia
 */

#ifndef CARRERA_H_
#define CARRERA_H_

#include <map>
#include <string>

#include "DTCarrera.h"
#include "Asignatura.h"

using namespace std;

class Carrera {
private:
	string codigo;
	string nombre;
	map<string, Asignatura*> * asignaturas;
public:
	Carrera(string codigo, string nombre, map<string, Asignatura*> * asignaturas);
	~Carrera();
	DTCarrera * crearDT();
	bool asignaturaEnCarrera(string idAs);
};

#endif /* CARRERA_H_ */
