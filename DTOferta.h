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
 * Archivo: DTOferta.h
 *******************************************************************************/

#ifndef DTOFERTA_H_
#define DTOFERTA_H_

#include <string>

using namespace std;

class DTOferta {
private:
	int numero_de_expediente;
	string titulo;

public:
	DTOferta();
	DTOferta(int numero_de_expediente, string titulo);
	~DTOferta();

	int getNumeroDeExpediente();
	string getTitulo();
};

#endif /* DTOFERTA_H_ */
