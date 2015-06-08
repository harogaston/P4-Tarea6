/*
 * Estudiante.h
 *
 *  Created on: Jun 6, 2015
 *      Author: marccio
 */

#ifndef ESTUDIANTE_H_
#define ESTUDIANTE_H_

#include <set>

#include "FirmaContrato.h"
#include "DTEstudiante.h"
#include "Aplica.h"

using namespace std;

class Estudiante {
private:
	set<FirmaContrato*> * contratos;
public:
	Estudiante();
	~Estudiante();
	void asignarCargo(FirmaContrato * f);
	void cancelarContrato(FirmaContrato * f);
	DTEstudiante * crearDT();
	string getCedula();
	void cancelarAplica();
};

#endif /* ESTUDIANTE_H_ */
