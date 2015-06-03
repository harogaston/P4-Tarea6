/*
 * Asignatura.h
 *
 *  Created on: Jun 2, 2015
 *      Author: sofia
 */

#ifndef ASIGNATURA_H_
#define ASIGNATURA_H_

#include <string>

#include "OfertaLaboral.h"
#include "DTAsignaturaSalvada.h"

using namespace std;

class Asignatura {
private:
	string codigo;
	string nombre;
	int creditos;
public:
	Asignatura(string codigo, string nombre, int creditos);
	virtual ~Asignatura();
	asociarAsignaturaOferta(OfertaLaboral of);
	bool fueSalvada(string ci);
	DTAsignaturaSalvada getDatosAprobacionAsignatura();
};

#endif /* ASIGNATURA_H_ */