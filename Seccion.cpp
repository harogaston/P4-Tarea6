/*
 * Seccion.cpp
 *
 *  Created on: Jun 7, 2015
 *      Author: marccio
 */

#include "Seccion.h"

Seccion::Seccion(string nombre, int interno, Sucursal * sucursal) {
	this->nombre = nombre;
	this->interno = interno;
	this->ofertas = NULL;
	this->sucursal = sucursal;
}

Seccion::~Seccion() {
	for (set<OfertaLaboral*>::iterator it = ofertas->begin() ; it != ofertas->end() ; it++) {
		delete((*it));
		ofertas->erase(it);
	}
}

string Seccion::getNombre() {
	return nombre;
}

int Seccion::getInterno() {
	return interno;
}

OfertaLaboral* Seccion::crearOferta(DataOferta* dataOferta) {
	OfertaLaboral * o = new OfertaLaboral(
			dataOferta->getNumeroDeExpediente(),
			dataOferta->getTitulo(),
			dataOferta->getDescripcion(),
			dataOferta->getHorasSemanales(),
			dataOferta->getSueldoMin(),
			dataOferta->getSueldoMax(),
			dataOferta->getComienzoLlamado(),
			dataOferta->getFinLlamado(),
			dataOferta->getPuestosDisponibles(),
			NULL,
			this);
	ofertas->insert(o);
	return o;
}

DTSeccion* Seccion::crearDT() {
	DTSeccion * dt = new DTSeccion(nombre, interno);
	return dt;
}

DTAplicacion* Seccion::getDatosSeccion() {
	DTAplicacion * dapReducido = sucursal->getDatosSucursal();
	DTAplicacion * dap = new DTAplicacion(
			dapReducido->getExpedienteOferta(),
			dapReducido->getTituloOferta(),
			dapReducido->getRutEmpresa(),
			dapReducido->getEmpresa(),
			dapReducido->getSucursal(),
			dapReducido->getTelefonoSuc(),
			dapReducido->getDireccionSuc(),
			nombre,
			interno);
	delete dapReducido;
	return dap;
}

string Seccion::getUbicacion() {
	return sucursal->getDireccion();
}

string Seccion::getNombreEmpresa() {
	return sucursal->getNombreEmpresa();
}
