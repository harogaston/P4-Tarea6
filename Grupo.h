/*
 * Grupo.h
 *
 *  Created on: Jun 11, 2015
 *      Author: marccio
 */

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
