/*
 * main.cpp
 *
 *  Created on: Jun 4, 2015
 *      Author: marccio
 */

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>

#include "DataEstudiante.h"
#include "Date.h"
#include "DTAplicacion.h"
#include "DTAsignaturaSalvada.h"
#include "DTCarrera.h"

using namespace std;

int main() {
	/*
	//Test DataEstudiante
	set<DTCarrera*> carreras;
	carreras.insert(new DTCarrera("1236", "Matematica"));
	carreras.insert(new DTCarrera("1362", "Chorologia"));
	set<DTAsignaturaSalvada*> asignaturas;
	set<DTAplicacion*> aplicaciones;
	aplicaciones.insert(new DTAplicacion(1, 1, 1, "Microsoft", "bicha", 1, "bicha", "bicha", 1));
	Date * fechaNacimiento = new Date(8, 1, 1992);
	DataEstudiante * dt = new DataEstudiante(
			"4.547.864-4",
			"Jorge",
			"Nasser",
			fechaNacimiento,
			4080637,
			401,
			&carreras,
			&asignaturas,
			&aplicaciones
			);
	cout << "Cedula: " << dt->getCedula() << endl;
	cout << "Nombre: " << dt->getNombre() << endl;
	cout << "Apellido: " << dt->getApellido() << endl;
	cout << "Fecha de nacimiento: " << dt->getFechaNac()->getDd() << "/" << dt->getFechaNac()->getMm() << "/" << dt->getFechaNac()->getAaaa() << endl;
	cout << "Teléfono: " << dt->getTelefono() << endl;
	cout << "Créditos obtenidos: " << dt->getCreditosObtenidos() << endl;
	for (set<DTCarrera*>::iterator it = dt->getCarreras()->begin() ; it != dt->getCarreras()->end() ; it++) {
		cout << "Carrera: " << (*it)->getNombre() << endl;
		cout << "Código de la carrera: " << (*it)->getCodigo() << endl;
	}
	for (set<DTAsignaturaSalvada*>::iterator it = dt->getAsignaturasSalvadas()->begin() ; it != dt->getAsignaturasSalvadas()->end() ; it++) {
		cout << "Asignatura: " << (*it)->getNombre() << endl;
	}
	for (set<DTAplicacion*>::iterator it = dt->getAplicaciones()->begin() ; it != dt->getAplicaciones()->end() ; it++) {
		cout << "Empresa a la que aplicó: " << (*it)->getEmpresa() << endl;
	}
	delete(dt);
	*/
}


