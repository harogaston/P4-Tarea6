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
 * Archivo: OfertaLaboral.h
 *******************************************************************************/

#ifndef OFERTALABORAL_H_
#define OFERTALABORAL_H_

// STL
#include <string>
#include <set>
#include <map>

// DataTypes
#include "Date.h"
#include "DTOferta.h"
#include "FullDTOferta.h"
#include "DTAplicacion.h"
#include "DataOfertaRestringida.h"
#include "DTEstudiante.h"

// Clases
class Aplica;
class Asignatura;
class FirmaContrato;
#include "Seccion.h"

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

	Seccion * seccion;
	map<string, Asignatura*> * asignaturasRequeridas;
	set<FirmaContrato*> * contratos;
	set<Aplica*> * aplicaciones;

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
			set<string> * asignaturasRequeridas,
			Seccion * seccion);
	~OfertaLaboral();

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
	DTAplicacion* getDatosAplicacion();
	DTOferta * crearDT();
	void cancelar();
	bool esElegible(string cedula);
	void asignarAplicacion(Aplica * a);
	void modificarOferta(DataOfertaRestringida * dtOR);
	bool seleccionarAsignatura(bool accion, string codigo);
	void agregarAsignatura(Asignatura * a);
	void quitarAsignaturaRequerida(string codigo);
	set<DTEstudiante*> * listarInscriptos();
	void asociarContrato(FirmaContrato * fir);
	bool agendarEntrevista(Date * fecha);
	void crearEntrevista(string cedula, Date * fecha);
};

#include "Aplica.h"
#include "Asignatura.h"
#include "FirmaContrato.h"

#endif /* OFERTALABORAL_H_ */
