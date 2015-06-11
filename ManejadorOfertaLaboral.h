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
		static ManejadorOfertaLaboral * instance;
		ManejadorOfertaLaboral();
		map<string, OfertaLaboral*> Ofertas;
	public:
		static ManejadorOfertaLaboral * getInstance();
		
		bool verificarExpediente(int exp);
		void agregarOfertaLaboral(OfertaLaboral * o);
		DataOferta * crearDataOferta(
				int numero_de_expediente,
				string titulo,
				string descripcion,
				int horas_semanales,
				float sueldo_min,
				float sueldo_max,
				Date * comienzo_llamado,
				Date * fin_llamado,
				int puestos_disponibles,
				set<string> * asignaturasRequeridas); //metodo bastante al pedo!

		DTAplicacion getDatosOL();

		void agregarAsignatura(Asignatura as);
		DTOferta crearDT();
		void cancelar();

		bool esOfertaActiva();
		FullDTOferta getFullDatos();

		bool esElegible(string ci);
		void asignarAplicacion(Aplica ap);


		bool esOfertaFinalizada();
		set<DTEstudiante> listarInscriptos();
		OfertaLaboral asignarCargo(FirmaContrato fc, int numExp);

		bool agendarEntrevista(Date d);
		bool crearEntrevista(string ci, Date d);

		void ingresarDatosOferta(DataOfertaRestringida dOR);
		bool seleccionarAsignatura(int accion, string idAs);
		void agregarAsignaturaRequerida(string idAs);
		void quitarAsignaturaRequerida(string idAs);
}
