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
 * Archivo: DTSucursal.h
 *******************************************************************************/

#ifndef DTSUCURSAL_H_
#define DTSUCURSAL_H_

#include <string>

using namespace std;

class DTSucursal {
private:
	string idSuc;
	int telefono;
	string direccion;

public:
	DTSucursal(string idSuc, int telefono, string direccion);
	~DTSucursal();

	string getIdSuc();
	int getTelefono();
	string getDireccion();
};

#endif /* DTSUCURSAL_H_ */
