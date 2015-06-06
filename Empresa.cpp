/*
 * Empresa.cpp
 *
 *  Created on: Jun 6, 2015
 *      Author: marccio
 */

#include "Empresa.h"

#include <stdexcept>

Empresa::Empresa(int rut, string nombre) {
	this->rut = rut;
	this->nombre = nombre;
	this->sucursales = NULL;
}

Empresa::~Empresa() {
}

DTEmpresa* Empresa::crearDT() {
	DTEmpresa * dt = new DTEmpresa(this->rut, this->nombre);
	return dt;
}

set<DTSucursal*>* Empresa::listarSucursales() {
	set<DTSucursal*> * setSucursales = NULL;
	for (map<string, Sucursal*>::iterator it = sucursales->begin() ; it != sucursales->end() ; it++) {
		setSucursales->insert(new DTSucursal((*it).second->getNombre(), (*it).second->getTelefono(), (*it).second->getDireccion()));
	}
	return setSucursales;
}

bool Empresa::seleccionarSucursal(string idSuc) {
	return (sucursales->find(idSuc) != sucursales->end());
}

map<string, DTSeccion*>* Empresa::listarSecciones(string idSec) {
	map<string, Sucursal*>::iterator it = sucursales->find(idSec);
	if (it != sucursales->end()) {
		return (*it).second->listarSecciones();
	} else {
		return NULL;
	}
}

bool Empresa::seleccionarSeccion(string idSuc, string idSec) {
	map<string, Sucursal*>::iterator it = sucursales->find(idSuc);
	if (it != sucursales->end()) {
		return (*it).second->seleccionarSeccion(idSec);
	} else return false;
}

OfertaLaboral* Empresa::crearOferta(string idSuc, string idSec, DataOferta* dtO) {
	map<string, Sucursal*>::iterator it = sucursales->find(idSuc);
	if (it != sucursales->end()){
		return (*it).second->crearOferta(idSec, dtO);
	} else {
		throw std::invalid_argument("Esa sucursal no existe en el sistema.\n");
	}
}

DTAplicacion* Empresa::getDatosEmpresa() {
	return new DTAplicacion(0, "", this->rut, this->nombre, "", 0, "", "", 0);
}
