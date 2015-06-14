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
//#include "DTSeccion.h"
//#include "DataOferta.h"
//

using namespace std;

class ICtrlEstudiante {
public:
	virtual ~ICtrlEstudiante() {};
	virtual	set<DTEstudiante> listarEstudiantes() = 0;
	virtual bool seleccionarEstudiante(string) = 0;
	virtual DataEstudiante consultarDatosEstudiante() = 0;
	virtual void modDatosEstudiante(string nom, string ape, Date fechaNac, int tel) = 0;
	virtual void addCarrera(string) = 0;
	virtual void quitCarrera(string) = 0;
	virtual void addAsignatura(string, Date, int) = 0;
	virtual void quitAsignatura(string) = 0;
	virtual set<FullDTOferta> consultarNotificaciones() = 0;
};

#endif /* ICTRLESTUDIANTE_H_ */
