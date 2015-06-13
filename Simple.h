/*
 * Simple.h
 *
 *  Created on: Jun 11, 2015
 *      Author: marccio
 */

#ifndef SIMPLE_H_
#define SIMPLE_H_

// STL
#include <set>
#include <string>

// Clases
#include "IStrategy.h"

using namespace std;

class Simple: public IStrategy {
public:
	Simple();
	~Simple();
	set<string> * actualizarRequerimientos();
};

#endif /* SIMPLE_H_ */
