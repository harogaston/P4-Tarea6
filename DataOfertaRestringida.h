/*
 * DataOfertaRestringida.h
 *
 *  Created on: Jun 8, 2015
 *      Author: marccio
 */

#ifndef DATAOFERTARESTRINGIDA_H_
#define DATAOFERTARESTRINGIDA_H_

// STL
#include <string>

// DataTypes
#include "Date.h"

using namespace std;

class DataOfertaRestringida {
private:
	string titulo;
	string descripcion;
	int horas_semanales;
	float sueldo_min;
	float sueldo_max;
	Date * comienzo_llamado;
	Date * fin_llamado;
	int puestos_disponibles;

public:
	DataOfertaRestringida(
			string titulo,
			string descripcion,
			int horas_semanales,
			float sueldo_min,
			float sueldo_max,
			Date * comienzo_llamado,
			Date * fin_llamado,
			int puestos_disponibles);
	~DataOfertaRestringida();

	string getTitulo();
	string getDescripcion();
	int getHorasSemanales();
	float getSueldoMin();
	float getSueldoMax();
	Date * getComienzoLlamado();
	Date * getFinLlamado();
	int getPuestosDisponibles();
};

#endif /* DATAOFERTARESTRINGIDA_H_ */
