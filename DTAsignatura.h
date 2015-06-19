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
 * Archivo: DTAsignatura.h
 *******************************************************************************/

#ifndef DTASIGNATURA_H_
#define DTASIGNATURA_H_

#include <string>

using namespace std;

class DTAsignatura {
private:
	string codigo;
	string nombre;

public:
	DTAsignatura();
	DTAsignatura(string codigo, string nombre);
	~DTAsignatura();

	string getCodigo();
	string getNombre();
};

#endif /* DTASIGNATURA_H_ */
