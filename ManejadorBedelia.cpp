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
#include <iostream>
#include "EstrategiaDos.h"
#include "EstrategiaUno.h"
#include "Notificacion.h"

ManejadorBedelia * ManejadorBedelia::instancia = NULL;

ManejadorBedelia * ManejadorBedelia::getInstance(){
	if (instancia == NULL)
		instancia = new ManejadorBedelia();
	return instancia;
}

ManejadorBedelia::ManejadorBedelia() {
	estrategia = NULL;
	estrategiaUno = new set<string>;
	estrategiaDos = new set<string>;
	observadores = new set<IObserver*>;
	estudiantes = new map<string, Estudiante*>;
	carreras = new map<string, Carrera*>;
	asignaturas = new map<string, Asignatura*>;
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
	ManejadorOfertaLaboral * mol = ManejadorOfertaLaboral::getInstance();
	for (set<string>::iterator it1 = asignaturas->begin() ;
			it1 != asignaturas->end() ; it1++){
		map<string, Asignatura*>::iterator it2 = this->asignaturas->find((*it1));
		if (it2 != this->asignaturas->end()) { //la agrego
			mol->asociarAsignaturaAOferta(of, (*it2).second);
		}
	}
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
	} else throw std::invalid_argument("Ese criterio no se encuentra en el sistema.");
}

void ManejadorBedelia::notificarObservers(OfertaLaboral * of, set<string> * asignaturas) {
	for (set<IObserver*>::iterator it3 = observadores->begin() ;
			it3 != observadores->end() ; it3++) {
		(*it3)->notificar(new Notificacion(of), asignaturas);
		/*
		cout << "El estudiante " << static_cast<Estudiante*>(*it3)->getNombre()
				<< " " << static_cast<Estudiante*>(*it3)->getApellido() <<
				"fue notificado" << endl;
		*/
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

set<DTEstudiante*>* ManejadorBedelia::listarNoInscriptos(int numExp) {
	set<DTEstudiante*> * setOut = new set<DTEstudiante*>;
	for (map<string, Estudiante*>::iterator it = estudiantes->begin() ;
			it != estudiantes->end() ; it++) {
		bool estaInscripto = (*it).second->estaInscripto(numExp);
		if (not estaInscripto) {
			string cedula = (*it).second->getCedula();
			ManejadorOfertaLaboral * mol = ManejadorOfertaLaboral::getInstance();
			bool elegible = mol->esElegible(numExp, cedula);
			if (elegible) {
				DTEstudiante * dt = (*it).second->crearDT();
				setOut->insert(dt);
			}
		}
	}
	return setOut;
}

Estudiante* ManejadorBedelia::getEstudiante(string cedula) {
	map<string, Estudiante*>::iterator it = estudiantes->find(cedula);
	if (it != estudiantes->end()) return (*it).second;
	else throw std::invalid_argument("Ese estudiante no se encuentra en el sistema.");
}

set<DTEstudiante*>* ManejadorBedelia::listarEstudiantes() {
	set<DTEstudiante*> * setOut = new set<DTEstudiante*>;
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
		} else throw std::invalid_argument("Ese Estudiante no se encuentra en el Sistema.");
	} else throw std::invalid_argument("Esa Carrera no se encuentra en el Sistema.");
}

void ManejadorBedelia::quitCarrera(string cedula, string idCar) {
	map<string, Carrera*>::iterator it = carreras->find(idCar);
	if (it != carreras->end()) {
		map<string, Estudiante*>::iterator it1 = estudiantes->find(cedula);
		if (it1 != estudiantes->end()) {
			(*it1).second->quitCarrera((*it).second);
		} else throw std::invalid_argument("Ese Estudiante no se encuentra en el Sistema.");
	} else throw std::invalid_argument("Esa Carrera no se encuentra en el Sistema.");
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
				} else throw std::invalid_argument("Esa Asignatura no pertenece a las Carreras que cursa el Estudiante.");
			}
		} else throw std::invalid_argument("Esa Asignatura ya fue aprobada por el Estudiante.");

	} else throw std::invalid_argument("Esa Asignatura no se encuentra en el Sistema.");
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
			} else throw std::invalid_argument("Ese Estudiante no se encuentra en el Sistema.");
			delete s;
		} else throw std::invalid_argument("Esa Asignatura no ha sido aprobada por el Estudiante.");
	} else throw std::invalid_argument("Esa Asignatura no se encuentra en el Sistema.");
}

bool ManejadorBedelia::existeAsignatura(string codigo) {
	return (asignaturas->find(codigo) != asignaturas->end());
}

