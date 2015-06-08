/*
 * ManejadorOfertaLaboral.h
 *
 *  Created on: Jun 8, 2015
 *      Author: sofi
 */

#include <iostream>
#include <map>
#include <set>
#include <string>

#include "Aplica.h"
#include "Asignatura.h"
#include "DataOfertaRestringida.h"
#include "Date.h"
#include "DTAplicacion.h"
#include "DTEstudiante.h"
#include "DTOferta.h"
#include "FirmaContrato.h"
#include "FullDTOferta.h"
#include "OfertaLaboral.h"

using namespace std;

class ManejadorOfertaLaboral {
	private:
		static manejadorOfertaLaboral * instance;
		manejadorOfertaLaboral();
		map<string, OfertaLaboral> Ofertas;
	public:
		static manejadorOfertaLaboral * getInstance();
		
		void agregarAsignatura(Asignatura as);
		DTOferta crearDT();
		void cancelar();

		bool esOfertaActiva();
		FullDTOferta getFullDatos();

		bool esElegible(string ci);
		void asignarAplicacion(Aplica ap);

		DTAplicacion getDatosOL();

		bool esOfertaFinalizada();
		set<DTEstudiante> listarInscriptos();
		void asignarCargo(FirmaContrato fc);

		bool agendarEntrevista(Date d);
		bool crearEntrevista(string ci, Date d);

		void ingresarDatosOferta(DataOfertaRestringida dOR);
		bool seleccionarAsignatura(int accion, string idAs);
		void agregarAsignaturaRequerida(string idAs);
		void quitarAsignaturaRequerida(string idAs);
}