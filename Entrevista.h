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
 * Archivo: Entrevista.h
 *******************************************************************************/

#ifndef ENTREVISTA_H_
#define ENTREVISTA_H_

// DataTypes
#include "Date.h"

class Entrevista {
private:
	Date * fecha;

public:
	Entrevista(Date * fecha);

	//getters
	Date * getFecha();
};

#endif /* ENTREVISTA_H_ */
