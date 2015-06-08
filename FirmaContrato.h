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
	//getters
	Date * getFecha();
	float getSueldo();
	OfertaLaboral * getOferta();
	//operaciones
	void cancelar();
	void asociarAOfertayEstudiante(OfertaLaboral * o, Estudiante * e);
};

#endif /* FIRMACONTRATO_H_ */
