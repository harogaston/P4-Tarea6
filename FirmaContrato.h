/*
 * FirmaContrato.h
 *
 *  Created on: Jun 6, 2015
 *      Author: marccio
 */

#ifndef FIRMACONTRATO_H_
#define FIRMACONTRATO_H_

#include "Estudiante.h"
#include "OfertaLaboral.h"

class FirmaContrato {
private:
	Date * fecha;
	float sueldo;
	Estudiante * estudiante;
	OfertaLaboral * oferta;
public:
	FirmaContrato(Date * fecha, float sueldo);
	~FirmaContrato();
	Date * getFecha();
	float getSueldo();
	void cancelar();
	void asociarAOfertayEstudiante(OfertaLaboral * o, Estudiante * e);
};

#endif /* FIRMACONTRATO_H_ */
