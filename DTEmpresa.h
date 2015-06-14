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
 * Archivo: DTEmpresa.h
 *******************************************************************************/

#ifndef DTEMPRESA_H_
#define DTEMPRESA_H_

#include <string>

using namespace std;

class DTEmpresa {
private:
	string RUT;
	string nombre;

public:
	DTEmpresa(string rut, string nombre);
	~DTEmpresa();

	string getRUT();
	string getNombre();
};

#endif /* DTEMPRESA_H_ */
