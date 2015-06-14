/*
 * Asignatura.h
 *
 *  Created on: Jun 2, 2015
 *      Author: sofia
 */

#ifndef ASIGNATURA_H_
#define ASIGNATURA_H_

// STL
#include <set>
#include <string>

// DataTypes
#include "DTAsignaturaSalvada.h"

// Clases
#include "OfertaLaboral.h"
#include "Salva.h"

using namespace std;

class Asignatura {
private:
	string codigo;
	string nombre;
	int creditos;

	set<Salva*> * salvantes;

public:
	Asignatura(string codigo, string nombre, int creditos);
	~Asignatura();

	// getters
	string getCodigo();
	string getNombre();
	int getCreditos();

	// operaciones
	bool fueSalvada(string cedula);
	bool tieneAprobaciones();
	void addSalvada(Salva * s);
	Salva * getSalvada(string cedula);
};

#endif /* ASIGNATURA_H_ */
