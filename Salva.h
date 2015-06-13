/*
 * Salva.h
 *
 *  Created on: Jun 6, 2015
 *      Author: marccio
 */

#ifndef SALVA_H_
#define SALVA_H_

// STL
#include <string>

// DataTypes
#include "Date.h"
#include "DTAsignaturaSalvada.h"

// Clases
class Asignatura;
#include "Estudiante.h"

using namespace std;

class Salva {
private:
	Date * fecha;
	int nota;
	Asignatura * asignatura;
	Estudiante * estudiante;

public:
	Salva(Date * fecha, int nota);

	// getters
	Estudiante * getEstudiante();
	Asignatura * getAsignatura();

	// operaciones
	DTAsignaturaSalvada * getDatosAprobacionAsignatura();
	bool estaSalvada(string cedula);
	void asociarAsignaturaEstudiante(Asignatura * a, Estudiante * e);
};

#include "Asignatura.h"

#endif /* SALVA_H_ */
