/*
 * Fabrica.cpp
 *
 *  Created on: Jun 11, 2015
 *      Author: marccio
 */

#include "Fabrica.h"
#include "CtrOfertasActivas.h"
#include "CtrlEstudiantes.h"
#include "CtrlOfertasLaborales.h"

#include <stddef.h>

Fabrica * Fabrica::instancia=NULL;

Fabrica* Fabrica::getInstancia() {
	if (instancia==NULL)
		instancia = new Fabrica;
	return instancia;
}

ICtrlOfertaLaboral* Fabrica::getICtrlOfertaLaboral() {
	ICtrlOfertaLaboral * ctrl = new CtrlOfertasLaborales();
	return ctrl;
}

ICtrlEstudiantes* Fabrica::getICtrlEstudiantes() {
	ICtrlEstudiantes * ctrl = new CtrlEstudiantes();
	return ctrl;
}

ICtrlOfertasActivas* Fabrica::getICtrlOfertasActivas() {
	ICtrlOfertasActivas * ctrl = new CtrOfertasActivas();
	return ctrl;
}
