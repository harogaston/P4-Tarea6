/*
 * FullDTOferta.cpp
 *
 *  Created on: Jun 2, 2015
 *      Author: marccio
 */

#include "FullDTOferta.h"

FullDTOferta::FullDTOferta() {
}

FullDTOferta::FullDTOferta(int numero_de_expediente, string titulo,
		string descripcion, int horas_semanales, float sueldo_min,
		float sueldo_max, Date * comienzo_llamado, Date * fin_llamado,
		int puestos_disponibles, string empresa, string ubicacionSucursal,
		int cantidad_inscriptos) {
	this->numero_de_expediente = numero_de_expediente;
	this->titulo = titulo;
	this->descripcion = descripcion;
	this->horas_semanales = horas_semanales;
	this->sueldo_min = sueldo_min;
	this->sueldo_max = sueldo_max;
	this->comienzo_llamado = comienzo_llamado;
	this->fin_llamado = fin_llamado;
	this->puestos_disponibles = puestos_disponibles;
	this->empresa = empresa;
	this->ubicacionSucursal = ubicacionSucursal;
	this->cantidad_inscriptos = cantidad_inscriptos;
}

FullDTOferta::~FullDTOferta() {
}

string FullDTOferta::getEmpresa() {
	return this->empresa;
}

string FullDTOferta::getUbicacionSucursal() {
	return this->ubicacionSucursal;
}

int FullDTOferta::getCantidadInscriptos() {
	return this->cantidad_inscriptos;
}

Date * FullDTOferta::getComienzoLlamado() {
	return this->comienzo_llamado;
}

string FullDTOferta::getDescripcion() {
	return this->descripcion;
}

Date * FullDTOferta::getFinLlamado() {
	return this->fin_llamado;
}

int FullDTOferta::getHorasSemanales() {
	return this->horas_semanales;
}

int FullDTOferta::getNumeroDeExpediente() {
	return this->numero_de_expediente;
}

int FullDTOferta::getPuestosDisponibles() {
	return this->puestos_disponibles;
}

float FullDTOferta::getSueldoMax() {
	return this->sueldo_max;
}

float FullDTOferta::getSueldoMin() {
	return this->sueldo_min;
}

string FullDTOferta::getTitulo() {
	return this->getTitulo();
}
