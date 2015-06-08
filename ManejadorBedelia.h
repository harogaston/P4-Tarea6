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
#include "Estudiante"
#include "FullDTOferta.h"

using namespace std;

class manejadorBedelia {
	private:
		static manejadorBedelia * instance;
		manejadorBedelia();
		map<string, Estudiante> Stds;
		map<string, Carrera> Carr;
		map<string, Asignatura> Asig;
		
	public: 
		static manejadorBedelia * getInstance();
		
		bool validarAsignaturas(set<string> asignaturas);
		void agregarAsignaturas(OfertaLaboral of, set<string> asignaturas);
		bool existenCandidatos(OfertaLaboral of);
		void actualizarRequerimientos(); // PARAMETROS!!!
		void notificarObservers();
		void agregar(Observer ob);
		void quitar(Observer ob);
		void notificarCandidatos(OfertaLaboral of, set<string> asignaturas) //creo q no va
		set<DTEstudiante> listarNoInscriptos(int exp);
		Estudiante getEstudiante(string ci);
		set<DTEstudiante> listarEstudiantes();
		DataEstudiante consultarDatosEstudiante(string ci);
		Estudiante asignarCargo(FirmaContrato fir);
		void modDatosEstudiante(string nombre, string apellido, Date d, integer tel);
		void addCarrera(string idCar, string ci);
		void quitCarrera(string idCar, string ci);
		void addAsignatura(string idAs, Date d, integer nota, string ci);
		void quitAsignatura(string idAs, string ci);
		bool existeAsignatura(string idAs);
		set<FullDTOferta> mostrarNotificacionesDeEstudiante(string ci);
		
	 //Funciones para Cargar Datos
		Carrera crearCarrera(string idC, string nombre);
		Asignatura crearAsignatura(string idAs, string nombre);
		void asociarAsignaturaACarrera(string idAs, string idC);
		Estudiante crearEstudiante(string ci, string nom, string ap, Date fecha_nac, int telefono, int cred);
}
