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
 * Archivo: DTSeccion.h
 *******************************************************************************/

#ifndef DTSECCION_H_
#define DTSECCION_H_

#include <string>

using namespace std;

class DTSeccion {
private:
	string idSec;
	int interno;

public:
	DTSeccion();
	DTSeccion(string idSec, int interno);
	~DTSeccion();

	string getIdSec();
	int getInterno();
};

#endif /* DTSECCION_H_ */
