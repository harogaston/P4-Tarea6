/*******************************************************************************
 * Programación 4 - Laboratorio 6 - Año 2015
 *
 * Profesor: Pablo Milanese
 * Grupo: 17
 * Integrantes: Juan Pablo Copello - jpcopel@gmail.com
 * 			Gastón Haro - harogaston@gmail.com
 * 			Sofia Honty - sofisho@gmail.com
 * 			Marccio Silva - marcciosilva@gmail.com
 *
 * Archivo: Carrera.h
 *******************************************************************************/

#ifndef CARRERA_H_
#define CARRERA_H_

// STL
#include <map>
#include <string>

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

	// getters
	string getCodigo();
	string getNombre();
	map<string, Asignatura*> * getAsignaturas();

	// operaciones
	DTCarrera * crearDT();
	bool asignaturaEnCarrera(string idAs);

	// main
	void addAsignatura(Asignatura * a);
};

#endif /* CARRERA_H_ */
