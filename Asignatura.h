/*
 * Asignatura.h
 *
 *  Created on: Jun 2, 2015
 *      Author: sofia
 */

#ifndef ASIGNATURA_H_
#define ASIGNATURA_H_

#include <string>
#include <set>

#include "OfertaLaboral.h"
#include "DTAsignaturaSalvada.h"
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
	string getCodigo();
	string getNombre();
	int getCreditos();
	void asociarAsignaturaOferta(OfertaLaboral * of);
	bool fueSalvada(string ci);
	DTAsignaturaSalvada * getDatosAprobacionAsignatura();
	void addSalva(Salva * s);
	Salva * getSalvada(string ci);
	bool tieneAprobaciones();
};

#endif /* ASIGNATURA_H_ */
