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
 * Archivo: Salva.cpp
 *******************************************************************************/

#include "Salva.h"
#include <stddef.h>

Salva::Salva(Date* fecha, int nota) {
	this->fecha = fecha;
	this->nota = nota;
	asignatura = NULL;
	estudiante = NULL;
}

Salva::~Salva() {
	delete fecha;
}

Estudiante* Salva::getEstudiante() {
	return estudiante;
}

Asignatura* Salva::getAsignatura() {
	return asignatura;
}

DTAsignaturaSalvada* Salva::getDatosAprobacionAsignatura() {
	DTAsignaturaSalvada * dt = new DTAsignaturaSalvada(
			asignatura->getCodigo(),
			asignatura->getNombre(),
			fecha,
			nota);
	return dt;
}

bool Salva::fueSalvada(string cedula) {
	return (cedula == estudiante->getCedula());
}

void Salva::asociarAsignaturaEstudiante(Asignatura* a, Estudiante* e) {
	asignatura = a;
	estudiante = e;
}
