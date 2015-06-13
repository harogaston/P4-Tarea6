/*
 * Entrevista.h
 *
 *  Created on: Jun 6, 2015
 *      Author: marccio
 */

#ifndef ENTREVISTA_H_
#define ENTREVISTA_H_

// DataTypes
#include "Date.h"

class Entrevista {
private:
	Date * fecha;

public:
	Entrevista(Date * fecha);

	//getters
	Date * getFecha();
};

#endif /* ENTREVISTA_H_ */
