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
#include "Salva.h"

using namespace std;

class Asignatura {
private:
	string codigo;
	string nombre;
	int creditos;
public:
	Asignatura(string codigo, string nombre, int creditos);
	~Asignatura();
	void asociarAsignaturaOferta(OfertaLaboral& of);
	bool fueSalvada(string ci);
	DTAsignaturaSalvada getDatosAprobacionAsignatura();
	void addSalva(Salva * s);
	Salva * getSalvada(string ced);
};

#endif /* ASIGNATURA_H_ */
