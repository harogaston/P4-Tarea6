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
 * Archivo: Notificacion.h
 *******************************************************************************/

#ifndef NOTIFICACION_H_
#define NOTIFICACION_H_

// DataTypes
#include "DataOferta.h"
#include "FullDTOferta.h"

class Notificacion {
private:
	DataOferta * dtO;

public:
	Notificacion(DataOferta * dtO);
	~Notificacion();

	// operaciones
	DataOferta * mostrarNotificacion();
};

#endif /* NOTIFICACION_H_ */
