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
 * Archivo: ManejadorBedelia.cpp
 *******************************************************************************/

#include "ManejadorBedelia.h"
#include <stdexcept>

#include "EstrategiaDos.h"
#include "EstrategiaUno.h"

ManejadorBedelia * ManejadorBedelia::instancia = NULL;

ManejadorBedelia * ManejadorBedelia::getInstance(){
	if (instancia == NULL)
		instancia = new ManejadorBedelia();
		cout << "Creado manejador bedelia" << endl;
	return instancia;
}

ManejadorBedelia::ManejadorBedelia() {
	estrategia = NULL;
	estrategiaUno = NULL;
	estrategiaDos = NULL;
	observadores = NULL;
	estudiantes = NULL;
	carreras = NULL;
	asignaturas = NULL;
}

bool ManejadorBedelia::validarAsignaturas(set<string>* asignaturas) {
	//si en mi coleccion de asignaturas estan todas las pasadas por parametro
	//retorno TRUE
	for (set<string>::iterator it = asignaturas->begin() ;
			it != asignaturas->end() ; it++ ) {
		//si no se encuentra
		if (not (this->asignaturas->find((*it)) != this->asignaturas->end()))
			return false;
	}
	return true;
}

void ManejadorBedelia::agregarAsignaturas(OfertaLaboral* of, set<string>* asignaturas) {
}

bool ManejadorBedelia::existenCandidatos(set<string> * asignaturas) {
	for (map<string, Estudiante*>::iterator it = estudiantes->begin() ;
			it != estudiantes->end() ; it++) {
		//si alguno es candidato devuelvo TRUE
		if ((*it).second->esCandidato(asignaturas)) return true;
	}
	return false;
}

set<string>* ManejadorBedelia::getEstrategiaDos(set<string> * asignaturasRequeridas) {
	IStrategy * strategy = new EstrategiaDos();
	return strategy->actualizarRequerimientos(estudiantes, asignaturasRequeridas, asignaturas);
}

set<string>* ManejadorBedelia::getEstrategiaUno() {
	IStrategy * strategy = new EstrategiaUno();
	return strategy->actualizarRequerimientos(estudiantes, NULL, NULL);
}

set<string> * ManejadorBedelia::actualizarRequerimientos(int criterio, set<string> * asignaturasRequeridas) {
	if (criterio == 1) {
		return this->getEstrategiaUno();
	} else if (criterio == 2) {
		return this->getEstrategiaDos(asignaturasRequeridas);
	} else throw std::invalid_argument("Ese criterio no existe.\n");
}

void ManejadorBedelia::notificarObservers(OfertaLaboral * oferta,
		set<string> * asignaturas) {
	Notificacion * n = new Notificacion(oferta);
	for (set<IObserver*>::iterator it = observadores->begin() ;
			it != observadores->end() ; it++) {
		(*it)->notificar(n, asignaturas);
	}
}

void ManejadorBedelia::agregar(IObserver* ob) {
	observadores->insert(ob);
}

void ManejadorBedelia::quitar(IObserver* ob) {
	bool found = false;
	set<IObserver*>::iterator it = observadores->begin();
	while (not found) {
		if ((*it) == ob) {
			observadores->erase(it);
			found = true;
		}
	}
}

set<DTEstudiante*>* ManejadorBedelia::listarNoInscriptos(int exp) {
	set<DTEstudiante*> * setOut = NULL;
	for (map<string, Estudiante*>::iterator it = estudiantes->begin() ;
			it != estudiantes->end() ; it++) {
		bool estaInscripto = (*it).second->estaInscripto(exp);
		if (not estaInscripto) {
			string ci = (*it).second->getCedula();
			ManejadorOfertaLaboral * mol = ManejadorOfertaLaboral::getInstance();
			bool posible = mol->esElegible(exp, ci);
			if (posible) {
				DTEstudiante * dt = (*it).second->crearDT();
				setOut->insert(dt);
			}
		}
	}
	return setOut;
}

Estudiante* ManejadorBedelia::getEstudiante(string ci) {
	map<string, Estudiante*>::iterator it = estudiantes->find(ci);
	if (it != estudiantes->end()) return (*it).second;
	else throw std::invalid_argument("Ese estudiante no existe.\n");
}

set<DTEstudiante*>* ManejadorBedelia::listarEstudiantes() {
	set<DTEstudiante*> * setOut = NULL;
	for (map<string, Estudiante*>::iterator it = estudiantes->begin() ;
			it != estudiantes->end() ; it++) {
		DTEstudiante * dt = (*it).second->crearDT();
		setOut->insert(dt);
	}
	return setOut;
}

DataEstudiante* ManejadorBedelia::consultarDatosEstudiante(string cedula) {
	DataEstudiante * dtOut = NULL;
	map<string, Estudiante*>::iterator it = estudiantes->find(cedula);
	if (it != estudiantes->end()) {
		dtOut = (*it).second->consultarDatosEstudiante();
	}
	return dtOut;
}

