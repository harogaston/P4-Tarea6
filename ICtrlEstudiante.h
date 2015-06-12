/*
 * ICtrlEstudiante.h
 *
 *  Created on: Jun 11, 2015
 *      Author: marccio
 */

#ifndef ICTRLESTUDIANTE_H_
#define ICTRLESTUDIANTE_H_

using namespace std;

class ICtrlEstudiante {
public:
	virtual ~ICtrlEstudiante() {};
	virtual	set<DTEstudiante> listarEstudiantes() = 0;
	virtual bool seleccionarEstudiante(string) = 0;
	virtual DataEstudiante consultarDatosEstudiante() = 0;
	virtual void modDatosEstudiante(nom: string, ape: string, fecha: date, tel: integer) = 0;
	virtual void addCarrera(string) = 0;
	virtual void quitCarrera(string) = 0;
	virtual void addAsignatura(string, Date, int) = 0;
	virtual void quitAsignatura(string) = 0;
	virtual set<FullDTOferta> consultarNotificaciones() = 0;
};

#endif /* ICTRLESTUDIANTE_H_ */
