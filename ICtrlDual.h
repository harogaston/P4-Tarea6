/*
 * ICtrlDual.h
 *
 *  Created on: Jun 2, 2015
 *      Author: marccio
 */

#ifndef ICTRLDUAL_H_
#define ICTRLDUAL_H_

#include <set>
#include <string>

using namespace std;

class ICtrlDual {
public:
	virtual ~ICtrlDual();
	virtual set<FullDTOferta*> * listarOfertasActivas() = 0;
	virtual set<DTEstudiante*> * listarEstudiantes() = 0;
	virtual bool seleccionarEstudiante(string cedula) = 0;
	virtual DataEstudiante* consultarDatosEstudiante() = 0;
	virtual bool seleccionarOfertaActiva(int exp) = 0;
	virtual set<DTEstudiante*> * listarNoInscriptos() = 0;
	virtual void inscribirEstudiante() = 0;
};

#endif /* ICTRLDUAL_H_ */
