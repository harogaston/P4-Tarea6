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
 * Archivo: DTAplicacion.h
 *******************************************************************************/

#ifndef DTAPLICACION_H_
#define DTAPLICACION_H_

#include <string>

using namespace std;

class DTAplicacion {
private:
	int expedienteOferta;
	string tituloOferta;
	string rutEmpresa;
	string empresa;
	string sucursal;
	int telefonoSuc;
	string direccionSuc;
	string seccion;
	int internoSeccion;

public:
	DTAplicacion(
			int expedienteOferta,
			string tituloOferta,
			string rutEmpresa,
			string empresa,
			string sucursal,
			int telefonoSuc,
			string direccionSuc,
			string seccion,
			int internoSeccion);
	~DTAplicacion();

	string getDireccionSuc();
	string getEmpresa();
	int getExpedienteOferta();
	int getInternoSeccion();
	string getRutEmpresa();
	string getSeccion();
	string getSucursal();
	int getTelefonoSuc();
	string getTituloOferta();
};

#endif /* DTAPLICACION_H_ */
