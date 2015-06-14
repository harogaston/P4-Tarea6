/*
 * DTOferta.h
 *
 *  Created on: Jun 2, 2015
 *      Author: marccio
 */

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
