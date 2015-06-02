/*
 * DTOferta.cpp
 *
 *  Created on: Jun 2, 2015
 *      Author: marccio
 */

#include "DTOferta.h"

DTOferta::DTOferta() {
	numero_de_expediente = 0;
	titulo = "";
}

DTOferta::DTOferta(int numero_de_expediente, string titulo) {
	this->numero_de_expediente = numero_de_expediente;
	this->titulo = titulo;
}

DTOferta::~DTOferta() {
}

int DTOferta::getNumeroDeExpediente() {
	return this->numero_de_expediente;
}

string DTOferta::getTitulo() {
	return this->titulo;
}
