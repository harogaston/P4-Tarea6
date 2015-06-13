/*
 	 * Estudiante.h
 *
 *  Created on: Jun 6, 2015
 *      Author: marccio
 */

#ifndef ESTUDIANTE_H_
#define ESTUDIANTE_H_

// STL
#include <set>
#include <string>

// DataTypes
#include "DTEstudiante.h"
#include "DataEstudiante.h"
#include "Date.h"

// Clases
#include "Aplica.h"
#include "Carrera.h"
#include "FirmaContrato.h"
#include "IObserver.h"
#include "Notificacion.h"
#include "Salva.h"

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
			int telefono,
			int creditosObtenidos
			);

	// getters
	string getCedula();
	string getNombre();
	string getApellido();
	Date * getFechaNacimiento();
	int getTelefono();
	int getCreditosObtenidos();

	// operaciones
	DTEstudiante* crearDT();
	DataEstudiante* consultarDatosEstudiante();
	set<FullDTOferta*>* mostrarNotificaciones();
	void cancelarContrato(FirmaContrato * fc);
	void cancelarAplica(Aplica * a);
	bool estaInscripto(int numExp);
	void asignarAplicacion(Aplica * a);
	void asociarContrato(FirmaContrato * fir);
	void modificarEstudiante(string nombre, string apellido, Date * fecha, int telefono);
	void addCarrera(Carrera * car);
	void quitCarrera(Carrera * car);
	void addSalva(Salva * s);
	bool esCandidato(set<string> * asignaturas);
	set<DTAsignaturaSalvada*>* listarSalvadas();
	bool asignaturaEnCarrera(string idAs);
	void agregarCreditos(int nuevosCreditos);
	void quitarCreditos(int nuevosCreditos);
	void quitAsignatura(Salva * s);
	void notificar(Notificacion * notificacion, set<string> * asignaturas);
};

#endif /* ESTUDIANTE_H_ */
