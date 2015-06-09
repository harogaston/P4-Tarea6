/*
 * Entrevista.h
 *
 *  Created on: Jun 6, 2015
 *      Author: marccio
 */

#ifndef ENTREVISTA_H_
#define ENTREVISTA_H_

#include "Date.h"

class Entrevista {
private:
	Date * fecha;
public:
	Entrevista(Date * fecha);
	virtual ~Entrevista();
	Date * getFecha();
};

#endif /* ENTREVISTA_H_ */
