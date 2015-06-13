/*
 * Aplica.h
 *
 *  Created on: Jun 7, 2015
 *      Author: marccio
 */

#ifndef APLICA_H_
#define APLICA_H_

// STL
#include <set>

// DataTypes
#include "DTAplicacion.h"
#include "DTEstudiante.h"

// Clases
#include "Entrevista.h"
#include "Estudiante.h"
#include "FechaSistema.h"
#include "OfertaLaboral.h"

using namespace std;

class Aplica {
private:
	Date * fecha;
	set<Entrevista*> * entrevistas;
	Estudiante * estudiante;
	OfertaLaboral * oferta;

public:
	// operaciones
	DTAplicacion * getDatosAplicacion();
	void cancelar();
	bool estaInscripto(int numExp);
	DTEstudiante * getDTEstudiante();
	void crearEntrevista(Date * fecha);
};

#endif /* APLICA_H_ */
