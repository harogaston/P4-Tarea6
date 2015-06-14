/*
 * FechaSistema.cpp
 *
 *  Created on: Jun 8, 2015
 *      Author: marccio
 */

#include "FechaSistema.h"
#include <stddef.h>

FechaSistema * FechaSistema::instancia = NULL;

FechaSistema* FechaSistema::getInstance() {
	if (instancia == NULL){
		instancia = new FechaSistema;
	}

	return instancia;
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
