/*
 * CtrlEstudiante.h
 *
 *  Created on: Jun 11, 2015
 *      Author: marccio
 */

#ifndef CTRLESTUDIANTE_H_
#define CTRLESTUDIANTE_H_

#include "DataEstudiante.h"
#include "DTEstudiante.h"
#include "FullDTOferta.h"
#include "ICtrlEstudiante.h"

using namespace std;

class CtrlEstudiante : public ICtrlEstudiante {
public:
	CtrlEstudiante();
	virtual ~CtrlEstudiante();
	set<DTEstudiante> listarEstudiantes();
	bool seleccionarEstudiante(string);
	DataEstudiante consultarDatosEstudiante();
	void modDatosEstudiante(nom: string, ape: string, fecha: date, tel: integer);
	void addCarrera(string);
	void quitCarrera(string);
	void addAsignatura(string, Date, int);
	void quitAsignatura(string);
	set<FullDTOferta> consultarNotificaciones();
};

#endif /* CTRLESTUDIANTE_H_ */
