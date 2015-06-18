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
 * Archivo: DataOferta.cpp
 *******************************************************************************/

#include "DataOferta.h"

DataOferta::DataOferta(
		int numero_de_expediente,
		string titulo,
		string descripcion,
		int horas_semanales,
		float sueldo_min,
		float sueldo_max,
		Date * comienzo_llamado,
		Date * fin_llamado,
		int puestos_disponibles,
		set<string> * asignaturasRequeridas) {
	this->numero_de_expediente = numero_de_expediente;
	this->titulo = titulo;
	this->descripcion = descripcion;
	this->horas_semanales = horas_semanales;
	this->sueldo_min = sueldo_min;
	this->sueldo_max = sueldo_max;
	this->comienzo_llamado = new Date(
			comienzo_llamado->getDd(),
			comienzo_llamado->getMm(),
			comienzo_llamado->getAaaa());
	this->fin_llamado = new Date(
			fin_llamado->getDd(),
			fin_llamado->getMm(),
			fin_llamado->getAaaa());
	this->puestos_disponibles = puestos_disponibles;
	this->asignaturasRequeridas = asignaturasRequeridas;
}

DataOferta::~DataOferta() {
	delete comienzo_llamado;
	delete fin_llamado;
	asignaturasRequeridas->clear();
	delete asignaturasRequeridas;
}

set<string> * DataOferta::getAsignaturasRequeridas() {
	return this->asignaturasRequeridas;
}

Date * DataOferta::getComienzoLlamado() {
	return this->comienzo_llamado;
}

string DataOferta::getDescripcion() {
	return this->descripcion;
}

Date * DataOferta::getFinLlamado() {
	return this->fin_llamado;
}

int DataOferta::getHorasSemanales() {
	return this->horas_semanales;
}

int DataOferta::getNumeroDeExpediente() {
	return this->numero_de_expediente;
}

int DataOferta::getPuestosDisponibles() {
	return this->puestos_disponibles;
}

float DataOferta::getSueldoMax() {
	return this->sueldo_max;
}

float DataOferta::getSueldoMin() {
	return this->sueldo_min;
}

string DataOferta::getTitulo() {
	return this->titulo;
}
