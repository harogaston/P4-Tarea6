/*
 * Salva.h
 *
 *  Created on: Jun 6, 2015
 *      Author: marccio
 */

#ifndef SALVA_H_
#define SALVA_H_

class Salva {
public:
	Salva();
	virtual ~Salva();
	bool estaSalvada(string ci);
	Salva * getSalvada();
};

#endif /* SALVA_H_ */
