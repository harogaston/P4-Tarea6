/*
 * Estudiante.h
 *
 *  Created on: Jun 6, 2015
 *      Author: marccio
 */

#ifndef ESTUDIANTE_H_
#define ESTUDIANTE_H_

#include <set>
#include <string>

#include "DTEstudiante.h"
#include "Aplica.h"
#include "Notificacion.h"
#include "DataEstudiante.h"
#include "Carrera.h"
#include "Salva.h"
#include "IObserver.h"
#include "Notificacion.h"

class FirmaContrato;

using namespace std;

class Estudiante : public IObserver {
private:
	string cedula;
	string nombre;
	string apellido;
	Date * fecha_nac;
	int telefono;
	int creditosObtenidos;
	set<FirmaContrato*> * contratos;
	set<Salva*> * salvadas;
	set<Carrera*> * carreras;
	set<Notificacion*> * notificaciones;
	set<Aplica*> * aplicaciones;
public:
	Estudiante(
			string cedula,
			string nombre,
			string apellido,
			Date * fecha_nac,
			int telefono
			);
	~Estudiante();
	//getters y setters
	string getCedula();
	string getNombre();
	string getApellido();
	string getFechaNacimiento();
	int getTelefono();
	int getCreditosObtenidos();
	//operaciones
	void asignarCargo(FirmaContrato * f);
	void cancelarContrato(FirmaContrato * f);
	DTEstudiante * crearDT();
	void cancelarAplica(Aplica * a);
	bool esNoInscripto(int exp);
	void asignarAplicacion(Aplica * a);
	DataEstudiante * consultarDatosEstudiante();
	bool esCandidato(set<string> * asignaturasRequeridas);
	void notificar(Notificacion * n, set<string> * asignaturas);
	void modificarDatosEstudiante(
			string cedula,
			string nombre,
			string apellido,
			Date * fecha,
			int telefono);
	void addCarrera(Carrera * c);
	void quitCarrera(Carrera * c);
	bool asignaturaEnCarrera(string a);
	void addSalva(Salva * s);
	void quitAsignatura(Salva * s);
	set<FullDTOferta*> * mostrarNotificacionesDeEstudiante();
};

#include "FirmaContrato.h"

#endif /* ESTUDIANTE_H_ */
