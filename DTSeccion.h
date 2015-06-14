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
