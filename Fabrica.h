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
 * Archivo: Fabrica.h
 *******************************************************************************/

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

	// operaciones
	ICtrlOfertaLaboral * getICtrlOfertaLaboral();
	ICtrlEstudiante * getICtrlEstudiante();
	ICtrlOfertaActiva * getICtrlOfertaActiva();
};

#endif /* FABRICA_H_ */
