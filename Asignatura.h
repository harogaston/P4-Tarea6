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
 * Archivo: Asignatura.h
 *******************************************************************************/

#ifndef ASIGNATURA_H_
#define ASIGNATURA_H_

// STL
#include <set>
#include <string>

// DataTypes
#include "DTAsignatura.h"
#include "DTAsignaturaSalvada.h"

// Clases
#include "OfertaLaboral.h"
#include "Salva.h"

using namespace std;

class Asignatura {
private:
	string codigo;
	string nombre;
	int creditos;

	set<Salva*> * salvantes;

public:
	Asignatura(string codigo, string nombre, int creditos);
	~Asignatura();

	// getters
	string getCodigo();
	string getNombre();
	int getCreditos();

	// operaciones
	DTAsignatura* crearDT();
	bool fueSalvada(string cedula);
	bool tieneAprobaciones();
	void addSalvada(Salva * s);
	Salva * getSalvada(string cedula);
};

#endif /* ASIGNATURA_H_ */
