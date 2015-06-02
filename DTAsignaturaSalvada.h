/*
 * DTAsignaturaSalvada.h
 *
 *  Created on: Jun 2, 2015
 *      Author: marccio
 */

#ifndef DTASIGNATURASALVADA_H_
#define DTASIGNATURASALVADA_H_

#include <string>

#include "Date.h"

using namespace std;

class DTAsignaturaSalvada {
private:
	string codigo;
	string nombre;
	Date * fecha;
	int nota;
public:
	DTAsignaturaSalvada();
	DTAsignaturaSalvada(string codigo, string nombre, Date& fecha, int nota);
	virtual ~DTAsignaturaSalvada();
	string getCodigo();
	string getNombre();
	Date * getFecha();
	int getNota();
};

#endif /* DTASIGNATURASALVADA_H_ */
