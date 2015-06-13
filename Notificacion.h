/*
 * Notificacion.h
 *
 *  Created on: Jun 8, 2015
 *      Author: marccio
 */

#ifndef NOTIFICACION_H_
#define NOTIFICACION_H_

#include "OfertaLaboral.h"
#include "FullDTOferta.h"

class Notificacion {
private:
	OfertaLaboral * oferta;

public:
	Notificacion(OfertaLaboral * oferta);
	FullDTOferta * mostrarNotificacion();
};

#endif /* NOTIFICACION_H_ */
