/*
 * main.cpp
 *
 *  Created on: Jun 4, 2015
 *      Author: marccio
 */

#include <set>
#include <utility>

#include "DataEstudiante.h"
#include "Date.h"
#include "DTAplicacion.h"
#include "DTAsignaturaSalvada.h"
#include "DTCarrera.h"

using namespace std;

int main() {

	set<DTCarrera> carreras;
	carreras.insert(DTCarrera("1234", "Matematica"));
	carreras.insert(DTCarrera("12345", "Chorologia"));
	set<DTAsignaturaSalvada> asignaturas;
	set<DTAplicacion> aplicaciones;
	aplicaciones.insert(DTAplicacion(1, 1, 1, "bicha", "bicha", 1, "bicha", "bicha", 1));
	DataEstudiante dt = DataEstudiante(string("1"), string("Jorge"), string("Nasser"), Date(8, 1, 1992), 1, 1, &carreras, &asignaturas, &aplicaciones);

}


