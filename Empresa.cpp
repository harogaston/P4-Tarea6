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
 * Archivo: Empresa.cpp
 *******************************************************************************/

#include "Empresa.h"

#include <stdexcept>
#include <iterator>

Empresa::Empresa(int rut, string nombre) {
	this->rut = rut;
	this->nombre = nombre;
	this->sucursales = NULL;
}

Empresa::~Empresa() {
	for (map<string, Sucursal*>::iterator it = sucursales->begin() ;
			it != sucursales->end() ; it++) {
		delete * it;
	}
	sucursales->clear();
	delete sucursales;
}

void Empresa::agregarSucursal(string idSuc, Sucursal* s){
	sucursales->insert(pair<string, Sucursal*>(idSuc, s));
};

DTEmpresa* Empresa::crearDT() {
	DTEmpresa * dt = new DTEmpresa(this->rut, this->nombre);
	return dt;
}

set<DTSucursal*>* Empresa::listarSucursales() {
	set<DTSucursal*> * setSucursales = NULL;
	for (map<string, Sucursal*>::iterator it = sucursales->begin() ; it != sucursales->end() ; it++) {
		setSucursales->insert(new DTSucursal((*it).second->getNombre(), (*it).second->getTelefono(), (*it).second->getDireccion()));
	}
	return setSucursales;
}

bool Empresa::seleccionarSucursal(string idSuc) {
	return (sucursales->find(idSuc) != sucursales->end());
}

set<DTSeccion*>* Empresa::listarSecciones(string idSuc) {
	map<string, Sucursal*>::iterator it = sucursales->find(idSuc);
	if (it != sucursales->end()) {
		return (*it).second->listarSecciones();
	} else {
		return NULL;
	}
}

bool Empresa::seleccionarSeccion(string idSuc, string idSec) {
	map<string, Sucursal*>::iterator it = sucursales->find(idSuc);
	if (it != sucursales->end()) {
		return (*it).second->seleccionarSeccion(idSec);
	} else return false;
}

OfertaLaboral* Empresa::crearOferta(DataOferta * dtO, string idSuc, string idSec) {
	map<string, Sucursal*>::iterator it = sucursales->find(idSuc);
	if (it != sucursales->end()){
		return (*it).second->crearOferta(dtO, idSec);
	} else {
		throw std::invalid_argument("Esa sucursal no existe en el sistema.\n");
	}
}

int Empresa::getRut() {
	return this->rut;
}

string Empresa::getNombre() {
	return this->nombre;
}
