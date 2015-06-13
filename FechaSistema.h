/*
 * FechaSistema.h
 *
 *  Created on: Jun 8, 2015
 *      Author: marccio
 */

#ifndef FECHASISTEMA_H_
#define FECHASISTEMA_H_

#include "Date.h"

class FechaSistema {
private:
	static FechaSistema * instancia;
	Date * fecha;
	FechaSistema();

public:
	//getters y setters
	Date * getFecha();
	void setFecha(Date * d);

	// operaciones
	static FechaSistema * getInstance();
};

#endif /* FECHASISTEMA_H_ */
