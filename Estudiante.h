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
 * Archivo: Estudiante.h
 *******************************************************************************/

#ifndef ESTUDIANTE_H_
#define ESTUDIANTE_H_

// STL
#include <set>
#include <string>
#include <map>

// DataTypes
#include "DTEstudiante.h"
#include "DataEstudiante.h"
#include "Date.h"
#include "DataOferta.h"

// Clases
class Aplica;
class Salva;
class Carrera;
#include "FirmaContrato.h"
#include "IObserver.h"
#include "Notificacion.h"
#include "Asignatura.h"

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
	map<string, Carrera*> * carreras;
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
	~Estudiante();

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
	set<DataOferta*>* mostrarNotificaciones();
	void cancelarContrato(FirmaContrato * fc);
	void cancelarAplica(Aplica * a);
	bool estaInscripto(int numExp);
	void asignarAplicacion(Aplica * a);
	void asociarContrato(FirmaContrato * fir);
	void modificarEstudiante(string nombre, string apellido, Date * fecha, int telefono);
	void addCarrera(Carrera * car);
	void quitCarrera(Carrera * car);
	void addSalvada(Salva * s);
	bool esCandidato(set<string> * asignaturas);
	set<DTAsignaturaSalvada*>* listarSalvadas();
	bool asignaturaEnCarrera(string codigo);
	void agregarCreditos(int creditos);
	void quitarCreditos(int creditos);
	void quitAsignatura(Salva * s);
	void notificar(Notificacion * notificacion, set<string> * asignaturas);
};

#include "Aplica.h"
#include "Salva.h"
#include "Carrera.h"

#endif /* ESTUDIANTE_H_ */
