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
 * Archivo: ICtrlEstudiante.h
 *******************************************************************************/

#ifndef ICTRLESTUDIANTE_H_
#define ICTRLESTUDIANTE_H_

#include <set>
#include <string>

#include "DTEstudiante.h"
#include "DataEstudiante.h"
#include "Date.h"
#include "FullDTOferta.h"

using namespace std;

class ICtrlEstudiante {
public:
	virtual ~ICtrlEstudiante() {};
	virtual set<DTEstudiante*> * listarEstudiantes() = 0;
	virtual bool seleccionarEstudiante(string cedula)= 0;
	virtual DataEstudiante * consultarDatosEstudiante()= 0;
	virtual set<FullDTOferta*> * mostrarNotificacionesDeEstudiante()= 0;
	virtual void modificarEstudiante(string nombre, string apellido, Date * fecha, int tel)= 0;
	virtual void addCarrera(string idCarrera)= 0;
	virtual void quitCarrera(string idCarrera)= 0;
	virtual void addAsignatura(Date * fecha, int nota, string idAs)= 0;
	virtual void quitAsignatura(string idAs)= 0;
};

#endif /* ICTRLESTUDIANTE_H_ */
