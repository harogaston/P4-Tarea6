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
 * Archivo: Notificacion.cpp
 *******************************************************************************/

#include "Notificacion.h"

Notificacion::Notificacion(OfertaLaboral * of) {
	dtO = of->getFullDatos();
}

Notificacion::~Notificacion() {
	delete dtO;
}

FullDTOferta* Notificacion::mostrarNotificacion() {
	return this->dtO;
}
