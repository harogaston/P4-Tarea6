/*
 * CtrOfertasActivas.h
 *
 *  Created on: Jun 11, 2015
 *      Author: marccio
 */

#ifndef CTRLOFERTAACTIVA_H_
#define CTRLOFERTAACTIVA_H_

#include "DataOfertaRestringida.h"
#include "DTEstudiante.h"
#include "FullDTOferta.h"
#include "ICtrlOfertaActiva.h"

using namespace std;

class CtrlOfertaActiva : public ICtrlOfertaActiva {
public:
	CtrlOfertaActiva();
	virtual ~CtrOfertaActiva();

	set<FullDTOferta> listarOfertasActivas();
	bool seleccionarOfertaActiva(int);
	set<DTEstudiante> listarNoInscriptos();
	bool seleccionarEstudiante(string);
	void inscribirEstudiante();
	void ingresarDatosOferta(DataOfertaRestringida);
	bool seleccionarAsignatura(bool, string);
	void agregarAsignaturaRequerida();
	void quitarAsignaturaRequerida();
};

#endif /* CTRLOFERTAACTIVA_H_ */
