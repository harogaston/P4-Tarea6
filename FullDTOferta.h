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
 * Archivo: FullDTOferta.h
 *******************************************************************************/

#ifndef FULLDTOFERTA_H_
#define FULLDTOFERTA_H_

// STL
#include <string>

// DataTypes
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
	FullDTOferta(int numero_de_expediente,
			string titulo,
			string descripcion,
			int horas_semanales,
			float sueldo_min,
			float sueldo_max,
			Date * comienzo_llamado,
			Date * fin_llamado,
			int puestos_disponibles,
			string empresa,
			string ubicacionSucursal,
			int cantidad_inscriptos);
	~FullDTOferta();

	// getters
	int getNumeroDeExpediente();
	string getTitulo();
	string getDescripcion();
	int getHorasSemanales();
	float getSueldoMin();
	float getSueldoMax();
	Date * getComienzoLlamado();
	Date * getFinLlamado();
	int getPuestosDisponibles();
	string getEmpresa();
	string getUbicacionSucursal();
	int getCantidadInscriptos();
};

#endif /* FULLDTOFERTA_H_ */
