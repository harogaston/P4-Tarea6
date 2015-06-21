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
 * Archivo: OfertaLaboral.cpp
 *******************************************************************************/

#include "OfertaLaboral.h"
#include "FechaSistema.h"
#include "ManejadorBedelia.h"
#include <stdexcept>

OfertaLaboral::OfertaLaboral(
		int numero_de_expediente,
		string titulo,
		string descripcion,
		int horas_semanales,
		float sueldo_min,
		float sueldo_max,
		Date * comienzo_llamado,
		Date * fin_llamado,
		int puestos_disponibles,
		set<string>* setAsignaturas,
		Seccion * seccion) {
	this->numero_de_expediente = numero_de_expediente;
	this->titulo = titulo;
	this->descripcion = descripcion;
	this->horas_semanales = horas_semanales;
	this->sueldo_min = sueldo_min;
	this->sueldo_max = sueldo_max;
	this->comienzo_llamado = comienzo_llamado;
	this->fin_llamado = fin_llamado;
	this->puestos_disponibles = puestos_disponibles;
	this->asignaturasRequeridas = new map<string, Asignatura*>;
	ManejadorBedelia * mb = ManejadorBedelia::getInstance();
	if (mb->validarAsignaturas(setAsignaturas)) {
		for (set<string>::iterator it = setAsignaturas->begin(); it != setAsignaturas->end(); ++it) {
			Asignatura * a = mb->getAsignatura((*it));
			this->asignaturasRequeridas->insert(pair<string,Asignatura*>(a->getCodigo(),a));
		}
	}
	this->contratos = new set<FirmaContrato*>;
	this->aplicaciones = new set<Aplica*>;
	this->seccion = seccion;
}

OfertaLaboral::~OfertaLaboral() {
	delete comienzo_llamado;
	delete fin_llamado;
	seccion = NULL;
	asignaturasRequeridas->clear();
	contratos->clear();
	aplicaciones->clear();
}

Date* OfertaLaboral::getComienzoLlamado() {
	return comienzo_llamado;
}

void OfertaLaboral::setComienzoLlamado(Date* comienzoLlamado) {
	comienzo_llamado = comienzoLlamado;
}

string OfertaLaboral::getDescripcion() {
	return descripcion;
}

void OfertaLaboral::setDescripcion(string descripcion) {
	this->descripcion = descripcion;
}

Date* OfertaLaboral::getFinLlamado() {
	return fin_llamado;
}

void OfertaLaboral::setFinLlamado(Date* finLlamado) {
	fin_llamado = finLlamado;
}

int OfertaLaboral::getHorasSemanales() {
	return horas_semanales;
}

void OfertaLaboral::setHorasSemanales(int horasSemanales) {
	horas_semanales = horasSemanales;
}

int OfertaLaboral::getNumeroDeExpediente() {
	return numero_de_expediente;
}

void OfertaLaboral::setNumeroDeExpediente(int numeroDeExpediente) {
	numero_de_expediente = numeroDeExpediente;
}

int OfertaLaboral::getPuestosDisponibles() {
	return puestos_disponibles;
}

void OfertaLaboral::setPuestosDisponibles(int puestosDisponibles) {
	puestos_disponibles = puestosDisponibles;
}

float OfertaLaboral::getSueldoMax() {
	return sueldo_max;
}

void OfertaLaboral::setSueldoMax(float sueldoMax) {
	sueldo_max = sueldoMax;
}

float OfertaLaboral::getSueldoMin() {
	return sueldo_min;
}

void OfertaLaboral::setSueldoMin(float sueldoMin) {
	sueldo_min = sueldoMin;
}

string OfertaLaboral::getTitulo() {
	return titulo;
}

void OfertaLaboral::setTitulo(string titulo) {
	this->titulo = titulo;
}

void OfertaLaboral::agregarAsignatura(Asignatura* a) {
	map<string, Asignatura*>::iterator it = asignaturasRequeridas->find(a->getCodigo());
	if (it == asignaturasRequeridas->end()){
		asignaturasRequeridas->insert(pair<string, Asignatura*>(a->getCodigo(), a));
	} else throw std::invalid_argument("La asignatura que intenta agregar ya estaba asociada en la oferta");
}

DTOferta* OfertaLaboral::crearDT() {
	DTOferta * dt = new DTOferta(numero_de_expediente, titulo);
	return dt;
}

void OfertaLaboral::cancelar() {
	for (set<FirmaContrato*>::iterator it1 = contratos->begin() ; it1 != contratos->end() ; it1++) {
		FirmaContrato * fir = *it1;
		fir->cancelar();
		delete fir;
	}
	contratos->clear();

	for (set<Aplica*>::iterator it2 = aplicaciones->begin() ; it2 != aplicaciones->end() ; it2++) {
		Aplica * a = *it2;
		a->cancelar();
		delete a;
	}
	aplicaciones->clear();

	this->seccion->cancelarOferta(this);
}

bool OfertaLaboral::esActiva() {
	FechaSistema * f = FechaSistema::getInstance();
	return ((*(f->getFecha()) <= *(this->fin_llamado)) && (*(f->getFecha()) >= *(this->comienzo_llamado)));
}

