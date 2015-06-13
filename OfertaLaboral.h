/*
 * OfertaLaboral.h
 *
 *  Created on: Jun 1, 2015
 *      Author: marccio
 */

#ifndef OFERTALABORAL_H_
#define OFERTALABORAL_H_

// STL
#include <string>
#include <set>
#include <map>
#include <iterator>

// DataTypes
#include "Date.h"
#include "DTOferta.h"
#include "FullDTOferta.h"
#include "DTAplicacion.h"
#include "DataOfertaRestringida.h"

// Clases
class Aplica;
class Asignatura;
#include "Seccion.h"
#include "FirmaContrato.h"

using namespace std;

class OfertaLaboral {
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
	map<string, Asignatura*> * asignaturasRequeridas;
	set<FirmaContrato*> * contratos;
	set<Aplica*> * aplicaciones;
	Seccion * seccion;

public:
	OfertaLaboral(
			int numero_de_expediente,
			string titulo,
			string descripcion,
			int horas_semanales,
			float sueldo_min,
			float sueldo_max,
			Date * comienzo_llamado,
			Date * fin_llamado,
			int puestos_disponibles,
			map<string, Asignatura*>* asignaturasRequeridas,
			Seccion * seccion);

	// getters y setters
	int getNumeroDeExpediente();
	void setNumeroDeExpediente(int numeroDeExpediente);
	string getTitulo();
	void setTitulo(string titulo);
	string getDescripcion();
	void setDescripcion(string descripcion);
	int getHorasSemanales();
	void setHorasSemanales(int horasSemanales);
	float getSueldoMin();
	void setSueldoMin(float sueldoMin);
	float getSueldoMax();
	void setSueldoMax(float sueldoMax);
	Date * getComienzoLlamado();
	void setComienzoLlamado(Date * comienzoLlamado);
	Date * getFinLlamado();
	void setFinLlamado(Date * finLlamado);
	int getPuestosDisponibles();
	void setPuestosDisponibles(int puestosDisponibles);

	// operaciones
	bool esActiva();
	bool esFinalizada();
	FullDTOferta * getFullDatos();
	DTOferta * crearDT();
	void cancelar();
	bool esElegible(string cedula);
	void asignarAplicacion(Aplica * a);
	void modificarOferta(DataOfertaRestringida * dtOR);
	bool seleccionarAsignatura(bool accion, string codigo);
	void agregarAsignatura(Asignatura * a);
	void quitarAsignaturaRequerida(string codigo);
	set<DTEstudiante*> * listarInscriptos();
	void asociarContrato(FirmaContrato * f);
	bool agendarEntrevista(Date * fecha);
	bool crearEntrevista(string cedula, Date * fecha);
	DTAplicacion* getDatosOL();
};

#include "Aplica.h"
#include "Asignatura.h"

#endif /* OFERTALABORAL_H_ */
