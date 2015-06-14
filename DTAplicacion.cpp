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
 * Archivo: DTAplicacion.cpp
 *******************************************************************************/

#include "DTAplicacion.h"

DTAplicacion::DTAplicacion(
		int expedienteOferta,
		string tituloOferta,
		string rutEmpresa,
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

string DTAplicacion::getRutEmpresa() {
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
