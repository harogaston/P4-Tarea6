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

public:
	FirmaContrato(float sueldo);
	~FirmaContrato();

	// getters
	Date * getFecha();
	float getSueldo();
	Estudiante * getEstudiante();

	// operaciones
	void cancelar();
};

#include "Estudiante.h"

#endif /* FIRMACONTRATO_H_ */
