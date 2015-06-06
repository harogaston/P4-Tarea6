/*
 * DTAplicacion.h
 *
 *  Created on: Jun 2, 2015
 *      Author: marccio
 */

#ifndef DTAPLICACION_H_
#define DTAPLICACION_H_

#include <string>

using namespace std;

class DTAplicacion {
private:
	int expedienteOferta;
	string tituloOferta;
	int rutEmpresa;
	string empresa;
	string sucursal;
	string telefonoSuc;
	string direccionSuc;
	string seccion;
	int internoSeccion;
public:
	DTAplicacion(
			int expedienteOferta,
			string tituloOferta,
			int rutEmpresa,
			string empresa,
			string sucursal,
			string telefonoSuc,
			string direccionSuc,
			string seccion,
			int internoSeccion);
	~DTAplicacion();
	string getDireccionSuc();
	string getEmpresa();
	int getExpedienteOferta();
	int getInternoSeccion();
	int getRutEmpresa();
	string getSeccion();
	string getSucursal();
	string getTelefonoSuc();
	string getTituloOferta();
};

#endif /* DTAPLICACION_H_ */
