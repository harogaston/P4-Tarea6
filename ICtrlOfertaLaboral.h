#ifndef ICTRLOFERTALABORAL_H_
#define ICTRLOFERTALABORAL_H_


#include <set>
#include <string>

#include "DTEmpresa.h"
#include "DTSucursal.h"
#include "DTOferta.h"
#include "DTSeccion.h"
#include "DataOferta.h"

using namespace std;

class ICtrlOfertaLaboral {
public:
	virtual ~ICtrlOfertaLaboral() {};
	virtual set<DTEmpresa*> * listarEmpresas() = 0;
	virtual bool seleccionarEmpresa(int rut) = 0;
	virtual set<DTSucursal*> * listarSucursales() = 0;
	virtual bool seleccionarSucursal(string nombre) = 0;
	virtual set<DTSeccion*> * listarSecciones() = 0;
	virtual bool seleccionarSeccion(string nombre) = 0;
	virtual bool chequearOfertaLaboral(DataOferta * dtO) = 0;
	virtual void confirmarCreacionOferta() = 0;
	virtual set<DTOferta*> * obtenerOfertasTodas() = 0;
	virtual bool seleccionarOferta(int numExp) = 0;
	virtual void darDeBaja() = 0;

	virtual void addEmpresa(int rut, string nombre);
	virtual void addSucursal(int rutEmpresa, string nombreSuc, int telefono, string direccionSuc);
	virtual void addSeccion(int rutEmpresa, string nombreSucursal, string nombreSeccion, int interno);
	virtual void setRUT(int RUT);
	virtual void setIdSuc(string idSuc);
	virtual void setIdSec(string idSec);
	virtual void setNumExp (int Exp);
	virtual void setDataOferta(DataOferta * dtOL);

};


#endif /* ICTRLOFERTALABORAL_H_ */
