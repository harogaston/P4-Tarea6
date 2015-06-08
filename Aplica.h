/*
 * Aplica.h
 *
 *  Created on: Jun 7, 2015
 *      Author: marccio
 */

#ifndef APLICA_H_
#define APLICA_H_

#include <set>

#include "Entrevista.h"
#include "DTAplicacion.h"
#include "DTEstudiante.h"
class OfertaLaboral;
class Estudiante;

using namespace std;

class Aplica {
private:
	Date * fecha;
	set<Entrevista*> * entrevistas;
	Estudiante * estudiante;
	OfertaLaboral * oferta;
public:
	Aplica(Date * f, Estudiante * e, OfertaLaboral * o);
	~Aplica();
	void cancelar();
	bool yaEstaInscripto(int a);
	DTAplicacion * getDatosAplicacion();
	DTEstudiante * getEstudiante();
	Aplica * getAplicacionEstudiante(string a);
	void crearEntrevista(Date * d);
};

#include "OfertaLaboral.h"
#include "Estudiante.h"

#endif /* APLICA_H_ */
