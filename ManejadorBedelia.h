/*
 * ManejadorBedelia.h
 *
 *  Created on: Jun 8, 2015
 *      Author: sofi
 */

#include <iostream>
#include <map>
#include <set>
#include <string>

#include "Asignatura.h"
#include "Carrera.h"
#include "DataEstudiante.h"
#include "Date.h"
#include "DTEstudiante.h"
#include "Estudiante.h"
#include "FullDTOferta.h"
#include "IObserver.h"

using namespace std;

class ManejadorBedelia {
	private:
		static ManejadorBedelia * instance;
		ManejadorBedelia();
		map<string, Estudiante*> Stds;
		map<string, Carrera*> Carr;
		map<string, Asignatura*> Asig;
		
	public: 
		static ManejadorBedelia * getInstance();
		
		bool validarAsignaturas(set<string> asignaturas);
		void agregarAsignaturas(OfertaLaboral of, set<string> asignaturas);
		bool existenCandidatos(OfertaLaboral of);
		void actualizarRequerimientos(); // PARAMETROS!!!
		void notificarObservers();
		void agregar(IObserver * ob);
		void quitar(IObserver * ob);
		void notificarCandidatos(OfertaLaboral of, set<string> asignaturas) //creo q no va
		set<DTEstudiante> listarNoInscriptos(int exp);
		Estudiante * getEstudiante(string ci);
		set<DTEstudiante> listarEstudiantes();
		DataEstudiante consultarDatosEstudiante(string ci);
		Estudiante * asignarCargo(FirmaContrato fir, string ci);
		void modDatosEstudiante(string nombre, string apellido, Date d, int tel);
		void addCarrera(string idCar, string ci);
		void quitCarrera(string idCar, string ci);
		void addAsignatura(string ci, Date d, int nota, string idAs);
		void quitAsignatura(string idAs, string ci);
		bool existeAsignatura(string idAs);
		set<FullDTOferta> mostrarNotificacionesDeEstudiante(string ci);
		
	 //Funciones para Cargar Datos
		Carrera crearCarrera(string idC, string nombre);
		Asignatura crearAsignatura(string codigo, string nombre, int creditos);
		void asociarAsignaturaACarrera(string idAs, string idC);
		void crearEstudiante(string ci, string nom, string ap, Date fecha_nac, int telefono, int cred);
		void asociarEstudianteACarrera(string ci, string idC);
}
