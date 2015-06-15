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
 * Archivo: main.cpp
 *******************************************************************************/

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>

#include "CtrlOfertaLaboral.h"
#include "DataEstudiante.h"
#include "DataOferta.h"
#include "Date.h"
#include "DTAplicacion.h"
#include "DTAsignaturaSalvada.h"
#include "DTCarrera.h"
#include "DTEmpresa.h"
#include "Fabrica.h"
#include "FechaSistema.h"
#include "ICtrlEstudiante.h"
#include "ICtrlOfertaActiva.h"
#include "ICtrlOfertaLaboral.h"
#include "ManejadorBedelia.h"
#include "ManejadorOfertaLaboral.h"



using namespace std;

void CargarDatos(ManejadorBedelia* mngB, ICtrlOfertaLaboral* ctrlOL) {
	//**********************AgregarEmpresas********************************************************

	ctrlOL->addEmpresa("1112335684", "Segurol S.A.");
	ctrlOL->addEmpresa("5464897986", "Ingenieros Electricos Unidos");
	ctrlOL->addEmpresa("1265498765", "MiniSoft Uy");
	ctrlOL->addEmpresa("1298865497", "RoboTI");
	ctrlOL->addEmpresa("1326548654", "Academia Yotexplico");
	//**********************AgregarSucursales******************************************************
	ctrlOL->addSucursal("1112335684", "Casa central", 24598765, "Ciudad Vieja");
	ctrlOL->addSucursal("5464897986", "Sucursal comercial", 25225323, "Malvin");
	ctrlOL->addSucursal("5464897986", "Sucursal San Carlos", 42668350, "San Carlos");
	ctrlOL->addSucursal("1265498765", "Sede Montevideo", 25468932, "Buceo");
	ctrlOL->addSucursal("1265498765", "Sede Ciudad de la Costa", 43764232, "Solymar");
	ctrlOL->addSucursal("1298865497", "Oficina central", 25495878, "Centro");
	ctrlOL->addSucursal("1326548654", "Academia", 24594565, "Parque rodo");
	//**********************AgregarSecciones*******************************************************
	/*SE01*/ctrlOL->addSeccion("1112335684", "Casa central", "Contaduria", 101);
	/*SE02*/ctrlOL->addSeccion("1112335684", "Casa central", "Recursos humanos", 102);
	/*SE03*/ctrlOL->addSeccion("1112335684", "Casa central", "Recepcion", 103);
	/*SE04*/ctrlOL->addSeccion("1112335684", "Casa central", "Desarrollo", 104);
	/*SE05*/ctrlOL->addSeccion("1112335684", "Casa central", "Pentesting", 105);
	/*SE06*/ctrlOL->addSeccion("5464897986", "Sucursal comercial", "Marketing", 1201);
	/*SE07*/ctrlOL->addSeccion("5464897986", "Sucursal comercial", "Atencion al cliente", 1202);
	/*SE08*/ctrlOL->addSeccion("5464897986", "Sucursal comercial", "Tesoreria", 1203);
	/*SE09*/ctrlOL->addSeccion("5464897986", "Sucursal comercial", "Ventas", 1204);
	/*SE10*/ctrlOL->addSeccion("5464897986", "Sucursal comercial", "Seccion tecnica", 1205);
	/*SE11*/ctrlOL->addSeccion("5464897986", "Sucursal San Carlos", "Seccion tecnica", 1009);
	/*SE12*/ctrlOL->addSeccion("5464897986", "Sucursal San Carlos", "I+D", 1008);
	/*SE13*/ctrlOL->addSeccion("5464897986", "Sucursal San Carlos", "Recepcion", 1000);
	/*SE14*/ctrlOL->addSeccion("1265498765", "Sede Montevideo", "Secretaria", 100);
	/*SE15*/ctrlOL->addSeccion("1265498765", "Sede Montevideo", "Desarrollo", 1001);
	/*SE16*/ctrlOL->addSeccion("1265498765", "Sede Montevideo", "Testing", 1002);
	/*SE17*/ctrlOL->addSeccion("1265498765", "Sede Ciudad de la Costa", "Secretaria", 100);
	/*SE18*/ctrlOL->addSeccion("1265498765", "Sede Ciudad de la Costa", "Desarrollo", 1001);
	/*SE19*/ctrlOL->addSeccion("1265498765", "Sede Ciudad de la Costa", "Testing", 1002);
	/*SE20*/ctrlOL->addSeccion("1298865497", "Oficina central", "Laboratorio", 10);
	/*SE21*/ctrlOL->addSeccion("1298865497", "Oficina central", "Atencion comercial", 11);
	/*SE22*/ctrlOL->addSeccion("1326548654", "Academia", "Direccion", 101);
	/*SE23*/ctrlOL->addSeccion("1326548654", "Academia", "Inscripciones", 102);
	//**********************AgregarCarreras********************************************************
	//manejadorBedelia* mngB ManejadorBedelia->getInstance();
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
	/*Es01*/mngB->crearEstudiante("4516231", "Esteban", "Perez", new Date(10, 02, 1990), 99111222, 0);
	/*Es02*/mngB->crearEstudiante("5111235", "Felipe", "Garcia", new Date(20, 8, 1992), 24035612, 0);
	/*Es03*/mngB->crearEstudiante("3594561", "Juan", "Wolf", new Date(30, 01, 1980), 91222223, 0);
	/*Es04*/mngB->crearEstudiante("2784531", "Alfonsina", "Ramirez", new Date(05, 06, 1975), 43712345, 0);
	/*Es05*/mngB->crearEstudiante("1956234", "Hector", "Otonello", new Date(10, 10, 1969), 98334456, 0);
	/*Es06*/mngB->crearEstudiante("5005684", "Lorena", "Nuñez", new Date(03, 01, 1994), 92659878, 0);
	/*Es07*/mngB->crearEstudiante("4686231", "Hector", "Lorenzo", new Date(9, 03, 1993), 21656498, 0);
	/*Es08*/mngB->crearEstudiante("4987623", "Julio", "Lee", new Date(05, 8, 1992), 26984899, 0);
	/*Es09*/mngB->crearEstudiante("4986313", "Rodrigo", "Fernandez", new Date(07, 9, 1990), 22233346, 0);
	/*Es10*/mngB->crearEstudiante("3659532", "Noelia", "Pereira", new Date(02, 9, 1990), 99112233, 0);
	/*Es11*/mngB->crearEstudiante("3665492", "Cecilia", "Garrido", new Date(30, 3, 1984), 94698568, 0);
	/*Es12*/mngB->crearEstudiante("3335689", "Roman", "Gul", new Date(9, 12, 1983), 96677889, 0);
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
	mngB->addAsignatura("4516231", new Date(10, 11, 2013), 8, "1686");
	mngB->addAsignatura("4516231", new Date(20, 8, 2014), 5, "1689");
	mngB->addAsignatura("4516231", new Date(12, 11, 2014), 10, "8683");
	mngB->addAsignatura("4516231", new Date(10, 12, 2014), 11, "3216");
	mngB->addAsignatura("5111235", new Date(10, 6, 2014), 9, "6598");
	mngB->addAsignatura("5111235", new Date(15, 6, 2014), 12,  "5698");
	mngB->addAsignatura("5111235", new Date(02, 2, 2015), 7,  "4875");
	mngB->addAsignatura("5111235", new Date(11, 8, 2014), 6, "6416" );
	mngB->addAsignatura("3594561", new Date(20, 7, 2005), 3, "1686");
	mngB->addAsignatura("3594561", new Date(12, 12, 2005), 10, "6598");
	mngB->addAsignatura("3594561", new Date(30, 7, 2006), 9, "5698");
	mngB->addAsignatura("3594561", new Date(02, 2, 2007), 7, "4875");
	mngB->addAsignatura("3594561", new Date(10, 12, 2007), 8, "1689");
	mngB->addAsignatura("3594561", new Date(05, 12, 2008), 10, "6943");
	mngB->addAsignatura("3594561", new Date(15, 12, 2008), 11, "6879" );
	mngB->addAsignatura("3594561", new Date(12, 02, 2009), 8, "6416");
	mngB->addAsignatura("3594561", new Date(20, 11, 2010), 10, "6587");
	mngB->addAsignatura("3594561", new Date(15, 11, 2007), 6, "5498");
	mngB->addAsignatura("3594561", new Date(25, 11, 2009), 10, "1889");
	mngB->addAsignatura("2784531", new Date(10, 6, 2010), 8, "6598");
	mngB->addAsignatura("2784531", new Date(30, 7, 2010), 6, "5698");
	mngB->addAsignatura("1956234", new Date(10, 11, 1993), 3, "1686");
	mngB->addAsignatura("1956234", new Date(20, 8, 1994), 3, "1689");
	mngB->addAsignatura("1956234", new Date(10, 12, 1994), 10, "3216");
	mngB->addAsignatura("1956234", new Date(11, 8, 1995), 12, "6416");
	mngB->addAsignatura("4686231", new Date(10, 11, 2013), 10, "1686" );
	mngB->addAsignatura("4686231", new Date(10, 6, 2014), 8, "6598");
	mngB->addAsignatura("4987623", new Date(10, 7, 2011), 8, "1686");
	mngB->addAsignatura("4987623", new Date(10, 11, 2011), 7, "6598");
	mngB->addAsignatura("4987623", new Date(30, 07, 2012), 10, "5698");
	mngB->addAsignatura("4987623", new Date(25, 11, 2012), 9, "4875");
	mngB->addAsignatura("4987623", new Date(05, 12, 2013), 10, "6943");
	mngB->addAsignatura("4987623", new Date(15, 12, 2013), 12, "6879");
	mngB->addAsignatura("4987623", new Date(15, 11, 2014), 12, "1698");
	mngB->addAsignatura("4987623", new Date(25, 11, 2013), 10, "1889");
	mngB->addAsignatura("4986313", new Date(10, 11, 2014), 5, "1686");
	mngB->addAsignatura("3659532", new Date(10, 11, 2007), 8, "1686");
	mngB->addAsignatura("3659532", new Date(10, 6, 2008), 9, "6598");
	mngB->addAsignatura("3659532", new Date(30, 7, 2009), 3, "5698");
	mngB->addAsignatura("3665492", new Date(10, 11, 2003), 4, "1686");
	mngB->addAsignatura("3665492", new Date(10, 6, 2004), 5, "6598");
	mngB->addAsignatura("3665492", new Date(30, 7, 2004), 10, "5698");
	mngB->addAsignatura("3665492", new Date(02, 2, 2005), 8, "4875");
	mngB->addAsignatura("3665492", new Date(20, 8, 2004), 7, "1689");
	mngB->addAsignatura("3665492", new Date(12, 11, 2005),10, "8683");
	mngB->addAsignatura("3665492", new Date(04, 12, 2005), 9, "6943");
	mngB->addAsignatura("3335689", new Date(10, 11, 2003), 7, "1686");
	mngB->addAsignatura("3335689", new Date(10, 12, 2003), 8, "1689");

	//**********************AgregarOfertas*********************************************************
	//O1
	ctrlOL->setRUT("1112335684");
	ctrlOL->setIdSuc("Casa central");
	ctrlOL->setIdSec("Recursos humanos");

	set<string> * Lista;
	Lista->insert("6598");
	Lista->insert("5698");
	Lista->insert("4875");
	Lista->insert("9171");
	DataOferta * dtO = new DataOferta(
			45896,
			"Auditor de seguridad part-time junior",
			"Segurol S.A. busca estudiantes de Ingenieria en Computacion para unirse a su equipo. Se requiere un nivel minimo de conocimiento en seguridad informatica y programacion. Interesados enviar cv a oportunidades@segurol.com.uy",
			20,
			2000.0,
			3000.0,
			new Date(01, 06, 2015),
			new Date(20, 07, 2015),
			5,
			Lista);
	ctrlOL->setDataOferta(dtO);
	ctrlOL->confirmarCreacionOferta();
	Lista->clear();
	//O2
	ctrlOL->setRUT("5464897986");
	ctrlOL->setIdSuc("Sucursal comercial");
	ctrlOL->setIdSec("Seccion tecnica");
	Lista->insert("8683");
	Lista->insert("3216");
	dtO = new DataOferta(12356,
			"Ayudante de Ingeniero",
			"Estamos buscando estudiantes avanzados de Ingenieria Electrica con perfil potencia. Es imprescindible tener disponibilidad para viajar al interior del pais una vez por mes. Se pagan viaticos ademas de sueldo. Llamar al 25225323 int 1205 para mas detalles.",
			30,
			4000,
			5000,
			new Date(20, 05, 2015),
			new Date(30, 06, 2015),
			2,
			Lista);
	ctrlOL->setDataOferta(dtO);
	ctrlOL->confirmarCreacionOferta();
	Lista->clear();
	//O3
	ctrlOL->setRUT("1265498765");
	ctrlOL->setIdSuc("Sede Montevideo");
	ctrlOL->setIdSec("Desarrollo");
	Lista->insert("6598");
	Lista->insert("5698");
	Lista->insert("4875");
	Lista->insert("6943");
	Lista->insert("6587");
	Lista->insert("1889");
	dtO = new DataOferta(88890,
			"Desarrollador C++",
			"Buscamos desarrollador C++ para importante proyecto internacional. Llenar formulario con datos personales y cv en minisoft.uy/careers.",
			40,
			5000,
			6000,
			new Date(5, 6, 2015),
			new Date(6, 8, 2015),
			4,
			Lista);
	ctrlOL->setDataOferta(dtO);
	ctrlOL->confirmarCreacionOferta();
	Lista->clear();
	//O4	1326548654, "Academia", "Inscripciones", 102
	ctrlOL->setRUT("1326548654");
	ctrlOL->setIdSuc("Academia");
	ctrlOL->setIdSec("Direccion");
	Lista->insert("1686");
	Lista->insert("1689");
	dtO = new DataOferta(49563,
			"Estudiantes para dictar clases de Calculo I y II",
			"Buscamos estudiantes de Ingenieria con Calculo 1 y 2 aprobadas. Deben tener disponibilidad horaria y gusto por enseñar. Enviar mail a academiayotexplico@gmail.com.",
			5,
			500,
			2000,
			new Date(10, 9, 2015),
			new Date(20, 12, 2015),
			10,
			Lista);
	ctrlOL->setDataOferta(dtO);
	ctrlOL->confirmarCreacionOferta();
	Lista->clear();
}
int main() {
	//*************************************************Declaracion de variables** *****************************************************
	int comando, numExp, h_semanales, anio, mes, dia, puestos, criterio;
	float sueldo_min, sueldo_max, sueldo;
	bool salir, okOferta, okEstudiante;
	string int_aux, idSuc, idSec, titulo, descripcion, asign, ci, RUT;
	//*************************************************Inicializacion del sistema *****************************************************

	Fabrica* f = Fabrica::getInstancia();
	ICtrlOfertaLaboral * ctrlOL= f -> getICtrlOfertaLaboral();
	//ICtrlOfertaActiva* ctrlOA = f->getICtrlOfertaActiva();
	//ICtrlEstudiante* ctrlE = f -> getICtrlEstudiante();

	FechaSistema * FS = FechaSistema::getInstance();
	Date * d= new Date();
	FS->setFecha(d);

	//*************************************************Presentacion del menu***********************************************************
	cout<< "__________________________________________________________________________"<<endl;
	cout<< "				Laboratorio 6 de Programacion 4 2015 "<<endl;
	cout<< "							BuscoFIngJobs "<<endl;
	cout<< "__________________________________________________________________________"<<endl;

	//***************************************************Seleccion de opciones ********************************************************
	salir = false;
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
			cout<< " >";

			getline(cin, int_aux);
			stringstream(int_aux) >> comando;


			salir = (comando==13);
			switch (comando) {
			case 1: { // CU Alta Oferta Laboral
			//listarEmpresas
				set<DTEmpresa*> * Emps = ctrlOL->listarEmpresas();
				if(not Emps->empty()) {
					cout<< "Empresas Registradas:" << endl;
					for(set<DTEmpresa*>::iterator it = Emps->begin() ; it!=Emps->end() ; it++) {
						DTEmpresa* Emps = *it;
						cout << "	**RUT: " << Emps->getRUT() << "Empresa: " << Emps->getNombre() << endl;
					};
				}
				else {
					cout<<"No existen Empresas registradas en el Sistema. \n";
					throw 2;
				};
			//seleccionarEmpresa
				cout<<"Ingrese el RUT de la Empresa que creara la nueva Oferta Laboral y presione [ENTER] \n";
				cout<<" >";
				getline(cin, RUT);
				bool okEmpresa = ctrlOL->seleccionarEmpresa(RUT);
				while(!okEmpresa) {
					cout<<"El RUT ingresado no corresponde a una Empresa registrada en el Sistema.\n";
					cout<<"Ingrese un RUT valido a continuacion y presione [ENTER] o ingrese 0 si desea salir del Caso de Uso.\n";
					cout<<"	>";
					getline(cin, RUT);
					if(RUT=="0")
						break;
					else
						okEmpresa = ctrlOL->seleccionarEmpresa(RUT);
				};
			//listarSucursales
				set<DTSucursal*> * Sucs = ctrlOL->listarSucursales();
				if(!Sucs->empty()) {
					cout << "Sucursales:" << endl;
					for(set<DTSucursal*>::iterator itSuc=Sucs->begin() ; itSuc!=Sucs->end() ; itSuc++) {
						DTSucursal* Sucs = *itSuc;
						cout<<"**Nombre: "<< Sucs->getIdSuc() << " -Telefono: " << Sucs->getTelefono() <<
								" -Direccion: " << Sucs->getDireccion() << endl;
					};
				}
				else {
					cout<<"No existen Sucursales para esa Empresa. \n";
					throw 2;
				};
			//seleccionarSucursal
				cout<<"Ingrese el nombre de la Sucursal que creara la nueva Oferta Laboral y presione [ENTER] \n";
				cout<<">";
				getline(cin, idSuc);
				bool okSucursal = ctrlOL->seleccionarSucursal(idSuc);
				while(!okSucursal) {
					cout<<"El nombre ingresado no corresponde a una Sucursal de la empresa seleccionada.\n";
					cout<<"Ingrese un nombre valido a continuacion, o ingrese 0 si desea salir del Caso de Uso, y presione [ENTER].\n";
					cout<<" >";
					getline(cin, idSuc);
					if(idSuc=="0")
						break;
					else
						okSucursal = ctrlOL->seleccionarSucursal(idSuc);
				}
			//listarSecciones
				set<DTSeccion*> * Secs = ctrlOL->listarSecciones();
				if(!Secs->empty()) {
					cout<<"Secciones:"<<endl;
					for(set<DTSeccion*>::iterator it=Secs->begin() ; it!=Secs->end() ; it++) {
						DTSeccion* Secs = *it;
						cout << "**Nombre: " << Secs->getIdSec() << " -Interno: " <<
								Secs->getInterno() << endl;
					};
				}
				else {
					cout<<"No existen Secciones para el par Sucursal/Empresa seleccionado. \n";
					throw 2;
				};
			//seleccionarSeccion
				cout<<"Ingrese el nombre de la Seccion que creara la nueva Oferta Laboral y presione [ENTER] \n";
				cout<<">";
				getline(cin, idSec);
				bool okSeccion = ctrlOL->seleccionarSeccion(idSec);
				while(!okSeccion) {
					cout<<"El nombre ingresado no corresponde a una Seccion de la Empresa  y Sucursal seleccionadas.\n";
					cout<<"Ingrese un nombre valido a continuacion y presione [ENTER] o ingrese 0 si desea salir del Caso de Uso.\n";
					cout<<" >";
					getline(cin, idSec);
					if(idSuc=="0")
						break;
					else
						okSeccion = ctrlOL->seleccionarSeccion(idSec);
				}
			//ingresoYChequeoDeDatosParaLaCreacionDeLaOferta
				cout<<"A continuacion se pide ingresar los datos de la Oferta Laboral concreta. \n";
				cout<<"Ingrese el numero de Expediente que se asociará a la nueva Oferta Laboral y luego presione [ENTER]. \n" ;
				cout<<" >";
				getline(cin, int_aux);
				stringstream(int_aux) >> numExp;
				bool okExp =ctrlOL->chequearExpedienteDisponible(numExp);
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
						//numExp = stoi(int_aux);
						getline(cin, int_aux);
						stringstream(int_aux) >> numExp;
						okExp =ctrlOL->chequearExpedienteDisponible(numExp);
					}
				}
				cout<<"Ingrese el titulo de la nueva Oferta Laboral seguido de [Enter]. \n";
				cout<<" >";
				getline(cin, titulo);
				cout<<"Ingrese la descripcion de la nueva Oferta Laboral y solamente al final presione [Enter]. \n";
				cout<<" >";
				getline(cin, descripcion);
				cout<<"Ingrese la cantidad de horas semanales que requerira el nuevo puesto de trabajo y luego presione [ENTER]. \n" ;
				cout<<" >";
				getline(cin, int_aux);
				stringstream(int_aux) >> h_semanales;
				while(h_semanales>60) {
					cout<<"Error!! \n";
					cout<<"No se permite un llamado que exija mas de 60 horas semanales.\n";
					cout<<"Ingrese la cantidad de horas semanales que requerira el nuevo puesto de trabajo y luego presione [ENTER]. \n" ;
					cout<<" >";
					getline(cin, int_aux);
					stringstream(int_aux) >> h_semanales;
				}
				cout<<"Ingrese el sueldo minimo ofrecido y luego presione [ENTER]. \n" ;
				cout<<" >";
				getline(cin, int_aux);
				stringstream(int_aux) >> sueldo_min;
				cout<<"Ingrese el sueldo maximo ofrecido y luego presione [ENTER]. \n" ;
				cout<<" >";
				getline(cin, int_aux);
				stringstream(int_aux) >> sueldo_max;
				while (sueldo_min > sueldo_max) {
					cout<<"Error!! \n";
					cout<<"El sueldo minimo es mayor que el sueldo maximo de la Oferta Laboral.\n";
					cout<<"Ingrese el sueldo minimo ofrecido y luego presione [ENTER]. \n" ;
					cout<<" >";
					getline(cin, int_aux);
					stringstream(int_aux) >> sueldo_min;
					cout<<"Ingrese el sueldo maximo ofrecido y luego presione [ENTER]. \n" ;
					cout<<" >";
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
				Date* comienzo = new Date(dia, mes, anio);
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
				Date* fin = new Date(dia, mes, anio);
				while (*fin <= *comienzo) {
					cout<<"Error!! \n";
					cout<<"La fecha de finalizacion no es posterior a la fecha de comienzo de la Oferta Laboral.\n";
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
				cout<<"A continuacion debera ingresar los codigos de las Asignaturas requeridas por la Oferta Laaboral seguidos de [ENTER].\n" ;
				cout<<"Cuando no desee agregar mas Asignaturas, ingrese 0 y presione [ENTER]. \n";
				cout<<" >";
				getline(cin, asign);
				set<string> s;
				while (asign != "0") {
					s.insert(asign);
					cout<<" >";
					getline(cin, asign);
				}
				DataOferta * dtO = new DataOferta(numExp, titulo, descripcion, h_semanales, sueldo_min, sueldo_max,
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
				};
			//chequearCandidatos
				bool cand = ctrlOL->chequearCandidatos();
				if (!cand) {
					cout<<"Advertencia!! \n";
					cout<<"Actualmente no existen Estudiantes que hayan aprobado todas las Asignaturas ingresadas. \n\n";
					cout<<"A continuacion se muestran criterios con los que actualizar su lista de AsignaturasRequeridas: \n";
					cout<<"	-Criterio 1: Sugiere las materias aprobadas por algún estudiante.\n";
					cout<<"	-Criterio 2: Sugiere una de las asignaturas seleccionadas, que algún estudiante haya aprobado.\n";
			//actualizarRequerimientos
					cout<<"Ingrese el numero del criterio que desea aplicar para actualizar los requerimientos "
							"de su Oferta Laboral seguido de [ENTER].\n";
					cout<<"Si desea salir del Caso de Uso sin crear la Oferta Laboral ingrese 0 seguido de [ENTER].\n";
					cout<<"	>";
					getline(cin, int_aux);
					stringstream(int_aux) >> criterio;
					bool okCriterio = ((criterio == 1) || (criterio == 2)||(criterio==0));
					while (!okCriterio) {
						cout<<"Error!!\n";
						cout<<"No ha ingresado una opción valida, por favor ingrese [1] o [2] para aplicar uno de los"
								"criterios de actualizacion o [0] para salir del CU.\n";
						getline(cin, int_aux);
						stringstream(int_aux) >> criterio;
						okCriterio = ((criterio == 1) || (criterio == 2)||(criterio==0));
					};
					if (criterio == 0) {
						delete comienzo;
						delete fin;
						delete dtO;
						break;
					}
					else
						ctrlOL->actualizarRequerimientos(criterio);
				}
			//confirmarCreacionOferta
				ctrlOL->confirmarCreacionOferta();
				cout<<"***CASO DE USO FINALIZADO***\n";
				cout<<"La Oferta Laboral ha sido creada con exito!\n";
				delete comienzo;
				delete fin;
				delete dtO;
				break;
			}
			case 2: { // CU Alta Entrevista
			//listar todas las ofertas
				set<DTOferta*> ofs = ctrlOL->obtenerOfertasTodas();
				set<DTOferta*>::iterator it;
				if(!ofs.empty()) {
					cout<<"Ofertas Regristradas:"<<endl;
					for(it = ofs.begin(); it != ofs.end() ; it++) {
						DTOferta* ofs = *it;
						cout<<"	**Num_de_Expediente: "<<ofs->getNumeroDeExpediente() <<
								" - Titulo: "<<ofs->getTitulo()<<"."<<endl;
					};
				}
				else {
					cout<<"No existen Ofertas Registradas en el Sistema. \n";
					throw 2;
				};
			//seleccionarOferta
				cout<<"Ingrese el Numero de Expediente de la Oferta a la cual se le quiere asignar "
						"una Entrevista y presione [ENTER]. \n";
				cout<<"	>";
				getline(cin, int_aux);
				stringstream(int_aux) >> numExp;
				okOferta = ctrlOL->seleccionarOferta(numExp);
				while(!okOferta) {
					cout<<"Error!!\n";
					cout<<"El Numero de Expediente ingresado no corresponde a una Oferta registrada en el Sistema.\n";
					cout<<"Ingrese un Numero de Expediente valido a continuacion y presione [ENTER] "
							"o ingrese 0 si desea salir del Caso de Uso.\n";
					cout<<"	>";
					getline(cin, int_aux);
					stringstream(int_aux) >> numExp;
					if(numExp==0)
						break;
					else
						okOferta = ctrlOL->seleccionarOferta(numExp);
				}
			//listarInscriptos
				set<DTEstudiante*> Ests = ctrlOL->listarInscriptos();
				set<DTEstudiante*>::iterator itEst;
				if(!Ests.empty()) {
					cout<<"Estudiantes Inscriptos a la Oferta Laboral:"<<endl;
					for(itEst=Ests.begin() ; itEst!=Ests.end() ; itEst++) {
						DTEstudiante* est = *itEst;
						cout<<"	**CI: "<<est->getCedula()<<" - Nombre: "<<est->getNombre() <<" - Apellido: "
								<<est->getApellido()<<" - Creditos: "<<est->getCreditosObtenidos()<<"."<<endl;
					};
				}
				else {
					cout<<"No existen Estudiantes Inscriptos para la Oferta Laboral seleccionada. \n";
					cout<<"Fin del Caso de Uso.\n";
					break;
				};
			//seleccionarEstudiante
				cout<<"Ingrese la C.I. del Estudiante a entrevistar y presione [ENTER]. \n";
				cout<<"	>";
				getline(cin, ci);
				okEstudiante = ctrlOL->seleccionarEstudiante(ci);
				while(!okEstudiante) {
					cout<<"Error!!\n";
					cout<<"La C.I. ingresada no corresponde a un Estudiante que haya aplicado a la Oferta.\n";
					cout<<"Ingrese una C.I. valida a continuacion y presione [ENTER] o ingrese 0 si desea salir del Caso de Uso.\n";
					cout<<"	>";
					getline(cin, ci);
					if(ci=="0")
						break;
					else
						okEstudiante = ctrlOL->seleccionarEstudiante(ci);
				};
			//agendarEntrevista
				cout<< "Ingrese la fecha en la que quiere agendar la entrevista: \n";
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
				Date * fecha = new Date(dia, mes, anio);
				bool okFecha = ctrlOL->agendarEntrevista(fecha);
				while (!okFecha) {
					cout<<"Error!! \n";
					cout<<"La fecha ingreasada no es correcta.Las entrevistas deberán agendarse"
							" para fechas posteriores a la fecha de finalizacion del llamado.\n";
					cout<<"Ingrese 1 si quiere ingresar otra fecha o ingrese 0 si desea salir del Caso de Uso.\n";
					cout<<"	>";
					getline(cin, int_aux);
					stringstream(int_aux) >> numExp;
					if(numExp==0)
						break;
					else {
						cout<< "Ingrese una fecha valida: \n";
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
						delete fecha;
						fecha = new Date(dia, mes, anio);
						okFecha = ctrlOL->agendarEntrevista(fecha);
					};
				};
			//confirmarCreacionEntrevista
				ctrlOL->crearEntrevista();
				cout<<"***CASO DE USO FINALIZADO***\n";
				cout<<"La entrevista ha sido agendada.\n";
				delete fecha;
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
			//listarOfertasFinalizadas
				set<DTOferta*> ofs = ctrlOL->listarOfertasFinalizadas();
				set<DTOferta*>::iterator it;
				if(!ofs.empty()) {
					cout<<"Ofertas Finalizadas:"<<endl;
					for(it = ofs.begin(); it != ofs.end() ; it++) {
						DTOferta* ofs = *it;
						cout<<"	**Num_de_Expediente: "<<ofs->getNumeroDeExpediente() <<
								" - Titulo: "<<ofs->getTitulo()<<"."<<endl;
					};
				}
				else {
					cout<<"Error!!\n";
					cout<<"No existen Ofertas Finalizadas en este momento. \n";
					throw 2;
				};
			//seleccionarOfertaFinalizada
				cout<<"Ingrese el Numero de Expediente de la Oferta Laboral a la cual se asociara el nuevo contrato"
						"y presione [ENTER]. \n";
				cout<<"	>";
				getline(cin, int_aux);
				stringstream(int_aux) >> numExp;
				okOferta = ctrlOL->seleccionarOfertaFinalizada(numExp);
				while(!okOferta) {
					cout<<"Error!!\n";
					cout<<"El Numero de Expediente ingresado no corresponde a una Oferta Finalizada del Sistema.\n";
					cout<<"Ingrese un Numero de Expediente valido a continuacion y presione [ENTER] "
							"o ingrese 0 si desea salir del Caso de Uso.\n";
					cout<<"	>";
					getline(cin, int_aux);
					stringstream(int_aux) >> numExp;
					if(numExp==0)
						break;
					else
						okOferta = ctrlOL->seleccionarOferta(numExp);
				}
			//listarInscriptos
				set<DTEstudiante*> Ests = ctrlOL->listarInscriptos();
				set<DTEstudiante*>::iterator itEst;
				if(!Ests.empty()) {
					cout<<"Estudiantes Inscriptos a la Oferta Laboral:"<<endl;
					for(itEst=Ests.begin() ; itEst!=Ests.end() ; itEst++) {
						DTEstudiante* est = *itEst;
						cout<<"	**CI: "<<est->getCedula()<<" - Nombre: "<<est->getNombre() <<" - Apellido: "
								<<est->getApellido()<<" - Creditos: "<<est->getCreditosObtenidos()<<"."<<endl;
					};
				}
				else {
					cout<<"No existen Estudiantes Inscriptos para la Oferta Laboral seleccionada. \n";
					cout<<"Fin del Caso de Uso.\n";
					break;
				};
			//seleccionarEstudiante
				cout<<"Ingrese la C.I. del Estudiante a entrevistar y presione [ENTER]. \n";
				cout<<"	>";
				getline(cin, ci);
				okEstudiante = ctrlOL->seleccionarEstudiante(ci);
				while(!okEstudiante) {
					cout<<"Error!!\n";
					cout<<"La C.I. ingresada no corresponde a un Estudiante que haya aplicado a la Oferta.\n";
					cout<<"Ingrese una C.I. valida a continuacion y presione [ENTER] o ingrese 0 si desea salir del Caso de Uso.\n";
					cout<<"	>";
					getline(cin, ci);
					if(ci=="0")
						break;
					else
						okEstudiante = ctrlOL->seleccionarEstudiante(ci);
				};
			//asignarCargo
				cout<<"Finalmente ingrese el sueldo acordado para la contratacion y presione [ENTER].\n";
				cout<<"	>";
				getline(cin, int_aux);
				stringstream(int_aux) >> sueldo;
				ctrlOL->asignarCargo(sueldo);
				cout<<"***CASO DE USO FINALIZADO***\n";
				cout<<"El puesto laboral ha sido asignado.";
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
				ManejadorBedelia* mngB = ManejadorBedelia::getInstance();
				CargarDatos(mngB, ctrlOL);
				break;
			}
			case 13: {
				break;
			}
			default: {
				throw 1;
				break;
			}
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
				//cin >> comando;
				break;
			}
			case 2: { //CU Abortado
				cout<< "Caso de Uso Abortado por falta de Informacion en el Sistema.\n";
				break;
			}
			}
		}
	}
	return 0;
}
