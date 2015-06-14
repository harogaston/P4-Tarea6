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
 * Archivo: DTOferta.cpp
 *******************************************************************************/

#include "DTOferta.h"

DTOferta::DTOferta() {
	numero_de_expediente = 0;
	titulo = "";
}

DTOferta::DTOferta(int numero_de_expediente, string titulo) {
	this->numero_de_expediente = numero_de_expediente;
	this->titulo = titulo;
}

DTOferta::~DTOferta() {
}

int DTOferta::getNumeroDeExpediente() {
	return this->numero_de_expediente;
}

string DTOferta::getTitulo() {
	return this->titulo;
}
