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
 * Archivo: IObserver.h
 *******************************************************************************/

#ifndef IOBSERVER_H_
#define IOBSERVER_H_

#include "Notificacion.h"

class IObserver {
public:
	virtual ~IObserver();
	virtual void notificar(Notificacion * notificacion, set<string> * asignaturas) = 0;
};

#endif /* IOBSERVER_H_ */
