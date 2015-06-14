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
 * Archivo: DTSucursal.cpp
 *******************************************************************************/

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
