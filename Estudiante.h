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
#include <iterator>

#include "DTEstudiante.h"
#include "Aplica.h"
#include "Notificacion.h"
#include "DataEstudiante.h"
#include "Carrera.h"
#include "Salva.h"
#include "IObserver.h"

class Notificacion;
class FirmaContrato;

using namespace std;

class Estudiante : public IObserver {
private:
	string cedula;
	string nombre;
	string apellido;
	Date * fecha_nac;
	string telefono;
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
			string telefono
			);
	~Estudiante();
	//getters y setters
	string getCedula();
	string getNombre();
	string getApellido();
	Date * getFechaNacimiento();
	string getTelefono();
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
	void notificar(Notificacion * notificacion, set<string> * asignaturas);
	void modificarDatosEstudiante(
			string cedula,
			string nombre,
			string apellido,
			Date * fecha,
			string telefono);
	void addCarrera(Carrera * c);
	void quitCarrera(Carrera * c);
	bool asignaturaEnCarrera(string a);
	void addSalva(Salva * s);
	void quitAsignatura(Salva * s);
	set<FullDTOferta*> * mostrarNotificacionesDeEstudiante();
};

#include "FirmaContrato.h"
#include "Notificacion.h"

#endif /* ESTUDIANTE_H_ */
