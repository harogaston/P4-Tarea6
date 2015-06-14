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
 * Archivo: Salva.h
 *******************************************************************************/

#ifndef SALVA_H_
#define SALVA_H_

// STL
#include <string>

// DataTypes
#include "Date.h"
#include "DTAsignaturaSalvada.h"

// Clases
#include "Estudiante.h"
class Asignatura;

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
	Date * getFecha();
	int getNota();
	Estudiante * getEstudiante();
	Asignatura * getAsignatura();

	// operaciones
	DTAsignaturaSalvada * getDatosAprobacionAsignatura();
	bool estaSalvada(string cedula);
	void asociarAsignaturaEstudiante(Asignatura * a, Estudiante * e);
};

#include "Asignatura.h"

#endif /* SALVA_H_ */
