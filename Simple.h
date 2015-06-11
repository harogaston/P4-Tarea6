/*
 * Simple.h
 *
 *  Created on: Jun 11, 2015
 *      Author: marccio
 */

#ifndef SIMPLE_H_
#define SIMPLE_H_

#include "IStrategy.h"
#include "Estudiante.h"

#include <string>
#include <set>

using namespace std;

class Simple: public IStrategy {
public:
	Simple();
	~Simple();
	set<string> * actualizarRequerimientos(
			map<string, Estudiante*> * estudiantes,
			set<string> * asignaturasRequeridas,
			map<string, Asignatura*> * asignaturas);
};

#endif /* SIMPLE_H_ */
