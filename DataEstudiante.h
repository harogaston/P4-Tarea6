/*
 * DataEstudiante.h
 *
 *  Created on: Jun 2, 2015
 *      Author: marccio
 */

#ifndef DATAESTUDIANTE_H_
#define DATAESTUDIANTE_H_

#include <set>
#include <string>

#include "DTAplicacion.h"
#include "DTAsignaturaSalvada.h"
#include "DTCarrera.h"

using namespace std;

class DataEstudiante {
private:
	string cedula;
	string nombre;
	string apellido;
	Date fechaNac;
	int telefono;
	int creditosObtenidos;
	set<DTCarrera*> * carreras;
	set<DTAsignaturaSalvada*> * asignaturasSalvadas;
	set<DTAplicacion*> * aplicaciones;
public:
	DataEstudiante();
	DataEstudiante(string cedula,
			string nombre,
			string apellido,
			Date& fechaNac,
			int telefono,
			int creditosObtenidos,
			set<DTCarrera*>& carreras,
			set<DTAsignaturaSalvada*>& asignaturasSalvadas,
			set<DTAplicacion*>& aplicaciones);
	virtual ~DataEstudiante();
	string getCedula();
	string getNombre();
	string getApellido();
	Date getFechaNac();
	int getTelefono();
	int getCreditosObtenidos();
	set<DTCarrera*> * getCarreras();
	set<DTAsignaturaSalvada*> * getAsignaturasSalvadas();
	set<DTAplicacion*> * getAplicaciones();
};

#endif /* DATAESTUDIANTE_H_ */
