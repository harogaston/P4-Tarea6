/*
 * DTSucursal.cpp
 *
 *  Created on: Jun 1, 2015
 *      Author: marccio
 */

#include "DTSucursal.h"

DTSucursal::DTSucursal(string nombre, int telefono, string direccion) {
	this->nombre = nombre;
	this->telefono = telefono;
	this->direccion = direccion;
}

DTSucursal::~DTSucursal() {
}

string DTSucursal::getDireccion() {
	return direccion;
}

string DTSucursal::getNombre() {
	return nombre;
}

int DTSucursal::getTelefono() {
	return telefono;
}
