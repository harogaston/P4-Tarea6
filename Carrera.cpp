/*
 * Carrera.cpp
 *
 *  Created on: Jun 2, 2015
 *      Author: Sofia
 */

#include "Carrera.h"

using namespace std;

	Carrera::Carrera(string codigo, string nombre) {
		this->codigo = codigo;
		this->nombre = nombre;
	};
	
	Carrera::~Carrera(){
	};
	
	DTCarrera Carrera::crearDT() {
		return DTCarrera(this->codigo, this->nombre);
	};

