/*
 * DataOferta.h
 *
 *  Created on: Jun 1, 2015
 *      Author: marccio
 */

#ifndef DATAOFERTA_H_
#define DATAOFERTA_H_

// STL
#include <string>
#include <set>

// DataTypes
#include "Date.h"

using namespace std;

class DataOferta {
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
	set<string> * asignaturasRequeridas;

public:
	DataOferta(int numero_de_expediente,
			string titulo,
			string descripcion,
			int horas_semanales,
			float sueldo_min,
			float sueldo_max,
			Date * comienzo_llamado,
			Date * fin_llamado,
			int puestos_disponibles,
			set<string> * asignaturasRequeridas);
	~DataOferta();

	int getNumeroDeExpediente();
	string getTitulo();
	string getDescripcion();
	int getHorasSemanales();
	float getSueldoMin();
	float getSueldoMax();
	Date * getComienzoLlamado();
	Date * getFinLlamado();
	int getPuestosDisponibles();
	set<string> * getAsignaturasRequeridas();
};

#endif /* DATAOFERTA_H_ */
