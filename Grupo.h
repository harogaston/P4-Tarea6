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

#ifndef GRUPO_H_
#define GRUPO_H_

// STL
#include <set>
#include <string>

// Clases
#include "IStrategy.h"

using namespace std;

class Grupo: public IStrategy {
public:
	Grupo();
	~Grupo();

	set<string> * actualizarRequerimientos();
};

#endif /* GRUPO_H_ */
