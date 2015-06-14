/*
 * DTSucursal.cpp
 *
 *  Created on: Jun 1, 2015
 *      Author: marccio
 */

#include "DTSucursal.h"

DTSucursal::DTSucursal(string idSuc, int telefono, string direccion) {
	this->idSuc = idSuc;
	this->telefono = telefono;
	this->direccion = direccion;
}

DTSucursal::~DTSucursal() {
}

string DTSucursal::getDireccion() {
	return direccion;
}

string DTSucursal::getIdSuc() {
	return idSuc;
}

int DTSucursal::getTelefono() {
	return telefono;
}
