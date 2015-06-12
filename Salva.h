/*
 * Salva.h
 *
 *  Created on: Jun 6, 2015
 *      Author: marccio
 */

#ifndef SALVA_H_
#define SALVA_H_

#include <string>

#include "Date.h"
#include "DTAsignaturaSalvada.h"

class Asignatura;
class Estudiante;

using namespace std;

class Salva {
private:
	Date * fecha;
	int nota;
	Asignatura * asignatura;
	Estudiante * estudiante;
public:
	Salva(Date * fecha, int nota);
	~Salva();
	//getters
	Estudiante * getEstudiante();
	Asignatura * getAsignatura();
	//operaciones
	bool estaSalvada(string ci);
	Salva * getSalvada();
	DTAsignaturaSalvada * getDatosAprobacionAsignatura();
	void vincularConAsignaturayEstudiante(Asignatura * a, Estudiante * e);
};

#include "Asignatura.h"
#include "Estudiante.h"

#endif /* SALVA_H_ */
