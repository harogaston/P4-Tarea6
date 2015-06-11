/*
 * Grupo.h
 *
 *  Created on: Jun 11, 2015
 *      Author: marccio
 */

#ifndef GRUPO_H_
#define GRUPO_H_

#include "Estudiante.h"
#include "IStrategy.h"

#include <string>
#include <map>

using namespace std;


class Grupo: public IStrategy {
public:
	Grupo();
	~Grupo();
	set<string> * actualizarRequerimientos(
			map<string, Estudiante*> * estudiantes,
			set<string> * asignaturasRequeridas,
			map<string, Asignatura*> * asignaturas);
};

#endif /* GRUPO_H_ */
