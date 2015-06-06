/*
 * ICtrlOfertaLaboral.h
 *
 *  Created on: Jun 2, 2015
 *      Author: marccio
 */

#ifndef ICTRLOFERTALABORAL_H_
#define ICTRLOFERTALABORAL_H_


#include <set>
#include <string>

using namespace std;

class ICtrlOfertaLaboral {
public:
	virtual ~ICtrlOfertaLaboral() = 0;
	virtual set<DTEmpresa*> * listarEmpresas() = 0;
	virtual bool seleccionarEmpresa(int rut) = 0;
	virtual set<DTSucursal*> * listarSucursales() = 0;
	virtual bool seleccionarSucursal(string nombre) = 0;
	virtual set<DTSeccion*> * listarSecciones() = 0;
	virtual bool seleccionarSeccion(string nombre) = 0;
	virtual bool chequearOfertaLaboral(DataOferta& dtO) = 0;
	virtual void confirmarCreacionOferta() = 0;
	virtual set<DTOferta*> * obtenerOfertasTodas() = 0;
	virtual bool seleccionarOferta(int numExp) = 0;
	virtual void darDeBaja() = 0;
};


#endif /* ICTRLOFERTALABORAL_H_ */
