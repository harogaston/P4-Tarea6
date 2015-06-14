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

#ifndef SIMPLE_H_
#define SIMPLE_H_

// STL
#include <set>
#include <string>

// Clases
#include "IStrategy.h"

using namespace std;

class Simple : public IStrategy {
public:
	Simple();
	~Simple();

	set<string> * actualizarRequerimientos();
};

#endif /* SIMPLE_H_ */
