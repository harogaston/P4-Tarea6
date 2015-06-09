/*
 * ManejadorBedelia.cpp
 *
 *  Created on: Jun 8, 2015
 *      Author: sofi
 */

#include <iostream>
#include <map>
#include <set>
#include <string>

#include "ManejadorBedelia.h"

#include "Asignatura.h"
#include "Carrera.h"
#include "DataEstudiante.h"
#include "Date.h"
#include "DTEstudiante.h"
#include "Estudiante"
#include "FullDTOferta.h"

/*
	map<string, Estudiante*> Stds;
	map<string, Carrera*> Carr;
	map<string, Asignatura*> Asig;
*/

	manejadorBedelia * manejadorBedelia::instance = NULL;
	manejadorBedelia::manejadorBedelia(){
	
	} 
	manejadorBedelia * manejadorBedelia::getInstance(){
		if (instance==NULL)
			instance= new manejadorBedelia();
		return instance;
	}
		
	bool manejadorBedelia::validarAsignaturas(set<string> asignaturas) {
		
	};
	void manejadorBedelia::agregarAsignaturas(OfertaLaboral of, set<string> asignaturas) {
		
	};
	bool manejadorBedelia::existenCandidatos(OfertaLaboral of) {
		
	};
	void manejadorBedelia::actualizarRequerimientos() { // PARAMETROS!!!
		
	}; 
	void manejadorBedelia::notificarObservers() {
		
	};
	void manejadorBedelia::agregar(Observer ob) {
		
	};
	void manejadorBedelia::quitar(Observer ob) { 
	};
	void manejadorBedelia::notificarCandidatos(OfertaLaboral of, set<string> asignaturas) { //creo q no va 

	}
	set<DTEstudiante> manejadorBedelia::listarNoInscriptos(int exp) {
		
	};
	Estudiante manejadorBedelia::getEstudiante(string ci) {
		
	};
	set<DTEstudiante> manejadorBedelia::listarEstudiantes() {
		
	};
	DataEstudiante manejadorBedelia::consultarDatosEstudiante(string ci) {
		
	};
	Estudiante manejadorBedelia::asignarCargo(FirmaContrato fir, string ci) {
		
	};
	void manejadorBedelia::modDatosEstudiante(string nombre, string apellido, Date d, integer tel) {
		
	};
	void manejadorBedelia::addCarrera(string idCar, string ci) {
		
	};
	void manejadorBedelia::quitCarrera(string idCar, string ci) {
		
	};
	void manejadorBedelia::addAsignatura(string ci, Date d, integer nota, string idAs) {
	};
	void manejadorBedelia::quitAsignatura(string idAs, string ci) {
		
	};
	bool manejadorBedelia::existeAsignatura(string idAs) {
		
	};
	set<FullDTOferta> manejadorBedelia::mostrarNotificacionesDeEstudiante(string ci) {
		
	};

	//Funciones para Cargar Datos
	Carrera manejadorBedelia::crearCarrera(string idC, string nombre) {
		
	};
	Asignatura manejadorBedelia::crearAsignatura(string idAs, string nombre) {
		
	};
	void manejadorBedelia::asociarAsignaturaACarrera(string idAs, string idC) {
		
	};
	void manejadorBedelia::crearEstudiante(string ci, string nom, string ap, Date fecha_nac, int telefono, int cred) {
	};
	void manejadorBedelia::asociarEstudianteACarrera(string ci, string idC) {
		
	};