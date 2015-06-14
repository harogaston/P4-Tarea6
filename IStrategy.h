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
 * Archivo: IStrategy.h
 *******************************************************************************/

#ifndef ISTRATEGY_H_
#define ISTRATEGY_H_

// STL
#include <string>

//Clases
#include "Estudiante.h"
#include "Asignatura.h"

using namespace std;

class IStrategy {
public:
	virtual ~IStrategy();
	virtual set<string> * actualizarRequerimientos(
			map<string, Estudiante*> * estudiantes,
			set<string> * asignaturasRequeridas,
			map<string, Asignatura*> * asignaturas) = 0;
};

#endif /* ISTRATEGY_H_ */
