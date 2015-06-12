/*
 * Fabrica.cpp
 *
 *  Created on: Jun 11, 2015
 *      Author: marccio
 */

#include "Fabrica.h"
#include "CtrlOfertaActiva.h"
#include "CtrlEstudiante.h"
#include "CtrlOfertaLaboral.h"

#include <stddef.h>

Fabrica * Fabrica::instancia=NULL;

Fabrica* Fabrica::getInstancia() {
	if (instancia==NULL)
		instancia = new Fabrica;
	return instancia;
}

ICtrlOfertaLaboral* Fabrica::getICtrlOfertaLaboral() {
	ICtrlOfertaLaboral * ctrl = new CtrlOfertaLaboral();
	return ctrl;
}

ICtrlEstudiante* Fabrica::getICtrlEstudiante() {
	ICtrlEstudiante * ctrl = new CtrlEstudiante();
	return ctrl;
}

ICtrlOfertaActiva* Fabrica::getICtrlOfertaActiva() {
	ICtrlOfertaActiva * ctrl = new CtrlOfertaActiva();
	return ctrl;
}
