/*
 * main.cpp
 *
 *  Created on: Jun 4, 2015
 *      Author: marccio
 */

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>

#include "ControladorOfertaLaboral.h"
#include "DataEstudiante.h"
#include "DataOferta.h"
#include "Date.h"
#include "DTAplicacion.h"
#include "DTAsignaturaSalvada.h"
#include "DTCarrera.h"
#include "DTEmpresa.h"
#include "ManejadorEstudiantes.h"
#include "ManejadorOfertasActivas.h"
#Include "ManejadorOfertasLaborales.h"


using namespace std;

void CargarDatos(ManejadorBedelia* mngB, ICtrlOfertaLaboral* ctrlOL) {
	//**********************AgregarEmpresas********************************************************
		ctrlOL->addEmpresa(1112335684, "Segurol S.A.");
		ctrlOL->addEmpresa(5464897986, "Ingenieros Electricos Unidos");
		ctrlOL->addEmpresa(1265498765, "MiniSoft Uy");
		ctrlOL->addEmpresa(1298865497, "RoboTI");
		ctrlOL->addEmpresa(1326548654, "Academia Yotexplico");
	//**********************AgregarSucursales******************************************************
		ctrlOL->addSucursal(1112335684, "Casa central", 24598765, "Ciudad Vieja");
		ctrlOL->addSucursal(5464897986, "Sucursal comercial", 25225323, "Malvin");
		ctrlOL->addSucursal(5464897986, "Sucursal San Carlos", 42668350, "San Carlos");
		ctrlOL->addSucursal(1265498765, "Sede Montevideo", 25468932, "Buceo");
		ctrlOL->addSucursal(1265498765, "Sede Ciudad de la Costa", 43764232, "Solymar");
		ctrlOL->addSucursal(1298865497, "Oficina central", 25495878, "Centro");
		ctrlOL->addSucursal(1326548654, "Academia", 24594565, "Parque rodo");
	//**********************AgregarSecciones*******************************************************
		/*SE01*/ctrlOL->addSeccion(1112335684, "Casa central", "Contaduria", 101);
		/*SE02*/ctrlOL->addSeccion(1112335684, "Casa central", "Recursos humanos", 102);
		/*SE03*/ctrlOL->addSeccion(1112335684, "Casa central", "Recepcion", 103);
		/*SE04*/ctrlOL->addSeccion(1112335684, "Casa central", "Desarrollo", 104);
		/*SE05*/ctrlOL->addSeccion(1112335684, "Casa central", "Pentesting", 105);
		/*SE06*/ctrlOL->addSeccion(5464897986, "Sucursal comercial", "Marketing", 1201);
		/*SE07*/ctrlOL->addSeccion(5464897986, "Sucursal comercial", "Atencion al cliente", 1202);
		/*SE08*/ctrlOL->addSeccion(5464897986, "Sucursal comercial", "Tesoreria", 1203);
		/*SE09*/ctrlOL->addSeccion(5464897986, "Sucursal comercial", "Ventas", 1204);
		/*SE10*/ctrlOL->addSeccion(5464897986, "Sucursal comercial", "Seccion tecnica", 1205);
		/*SE11*/ctrlOL->addSeccion(5464897986, "Sucursal San Carlos", "Seccion tecnica", 1009);
		/*SE12*/ctrlOL->addSeccion(5464897986, "Sucursal San Carlos", "I+D", 1008);
		/*SE13*/ctrlOL->addSeccion(5464897986, "Sucursal San Carlos", "Recepcion", 1000);
		/*SE14*/ctrlOL->addSeccion(1265498765, "Sede Montevideo", "Secretaria", 100);
		/*SE15*/ctrlOL->addSeccion(1265498765, "Sede Montevideo", "Desarrollo", 1001);
		/*SE16*/ctrlOL->addSeccion(1265498765, "Sede Montevideo", "Testing", 1002);
		/*SE17*/ctrlOL->addSeccion(1265498765, "Sede Ciudad de la Costa", "Secretaria", 100);
		/*SE18*/ctrlOL->addSeccion(1265498765, "Sede Ciudad de la Costa", "Desarrollo", 1001);
		/*SE19*/ctrlOL->addSeccion(1265498765, "Sede Ciudad de la Costa", "Testing", 1002);
		/*SE20*/ctrlOL->addSeccion(1298865497, "Oficina central", "Laboratorio", 10);
		/*SE21*/ctrlOL->addSeccion(1298865497, "Oficina central", "Atencion comercial", 11);
		/*SE22*/ctrlOL->addSeccion(1326548654, "Academia", "Direccion", 101);
		/*SE23*/ctrlOL->addSeccion(1326548654, "Academia", "Inscripciones", 102);
	//**********************AgregarCarreras********************************************************	
		manejadorBedelia* mngB ManejadorBedelia->getInstance();
		mngB->crearCarrera("1010", "Ingenieria Electrica");
		mngB->crearCarrera("1011", "Ingenieria en Computacion");
	//**********************AgregarAsignaturas*****************************************************
		/*A01*/mngB->crearAsignatura("1686", "Calculo I", 16); 
		/*A02*/mngB->crearAsignatura("6598", "Programacion 1", 10);
		/*A03*/mngB->crearAsignatura("5698", "Programacion 2", 12);
		/*A04*/mngB->crearAsignatura("4875", "Programacion 3", 15);
		/*A05*/mngB->crearAsignatura("1689", "Calculo II", 16);
		/*A06*/mngB->crearAsignatura("8683", "Electromagnetismo", 12);
		/*A07*/mngB->crearAsignatura("6943", "Bases de datos", 15);
		/*A08*/mngB->crearAsignatura("6879", "Redes de computadoras", 12);
		/*A09*/mngB->crearAsignatura("3216", "Ecuaciones diferenciales", 12);
		/*A10*/mngB->crearAsignatura("9171", "Fundamentos de seguridad informatica", 12);
		/*A11*/mngB->crearAsignatura("1698", "Robotica basada en comportamientos", 15);
		/*A12*/mngB->crearAsignatura("6416", "Ciencia, tecnologia y sociedad", 8);
		/*A13*/mngB->crearAsignatura("6587", "Proyecto de Ingenieria de software", 15);
		/*A14*/mngB->crearAsignatura("5498", "Arquitectura de computadoras", 12);
		/*A15*/mngB->crearAsignatura("1889", "Taller de programacion", 15);
	//**********************AgregarAsignaturasACarreras********************************************	
		mngB->asociarAsignaturaACarrera("1010", "1686");
		mngB->asociarAsignaturaACarrera("1010", "6598");
		mngB->asociarAsignaturaACarrera("1010", "1689");
		mngB->asociarAsignaturaACarrera("1010", "8683");
		mngB->asociarAsignaturaACarrera("1010", "3216");
		mngB->asociarAsignaturaACarrera("1010", "1698");
		mngB->asociarAsignaturaACarrera("1010", "6416");
		mngB->asociarAsignaturaACarrera("1011", "1686");
		mngB->asociarAsignaturaACarrera("1011", "6598");
		mngB->asociarAsignaturaACarrera("1011", "5698");
		mngB->asociarAsignaturaACarrera("1011", "4875");
		mngB->asociarAsignaturaACarrera("1011", "1689");
		mngB->asociarAsignaturaACarrera("1011", "6943");
		mngB->asociarAsignaturaACarrera("1011", "6879");
		mngB->asociarAsignaturaACarrera("1011", "9171");
		mngB->asociarAsignaturaACarrera("1011", "1698");
		mngB->asociarAsignaturaACarrera("1011", "6416");
		mngB->asociarAsignaturaACarrera("1011", "6587");
		mngB->asociarAsignaturaACarrera("1011", "5498");
		mngB->asociarAsignaturaACarrera("1011", "1889");
	//**********************AgregarEstudiantes*************************************************
		/*Es01*/mngB->crearEstudiante("4516231", "Esteban", "Perez", Date(10, 02, 1990), 099111222, 0);
		/*Es02*/mngB->crearEstudiante("5111235", "Felipe", "Garcia", Date(20, 08, 1992), 24035612, 0);
		/*Es03*/mngB->crearEstudiante("3594561", "Juan", "Wolf", Date(30, 01, 1980), 091222223, 0);
		/*Es04*/mngB->crearEstudiante("2784531", "Alfonsina", "Ramirez", Date(05, 06, 1975), 43712345, 0);
		/*Es05*/mngB->crearEstudiante("1956234", "Hector", "Otonello", Date(10, 10, 1969), 098334456, 0);
		/*Es06*/mngB->crearEstudiante("5005684", "Lorena", "Nuñez", Date(03, 01, 1994), 092659878, 0);
		/*Es07*/mngB->crearEstudiante("4686231", "Hector", "Lorenzo", Date(09, 03, 1993), 21656498, 0);
		/*Es08*/mngB->crearEstudiante("4987623", "Julio", "Lee", Date(05, 08, 1992), 26984899, 0);
		/*Es09*/mngB->crearEstudiante("4986313", "Rodrigo", "Fernandez", Date(07, 09, 1990), 22233346, 0);
		/*Es10*/mngB->crearEstudiante("3659532", "Noelia", "Pereira", Date(02, 09, 1990), 099112233, 0);
		/*Es11*/mngB->crearEstudiante("3665492", "Cecilia", "Garrido", Date(30, 03, 1984), 094698568, 0);
		/*Es12*/mngB->crearEstudiante("3335689", "Roman", "Gul", Date(09, 12, 1983), 096677889, 0);
	//**********************AgregarEstudiantesACarreras********************************************
		mngB->asociarEstudianteACarrera("4516231", "1010");
		mngB->asociarEstudianteACarrera("5111235", "1011");
		mngB->asociarEstudianteACarrera("3594561", "1011");
		mngB->asociarEstudianteACarrera("2784531", "1011");
		mngB->asociarEstudianteACarrera("1956234", "1010");
		mngB->asociarEstudianteACarrera("5005684", "1010");
		mngB->asociarEstudianteACarrera("4686231", "1010");
		mngB->asociarEstudianteACarrera("4987623", "1011");
		mngB->asociarEstudianteACarrera("4986313", "1010");
		mngB->asociarEstudianteACarrera("4986313", "1011");
		mngB->asociarEstudianteACarrera("3659532", "1011");
		mngB->asociarEstudianteACarrera("3665492", "1010");
		mngB->asociarEstudianteACarrera("3665492", "1011");
		mngB->asociarEstudianteACarrera("3335689", "1010");
	//**********************AgregarAprobaciones************************************************
		mngB->addAsignatura("4516231", Date(10, 11, 2013), 8,  "1686");
		mngB->addAsignatura("4516231", Date(20, 08, 2014), 5, "1689");
		mngB->addAsignatura("4516231", Date(12, 11, 2014), 10, "8683");
		mngB->addAsignatura("4516231", Date(10, 12, 2014), 11, "3216");
		mngB->addAsignatura("5111235", Date(10, 06, 2014), 9, "6598");
		mngB->addAsignatura("5111235", Date(15, 06, 2014), 12,  "5698");
		mngB->addAsignatura("5111235", Date(02, 02, 2015), 7,  "4875");
		mngB->addAsignatura("5111235", Date(11, 08, 2014), 6, "6416" );
		mngB->addAsignatura("3594561", Date(20, 07, 2005), 3, "1686");
		mngB->addAsignatura("3594561", Date(12, 12, 2005), 10, "6598");
		mngB->addAsignatura("3594561", Date(30, 07, 2006), 9, "5698");
		mngB->addAsignatura("3594561", Date(02, 02, 2007), 7, "4875");
		mngB->addAsignatura("3594561", Date(10, 12, 2007), 8, "1689");
		mngB->addAsignatura("3594561", Date(05, 12, 2008), 10, "6943");
		mngB->addAsignatura("3594561", Date(15, 12, 2008), 11, "6879" );
		mngB->addAsignatura("3594561", Date(12, 02, 2009), 8, "6416");
		mngB->addAsignatura("3594561", Date(20, 11, 2010), 10, "6587");
		mngB->addAsignatura("3594561", Date(15, 11, 2007), 6, "5498");
		mngB->addAsignatura("3594561", Date(25, 11, 2009), 10, "1889");
		mngB->addAsignatura("2784531", Date(10, 06, 2010), 8, "6598");
		mngB->addAsignatura("2784531", Date(30, 07, 2010), 6, "5698");
		mngB->addAsignatura("1956234", Date(10, 11, 1993), 3, "1686");
		mngB->addAsignatura("1956234", Date(20, 08, 1994), 3, "1689");
		mngB->addAsignatura("1956234", Date(10, 12, 1994), 10, "3216");
		mngB->addAsignatura("1956234", Date(11, 08, 1995), 12, "6416");
		mngB->addAsignatura("4686231", Date(10, 11, 2013), 10, "1686" );
		mngB->addAsignatura("4686231", Date(10, 06, 2014), 8, "6598");
		mngB->addAsignatura("4987623", Date(10, 07, 2011), 8, "1686");
		mngB->addAsignatura("4987623", Date(10, 11, 2011), 7, "6598");
		mngB->addAsignatura("4987623", Date(30, 07, 2012), 10, "5698");
		mngB->addAsignatura("4987623", Date(25, 11, 2012), 9, "4875");
		mngB->addAsignatura("4987623", Date(05, 12, 2013), 10, "6943");
		mngB->addAsignatura("4987623", Date(15, 12, 2013), 12, "6879");
		mngB->addAsignatura("4987623", Date(15, 11, 2014), 12, "1698");
		mngB->addAsignatura("4987623", Date(25, 11, 2013), 10, "1889");
		mngB->addAsignatura("4986313", Date(10, 11, 2014), 5, "1686");
		mngB->addAsignatura("3659532", Date(10, 11, 2007), 8, "1686");
		mngB->addAsignatura("3659532", Date(10, 06, 2008), 9, "6598");
		mngB->addAsignatura("3659532", Date(30, 07, 2009), 3, "5698");
		mngB->addAsignatura("3665492", Date(10, 11, 2003), 4, "1686");
		mngB->addAsignatura("3665492", Date(10, 06, 2004), 5, "6598");
		mngB->addAsignatura("3665492", Date(30, 07, 2004), 10, "5698");
		mngB->addAsignatura("3665492", Date(02, 02, 2005), 8, "4875");
		mngB->addAsignatura("3665492", Date(20, 08, 2004), 7, "1689");
		mngB->addAsignatura("3665492", Date(12, 11, 2005),10, "8683");
		mngB->addAsignatura("3665492", Date(04, 12, 2005), 9, "6943");
		mngB->addAsignatura("3335689", Date(10, 11, 2003), 7, "1686");
		mngB->addAsignatura("3335689", Date(10, 12, 2003), 8, "1689");
		
	//**********************AgregarOfertas*********************************************************	
	//O1
		ctrlOL->setRUT(1112335684);
		ctrlOL->setIdSuc("Casa central");
		ctrlOL->setIdSec("Recursos humanos");
		set<string> Lista;
		Lista.insert("6598");
		Lista.insert("5698");
		Lista.insert("4875");
		Lista.insert("9171");
		DataOferta dtO DataOferta(45896,
			"Auditor de seguridad part-time junior",
			"Segurol S.A. busca estudiantes de Ingenieria en Computacion para unirse a su equipo. Se requiere un nivel minimo de conocimiento en seguridad informatica y programacion. Interesados enviar cv a oportunidades@segurol.com.uy",
			20,
			2000,
			3000,
			Date(01, 06, 2015),
			Date(20, 07, 2015),
			5,
			Lista);
		ctrlOL->setOferta(dtO);
		ctrlOL->confirmarCreacionOferta();	
	//O2	
		ctrlOL->setRUT(5464897986);
		ctrlOL->setIdSuc("Sucursal comercial");
		ctrlOL->setIdSec("Seccion tecnica");
		set<string> Lista;
		Lista.insert("8683");
		Lista.insert("3216");
		DataOferta dtO DataOferta(12356,
			"Ayudante de Ingeniero",
			"Estamos buscando estudiantes avanzados de Ingenieria Electrica con perfil potencia. Es imprescindible tener disponibilidad para viajar al interior del pais una vez por mes. Se pagan viaticos ademas de sueldo. Llamar al 25225323 int 1205 para mas detalles.",
			30,
			4000,
			5000,
			Date(20, 05, 2015),
			Date(30, 06, 2015),
			2,
			Lista);
		ctrlOL->setOferta(dtO);	
		ctrlOL->confirmarCreacionOferta();	
	/O3	 
		ctrlOL->setRUT(1265498765);
		ctrlOL->setIdSuc("Sede Montevideo");
		ctrlOL->setIdSec("Desarrollo");
		set<string> Lista;
		Lista.insert("6598");
		Lista.insert("5698");
		Lista.insert("4875");
		Lista.insert("6943");
		Lista.insert("6587");
		Lista.insert("1889");
		DataOferta dtO DataOferta(88890,
			"Desarrollador C++",
			"Buscamos desarrollador C++ para importante proyecto internacional. Llenar formulario con datos personales y cv en minisoft.uy/careers.",
			40,
			5000,
			6000,
			Date(05, 06, 2015),
			Date(06, 08, 2015),
			4,
			Lista);
		ctrlOL->setOferta(dtO);
		ctrlOL->confirmarCreacionOferta();
	/O4	1326548654, "Academia", "Inscripciones", 102
		ctrlOL->setRUT(1326548654);
		ctrlOL->setIdSuc("Academia");
		ctrlOL->setIdSec("Direccion");
		set<string> Lista;
		Lista.insert("1686");
		Lista.insert("1689");
		DataOferta dtO DataOferta(49563,
			"Estudiantes para dictar clases de Calculo I y II",
			"Buscamos estudiantes de Ingenieria con Calculo 1 y 2 aprobadas. Deben tener disponibilidad horaria y gusto por enseñar. Enviar mail a academiayotexplico@gmail.com.",
			5,
			500,
			2000,
			Date(10, 09, 2015),
			Date(20, 12, 2015),
			10,
			Lista);
		ctrlOL->setOferta(dtO);
		ctrlOL->confirmarCreacionOferta();
	}

