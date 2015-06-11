/*
 * DataOfertaRestringida.cpp
 *
 *  Created on: Jun 8, 2015
 *      Author: marccio
 */

#include "DataOfertaRestringida.h"

DataOfertaRestringida::DataOfertaRestringida(string titulo, string descripcion,
		int horas_semanales, float sueldo_min, float sueldo_max,
		Date* comienzo_llamado, Date* fin_llamado, int puestos_disponibles) {
	this->titulo = titulo;
	this->descripcion = descripcion;
	this->horas_semanales = horas_semanales;
	this->sueldo_min = sueldo_min;
	this->sueldo_max = sueldo_max;
	this->comienzo_llamado = comienzo_llamado;
	this->fin_llamado = fin_llamado;
	this->puestos_disponibles = puestos_disponibles;
}

DataOfertaRestringida::~DataOfertaRestringida() {
}

string DataOfertaRestringida::getTitulo() {
	return titulo;
}

string DataOfertaRestringida::getDescripcion() {
	return descripcion;
}

int DataOfertaRestringida::getHorasSemanales() {
	return horas_semanales;
}

float DataOfertaRestringida::getSueldoMin() {
	return sueldo_min;
}

float DataOfertaRestringida::getSueldoMax() {
	return sueldo_max;
}

Date* DataOfertaRestringida::getComienzoLlamado() {
	return comienzo_llamado;
}

Date* DataOfertaRestringida::getFinLlamado() {
	return fin_llamado;
}

int DataOfertaRestringida::getPuestosDisponibles() {
	return puestos_disponibles;
}
