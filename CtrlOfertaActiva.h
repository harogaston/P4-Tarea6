/*
 * CtrOfertasActivas.h
 *
 *  Created on: Jun 11, 2015
 *      Author: marccio
 */

#ifndef CTRLOFERTAACTIVA_H_
#define CTRLOFERTAACTIVA_H_

// DataTypes
#include "DataOfertaRestringida.h"
#include "DTEstudiante.h"
#include "FullDTOferta.h"

// Clases
#include "ICtrlOfertaActiva.h"
#include "OfertaLaboral.h"
#include "ManejadorOfertaLaboral.h"
#include "ManejadorBedelia.h"
#include "Aplica.h"
#include "Estudiante.h"

using namespace std;

class CtrlOfertaActiva : public ICtrlOfertaActiva {
private:
	int numExp;
	string cedula;
	string cod;

public:
	// operaciones
	set<FullDTOferta*>* listarOfertasActivas();
	bool seleccionarOfertaActiva(int numExp);
	set<DTEstudiante*>* listarNoInscriptos();
	bool seleccionarEstudiante(string cedula);
	void inscribirEstudiante();
	void modificarOferta(DataOfertaRestringida * dtOR);
	bool seleccionarAsignatura(bool accion, string cod);
	void agregarAsignaturaRequerida();
	void quitarAsignaturaRequerida();
};

#endif /* CTRLOFERTAACTIVA_H_ */