int main()
{
    //*************************************************Declaracion de variables** *****************************************************
    int comando, RUT, numExp, h_semanales, anio, mes, dia, puestos;
	float sueldo_min, sueldo_max;
	Date comienzo, fin;
    string int_aux, idSuc, idSec, titulo, descripcion, asign;
    //*************************************************Inicializacion del sistema *****************************************************

    Fabrica *f=Fabrica::getInstance();
    ICtrlOfertasLaborales* ctrlOL= f -> getICtrlOfertLaboral();
    ICtrlOfertasActivas* ctrlOA = f -> getICtrlOfertaActiva();
	ICtrlEstudiantes* ctrlE = f -> getICtrlEstudiante();
	
	FechaSistema * FS = FechaSistema->getInstance();
	Date d= Date();
	FS->setFecha(d);
	
	//*************************************************Presentacion del menu***********************************************************
    cout<< "__________________________________________________________________________"<<endl;
    cout<< "				Laboratorio 6 de Programacion 4 2015 "<<endl;
    cout<< "							BuscoFIngJobs "<<endl;
    cout<< "__________________________________________________________________________"<<endl;
    
    //***************************************************Seleccion de opciones ********************************************************
    salir = (comando==13);
	while (!salir) {
		try {
		    cout<< "Menu de funcionalidades: \n ";
			cout<< "	1) Alta Oferta Laboral \n ";
			cout<< "	2) Alta Entrevista \n ";
			cout<< "	3) Inscripcion Oferta Laboral \n ";
			cout<< "	4) Listar Ofertas Activas\n ";
			cout<< "	5) Consultar Datos Estudiante \n ";
			cout<< "	6) Asignacion de Oferta a Estudiante \n ";
			cout<< "	7) Modificar Estudiante \n ";
			cout<< "	8) Modificar Llamado  \n ";
			cout<< "	9) Dar de Baja Llamado \n ";
			cout<< "	10) Mostrar Notificaciones de Estudiante \n ";
			cout<< " 	11) Setear Fecha del Sistema \n ";
			cout<< "	12) Cargar Datos \n ";
			cout<< "	13) Salir del programa \n ";
			cout << "Ingrese el numero de opcion que prefiera y presione [ENTER]: \n";
			cout<< '>';
			
            getline(cin, int_aux);
            stringstream(int_aux) >> comando;
			//cin>> comando;
			
			salir = (comando==13);
			switch (comando)
			{
				case 1: { // CU Alta Oferta Laboral
				//listarEmpresas
					set<DTEmpresa*> Emps = ctrlOL->listarEmpresas();
					set<DTEmpresa*>::iterator it;
					if(!Emps.empty()) {
						cout<<"Empresas Regristradas:"<<endl;
						for(it=Emps.begin() ; it!=Emps.end() ; it++) {
							DTEmpresa* Emps = *it;
							cout<<"**RUT: "<<Emps->getRut() <<"Empresa: "<<Emps->getNombre() <<endl;
						};
					}	
					else {
						cout<<"No existen Empresas Registradas en el Sistema. \n";
						throw 2;
					}	
				//seleccionarEmpresa
					cout<<"Ingrese el RUT de la Empresa que creara la nueva Oferta Laboral y presione [ENTER] \n";
					cout<<">";
					getline(cin, int_aux);
					stringstream(int_aux) >> RUT;
					bool okEmpresa = ctrlOL->seleccionarEmpresa(RUT);
					while(!okEmpresa) {
						cout<<"El RUT ingresado no corresponde a una Empresa registrada en el Sistema.\n";
						cout<<"Ingrese un RUT valido a continuacion y presione [ENTER] o ingrese 0 si desea salir del Caso de Uso.\n";
						cout<<">";
						getline(cin, int_aux);
						stringstream(int_aux) >> RUT;
						if(RUT==0) 
							break;
						else
							okEmpresa = ctrlOL->seleccionarEmpresa(RUT);
					}
				//listarSucursales
					set<DTSucursal*> Sucs = ctrlOL->listarSucursales();
					set<DTSucursal*>::iterator it;
					if(!Sucs.empty()) {
						cout<<"Sucursales:"<<endl;
						for(it=Sucs.begin() ; it!=Sucs.end() ; it++) {
							DTSucursal* Sucs = *it;
							cout<<"**Nombre: "<<Sucs->getNombre() <<" -Telefono: "<<Sucs->getTelefono() <<" -Direccion: "<<Sucs->getDireccion()<<endl;
						};
					}	
					else {
						cout<<"No existen Sucursales para esa Empresa. \n";
						throw 2;
					};
				//seleccionarSucursal	
					cout<<"Ingrese el nombre de la Sucursal que creara la nueva Oferta Laboral y presione [ENTER] \n";
					cout<<">";
					getline(cin, id_Suc);
					bool okSucursal = ctrlOL->seleccionarSucursal(idSuc);
					while(!okSucursal) {
						cout<<"El nombre ingresado no corresponde a una Sucursal de la empresa seleccionada.\n";
						cout<<"Ingrese un nombre valido a continuacion y presione [ENTER] o ingrese 0 si desea salir del Caso de Uso.\n";
						cout<<">";
						getline(cin, idSuc);
						if(idSuc=="0") 
							break;
						else
							okSucursal = ctrlOL->seleccionarSucursal(idSuc);
					}
				//listarSecciones
					set<DTSSeccion*> Secs = ctrlOL->listarSecciones();
					set<DTSeccion*>::iterator it;
					if(!Secs.empty()) {
						cout<<"Secciones:"<<endl;
						for(it=Secs.begin() ; it!=Secs.end() ; it++) {
							DTSeccion* Secs = *it;
							cout<<"**Nombre: "<<Secs->getNombre() <<" -Interno: "<<Sucs->getInterno() <<endl;
						};
					}	
					else {
						cout<<"No existen Secciones para el par Sucursal/Empresa seleccionado. \n";
						throw 2;
					};
				//seleccionarSeccion
					cout<<"Ingrese el nombre de la Seccion que creara la nueva Oferta Laboral y presione [ENTER] \n";
					cout<<">";
					getline(cin, id_Sec);
					bool okSeccion = ctrlOL->seleccionarSeccion(idSec);
					while(!okSeccion) {
						cout<<"El nombre ingresado no corresponde a una Seccion de la Empresa  y Sucursal seleccionadas.\n";
						cout<<"Ingrese un nombre valido a continuacion y presione [ENTER] o ingrese 0 si desea salir del Caso de Uso.\n";
						cout<<">";
						getline(cin, idSec);
						if(idSuc=="0") 
							break;
						else
							okSeccion = ctrlOL->seleccionarSeccion(idSec);
					}
				//ingresoYChequeoDeDatosParaLaCreacionDeLaOferta
					cout<<"A continuacion se pide ingresar los datos de la Oferta Laboral concreta. \n";
					cout<<"Ingrese en numero de Expediente que se asociará a la nueva Oferta Laboral y luego presione [ENTER]. \n" ;
						cout<<">";
						getline(cin, int_aux);
						stringstream(int_aux) >> numExp;
					bool okExp =chequearExpedienteDisponible(numExp);
					while (!okExp) {
						cout<<"Error!! \n";
						cout<<"El numero de expediente ingresado ya está registrado para otra Oferta Laboral.\n";
						cout<< "Ingrese otro numero de Expediente al que se asociará la nueva Oferta Laboral y luego presione [ENTER]. \n" ;
						cout<<"Si desea salir del CU ingrese \"salir\" y presione [ENTER]. \n";
						cout<<" >";
						getline(cin, int_aux);
						if (int_aux == "salir")
							break;
						else {
							stringstream(int_aux) >> numExp;
							okExp =chequearExpedienteDisponible(numExp);
						}
					}
					cout<<"Ingrese el titulo de la nueva Oferta Laboral seguido de [Enter]. \n";
						cout<<">";
						getLine(cin, titulo);
					cout<<"Ingrese la descripcion de la nueva Oferta Laboral y solamente al final presione [Enter]. \n";
						cout<<">";
						getLine(cin, descripcion);
					cout<<"Ingrese la cantidad de horas semanales que requerira el nuevo puesto de trabajo y luego presione [ENTER]. \n" ;
						cout<<">";
						getline(cin, int_aux);
						stringstream(int_aux) >> h_semanales;
					while(h_semanales>60) {
						cout<<"Error!! \n";
						cout<<"No se permite un llamado que exija mas de 60 horas semanales.\n";
						cout<<"Ingrese la cantidad de horas semanales que requerira el nuevo puesto de trabajo y luego presione [ENTER]. \n" ;
							cout<<">";
							getline(cin, int_aux);
							stringstream(int_aux) >> h_semanales;
					}
					cout<<"Ingrese el sueldo minimo ofrecido y luego presione [ENTER]. \n" ;
						cout<<">";
						getline(cin, int_aux);
						stringstream(int_aux) >> sueldo_min;
					cout<<"Ingrese el sueldo maximo ofrecido y luego presione [ENTER]. \n" ;
						cout<<">";
						getline(cin, int_aux);
						stringstream(int_aux) >> sueldo_max;	
					while (sueldo_min > sueldo_max) {
						cout<<"Error!! \n";
						cout<<"El sueldo minimo es mayor que el sueldo maximo de la Oferta Laboral.\n";
						cout<<"Ingrese el sueldo minimo ofrecido y luego presione [ENTER]. \n" ;
							cout<<">";
							getline(cin, int_aux);
							stringstream(int_aux) >> sueldo_min;
						cout<<"Ingrese el sueldo maximo ofrecido y luego presione [ENTER]. \n" ;
							cout<<">";
							getline(cin, int_aux);
							stringstream(int_aux) >> sueldo_max;
					}
					cout<< "Ingrese la fecha de comienzo del llamado: \n";
						cout<<"	Anio >";
                        getline(cin, int_aux);
                        stringstream(int_aux) >> anio;
						while((anio<1) ||(anio>9999)) {
							cout<<"Anio fuera de rango, ingrese un anio entre 1 y 9999.\n";
							cout<<"	Anio >";
                            getline(cin, int_aux);
                            stringstream(int_aux) >> anio;
						}	
						cout<<"	Mes >";
                        getline(cin, int_aux);
                        stringstream(int_aux) >> mes;
						while((mes<1) ||(mes>12)) {
							cout<<"Mes fuera de rango, ingrese un mes entre 1 y 12.\n";
							cout<<"	Mes >";
                            getline(cin, int_aux);
                            stringstream(int_aux) >> mes;
						}
						cout<<"	Dia >";
                        getline(cin, int_aux);
                        stringstream(int_aux) >> dia;
						while((dia<1) ||(dia>30)) {
							cout<<"Dia fuera de rango, ingrese un dia entre 1 y 30.\n";
							cout<<"	Dia>";
                            getline(cin, int_aux);
                            stringstream(int_aux) >> dia;
						}
						comienzo = Date(dia, mes, anio);
					cout<< "Ingrese la fecha de finalizacion del llamado: \n";
						cout<<"	Anio >";
                        getline(cin, int_aux);
                        stringstream(int_aux) >> anio;
						while((anio<1) ||(anio>9999)) {
							cout<<"Anio fuera de rango, ingrese un anio entre 1 y 9999.\n";
							cout<<"	Anio >";
                            getline(cin, int_aux);
                            stringstream(int_aux) >> anio;
						}	
						cout<<"	Mes >";
                        getline(cin, int_aux);
                        stringstream(int_aux) >> mes;
						while((mes<1) ||(mes>12)) {
							cout<<"Mes fuera de rango, ingrese un mes entre 1 y 12.\n";
							cout<<"	Mes >";
                            getline(cin, int_aux);
                            stringstream(int_aux) >> mes;
						}
						cout<<"	Dia >";
                        getline(cin, int_aux);
                        stringstream(int_aux) >> dia;
						while((dia<1) ||(dia>30)) {
							cout<<"Dia fuera de rango, ingrese un dia entre 1 y 30.\n";
							cout<<"	Dia>";
                            getline(cin, int_aux);
                            stringstream(int_aux) >> dia;
						}
						fin = Date(dia, mes, anio);
						while (fin <= comienzo) {
							cout<<"Error!! \n";
							cout<<"La fecha de finalizacion no es posterior a la fecha de comienzo de la Oferta Laboral.\n"
							cout<< "Ingrese la fecha de comienzo del llamado: \n";
								cout<<"	Anio >";
								getline(cin, int_aux);
								stringstream(int_aux) >> anio;
								while((anio<1) ||(anio>9999)) {
									cout<<"Anio fuera de rango, ingrese un anio entre 1 y 9999.\n";
									cout<<"	Anio >";
									getline(cin, int_aux);
									stringstream(int_aux) >> anio;
								}	
								cout<<"	Mes >";
								getline(cin, int_aux);
								stringstream(int_aux) >> mes;
								while((mes<1) ||(mes>12)) {
									cout<<"Mes fuera de rango, ingrese un mes entre 1 y 12.\n";
									cout<<"	Mes >";
									getline(cin, int_aux);
									stringstream(int_aux) >> mes;
								}
								cout<<"	Dia >";
								getline(cin, int_aux);
								stringstream(int_aux) >> dia;
								while((dia<1) ||(dia>30)) {
									cout<<"Dia fuera de rango, ingrese un dia entre 1 y 30.\n";
									cout<<"	Dia>";
									getline(cin, int_aux);
									stringstream(int_aux) >> dia;
								}
								comienzo = Date(dia, mes, anio);
							cout<< "Ingrese la fecha de finalizacion del llamado: \n";
								cout<<"	Anio >";
								getline(cin, int_aux);
								stringstream(int_aux) >> anio;
								while((anio<1) ||(anio>9999)) {
									cout<<"Anio fuera de rango, ingrese un anio entre 1 y 9999.\n";
									cout<<"	Anio >";
									getline(cin, int_aux);
									stringstream(int_aux) >> anio;
								}	
								cout<<"	Mes >";
								getline(cin, int_aux);
								stringstream(int_aux) >> mes;
								while((mes<1) ||(mes>12)) {
									cout<<"Mes fuera de rango, ingrese un mes entre 1 y 12.\n";
									cout<<"	Mes >";
									getline(cin, int_aux);
									stringstream(int_aux) >> mes;
								}
								cout<<"	Dia >";
								getline(cin, int_aux);
								stringstream(int_aux) >> dia;
								while((dia<1) ||(dia>30)) {
									cout<<"Dia fuera de rango, ingrese un dia entre 1 y 30.\n";
									cout<<"	Dia>";
									getline(cin, int_aux);
									stringstream(int_aux) >> dia;
								}
								fin = Date(dia, mes, anio);
						}
					cout<<"Ingrese la cantidad de puestos disponibles para la Oferta Laboral y luego presione [ENTER]. \n" ;
						cout<<" >";
						getline(cin, int_aux);
						stringstream(int_aux) >> puestos;
					cout<<"A continuacion debera ingresar los codigos de las asignaturas requeridas por la Oferta Laaboral seguidos de [ENTER].\n" ;
					cout<<"Cuando no desee agregar mas Asignaturas, ingrese 0 y presione [ENTER]. \n";
						cout<<" >";
						getline(cin, asign);
						set<string> s;
						while (asign != "0") {
							s.insert(asign);
							cout<<" >";
							getline(cin, asign);
						}
					DataOferta dtO = DataOferta(numExp, titulo, descripcion, h_semanales, sueldo_min, sueldo_max, 
						comienzo, fin, puestos, s);
					bool okOferta = ctrlOL->chequearAsignaturas(dtO);
					while (!okOferta) {
						cout<<"Error!! \n";
						cout<<"Uno o varios de los codigos de Asignatura ingresados no es correcto. \n";
						cout<<"A continuacion debera ingresar los codigos de las asignaturas requeridas por la Oferta Laaboral seguidos de [ENTER].\n" ;
						cout<<"Cuando no desee agregar mas Asignaturas, ingrese 0 y presione [ENTER]. \n";
							cout<<" >";
							getline(cin, asign);
							set<string> s;
							while (asign != "0") {
								s.insert(asign);
								cout<<" >";
								getline(cin, asign);
							}
							dtO = DataOferta(numExp, titulo, descripcion, h_semanales, sueldo_min, sueldo_max, 
								comienzo, fin, puestos, s);
							okOferta = ctrlOL->chequearAsignaturas(dtO);			
					}
				//confirmarCreacionOferta	
					ctrlOL->confirmarCreacionOferta();	
				}
				case 2: { // CU Alta Entrevista
					break;	
				}	
				case 3: { // CU Inscripcion Oferta Laboral
					break;	
				}
				case 4: { // CU Listar Ofertas Activas
					break;
				}
				case 5: { // CU Consultar Datos Estudiante
					break;
				}
				case 6: { // CU Asignacion de Oferta a Estudiante
					break;
				}
				case 7: { // CU Modificar Estudiante
					break;
				}
				case 8: { // CU Modificar Llamado
					break;
				}
				case 9: { //CU Dar de Baja Llamado
					break;
				}
				case 10: { //CU Mostrar Notificaciones de Estudiante
					break;
				}
				case 11: { //Setear Fecha del Sistema
					break;
				}
				case 12: { //Cargar Datos
					break;
				}
				default: { 
					throw 1;
					break;
				}
		}	
		
			catch (int exc) {
				cout<< "Error: ";
				switch (exc) {
					case 1: { // Comando invalido	
						cout<< "Comando invalido\n";
						cout<< "Ingrese un comando valido \n";
						cout<< ">";
						getline(cin, int_aux);
						stringstream(int_aux) >> comando;
						//cin>> comando;
						break;
					}	
					case 2: { //CU Abortado
						cout<< "Caso de Uso Abortado por falta de Informacion en el Sistema. \n"
						break;
					}
				}
			}
	}
	return 0;
}	