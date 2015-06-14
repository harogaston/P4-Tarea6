/*
 * ManejadorBedelia.h
 *
 *  Created on: Jun 11, 2015
 *      Author: marccio
 */

#ifndef MANEJADORBEDELIA_H_
#define MANEJADORBEDELIA_H_

// STL
#include <map>
#include <set>
#include <string>

// DataTypes
#include "DTEstudiante.h"
#include "FullDTOferta.h"

// Clases
#include "Asignatura.h"
#include "Carrera.h"
#include "Estudiante.h"
#include "IStrategy.h"
#include "ManejadorOfertaLaboral.h"

using namespace std;

class ManejadorBedelia {
private:
	static ManejadorBedelia * instancia = NULL;
	ManejadorBedelia();

	IStrategy * estrategia;
	set<string> * estrategiaSimple;
	set<string> * estrategiaGrupo;

	map<string, Estudiante*> * estudiantes;
	map<string, Carrera*> * carreras;
	map<string, Asignatura*> * asignaturas;
	set<IObserver*> * observadores;

public:
	static ManejadorBedelia * getInstance();

	// operaciones
	set<DTEstudiante*> * listarEstudiantes();
	DataEstudiante * consultarDatosEstudiante(string cedula);
	set<FullDTOferta*> * mostrarNotificacionesDeEstudiante(string cedula);
	set<DTEstudiante*> * listarNoInscriptos(int exp);
	Estudiante * getEstudiante(string cedula);
	bool existeAsignatura(string cod);
	Estudiante * asignarCargo(FirmaContrato * fir, string cedula);
	void modificarEstudiante(string cedula, string nombre, string apellido, Date * fecha, int tel);
	void addCarrera(string cedula, string idCar);
	void quitCarrera(string cedula, string idCar);
	bool validarAsignaturas(set<string> * asignaturas);
	bool existenCandidatos(set<string> * asignaturas);
	set<string> * getEstrategiaGrupo();
	set<string> * getEstrategiaSimple(set<string> * asignaturas);
	set<string> * actualizarRequerimientos(int criterio);
	void agregarAsignaturas(OfertaLaboral * of, set<string> * asignaturas);
	Asignatura * getAsignatura(string cod);
	void notificarObservers(OfertaLaboral * oferta, set<string> * asignaturas);
	void addAsignatura(string cedula, Date * fecha, int nota, string idAs);
	void quitAsignatura(string cedula, string idAs);

/* Estas operaciones no aparece en los
 * diagramas de comunicacion
 * pero sin dudas tienen que estar!!!
 *
 * Es decir, hay que modificarlos
 * para que incluiyan lo del patron
 * Observer.
 *
 * void agregar(IObserver * ob);
 * void quitar(IObserver * ob);
 * */

	// main
	void crearCarrera(string idC, string nombre);
	void crearAsignatura(string codigo, string nombre, int creditos);
	void asociarAsignaturaACarrera(string idAs, string idC);
	void crearEstudiante(string ci, string nom, string ap, Date * fecha_nac, int telefono, int cred);
	void asociarEstudianteACarrera(string ci, string idC);
};

#endif /* MANEJADORBEDELIA_H_ */
