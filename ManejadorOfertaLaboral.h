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
 * Archivo: ManejadorOfertaLaboral.h
 *******************************************************************************/

#ifndef MANEJADOROFERTALABORAL_H_
#define MANEJADOROFERTALABORAL_H_

// STL
#include <map>
#include <set>
#include <string>

// DataTypes
#include "DTEstudiante.h"

// Clases
#include "FirmaContrato.h"
#include "OfertaLaboral.h"

using namespace std;

class ManejadorOfertaLaboral {
private:
	static ManejadorOfertaLaboral * instancia;
	ManejadorOfertaLaboral();

	map<int, OfertaLaboral*> * ofertas;

public:
	static ManejadorOfertaLaboral * getInstance();

	// operaciones
	set<FullDTOferta*> * listarOfertasActivas();
	set<DTOferta*> * listarOfertasTodas();
	set<DTOferta*> * listarOfertasFinalizadas();
	bool seleccionarOferta(int numExp);
	bool seleccionarOfertaFinalizada(int numExp);
	bool seleccionarOfertaActiva(int numExp);
	void darDeBaja(int numExp);
	bool esElegible(int numExp, string cedula);
	OfertaLaboral * getOfertaLaboral(int numExp);
	void modificarOferta(int numExp, DataOfertaRestringida * dataOferta);
	bool seleccionarAsignatura(bool accion, string codigo, int numExp);
	void agregarAsignatura(string codigo, int numExp);
	void quitarAsignatura(string codigo, int numExp);
	set<DTEstudiante*> * listarInscriptos(int numExp);
	OfertaLaboral * asignarCargo(FirmaContrato * fir, int numExp);
	bool agendarEntrevista(Date * fecha, int numExp);
	void crearEntrevista(int numExp, string cedula, Date * fecha);
	bool chequearExpedienteDisponible(int numExp);
	void agregarOfertaLaboral(OfertaLaboral * of);
	void asociarAsignaturaAOferta(OfertaLaboral * of, Asignatura * asignatura);

	//Se necesita para actualizarRequerimientos, no lo saquen más carajo
	DataOferta * crearDataOferta(
			int numero_de_expediente,
			string titulo,
			string descripcion,
			int horas_semanales,
			float sueldo_min,
			float sueldo_max,
			Date * comienzo_llamado,
			Date * fin_llamado,
			int puestos_disponibles,
			set<string> * asignaturasRequeridas);
};

#endif /* MANEJADOROFERTALABORAL_H_ */
