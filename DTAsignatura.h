/*
 * DTAsignatura.h
 *
 *  Created on: Jun 6, 2015
 *      Author: marccio
 */

#ifndef DTASIGNATURA_H_
#define DTASIGNATURA_H_

#include <string>

using namespace std;

class DTAsignatura {
private:
	string codigo;
	string nombre;
	int creditos;
public:
	DTAsignatura(string codigo, string nombre, int creditos);
	~DTAsignatura();
	string getCodigo();
	string getNombre();
	int getCreditos();
};

#endif /* DTASIGNATURA_H_ */
