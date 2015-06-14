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
 * Archivo: DTAsignaturaSalvada.h
 *******************************************************************************/

#ifndef DTASIGNATURASALVADA_H_
#define DTASIGNATURASALVADA_H_

#include <string>

#include "Date.h"

using namespace std;

class DTAsignaturaSalvada {
private:
	string codigo;
	string nombre;
	Date * fecha;
	int nota;

public:
	DTAsignaturaSalvada();
	DTAsignaturaSalvada(string codigo, string nombre, Date * fecha, int nota);
	~DTAsignaturaSalvada();

	string getCodigo();
	string getNombre();
	Date * getFecha();
	int getNota();
};

#endif /* DTASIGNATURASALVADA_H_ */
