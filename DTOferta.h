/*
 * DTOferta.h
 *
 *  Created on: Jun 2, 2015
 *      Author: marccio
 */

#include <string>

using namespace std;

#ifndef DTOFERTA_H_
#define DTOFERTA_H_

class DTOferta {
private:
	int numero_de_expediente;
	string titulo;
public:
	DTOferta();
	DTOferta(int numero_de_expediente, string titulo);
	virtual ~DTOferta();
	int getNumeroDeExpediente();
	string getTitulo();
};

#endif /* DTOFERTA_H_ */
