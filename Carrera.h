/*
 * Carrera.h
 *
 *  Created on: Jun 2, 2015
 *      Author: Sofia
 */

#ifndef CARRERA_H_
#define CARRERA_H_

// STL
#include <map>
#include <string>
#include <iterator>

// DataTypes
#include "DTCarrera.h"

// Clases
#include "Asignatura.h"

using namespace std;

class Carrera {
private:
	string codigo;
	string nombre;
	map<string, Asignatura*> * asignaturas;

public:
	Carrera(string codigo, string nombre);
	~Carrera();

	//getters
	string getCodigo();
	string getNombre();

	//operaciones
	DTCarrera * crearDT();
	bool asignaturaEnCarrera(string idAs);

	//auxiliares
	void addAsignatura(Asignatura * a);
};

#endif /* CARRERA_H_ */
