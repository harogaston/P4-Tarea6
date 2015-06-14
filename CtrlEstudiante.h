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
 * Archivo: CtrlEstudiante.h
 *******************************************************************************/

#ifndef CTRLESTUDIANTE_H_
#define CTRLESTUDIANTE_H_

// STL
#include <set>
#include <string>

// DataTypes
#include "DataEstudiante.h"
#include "DTEstudiante.h"
#include "FullDTOferta.h"

// Clases
#include "ICtrlEstudiante.h"
#include "ManejadorBedelia.h"

using namespace std;

class CtrlEstudiante : public ICtrlEstudiante {
private:
	string cedula;
	set<DTEstudiante*> * listadoEstudiantes;

public:
	CtrlEstudiante();
	~CtrlEstudiante();

	// operaciones
	set<DTEstudiante*> * listarEstudiantes();
	bool seleccionarEstudiante(string cedula);
	DataEstudiante * consultarDatosEstudiante();
	set<FullDTOferta*> * mostrarNotificacionesDeEstudiante(string cedula);
	void modificarEstudiante(string nombre, string apellido, Date * fecha, int tel);
	void addCarrera(string idCarrera);
	void quitCarrera(string idCarrera);
	void addAsignatura(Date * fecha, int nota, string idAs);
	void quitAsignatura(string idAs);
};

#endif /* CTRLESTUDIANTE_H_ */