set<FullDTOferta*>* ManejadorBedelia::mostrarNotificacionesDeEstudiante(string cedula) {
	set<FullDTOferta*> * setOut = new set<FullDTOferta*>;
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

void ManejadorBedelia::asociarAsignaturaACarrera(string idC, string idAs) {
	map<string, Carrera*>::iterator it = carreras->find(idC);
	map<string, Asignatura*>::iterator it1 = asignaturas->find(idAs);
	if ((it != carreras->end()) && (it1 != asignaturas->end()))
		(*it).second->addAsignatura((*it1).second);
}

void ManejadorBedelia::crearEstudiante(string ci, string nom, string ap,
		Date* fecha_nac, int telefono, int cred) {
	Estudiante * e = new Estudiante(ci, nom, ap, fecha_nac, telefono, cred);
	estudiantes->insert(pair<string, Estudiante*>(ci, e));
	observadores->insert(e);
}

void ManejadorBedelia::asociarEstudianteACarrera(string ci, string idC) {
	map<string, Carrera*>::iterator it = carreras->find(idC);
	map<string, Estudiante*>::iterator it1 = estudiantes->find(ci);
	if ((it != carreras->end()) && (it1 != estudiantes->end()))
		(*it1).second->addCarrera((*it).second);
}

Asignatura* ManejadorBedelia::getAsignatura(string codigo) {
	map<string, Asignatura*>::iterator it = asignaturas->find(codigo);
	if (it != asignaturas->end()) return (*it).second;
	else throw std::invalid_argument("Esa asignatura no se encuentra en el sistema.");
}

map<string, Asignatura*>* ManejadorBedelia::getAsignaturas() {
	return asignaturas;
}

set<DTAsignatura*>* ManejadorBedelia::listarAsignaturas() {
	set<DTAsignatura*>* setOut = new set<DTAsignatura*>;
	for(map<string, Asignatura*>::iterator it = asignaturas->begin() ;
			it != asignaturas->end() ; it++) {
		DTAsignatura * dt = (*it).second->crearDT();
		setOut->insert(dt);
	}
	return setOut;
}

set<DTCarrera*>* ManejadorBedelia::listarCarreras() {
	set<DTCarrera*>* setOut = new set<DTCarrera*>;
	for(map<string, Carrera*>::iterator it = carreras->begin() ;
			it != carreras->end() ; it++) {
		DTCarrera * dt = (*it).second->crearDT();
		setOut->insert(dt);
	}
	return setOut;
}

ManejadorBedelia::~ManejadorBedelia() {
	estrategiaUno->clear();
	delete estrategiaUno;
	estrategiaDos->clear();
	delete estrategiaDos;
	delete estrategia;
	for (set<IObserver*>::iterator it1 = observadores->begin() ;
			it1 != observadores->end() ; it1++) {
		delete * it1;
	}
	observadores->clear();
	estudiantes->clear(); //se borran como observadores
	for (map<string, Carrera*>::iterator it2 = carreras->begin() ;
			it2 != carreras->end() ; it2++) {
		delete (*it2).second;
	}
	carreras->clear();
	for (map<string, Asignatura*>::iterator it3 = asignaturas->begin() ;
			it3 != asignaturas->end() ; it3++) {
		delete (*it3).second;
	}
	asignaturas->clear();

}

void ManejadorBedelia::ManejadorBedelia::destroyInstance() {
	if (instancia != NULL) {
		delete instancia;
		instancia = NULL;
	}
}
//TESTING
/*
void ManejadorBedelia::printAsignaturas() {
	cout << "PrintAsignaturas. \n";
	if(! this->asignaturas->empty()) {
		cout << "Asignaturas Registradas:" << endl;
		for(map<string, Asignatura*>::iterator it = this->asignaturas->begin() ; it!=this->asignaturas->end() ; it++) {
			cout << "	**Codigo: " << (*it).second->getCodigo() << endl;
		};
	}
	else {
		cout << "No existen Asignaturas registradas en el Sistema. \n";
		};
}
*/
/*
 void ManejadorBedelia::printAsignaturasDeCarrera(string ca) {
	cout << "Aisgnaturas de : " << ca << endl;
	map<string, Carrera*> * carrs = this->carreras;
	map<string, Carrera*>::iterator it;
	it = carrs->find(ca);
	Carrera * c = (*it).second;
	if (!c->asignaturas->empty()){
		for(map<string, Asignatura*>::iterator itA = c->asignaturas->begin() ; itA != c->asignaturas->end() ; itA++) {
			cout << "	**Codigo: " << (*itA).second->getCodigo() << endl;
		};
	}
	else {
		cout << "No hay Asignaturas asociadas a esta Carrera.\n";
	}

}
 */