bool OfertaLaboral::esFinalizada() {
	FechaSistema * f = FechaSistema::getInstance();
	return (*(f->getFecha()) > *(fin_llamado));
}

FullDTOferta* OfertaLaboral::getFullDatos() {
	int cantidadInscriptos = 0;

	//calculo cantidad inscriptos a la oferta
	for (set<Aplica*>::iterator it = aplicaciones->begin();	it != aplicaciones->end(); it++) {
		cantidadInscriptos++;
	}

	FullDTOferta * dt = new FullDTOferta(
			numero_de_expediente,
			titulo,
			descripcion,
			horas_semanales,
			sueldo_min,
			sueldo_max,
			comienzo_llamado,
			fin_llamado,
			puestos_disponibles,
			seccion->getNombreEmpresa(),
			seccion->getUbicacion(),
			cantidadInscriptos);
	return dt;
}

bool OfertaLaboral::esElegible(string cedula) {
	for (map<string, Asignatura*>::iterator it = asignaturasRequeridas->begin() ;
			it != asignaturasRequeridas->end() ; it++) {
		if (not (*it).second->fueSalvada(cedula)) // si alguna asignatura no fue salvada se devuelve false
			return false;
	}
	return true;
}

void OfertaLaboral::asignarAplicacion(Aplica* a) {
	aplicaciones->insert(a);
}

void OfertaLaboral::asociarContrato(FirmaContrato* f) {
	contratos->insert(f);
}

DTAplicacion* OfertaLaboral::getDatosAplicacion() {
	DTAplicacion * dapReducido = seccion->getDatosSeccion();
	DTAplicacion * dap = new DTAplicacion(
			numero_de_expediente,
			titulo,
			dapReducido->getRutEmpresa(),
			dapReducido->getEmpresa(),
			dapReducido->getSucursal(),
			dapReducido->getTelefonoSuc(),
			dapReducido->getDireccionSuc(),
			dapReducido->getSeccion(),
			dapReducido->getInternoSeccion()
			);
	delete dapReducido;
	return dap;
}

set<DTEstudiante*>* OfertaLaboral::listarInscriptos() {
	set<DTEstudiante*> * setOut = new set<DTEstudiante*>;
	if (not aplicaciones->empty()) {
		for (set<Aplica*>::iterator it = aplicaciones->begin() ;
				it != aplicaciones->end() ; it++) {
			setOut->insert((*it)->getDTEstudiante());
		}
		return setOut;
	}
	return setOut;
}

void OfertaLaboral::modificarOferta(DataOfertaRestringida* dtOR) {
	titulo = dtOR->getTitulo();
	descripcion = dtOR->getDescripcion();
	horas_semanales = dtOR->getHorasSemanales();
	sueldo_min = dtOR->getSueldoMin();
	sueldo_max = dtOR->getSueldoMax();
	comienzo_llamado = dtOR->getComienzoLlamado();
	fin_llamado = dtOR->getFinLlamado();
	puestos_disponibles = dtOR->getPuestosDisponibles();
}

bool OfertaLaboral::seleccionarAsignatura(bool accion, string codigo) {
	if (accion) { //devuelvo TRUE si no existe, pues la quiero agregar
		return (asignaturasRequeridas->find(codigo) == asignaturasRequeridas->end());
	} else { // devuelvo TRUE si existe, pues la quiero quitar
		return (asignaturasRequeridas->find(codigo) != asignaturasRequeridas->end());
	}
}

void OfertaLaboral::quitarAsignaturaRequerida(string codigo) {
	map<string, Asignatura*>::iterator it = asignaturasRequeridas->find(codigo);

	if (it != asignaturasRequeridas->end()) {
		asignaturasRequeridas->erase(codigo);
	} else throw std::invalid_argument("La asignatura no estaba asociada previamente a la oferta");
}

bool OfertaLaboral::agendarEntrevista(Date* fecha) {
	//verifica si es posible agendar una entrevista
	return (*(fecha) >= *(fin_llamado));
}

void OfertaLaboral::crearEntrevista(string cedula, Date* fecha) {
	set<Aplica*>::iterator it = aplicaciones->begin();
	bool encontre = false;
	while(it != aplicaciones->end() && not encontre) {
		DTEstudiante * dt = (*it)->getDTEstudiante();
		if (dt->getCedula() == cedula) {
			(*it)->crearEntrevista(fecha);
			encontre = true;
		}
		it++;
	}
}

bool OfertaLaboral::estaContratado(string cedula) {
	set<FirmaContrato*>::iterator it = contratos->begin();
		bool encontre = false;
		while(it != contratos->end() && not encontre) {
			Estudiante * e = (*it)->getEstudiante();
			if (e->getCedula() == cedula) {
				return true;
			} else it++;
		}
		return false;
}

set<string>* OfertaLaboral::getAsignaturasRequeridas() {
	set<string>* setOut = new set<string>;
	for (map<string, Asignatura*>::iterator it = asignaturasRequeridas->begin() ; it != asignaturasRequeridas->end() ; it++) {
		setOut->insert((*it).second->getCodigo());
	}
	return setOut;
}
