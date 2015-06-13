/*
 * Fabrica.h
 *
 *  Created on: Jun 11, 2015
 *      Author: marccio
 */

#ifndef FABRICA_H_
#define FABRICA_H_

// Clases
#include "ICtrlEstudiante.h"
#include "ICtrlOfertaActiva.h"
#include "ICtrlOfertaLaboral.h"
#include "CtrlEstudiante.h"
#include "CtrlOfertaActiva.h"
#include "CtrlOfertaLaboral.h"

class Fabrica{
private:
	static Fabrica * instancia;
	CtrlOfertaActiva * CtrlOfertaActiva;
	CtrlEstudiante * CtrlEstudiante;
	Fabrica();

public:
	static Fabrica * getInstance();
	ICtrlOfertaLaboral * getICtrlOfertaLaboral();
	ICtrlEstudiante * getICtrlEstudiante();
	ICtrlOfertaActiva * getICtrlOfertaActiva();
};

#endif /* FABRICA_H_ */
