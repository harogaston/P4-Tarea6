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
 * Archivo: ICtrlOfertaActiva.h
 *******************************************************************************/

#ifndef ICTRLOFERTAACTIVA_H_
#define ICTRLOFERTAACTIVA_H_

//STL
#include <set>

//Datatypes
#include "FullDTOferta.h"
#include "DTEstudiante.h"
#include "DataOfertaRestringida.h"

class ICtrlOfertaActiva {
public:
	virtual ~ICtrlOfertaActiva() {};

	// operaciones
	virtual set<FullDTOferta*>* listarOfertasActivas()= 0;
	virtual bool seleccionarOfertaActiva(int numExp)= 0;
	virtual set<DTEstudiante*>* listarNoInscriptos()= 0;
	virtual bool seleccionarEstudiante(string cedula)= 0;
	virtual void inscribirEstudiante()= 0;
	virtual void modificarOferta(DataOfertaRestringida * dtOR)= 0;
	virtual bool seleccionarAsignatura(bool accion, string codigo)= 0;
	virtual void agregarAsignaturaRequerida()= 0;
	virtual void quitarAsignaturaRequerida()= 0;
};

#endif /* ICTRLOFERTAACTIVA_H_ */
