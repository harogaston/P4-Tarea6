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

#include "Date.h"
#include "DTOferta.h"
#include "FullDTOferta.h"
#include "DTAplicacion.h"
#include "Aplica.h"

//forward-declaration de Asignatura
class Asignatura;

using namespace std;

class OfertaLaboral {
private:
	int numero_de_expediente;
	string titulo;
	string descripcion;
	int horas_semanales;
	float sueldo_min;
	float sueldo_max;
	Date comienzo_llamado;
	Date fin_llamado;
	int puestos_disponibles;
	set<Asignatura*> * asignaturasRequeridas;
public:
	OfertaLaboral();
	~OfertaLaboral();
	//getters y setters
	Date getComienzoLlamado();
	void setComienzoLlamado(Date comienzoLlamado);
	string getDescripcion();
	void setDescripcion(string descripcion);
	Date getFinLlamado();
	void setFinLlamado(Date finLlamado);
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
	void agregarAsignatura(Asignatura& a);
	DTOferta crearDT();
	void cancelar();
	bool esOfertaActiva();
	FullDTOferta getFullDatos();
	bool esElegible(string ci);
	void asignarAplicacion(Aplica& a);
	DTAplicacion getDatosOL();
};

#include "Asignatura.h"

#endif /* OFERTALABORAL_H_ */
