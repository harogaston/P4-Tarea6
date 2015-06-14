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
 * Archivo: FirmaContrato.h
 *******************************************************************************/

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
