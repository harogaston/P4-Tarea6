/*
 * DTSucursal.cpp
 *
 *  Created on: Jun 1, 2015
 *      Author: marccio
 */

#include "DTSucursal.h"

DTSucursal::DTSucursal() {
}

DTSucursal::DTSucursal(string nombre, string telefono, string direccion) {
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

string DTSucursal::getTelefono() {
	return telefono;
}
