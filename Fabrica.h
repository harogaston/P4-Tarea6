/*
 * Fabrica.h
 *
 *  Created on: Jun 11, 2015
 *      Author: marccio
 */

#ifndef FABRICA_H_
#define FABRICA_H_

#include "ICtrlEstudiante.h"
#include "ICtrlOfertaActiva.h"
#include "ICtrlOfertaLaboral.h"

class Fabrica{
private:
	static Fabrica * instancia;
public:
	static Fabrica * getInstancia();
	ICtrlOfertaLaboral * getICtrlOfertaLaboral();
	ICtrlEstudiante * getICtrlEstudiante();
	ICtrlOfertaActiva * getICtrlOfertaActiva();
};

#endif /* FABRICA_H_ */
