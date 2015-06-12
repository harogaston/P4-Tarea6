/*
 * DTAplicacion.cpp
 *
 *  Created on: Jun 2, 2015
 *      Author: marccio
 */

#include "DTAplicacion.h"

DTAplicacion::DTAplicacion(
		int expedienteOferta,
		string tituloOferta,
		int rutEmpresa,
		string empresa,
		string sucursal,
		int telefonoSuc,
		string direccionSuc,
		string seccion,
		int internoSeccion) {
	this->expedienteOferta = expedienteOferta;
	this->tituloOferta = tituloOferta;
	this->rutEmpresa = rutEmpresa;
	this->empresa = empresa;
	this->sucursal = sucursal;
	this->telefonoSuc = telefonoSuc;
	this->direccionSuc = direccionSuc;
	this->seccion = seccion;
	this->internoSeccion = internoSeccion;
}

DTAplicacion::~DTAplicacion() {
}

string DTAplicacion::getDireccionSuc() {
	return this->direccionSuc;
}

string DTAplicacion::getEmpresa() {
	return this->empresa;
}

int DTAplicacion::getExpedienteOferta() {
	return this->expedienteOferta;
}

int DTAplicacion::getInternoSeccion() {
	return this->internoSeccion;
}

int DTAplicacion::getRutEmpresa() {
	return this->rutEmpresa;
}

string DTAplicacion::getSeccion() {
	return this->seccion;
}

string DTAplicacion::getSucursal() {
	return this->sucursal;
}

int DTAplicacion::getTelefonoSuc() {
	return this->telefonoSuc;
}

string DTAplicacion::getTituloOferta() {
	return this->tituloOferta;
}
