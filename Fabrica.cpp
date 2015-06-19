/*******************************************************************************
 * Programación 4 - Laboratorio 6 - Año 2015
 *
 * Profesor: Pablo Milanese
 * Grupo: 17
 * Integrantes: Juan Pablo Copello - jpcopel@gmail.com
 * 			Gastón Haro - harogaston@gmail.com
 * 			Sofia Honty - sofisho@gmail.com
 * 			Marccio Silva - marcciosilva@gmail.com
 *
 * Archivo: Fabrica.cpp
 *******************************************************************************/
#include <stddef.h>

#include "Fabrica.h"

Fabrica * Fabrica::instancia = NULL;

Fabrica* Fabrica::getInstance() {
	if (instancia==NULL)
		instancia = new Fabrica();
	return instancia;
}

Fabrica::Fabrica() {
}

ICtrlOfertaLaboral* Fabrica::getICtrlOfertaLaboral() {
	ICtrlOfertaLaboral * ctrl = CtrlOfertaLaboral::getInstance();
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

Fabrica::~Fabrica() {
}

void Fabrica::destroyInstance() {
	if (instancia != NULL) {
		delete instancia;
		instancia = NULL;
	}
}
