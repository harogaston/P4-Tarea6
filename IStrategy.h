/*
 * IStrategy.h
 *
 *  Created on: Jun 2, 2015
 *      Author: marccio
 */

#ifndef ISTRATEGY_H_
#define ISTRATEGY_H_

// STL
#include <string>

using namespace std;

class IStrategy {
public:
	virtual ~IStrategy();
	virtual set<string> * actualizarRequerimientos() = 0;
};

#endif /* ISTRATEGY_H_ */
