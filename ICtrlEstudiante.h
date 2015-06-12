/*
 * ICtrlEstudiantes.h
 *
 *  Created on: Jun 11, 2015
 *      Author: marccio
 */

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

class ICtrlEstudiantes {
public:
	virtual set<DTEstudiante> listarEstudiantes() = 0;
	virtual bool seleccionarEstudiante(string CI) = 0;
	virtual DataEstudiante consultarDatosEstudiante() = 0;
	virtual void modDatosEstudiante(string nom, string ape, Date* fechaNac, int tel) = 0;
	virtual void addCarrera(string cod) = 0;
	virtual void quitCarrera(string cod) = 0;
	virtual void addAsignatura(string cod, Date* fecha, int ) = 0;
	virtual void quitAsignatura(string cod) = 0;

	virtual void mostrarNotificaciones() = 0;


};

#endif /* ICTRLESTUDIANTE_H_ */
