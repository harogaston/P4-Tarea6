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

#include <iostream>

// Clases
#include "ICtrlEstudiante.h"
#include "ICtrlOfertaActiva.h"
#include "ICtrlOfertaLaboral.h"
#include "CtrlEstudiante.h"
#include "CtrlOfertaActiva.h"
#include "CtrlOfertaLaboral.h"

using namespace std;

class Fabrica{
private:
	static Fabrica * instancia;
	CtrlOfertaActiva * ctrlOfertaActiva;
	CtrlEstudiante * ctrlEstudiante;
	Fabrica();
public:
	static Fabrica * getInstancia();

	// operaciones
	ICtrlOfertaLaboral * getICtrlOfertaLaboral();
	ICtrlEstudiante * getICtrlEstudiante();
	ICtrlOfertaActiva * getICtrlOfertaActiva();
	~Fabrica();
};

#endif /* FABRICA_H_ */
