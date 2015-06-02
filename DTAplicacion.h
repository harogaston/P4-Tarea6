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
	int expediente_oferta;
	string tituloOferta;
	int rutEmpresa;
	string empresa;
	string sucursal;
	int telefonoSuc;
	string direccionSuc;
	string seccion;
	int internoSeccion;
public:
	DTAplicacion();
	DTAplicacion(int expediente_oferta,
			int tituloOferta,
			int rutEmpresa,
			string empresa,
			string sucursal,
			int telefonoSuc,
			string direccionSuc,
			string seccion,
			int internoSeccion);
	virtual ~DTAplicacion();
	string getDireccionSuc();
	string getEmpresa();
	int getExpedienteOferta();
	int getInternoSeccion();
	int getRutEmpresa();
	string getSeccion();
	string getSucursal();
	int getTelefonoSuc();
	string getTituloOferta();
};

#endif /* DTAPLICACION_H_ */
