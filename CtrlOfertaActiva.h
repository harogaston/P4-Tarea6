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
 * Archivo: CtrlOfertaActiva.h
 *******************************************************************************/

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
	set<DTEstudiante*>* noInscriptos;

public:
	CtrlOfertaActiva();
	~CtrlOfertaActiva();

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