Estudiante* ManejadorBedelia::asignarCargo(FirmaContrato* fir, string ci) {
	map<string, Estudiante*>::iterator it = estudiantes->find(ci);
	if (it != estudiantes->end()) {
		(*it).second->asociarContrato(fir);
		return (*it).second;
	} else throw std::invalid_argument("Cedula no valida.\n");
}

void ManejadorBedelia::modificarEstudiante(	string cedula,
											string nombre,
											string apellido,
											Date * fecha,
											int tel) {

	map<string, Estudiante*>::iterator it = estudiantes->find(cedula);
	if (it != estudiantes->end())
		it->second->modificarEstudiante(nombre, apellido, fecha, tel);
}

void ManejadorBedelia::addCarrera(string cedula, string idCar) {
	map<string, Carrera*>::iterator it = carreras->find(idCar);
	if (it != carreras->end()) {
		map<string, Estudiante*>::iterator it1 = estudiantes->find(cedula);
		if (it1 != estudiantes->end()) {
			(*it1).second->addCarrera((*it).second);
		}
	}
}

void ManejadorBedelia::quitCarrera(string idCar, string ci) {
	map<string, Carrera*>::iterator it = carreras->find(idCar);
	if (it != carreras->end()) {
		map<string, Estudiante*>::iterator it1 = estudiantes->find(ci);
		if (it1 != estudiantes->end()) {
			(*it1).second->quitCarrera((*it).second);
		}
	}
}

void ManejadorBedelia::addAsignatura(string cedula, Date* fecha, int nota,
		string codigo) {
	map<string, Asignatura*>::iterator it = asignaturas->find(codigo);
	if (it != asignaturas->end()) {
		bool salvada = (*it).second->fueSalvada(cedula);
		if (not salvada) {
			map<string, Estudiante*>::iterator it1 = estudiantes->find(cedula);
			if (it1 != estudiantes->end()) {
				bool enCarrera = (*it1).second->asignaturaEnCarrera(codigo);
				if (enCarrera) {
					Salva * s = new Salva(fecha, nota);
					s->asociarAsignaturaEstudiante((*it).second, (*it1).second); //linkeo el 'salva' con asignatura y estudiante
					(*it).second->addSalvada(s); //linkeo asignatura con salva
					(*it1).second->addSalvada(s); //linkeo estudiante con salva
					(*it1).second->agregarCreditos((*it).second->getCreditos());
				}
			}
		}

	}
}

void ManejadorBedelia::quitAsignatura(string codigo, string cedula) {
	map<string, Asignatura*>::iterator it = asignaturas->find(codigo);
	if (it != asignaturas->end()) {
		bool salvada = (*it).second->fueSalvada(cedula);
		if (salvada) {
			Salva * s = (*it).second->getSalvada(cedula);
			map<string, Estudiante*>::iterator it1 = estudiantes->find(cedula);
			if (it1 != estudiantes->end()) {
				(*it1).second->quitAsignatura(s);
				(*it1).second->quitarCreditos((*it).second->getCreditos());
			}
			delete s;
		}
	}
}

bool ManejadorBedelia::existeAsignatura(string idAs) {
	return (asignaturas->find(idAs) != asignaturas->end());
}

set<FullDTOferta*>* ManejadorBedelia::mostrarNotificacionesDeEstudiante(string cedula) {
	set<FullDTOferta*> * setOut = NULL;
	map<string, Estudiante*>::iterator it = estudiantes->find(cedula);
	if (it != estudiantes->end()) {
		setOut = (*it).second->mostrarNotificaciones();
	}
	return setOut;
}

void ManejadorBedelia::crearCarrera(string idC, string nombre) {
	Carrera * c = new Carrera(idC, nombre);
	carreras->insert(pair<string, Carrera*>(idC, c));
}

void ManejadorBedelia::crearAsignatura(string codigo, string nombre,
		int creditos) {
	Asignatura * a = new Asignatura(codigo, nombre, creditos);
	asignaturas->insert(pair<string, Asignatura*>(codigo, a));
}

void ManejadorBedelia::asociarAsignaturaACarrera(string idAs, string idC) {
	map<string, Carrera*>::iterator it = carreras->find(idC);
	map<string, Asignatura*>::iterator it1 = asignaturas->find(idAs);
	if (it != carreras->end() && it1 != asignaturas->end())
		(*it).second->addAsignatura((*it1).second);
}

void ManejadorBedelia::crearEstudiante(string ci, string nom, string ap,
		Date* fecha_nac, int telefono, int cred) {
	Estudiante * e = new Estudiante(ci, nom, ap, fecha_nac, telefono, cred);
	estudiantes->insert(pair<string, Estudiante*>(ci, e));
}

void ManejadorBedelia::asociarEstudianteACarrera(string ci, string idC) {
	map<string, Carrera*>::iterator it = carreras->find(idC);
	map<string, Estudiante*>::iterator it1 = estudiantes->find(ci);
	if (it != carreras->end() && it1 != estudiantes->end())
		(*it1).second->addCarrera((*it).second);
}

Asignatura* ManejadorBedelia::getAsignatura(string cod) {
	map<string, Asignatura*>::iterator it = asignaturas->find(cod);
	if (it != asignaturas->end()) return (*it).second;
	else throw std::invalid_argument("Esa asignatura no existe.\n");
}
