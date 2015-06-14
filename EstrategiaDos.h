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
 * Archivo: Grupo.h
 *******************************************************************************/

#ifndef ESTRATEGIADOS_
#define ESTRATEGIADOS_

// STL
#include <set>
#include <map>
#include <string>

// Clases
#include "IStrategy.h"
#include "Estudiante.h"
#include "Asignatura.h"

using namespace std;

class EstrategiaDos: public IStrategy {
public:
	EstrategiaDos();
	~EstrategiaDos();

	set<string> * actualizarRequerimientos(
			map<string, Estudiante*> * estudiantes,
			set<string> * asignaturasRequeridas,
			map<string, Asignatura*> * asignaturas);
};

#endif /* ESTRATEGIADOS_ */
