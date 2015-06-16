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
 * Archivo: Sucursal.cpp
 *******************************************************************************/

#include "Sucursal.h"

Sucursal::Sucursal(string nombre, int telefono, string direccion, Empresa * empresa) {
	this->nombre = nombre;
	this->telefono = telefono;
	this->direccion = direccion;
	this->empresa = empresa;
	this->secciones = new map<string, Seccion*>;
}

Sucursal::~Sucursal() {
}

void Sucursal::agregarSeccion(string idSec, Seccion* s) {
	secciones->insert(pair<string, Seccion*>(idSec, s));
}

DTSucursal* Sucursal::crearDT() {
	DTSucursal * dt = new DTSucursal(nombre, telefono, direccion);
	return dt;
}

set<DTSeccion*>* Sucursal::listarSecciones() {
	set<DTSeccion*> * setOut = new set<DTSeccion*>;
	for (map<string, Seccion*>::iterator it = secciones->begin() ;
			it != secciones->end() ; it++) {
		DTSeccion * dt = new DTSeccion((*it).second->getNombre(), (*it).second->getInterno());
		setOut->insert(dt);
	}
	return setOut;
}

bool Sucursal::seleccionarSeccion(string idSec) {
	return (secciones->find(idSec) != secciones->end());
}

OfertaLaboral* Sucursal::crearOferta(DataOferta * dataOferta, string idSec) {
	map<string, Seccion*>::iterator it = secciones->find(idSec);
	return (*it).second->crearOferta(dataOferta);
}

DTAplicacion * Sucursal::getDatosSucursal() {
	DTEmpresa * dapReducido = empresa->crearDT();
	DTAplicacion * dap = new DTAplicacion(
			0,
			"",
			dapReducido->getRUT(),
			dapReducido->getNombre(),
			nombre,
			telefono,
			direccion,
			"",
			0);
	delete dapReducido;
	return dap;
}

string Sucursal::getNombreEmpresa() {
	return empresa->getNombre();
}

string Sucursal::getDireccion() {
	return direccion;
}

string Sucursal::getNombre() {
	return nombre;
}

int Sucursal::getTelefono() {
	return telefono;
}
