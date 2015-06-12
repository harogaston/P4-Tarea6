/*
 * IStrategy.h
 *
 *  Created on: Jun 2, 2015
 *      Author: marccio
 */

#ifndef ISTRATEGY_H_
#define ISTRATEGY_H_

#include <string>

using namespace std;

class IStrategy {
public:
	virtual ~IStrategy() {};
	virtual set<string> * actualizarRequerimientos(
			map<string, Estudiante*> * estudiantes,
			set<string> * asignaturasRequeridas,
			map<string, Asignatura*> * asignaturas) = 0;
};

#endif /* ISTRATEGY_H_ */
