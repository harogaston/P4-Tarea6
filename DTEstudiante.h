/*
 * DTEstudiante.h
 *
 *  Created on: Jun 2, 2015
 *      Author: marccio
 */

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
	string telefono;
	int creditosObtenidos;

public:
	DTEstudiante();
	DTEstudiante(string cedula,
			string nombre,
			string apellido,
			Date * fechaNac,
			string telefono,
			int creditosObtenidos);
	~DTEstudiante();

	string getCedula();
	string getNombre();
	string getApellido();
	Date * getFechaNac();
	string getTelefono();
	int getCreditosObtenidos();
};

#endif /* DTESTUDIANTE_H_ */
