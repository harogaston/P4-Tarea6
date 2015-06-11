/*
 * Sucursal.cpp
 *
 *  Created on: Jun 7, 2015
 *      Author: marccio
 */

#include "Sucursal.h"

Sucursal::Sucursal(string nombre, string telefono, string direccion, Empresa * empresa, map<string, Seccion*> * secciones) {
	this->nombre = nombre;
	this->telefono = telefono;
	this->direccion = direccion;
	this->empresa = empresa;
	this->secciones = secciones;
}

Sucursal::~Sucursal() {
}

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

string Sucursal::getTelefono() {
	return telefono;
}
