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
 * Archivo: FechaSistema.h
 *******************************************************************************/

#ifndef FECHASISTEMA_H_
#define FECHASISTEMA_H_

#include "Date.h"

class FechaSistema {
private:
	static FechaSistema * instancia;
	Date * fecha;
	FechaSistema();

public:
	static FechaSistema * getInstance();

	//getters y setters
	Date * getFecha();
	void setFecha(Date * d);
};

#endif /* FECHASISTEMA_H_ */
