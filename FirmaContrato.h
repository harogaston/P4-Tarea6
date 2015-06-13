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
class Estudiante;
#include "OfertaLaboral.h"
#include "FechaSistema.h"

class FirmaContrato {
private:
	Date * fecha;
	float sueldo;
	Estudiante * estudiante;
	OfertaLaboral * oferta;

public:
	FirmaContrato(float sueldo);
	~FirmaContrato();
	// getters
	Date * getFecha();
	float getSueldo();
	OfertaLaboral * getOferta();
	Estudiante * getEstudiante();

	// operaciones
	void cancelar();
	void setOfertaLaboral(OfertaLaboral * of);
	void setEstudiante(Estudiante * es);
};

#include "Estudiante.h"

#endif /* FIRMACONTRATO_H_ */
