/*
 * FullDTOferta.h
 *
 *  Created on: Jun 2, 2015
 *      Author: marccio
 */

#ifndef FULLDTOFERTA_H_
#define FULLDTOFERTA_H_

#include <string>
#include <vector>

#include "Date.h"

using namespace std;

class FullDTOferta {
private:
	int numero_de_expediente;
	string titulo;
	string descripcion;
	int horas_semanales;
	float sueldo_min;
	float sueldo_max;
	Date * comienzo_llamado;
	Date * fin_llamado;
	int puestos_disponibles;
	string empresa;
	string ubicacionSucursal;
	int cantidad_inscriptos;

public:
	FullDTOferta();
	FullDTOferta(int numero_de_expediente,
			string titulo,
			string descripcion,
			int horas_semanales,
			float sueldo_min,
			float sueldo_max,
			Date& comienzo_llamado,
			Date& fin_llamado,
			int puestos_disponibles,
			string empresa,
			string ubicacionSucursal,
			int cantidad_inscriptos);
	virtual ~FullDTOferta();
	string getEmpresa();
	string getUbicacionSucursal();
	int getCantidadInscriptos();
	Date * getComienzoLlamado();
	string getDescripcion();
	Date * getFinLlamado();
	int getHorasSemanales();
	int getNumeroDeExpediente();
	int getPuestosDisponibles();
	float getSueldoMax();
	float getSueldoMin();
	string getTitulo();
};

#endif /* FULLDTOFERTA_H_ */
