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
 * Archivo: Seccion.cpp
 *******************************************************************************/

#include "Seccion.h"

Seccion::Seccion(string nombre, int interno, Sucursal * sucursal) {
	this->nombre = nombre;
	this->interno = interno;
	this->ofertas = new map<int, OfertaLaboral*>;
	this->sucursal = sucursal;
}

Seccion::~Seccion() {
	for (map<int, OfertaLaboral*>::iterator it = ofertas->begin() ; it != ofertas->end() ; it++) {
		delete (*it).second;
	}
	ofertas->clear();
}

string Seccion::getNombre() {
	return nombre;
}

int Seccion::getInterno() {
	return interno;
}

string Seccion::getUbicacion() {
	return sucursal->getDireccion();
}

string Seccion::getNombreEmpresa() {
	return sucursal->getNombreEmpresa();
}

DTAplicacion* Seccion::getDatosSeccion() {
	DTAplicacion * dapReducido = sucursal->getDatosSucursal();
	DTAplicacion * dap = new DTAplicacion(
			dapReducido->getExpedienteOferta(),
			dapReducido->getTituloOferta(),
			dapReducido->getRutEmpresa(),
			dapReducido->getEmpresa(),
			dapReducido->getSucursal(),
			dapReducido->getTelefonoSuc(),
			dapReducido->getDireccionSuc(),
			nombre,
			interno);
	delete dapReducido;
	return dap;
}

void Seccion::cancelarOferta(OfertaLaboral* oferta) {
	/*
	bool termine = false;
	map<int, OfertaLaboral*>::iterator it = ofertas->begin();
	while (it != ofertas->end() && not termine) {
		if (*(it->second) == *oferta) { // si son el mismo objeto
			ofertas->erase(it);
			termine = true;
		}
		it++;
	}
	*/
	for (map<int, OfertaLaboral*>::iterator it = ofertas->begin() ; it != ofertas->end() ; it++) {
		delete (*it).second;
	}
	ofertas->clear();
}

DTSeccion* Seccion::crearDT() {
	DTSeccion * dt = new DTSeccion(nombre, interno);
	return dt;
}

OfertaLaboral* Seccion::crearOferta(DataOferta* dataOferta) {
	set<string> * asignaturasRequeridas = new set<string>;
	for (set<string>::iterator it = asignaturasRequeridas->begin() ;
			it != asignaturasRequeridas->end() ; it++) {
		asignaturasRequeridas->insert((*it));
	}
	OfertaLaboral * of = new OfertaLaboral(
			dataOferta->getNumeroDeExpediente(),
			dataOferta->getTitulo(),
			dataOferta->getDescripcion(),
			dataOferta->getHorasSemanales(),
			dataOferta->getSueldoMin(),
			dataOferta->getSueldoMax(),
			new Date(dataOferta->getComienzoLlamado()->getDd(),
					dataOferta->getComienzoLlamado()->getMm(),
					dataOferta->getComienzoLlamado()->getAaaa()),
			new Date(dataOferta->getFinLlamado()->getDd(),
					dataOferta->getFinLlamado()->getMm(),
					dataOferta->getFinLlamado()->getAaaa()),
			dataOferta->getPuestosDisponibles(),
			asignaturasRequeridas,
			this);
	ofertas->insert(pair<int, OfertaLaboral*>(dataOferta->getNumeroDeExpediente(), of) );
	return of;
}
