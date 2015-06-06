/*
 * DataOferta.h
 *
 *  Created on: Jun 1, 2015
 *      Author: marccio
 */

#ifndef DATAOFERTA_H_
#define DATAOFERTA_H_

#include <string>
#include <set>

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
	DataOferta();
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
	set<string> * getAsignaturasRequeridas();
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

#endif /* DATAOFERTA_H_ */
