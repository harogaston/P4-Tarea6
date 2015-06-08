/*
 * ManejadorOfertaLaboral.cpp
 *
 *  Created on: Jun 8, 2015
 *      Author: sofi
 */

/*		map<string, OfertaLaboral> Ofertas; */


	manejadorOfertaLaboral * manejadorOfertaLaboral::instance = NULL;
	manejadorOfertaLaboral::manejadorOfertaLaboral(){
	};
	manejadorOfertaLaboral * manejadorOfertaLaboral::getInstance(){
		if (instance==NULL)
			instance= new manejadorOfertaLaboral();
		return instance;
	};
	void ManejadorOfertaLaboral::agregarAsignatura(Asignatura as) {
		
	};
	DTOferta ManejadorOfertaLaboral::crearDT() {
		
	};
	void ManejadorOfertaLaboral::cancelar() {
		
	};
	bool ManejadorOfertaLaboral::esOfertaActiva() {
		
	};
	FullDTOferta ManejadorOfertaLaboral::getFullDatos() {
		
	};
	bool ManejadorOfertaLaboral::esElegible(string ci){
		
	};
	void ManejadorOfertaLaboral::asignarAplicacion(Aplica ap) {
		
	};
	DTAplicacion ManejadorOfertaLaboral::getDatosOL() {
		
	};
	bool ManejadorOfertaLaboral::esOfertaFinalizada() {
		
	};
	set<DTEstudiante> ManejadorOfertaLaboral::listarInscriptos() {
		
	};
	void ManejadorOfertaLaboral::asignarCargo(FirmaContrato fc) {
		
	};
	bool ManejadorOfertaLaboral::agendarEntrevista(Date d) {
		
	};
	bool ManejadorOfertaLaboral::crearEntrevista(string ci, Date d) {
		
	};
	void ManejadorOfertaLaboral::ingresarDatosOferta(DataOfertaRestringida dOR) {
		
	};
	bool ManejadorOfertaLaboral::seleccionarAsignatura(int accion, string idAs) {
		
	};
	void ManejadorOfertaLaboral::agregarAsignaturaRequerida(string idAs) {
		
	};
	void ManejadorOfertaLaboral::quitarAsignaturaRequerida(string idAs) {
		
	};
}