/*
 * Notificacion.cpp
 *
 *  Created on: Jun 8, 2015
 *      Author: marccio
 */

#include "Notificacion.h"

Notificacion::Notificacion(OfertaLaboral* oferta) {
	this->oferta = oferta;
}

Notificacion::~Notificacion() {
}

FullDTOferta* Notificacion::mostrarNotificacion() {
	return oferta->getFullDatos();
}
