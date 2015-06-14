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
 * Archivo: DTCarrera.h
 *******************************************************************************/

#ifndef DTCARRERA_H_
#define DTCARRERA_H_

#include <string>

using namespace std;

class DTCarrera {
private:
	string codigo;
	string nombre;

public:
	DTCarrera();
	DTCarrera(string codigo, string nombre);
	~DTCarrera();

	string getCodigo();
	string getNombre();
};

#endif /* DTCARRERA_H_ */
