/*
 * FirmaContrato.h
 *
 *  Created on: Jun 6, 2015
 *      Author: marccio
 */

#ifndef FIRMACONTRATO_H_
#define FIRMACONTRATO_H_

// DataTypes
#include "Date.h"

// Clases
#include "Estudiante.h"
#include "OfertaLaboral.h"

class FirmaContrato {
private:
	Date * fecha;
	float sueldo;
	Estudiante * estudiante;
	OfertaLaboral * oferta;

public:
	FirmaContrato(float sueldo);

	// getters
	Date * getFecha();
	float getSueldo();
	OfertaLaboral * getOferta();

	// operaciones
	void cancelar();
};

#endif /* FIRMACONTRATO_H_ */
