/*
 * Sucursal.cpp
 *
 *  Created on: Jun 7, 2015
 *      Author: marccio
 */

#include "Sucursal.h"

Sucursal::Sucursal(string nombre, int telefono, string direccion, Empresa * empresa) {
	this->nombre = nombre;
	this->telefono = telefono;
	this->direccion = direccion;
	this->empresa = empresa;
	this->Secciones = map<int, Seccion*>;
}

Sucursal::~Sucursal() {
}

void agregarSeccion(string idSec, Seccion* s) {
	this->Secciones[idSec] = s;
};

DTSucursal* Sucursal::crearDT() {
	DTSucursal * dt = new DTSucursal(nombre, telefono, direccion);
	return dt;
}

set<DTSeccion*>* Sucursal::listarSecciones() {
	set<DTSeccion*> * setOut = NULL;
	for (map<string, Seccion*>::iterator it = secciones->begin() ;
			it != secciones->end() ; it++) {
		DTSeccion * dt = new DTSeccion((*it).second->getNombre(), (*it).second->getInterno());
		setOut->insert(dt);
	}
	return setOut;
}

bool Sucursal::seleccionarSeccion(string idSec) {
	return (secciones->find(idSec) != secciones->end());
}

OfertaLaboral* Sucursal::crearOferta(string idSec, DataOferta * dataOferta) {
	map<string, Seccion*>::iterator it = secciones->find(idSec);
	return (*it).second->crearOferta(dataOferta);
}

DTAplicacion * Sucursal::getDatosSucursal() {
	DTAplicacion * dapReducido = empresa->getDatosEmpresa();
	DTAplicacion * dap = new DTAplicacion(
			dapReducido->getExpedienteOferta(),
			dapReducido->getTituloOferta(),
			dapReducido->getRutEmpresa(),
			dapReducido->getEmpresa(),
			nombre,
			telefono,
			direccion,
			dapReducido->getSeccion(),
			dapReducido->getInternoSeccion());
	delete dapReducido;
	return dap;
}

string Sucursal::getNombreEmpresa() {
	return empresa->getNombre();
}

string Sucursal::getDireccion() {
	return direccion;
}

string Sucursal::getNombre() {
	return nombre;
}

int Sucursal::getTelefono() {
	return telefono;
}

string Sucursal::getDireccion() {
	return direccion;
}
