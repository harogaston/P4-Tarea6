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
 * Archivo: Simple.h
 *******************************************************************************/

#ifndef ESTRATEGIAUNO_H_
#define ESTRATEGIAUNO_H_

// STL
#include <set>
#include <string>
#include <map>

// Clases
#include "IStrategy.h"
#include "Estudiante.h"
#include "Asignatura.h"

using namespace std;

class EstrategiaUno : public IStrategy {
public:
	EstrategiaUno();
	~EstrategiaUno();

	set<string> * actualizarRequerimientos(
			map<string, Estudiante*> * estudiantes,
			set<string> * asignaturasRequeridas,
			map<string, Asignatura*> * asignaturas);
};

#endif /* ESTRATEGIAUNO_H_ */
