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
 * Archivo: FechaSistema.cpp
 *******************************************************************************/

#include <stddef.h>
#include "FechaSistema.h"


FechaSistema * FechaSistema::instancia = NULL;

FechaSistema* FechaSistema::getInstance() {
	if (instancia == NULL){
		instancia = new FechaSistema();
	}
	return instancia;
}

FechaSistema::FechaSistema(){
	fecha = new Date();
}

Date* FechaSistema::getFecha() {
	return fecha;
}

void FechaSistema::setFecha(Date* d) {
	fecha = d;
}

FechaSistema::~FechaSistema(){
	delete this->fecha;
}
