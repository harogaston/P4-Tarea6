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
 * Archivo: DTEstudiante.h
 *******************************************************************************/

#ifndef DTESTUDIANTE_H_
#define DTESTUDIANTE_H_

// STL
#include <string>

// DataTypes
#include "Date.h"

using namespace std;

class DTEstudiante {
private:
	string cedula;
	string nombre;
	string apellido;
	Date * fechaNac;
	int telefono;
	int creditosObtenidos;

public:
	DTEstudiante(string cedula,
			string nombre,
			string apellido,
			Date * fechaNac,
			int telefono,
			int creditosObtenidos);
	~DTEstudiante();

	string getCedula();
	string getNombre();
	string getApellido();
	Date * getFechaNac();
	int getTelefono();
	int getCreditosObtenidos();
};

#endif /* DTESTUDIANTE_H_ */
