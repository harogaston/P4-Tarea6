/*
 * Fabrica.h
 *
 *  Created on: Jun 11, 2015
 *      Author: marccio
 */

#ifndef FABRICA_H_
#define FABRICA_H_

#include "ICtrlEstudiantes.h"
#include "ICtrlOfertasActivas.h"
#include "ICtrlOfertasLaborales.h"

class Fabrica{
private:
	static Fabrica * instancia;
public:
	static Fabrica * getInstancia();
	ICtrlOfertasLaborales * getICtrlOfertaLaboral();
	ICtrlEstudiantes * getICtrlEstudiantes();
	ICtrlOfertasActivas * getICtrlOfertasActivas();
};

#endif /* FABRICA_H_ */
