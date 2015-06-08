/*
 * DTSeccion.h
 *
 *  Created on: Jun 1, 2015
 *      Author: marccio
 */

#ifndef DTSECCION_H_
#define DTSECCION_H_

#include <string>

using namespace std;

class DTSeccion {
private:
	string nombre;
	string interno;
public:
	DTSeccion();
	DTSeccion(string nombre, string interno);
	~DTSeccion();
	string getNombre();
	string getInterno();
};

#endif /* DTSECCION_H_ */
