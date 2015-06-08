/*
 * OfertaLaboral.h
 *
 *  Created on: Jun 1, 2015
 *      Author: marccio
 */

#ifndef OFERTALABORAL_H_
#define OFERTALABORAL_H_

#include <string>
#include <set>
#include <map>

#include "Date.h"
#include "DTOferta.h"
#include "FullDTOferta.h"
#include "DTAplicacion.h"
#include "Aplica.h"
#include "FirmaContrato.h"
#include "DataOfertaRestringida.h"

//forward-declarations
class Asignatura;
class Seccion;

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
			map<string, Asignatura*> * asignaturasRequeridas,
			Seccion * seccion);
	~OfertaLaboral();
	//getters y setters
	Date * getComienzoLlamado();
	void setComienzoLlamado(Date * comienzoLlamado);
	string getDescripcion();
	void setDescripcion(string descripcion);
	Date * getFinLlamado();
	void setFinLlamado(Date * finLlamado);
	int getHorasSemanales();
	void setHorasSemanales(int horasSemanales);
	int getNumeroDeExpediente();
	void setNumeroDeExpediente(int numeroDeExpediente);
	int getPuestosDisponibles();
	void setPuestosDisponibles(int puestosDisponibles);
	float getSueldoMax();
	void setSueldoMax(float sueldoMax);
	float getSueldoMin();
	void setSueldoMin(float sueldoMin);
	string getTitulo();
	void setTitulo(string titulo);
	//operaciones
	void agregarAsignatura(Asignatura * a);
	DTOferta * crearDT();
	void cancelar();
	bool esOfertaActiva();
	FullDTOferta * getFullDatos();
	bool esElegible(string ci);
	void asignarAplicacion(Aplica * a);
	void asignarCargo(FirmaContrato * f);
	DTAplicacion * getDatosOL();
	set<DTEstudiante*> * listarInscriptos();
	void ingresarDatosOferta(DataOfertaRestringida * dtOR);
	bool seleccionarAsignatura(string accion, string codigo);
};

#include "Asignatura.h"
#include "Seccion.h"

#endif /* OFERTALABORAL_H_ */
