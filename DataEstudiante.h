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
 * Archivo: DataEstudiante.h
 *******************************************************************************/

#ifndef DATAESTUDIANTE_H_
#define DATAESTUDIANTE_H_

// STL
#include <set>
#include <string>

// DataTypes
#include "DTAplicacion.h"
#include "DTAsignaturaSalvada.h"
#include "DTCarrera.h"

using namespace std;

class DataEstudiante {
private:
	string cedula;
	string nombre;
	string apellido;
	Date * fechaNac;
	int telefono;
	int creditosObtenidos;
	set<DTCarrera*> * carreras;
	set<DTAsignaturaSalvada*> * asignaturasSalvadas;
	set<DTAplicacion*> * aplicaciones;

public:
	DataEstudiante(string cedula,
			string nombre,
			string apellido,
			Date * fechaNac,
			int telefono,
			int creditosObtenidos,
			set<DTCarrera*> * carreras,
			set<DTAsignaturaSalvada*> * asignaturasSalvadas,
			set<DTAplicacion*> * aplicaciones);
	~DataEstudiante();

	string getCedula();
	string getNombre();
	string getApellido();
	Date * getFechaNac();
	int getTelefono();
	int getCreditosObtenidos();
	set<DTCarrera*> * getCarreras();
	set<DTAsignaturaSalvada*> * getAsignaturasSalvadas();
	set<DTAplicacion*> * getAplicaciones();
};

#endif /* DATAESTUDIANTE_H_ */
