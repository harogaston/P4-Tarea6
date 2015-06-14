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
#include "FullDTOferta.h"

// Clases
#include "OfertaLaboral.h"

class Notificacion {
private:
	OfertaLaboral * oferta;

public:
	Notificacion(OfertaLaboral * oferta);
	~Notificacion();
	FullDTOferta * mostrarNotificacion();
};

#endif /* NOTIFICACION_H_ */
