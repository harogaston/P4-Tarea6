/*
 * FechaSistema.cpp
 *
 *  Created on: Jun 8, 2015
 *      Author: marccio
 */

#include "FechaSistema.h"
#include <stddef.h>

FechaSistema* FechaSistema::getInstance() {
	if (instance == NULL){
		instance =new FechaSistema;
	}
		return instance;
}

Date* FechaSistema::getFecha() {
	return fecha;
}

void FechaSistema::setFecha(Date* d) {
	fecha = d;
}
