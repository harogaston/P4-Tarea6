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
#include <sstream>
#include <iterator>

#include "CtrlOfertaLaboral.h"
#include "DataEstudiante.h"
#include "DataOferta.h"
#include "DataOfertaRestringida.h"
#include "Date.h"
#include "DTAplicacion.h"
#include "DTAsignatura.h"
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

//Forward declarations de las operaciones auxiliares

void CargarDatos(ManejadorBedelia* mngB, ICtrlOfertaLaboral* ctrlOL);
Date * solicitarFecha();
DataOfertaRestringida * solicitarDatosOferta();
void printDTEstudiante(DTEstudiante * est);
void printAsignaturasSalvadas(set<DTAsignaturaSalvada*> * asignaturas);
void printAplicaciones(set<DTAplicacion*> * aplicaciones);
void printCarreras(set<DTCarrera*> * carreras);
void printDataEstudiante(DataEstudiante * est);
void printFullDTOferta(FullDTOferta * of);
// void printCarreras(ICtrlOfertaLaboral * ctrlOL, set<DTCarrera*> * Cs);
void liberarMemoria();
bool printAsignaturasNoRequeridas(int numExp);
bool printAsignaturasRequeridas(int numExp);


int main() {
	//*************************************************Declaracion de variables** *****************************************************
	int comando , numExp, h_semanales, puestos, criterio;
	float sueldo_min, sueldo_max, sueldo;
	bool salir, okOferta, okEstudiante;
	string int_aux, idSuc, idSec, titulo, descripcion, asign, ci, RUT, carr;
	//*************************************************Inicializacion del Sistema *****************************************************

	Fabrica* f = Fabrica::getInstance();
	FechaSistema * FS = FechaSistema::getInstance();
	ICtrlOfertaLaboral * ctrlOL= f -> getICtrlOfertaLaboral();

	{ // para que mngB viva solo en estas llaves

		ManejadorBedelia* mngB = ManejadorBedelia::getInstance();
		CargarDatos(mngB, ctrlOL);
	}


	// COSILLAS DE TESTEO
	//mngB->printAsignaturas();
	//mngB->printAsignaturasDeCarrera("1010");

	//*************************************************Presentacion del menu **********************************************************
	cout << "_______________________________________________________________________" << endl << endl;
	cout << "		Laboratorio 6 de Programacion 4 2015 " << endl;
	cout << "			BuscoFIngJobs " << endl;
	cout << "_______________________________________________________________________" << endl;

	//***************************************************Seleccion de opciones ********************************************************
	salir = false;
	while (!salir) {
		try {
			cout << endl << "Menu de funcionalidades: \n ";
			cout << "	1) Alta Oferta Laboral \n ";
			cout << "	2) Alta Entrevista \n ";
			cout << "	3) Inscripcion Oferta Laboral \n ";
			cout << "	4) Listar Ofertas Activas\n ";
			cout << "	5) Consultar Datos Estudiante \n ";
			cout << "	6) Asignacion de Oferta a Estudiante \n ";
			cout << "	7) Modificar Estudiante \n ";
			cout << "	8) Modificar Llamado  \n ";
			cout << "	9) Dar de Baja Llamado \n ";
			cout << "	10) Mostrar Notificaciones de Estudiante \n ";
			cout << " 	11) Setear Fecha del Sistema \n ";
			cout << "	12) Salir del programa \n ";
			cout << endl << "Ingrese el numero de opcion que prefiera y presione [ENTER]: \n";
			cout << " >";

			getline(cin, int_aux);
			stringstream(int_aux) >> comando;
			switch (comando) {
			case 1: {
			// CU Alta Oferta Laboral
			//listarEmpresas
				set<DTEmpresa*> * Emps = ctrlOL->listarEmpresas();
				if(not Emps->empty()) {
					cout<< endl << "Empresas Registradas:" << endl;
					int cantEmpresas = 0;
					for(set<DTEmpresa*>::iterator it = Emps->begin() ; it!=Emps->end() ; it++) {
						cantEmpresas++;
						DTEmpresa* Emps = *it;
						cout << "	Empresa " << cantEmpresas << ":" << endl;
						cout << "		RUT: " << Emps->getRUT() << endl;
						cout << "		Empresa: " << Emps->getNombre() << endl;
					};
				}
				else {
					cout << "No existen Empresas registradas en el Sistema. \n";
					throw 2;
				};
			//seleccionarEmpresa
				cout << endl << "Ingrese el RUT de la Empresa que creara la nueva Oferta Laboral y presione [ENTER] \n";
				cout << " >";
				getline(cin, RUT);
				bool okEmpresa = ctrlOL->seleccionarEmpresa(RUT);
				while(!okEmpresa) {
					cout << endl << "El RUT ingresado no corresponde a una Empresa registrada en el Sistema.\n";
					cout << "Ingrese un RUT valido a continuacion y presione [ENTER] o ingrese 0 si desea salir del Caso de Uso.\n";
					cout << "	>";
					getline(cin, RUT);
					if(RUT == "0")
						throw 3;
					else
						okEmpresa = ctrlOL->seleccionarEmpresa(RUT);
				};
			//listarSucursales
				set<DTSucursal*> * Sucs = ctrlOL->listarSucursales();
				if(!Sucs->empty()) {
					cout << endl << "Sucursales:" << endl;
					int cantSucursales = 0;
					for(set<DTSucursal*>::iterator itSuc=Sucs->begin() ; itSuc!=Sucs->end() ; itSuc++) {
						cantSucursales++;
						DTSucursal* Sucs = *itSuc;
						cout << "	Sucursal " << cantSucursales << ":" << endl;
						cout << "		Nombre: "<< Sucs->getIdSuc() << endl;
						cout << "		Telefono: " << Sucs->getTelefono() << endl;
						cout <<	"		Direccion: " << Sucs->getDireccion() << endl;
					};
				}
				else {
					cout << endl << "No existen Sucursales para esa Empresa. \n";
					throw 2;
				};
			//seleccionarSucursal
				cout << endl << "Ingrese el nombre de la Sucursal que creara la nueva Oferta Laboral y presione [ENTER] \n";
				cout << ">";
				getline(cin, idSuc);
				bool okSucursal = ctrlOL->seleccionarSucursal(idSuc);
				while(!okSucursal) {
					cout << endl << "El nombre ingresado no corresponde a una Sucursal de la empresa seleccionada.\n";
					cout << "Ingrese un nombre valido a continuacion, o ingrese 0 si desea salir del Caso de Uso, y presione [ENTER].\n";
					cout << " >";
					getline(cin, idSuc);
					if(idSuc == "0")
						throw 3;
					else
						okSucursal = ctrlOL->seleccionarSucursal(idSuc);
				}
			//listarSecciones
				set<DTSeccion*> * Secs = ctrlOL->listarSecciones();
				if(!Secs->empty()) {
					cout << endl << "Secciones:"<<endl;
					int cantSecciones = 0;
					for(set<DTSeccion*>::iterator it=Secs->begin() ; it!=Secs->end() ; it++) {
						cantSecciones++;
						DTSeccion* Secs = *it;
						cout << "	Seccion " << cantSecciones << ":" << endl;
						cout << "		Nombre: " << Secs->getIdSec() << endl;
						cout << "		Interno: " << Secs->getInterno() << endl;
					};
				}
				else {
					cout << endl << "No existen Secciones para el par Sucursal/Empresa seleccionado. \n";
					throw 2;
				};
			//seleccionarSeccion
				cout << endl << "Ingrese el nombre de la Seccion que creara la nueva Oferta Laboral y presione [ENTER] \n";
				cout << ">";
				getline(cin, idSec);
				bool okSeccion = ctrlOL->seleccionarSeccion(idSec);
				while(!okSeccion) {
					cout << endl << "El nombre ingresado no corresponde a una Seccion de la Empresa  y Sucursal seleccionadas.\n";
					cout << "Ingrese un nombre valido a continuacion y presione [ENTER] o ingrese 0 si desea salir del Caso de Uso.\n";
					cout << " >";
					getline(cin, idSec);
					if(idSuc == "0")
						throw 3;
					else
						okSeccion = ctrlOL->seleccionarSeccion(idSec);
				}
			//ingresoYChequeoDeDatosParaLaCreacionDeLaOferta
				cout << endl << "A continuacion se pide ingresar los datos de la Oferta Laboral concreta. \n";
				cout << "Ingrese el numero de Expediente que se asociará a la nueva Oferta Laboral y luego presione [ENTER]. \n" ;
				cout << " >";
				getline(cin, int_aux);
				stringstream(int_aux) >> numExp;
				bool okExp =ctrlOL->chequearExpedienteDisponible(numExp);
				while (!okExp) {
					cout << endl << "Error!! \n";
					cout << "El numero de expediente ingresado ya está registrado para otra Oferta Laboral.\n";
					cout<< "Ingrese otro numero de Expediente al que se asociará la nueva Oferta Laboral y luego presione [ENTER]. \n" ;
					cout << "Si desea salir del CU ingrese \"salir\" y presione [ENTER]. \n";
					cout << " >";
					getline(cin, int_aux);
					if (int_aux == "salir")
						throw 3;
					else {
						stringstream(int_aux) >> numExp;
						okExp =ctrlOL->chequearExpedienteDisponible(numExp);
					}
				}
				cout << endl << "Ingrese el titulo de la nueva Oferta Laboral seguido de [Enter]. \n";
				cout << " >";
				getline(cin, titulo);
				cout << endl << "Ingrese la descripcion de la nueva Oferta Laboral y solamente al final presione [Enter]. \n";
				cout << " >";
				getline(cin, descripcion);
				cout << endl << "Ingrese la cantidad de horas semanales que requerira el nuevo puesto de trabajo y luego presione [ENTER]. \n" ;
				cout << " >";
				getline(cin, int_aux);
				stringstream(int_aux) >> h_semanales;
				while(h_semanales>60) {
					cout << endl << "Error!! \n";
					cout << "No se permite un llamado que exija mas de 60 horas semanales.\n";
					cout << "Ingrese la cantidad de horas semanales que requerira el nuevo puesto de trabajo y luego presione [ENTER]. \n" ;
					cout << " >";
					getline(cin, int_aux);
					stringstream(int_aux) >> h_semanales;
				}
				cout << endl << "Ingrese el sueldo minimo ofrecido y luego presione [ENTER]. \n" ;
				cout << " >";
				getline(cin, int_aux);
				stringstream(int_aux) >> sueldo_min;
				cout << endl << "Ingrese el sueldo maximo ofrecido y luego presione [ENTER]. \n" ;
				cout << " >";
				getline(cin, int_aux);
				stringstream(int_aux) >> sueldo_max;
				while (sueldo_min > sueldo_max) {
					cout << endl <<  "Error!! \n";
					cout << "El sueldo minimo es mayor que el sueldo maximo de la Oferta Laboral.\n";
					cout << "Ingrese el sueldo minimo ofrecido y luego presione [ENTER]. \n" ;
					cout << " >";
					getline(cin, int_aux);
					stringstream(int_aux) >> sueldo_min;
					cout << endl <<  "Ingrese el sueldo maximo ofrecido y luego presione [ENTER]. \n" ;
					cout << " >";
					getline(cin, int_aux);
					stringstream(int_aux) >> sueldo_max;
				}
				cout<< endl << "Ingrese la fecha de comienzo del llamado: \n";
				Date* comienzo = solicitarFecha();
				cout<< endl << "Ingrese la fecha de finalizacion del llamado: \n";
				Date* fin = solicitarFecha();
				while (*fin <= *comienzo) {
					cout << endl << "Error!! \n";
					cout << "La fecha de finalizacion no es posterior a la fecha de comienzo de la Oferta Laboral.\n";
					delete comienzo;
					delete fin;
					comienzo = solicitarFecha();
					cout<< endl << "Ingrese la fecha de finalizacion del llamado: \n";
					fin = solicitarFecha();
				}
				cout << endl << "Ingrese la cantidad de puestos disponibles para la Oferta Laboral y luego presione [ENTER]. \n" ;
				cout << " >";
				getline(cin, int_aux);
				stringstream(int_aux) >> puestos;
				cout << endl << "A continuacion debera ingresar los codigos de las Asignaturas requeridas por la Oferta Laboral seguidos de [ENTER].\n" ;
				//listarAsignaturas
					set<DTAsignatura*> * As = ctrlOL->listarAsignaturas();
					if(!As->empty()) {
						cout << endl << "Asignaturas:"<<endl;
						int cantAsignaturas = 0;
						for(set<DTAsignatura*>::iterator it=As->begin() ; it!=As->end() ; it++) {
							cantAsignaturas++;
							DTAsignatura* DTAs = *it;
							cout << "	Asignatura " << cantAsignaturas << ":" << endl;
							cout << "		Nombre: " << DTAs->getNombre() << endl;
							cout << "		Codigo: " << DTAs->getCodigo() << endl;
						};
					}
					else {
						cout << endl << "No existen Asignaturas en el sistema. \n";
						throw 2;
					};
				cout << "Cuando no desee agregar mas Asignaturas, ingrese 0 y presione [ENTER]. \n";
				cout << " >";
				getline(cin, asign);
				set<string> * s = new set<string>;
				while (asign != "0") {
					s->insert(asign);
					cout << " >";
					getline(cin, asign);
				}
				DataOferta * dtO = new DataOferta(
						numExp,
						titulo,
						descripcion,
						h_semanales,
						sueldo_min,
						sueldo_max,
						comienzo,
						fin,
						puestos,
						s);
				bool okOferta = ctrlOL->chequearAsignaturas(dtO);
				while (!okOferta) {
					cout << endl << "Error!! \n";
					cout << "Uno o varios de los codigos de Asignatura ingresados no es correcto. \n";
					cout << "A continuacion debera ingresar los codigos de las asignaturas requeridas por la Oferta Laaboral seguidos de [ENTER].\n" ;
					cout << "Cuando no desee agregar mas Asignaturas, ingrese 0 y presione [ENTER]. \n";
					cout << " >";
					getline(cin, asign);
					set<string> * s = new set<string>;
					while (asign != "0") {
						s->insert(asign);
						cout << " >";
						getline(cin, asign);
					}
					dtO = new DataOferta(
							numExp,
							titulo,
							descripcion,
							h_semanales,
							sueldo_min,
							sueldo_max,
							comienzo,
							fin,
							puestos,
							s);
					okOferta = ctrlOL->chequearAsignaturas(dtO);
				};
			//chequearCandidatos
				bool cand = ctrlOL->chequearCandidatos();
				if (!cand) {
					cout << endl << "Advertencia!! \n";
					cout << "Actualmente no existen Estudiantes que hayan aprobado todas las Asignaturas ingresadas. \n\n";
					cout << "A continuacion se muestran criterios con los que actualizar su lista de AsignaturasRequeridas: \n";
					cout << "	Criterio 1: Sugiere las materias aprobadas por algún estudiante.\n";
					cout << "	Criterio 2: Sugiere una de las asignaturas seleccionadas, que algún estudiante haya aprobado.\n";
			//actualizarRequerimientos
					cout << endl << "Ingrese el numero del criterio que desea aplicar para actualizar los requerimientos "
							"de su Oferta Laboral seguido de [ENTER].\n";
					cout << "Si desea salir del Caso de Uso sin crear la Oferta Laboral ingrese 0 seguido de [ENTER].\n";
					cout << "	>";
					getline(cin, int_aux);
					stringstream(int_aux) >> criterio;
					bool okCriterio = ((criterio == 1) || (criterio == 2)||(criterio==0));
					while (!okCriterio) {
						cout << endl << "Error!!\n";
						cout << "No ha ingresado una opción valida, por favor ingrese [1] o [2] para aplicar uno de los"
								"criterios de actualizacion o [0] para salir del CU.\n";
						getline(cin, int_aux);
						stringstream(int_aux) >> criterio;
						okCriterio = ((criterio == 1) || (criterio == 2)||(criterio==0));
					};
					if (criterio == 0) {
						delete comienzo;
						delete fin;
						delete dtO;
						throw 3;
					}
					else
						ctrlOL->actualizarRequerimientos(criterio);
				}
			//confirmarCreacionOferta
				ctrlOL->confirmarCreacionOferta();
				cout << endl << "La Oferta Laboral ha sido creada con exito!\n";
				delete comienzo;
				delete fin;
				//delete dtO;
				break;
			}
			case 2: { // CU Alta Entrevista
			//listar todas las ofertas
				set<DTOferta*> * ofs = ctrlOL->obtenerOfertasTodas();
				set<DTOferta*>::iterator it;
				if(!ofs->empty()) {
					cout << endl << "Ofertas Registradas:"<<endl;
					int cantOfertas = 0;
					for(it = ofs->begin(); it != ofs->end() ; it++) {
						cantOfertas++;
						DTOferta* ofs = *it;
						cout << "	Oferta " << cantOfertas << ":" << endl;
						cout << "		Numero de expediente: " << ofs->getNumeroDeExpediente() << endl;
						cout << "		Titulo: " << ofs->getTitulo() << "." << endl;
					};
				}
				else {
					cout << endl << "No existen Ofertas Registradas en el Sistema. \n";
					throw 2;
				};
			//seleccionarOferta
				cout << endl << "Ingrese el Numero de Expediente de la Oferta a la cual se le quiere asignar "
						"una Entrevista y presione [ENTER]. \n";
				cout << "	>";
				getline(cin, int_aux);
				stringstream(int_aux) >> numExp;
				okOferta = ctrlOL->seleccionarOferta(numExp);
				while(!okOferta) {
					cout << endl << "Error!!\n";
					cout << endl << "El Numero de Expediente ingresado no corresponde a una Oferta registrada en el Sistema.\n";
					cout << "Ingrese un Numero de Expediente valido a continuacion y presione [ENTER] "
							"o ingrese 0 si desea salir del Caso de Uso.\n";
					cout << "	>";
					getline(cin, int_aux);
					stringstream(int_aux) >> numExp;
					if(numExp == 0)
						throw 3;
					else
						okOferta = ctrlOL->seleccionarOferta(numExp);
				}
			//listarInscriptos
				set<DTEstudiante*> * Ests = ctrlOL->listarInscriptos();
				set<DTEstudiante*>::iterator itEst;
				if(!Ests->empty()) {
					cout << endl << "Estudiantes Inscriptos a la Oferta Laboral:"<<endl;
					for(itEst=Ests->begin() ; itEst!=Ests->end() ; itEst++) {
						DTEstudiante* est = *itEst;
						printDTEstudiante(est);
					};
				}
				else {
					cout << endl << "No existen Estudiantes Inscriptos para la Oferta Laboral seleccionada. \n";
					cout << "Fin del Caso de Uso.\n";
					break;
				};
			//seleccionarEstudiante
				cout << endl << "Ingrese la C.I. del Estudiante a entrevistar y presione [ENTER]. \n";
				cout << "	>";
				getline(cin, ci);
				okEstudiante = ctrlOL->seleccionarEstudiante(ci);
				while(!okEstudiante) {
					cout << endl << "Error!!\n";
					cout << "La C.I. ingresada no corresponde a un Estudiante que haya aplicado a la Oferta.\n";
					cout << "Ingrese una C.I. valida a continuacion y presione [ENTER] o ingrese 0 si desea salir del Caso de Uso.\n";
					cout << "	>";
					getline(cin, ci);
					if(ci == "0")
						throw 3;
					else
						okEstudiante = ctrlOL->seleccionarEstudiante(ci);
				};
			//agendarEntrevista
				cout<< endl << "Ingrese la fecha en la que quiere agendar la entrevista: \n";
				Date * fecha = solicitarFecha();
				bool okFecha = ctrlOL->agendarEntrevista(fecha);
				while (!okFecha) {
					cout << endl << "Error!! \n";
					cout << "La fecha ingresada no es correcta. Las entrevistas deberán agendarse"
							" para fechas posteriores a la fecha de finalizacion del llamado.\n";
					delete fecha;
					cout << "Ingrese 1 si quiere ingresar otra fecha o ingrese 0 si desea salir del Caso de Uso.\n";
					cout << "	>";
					getline(cin, int_aux);
					stringstream(int_aux) >> numExp;
					if(numExp == 0)
						throw 3;
					else {
						cout<< endl << "Ingrese una fecha valida: \n";
						Date * fecha = solicitarFecha();
						okFecha = ctrlOL->agendarEntrevista(fecha);
					}
				}
			//confirmarCreacionEntrevista
				ctrlOL->crearEntrevista();
				cout << endl << "La entrevista ha sido agendada.\n";
				delete fecha;
				break;
			}
			case 3: { // CU Inscripcion Oferta Laboral
			//listarOfertasActivas
				ICtrlOfertaActiva* ctrlOA = f -> getICtrlOfertaActiva();
				set<FullDTOferta*> * Ofs = ctrlOA->listarOfertasActivas();
				//ICtrlEstudiante* ctrlE = f->getICtrlEstudiante();
				bool nohaycandidatos =  true;
				while (nohaycandidatos){
				if(not Ofs->empty()) {
					cout << endl << "Ofertas Activas:" << endl;
					for(set<FullDTOferta*>::iterator itOf=Ofs->begin() ; itOf!=Ofs->end() ; itOf++) {
						FullDTOferta* of = *itOf;
						printFullDTOferta(of);
					}
				}
				else {
					cout << endl << "No existen Ofertas Activas en el Sistema.\n";
					cout << endl << "Fin del Caso de Uso.\n";
					delete ctrlOA;
					break;
				}
			//seleccionarOfertaActiva
				cout << endl << "Ingrese el Numero de Expediente de la Oferta a la que desea inscribir un estudiante y presione [ENTER]. \n";
				cout << "	>";
				getline(cin, int_aux);
				stringstream(int_aux) >> numExp;
				okOferta = ctrlOA->seleccionarOfertaActiva(numExp);
				while(!okOferta) {
					cout << endl <<  "Error!!\n";
					cout << "El Numero de Expediente ingresado no corresponde a una Oferta Activa del Sistema.\n";
					cout << "Ingrese un Numero de Expediente valido a continuacion y presione [ENTER] "
							"o ingrese [0] si desea salir del Caso de Uso.\n";
					cout << "	>";
					getline(cin, int_aux);
					stringstream(int_aux) >> numExp;
					if(numExp == 0)
						throw 3;
					else
						okOferta = ctrlOA->seleccionarOfertaActiva(numExp);
				}
				if (okOferta) {
					//listarNoInscriptos
					set<DTEstudiante*> * noInscriptos = ctrlOA->listarNoInscriptos();
					set<DTEstudiante*>::iterator it = noInscriptos->begin();
					if(!noInscriptos->empty()) {
						nohaycandidatos = false;
						cout << endl << "A continuacion se listan los estudiantes no inscriptos y candidatos a la oferta seleccionada:" << endl;
						for (it = noInscriptos->begin() ; it != noInscriptos->end() ; it++) {
							printDTEstudiante((*it));
						}
						bool cancela = false;
						bool okEstudiante = false;
						while (not cancela and not okEstudiante){
							cout << endl << "Ingrese la C.I. del Estudiante a inscribir y presione [ENTER]. \n";
							cout << "	>";
							getline(cin, ci);
							okEstudiante = ctrlOA->seleccionarEstudiante(ci);
							while(!okEstudiante) {
								cout << endl << "Error!!\n";
								cout << "La C.I. ingresada no corresponde a un Estudiante elegible para la Oferta.\n";
								cout << "Ingrese una C.I. valida a continuacion y presione [ENTER] o ingrese [0] si desea salir del Caso de Uso.\n";
								cout << "	>";
								getline(cin, ci);
								if(ci=="0") {
									cancela = true;
									throw 3;
								}
								else okEstudiante = ctrlOA->seleccionarEstudiante(ci);
							}
							if (not cancela and okEstudiante) {
								ctrlOA->inscribirEstudiante();
								cout << endl << "El estudiante fue inscripto con exito" << endl;
							}
						}
					} else {
						nohaycandidatos = true;
						cout << endl << "No existen candidatos para la Oferta Laboral seleccionada." << endl;
						cout << "Ingrese [1] si desea probar la funcionalidad con otra Oferta Laboral." << endl;
						cout << "Ingrese [0] si desea salir del Caso de Uso." << endl;
						cout << "	>";
						getline(cin, int_aux);
						stringstream(int_aux) >> comando;
						while (comando != 0 && comando != 1) {
							cout << "El comando ingresado no es valido, por favor ingrese [0] o [1]." << endl;
							cout << "	>";
							getline(cin, int_aux);
							stringstream(int_aux) >> comando;
						}
						if (comando == 0)
							throw 3;
					}
				}
				}
				break;
			}
			case 4: { // CU Listar Ofertas Activas
			//listarOfertasActivas
				ICtrlOfertaActiva* ctrlOA = f -> getICtrlOfertaActiva();
				set<FullDTOferta*> * Ofs = ctrlOA->listarOfertasActivas();
				if(not Ofs->empty()) {
					cout << endl << "Ofertas Activas:" << endl;
					for(set<FullDTOferta*>::iterator itOf=Ofs->begin() ; itOf!=Ofs->end() ; itOf++) {
						FullDTOferta* of = *itOf;
						printFullDTOferta(of);
					}
				}
				else {
					cout << endl << "No existen Ofertas Activas en el Sistema.\n";
					cout << endl << "Fin del Caso de Uso.\n";
					delete ctrlOA;
					break;
				}
				cout << endl << "Todas las Ofertas Activas han sido presentadas" << endl;
				delete ctrlOA;
				break;
			}
			case 5: { // CU Consultar Datos Estudiante
			//listarEstudiantes
				// Fabrica* f = Fabrica::getInstancia();
				ICtrlEstudiante* ctrlE = f -> getICtrlEstudiante();
				set<DTEstudiante*> * Ests = ctrlE->listarEstudiantes();
				set<DTEstudiante*>::iterator itEst;
				bool cancela = false;

				while (not cancela){
					if(!Ests->empty()) {
						cout << "Estudiantes registrados:" << endl;
						for(itEst=Ests->begin() ; itEst!=Ests->end() ; itEst++) {
							DTEstudiante* est = *itEst;
							printDTEstudiante(est);
						}
					}
					else {
						cout << "No existen Estudiantes Registrados en el Sistema.\n";
						cout << "Fin del Caso de Uso.\n";
						break;
					}

					//seleccionarEstudiante
					DataEstudiante * dtE = NULL;

					cout << "Ingrese la C.I. del Estudiante a consultar y presione [ENTER]. \n";
					cout << "	>";
					getline(cin, ci);
					okEstudiante = ctrlE->seleccionarEstudiante(ci);
					while (not okEstudiante && not cancela) {
						cout << "Error!!\n";
						cout << "La C.I. ingresada no corresponde a un Estudiante del Sistema.\n";
						cout << "Ingrese una C.I. valida a continuacion y presione [ENTER] o ingrese 0 si desea salir del Caso de Uso.\n";
						cout << "	>";
						getline(cin, ci);
						if(ci == "0")
							cancela = true;
						else
							okEstudiante = ctrlE->seleccionarEstudiante(ci);
					}
					//consultarDatosEstudiante
					if (not cancela) {
						dtE = ctrlE->consultarDatosEstudiante();
						printDataEstudiante(dtE);
						delete dtE;
						bool error = false;
						do {
							cout << "Para hacer una nueva consulta presione 1, o 0 para salir del Caso de Uso." << endl;
							cout << "La nueva consulta mostrara nuevamente a los estudiantes, para su comodidad." << endl;
							cout << " >";
							getline(cin, int_aux);
							if (int_aux == "0") {
								cancela = true;
								error = false;
							}
							else if (int_aux != "1") {
								cout << "Esa opcion no es valida." << endl;
								error = true;
							} else error = false;
						} while (error);
					}
				}
				delete ctrlE;
				break;
			}
			case 6: { // CU Asignacion de Oferta a Estudiante
			//listarOfertasFinalizadas
				set<DTOferta*> * ofs = ctrlOL->listarOfertasFinalizadas();
				set<DTOferta*>::iterator it;
				if(!(*ofs).empty()) {
					cout << endl << "Ofertas Finalizadas:"<<endl;
					int cantOfertas = 0;
					for(it = ofs->begin(); it != ofs->end() ; it++) {
						cantOfertas++;
						DTOferta* ofs = *it;
						cout << "	Oferta " << cantOfertas << ":" << endl;
						cout << "		Numero de expediente: " << ofs->getNumeroDeExpediente() << endl;
						cout << "		Titulo: " << ofs->getTitulo() << "." << endl;
					};
				}
				else {
					cout << endl << "Error!!\n";
					cout << "No existen Ofertas Finalizadas en este momento. \n";
					throw 2;
				}
			//seleccionarOfertaFinalizada
				cout << endl << "Ingrese el Numero de Expediente de la Oferta Laboral a la cual se asociara el nuevo contrato y presione [ENTER]. \n";
				cout << "	>";
				getline(cin, int_aux);
				stringstream(int_aux) >> numExp;
				okOferta = ctrlOL->seleccionarOfertaFinalizada(numExp);
				while(!okOferta) {
					cout << endl << "Error!!\n";
					cout << "El Numero de Expediente ingresado no corresponde a una Oferta Finalizada del Sistema.\n";
					cout << "Ingrese un Numero de Expediente valido a continuacion y presione [ENTER] o ingrese 0 si desea salir del Caso de Uso.\n";
					cout << "	>";
					getline(cin, int_aux);
					stringstream(int_aux) >> numExp;
					if(numExp == 0)
						throw 3;
					else
						okOferta = ctrlOL->seleccionarOferta(numExp);
				}
			//listarInscriptos
				set<DTEstudiante*> * Ests = ctrlOL->listarInscriptos();
				set<DTEstudiante*>::iterator itEst;
				ManejadorOfertaLaboral * mol = ManejadorOfertaLaboral::getInstance();
				if (not (Ests->empty())) {
					bool estaContratado;
					set<DTEstudiante*>::iterator it1 = Ests->begin();
					while (it1 != Ests->end()){
						estaContratado = mol->getOfertaLaboral(numExp)->estaContratado((*it1)->getCedula());
						if (estaContratado) {
							delete * it1;
							it1 = Ests->erase(it1);
						} else it1++;
					} //me quedo solo con los estudiantes no contratados
					if(not Ests->empty()) { //si al "limpiar" la lista de inscriptos quedo vacia
						cout << endl << "Estudiantes inscriptos (y no contratados) a la Oferta Laboral:"<<endl;
						for(itEst=(*Ests).begin() ; itEst!=(*Ests).end() ; itEst++) {
							DTEstudiante* est = *itEst;
							cout << "	CI: " << est->getCedula() << endl;
							cout << "	Nombre: " << est->getNombre() << endl;
							cout << "	Apellido: " << est->getApellido() << endl;
							cout << "	Creditos: " << est->getCreditosObtenidos() << endl;
						};
						//seleccionarEstudiante
						cout << endl << "Ingrese la C.I. del Estudiante a contratar y presione [ENTER]\n";
						cout << "	>";
						getline(cin, ci);
						okEstudiante = ctrlOL->seleccionarEstudiante(ci);
						while(!okEstudiante) {
							cout << endl << "Error!!\n";
							cout << "La C.I. ingresada no corresponde a un estudiante que haya aplicado a la oferta\n";
							cout << "Ingrese una C.I. valida a continuacion y presione [ENTER] o ingrese 0 si desea salir del Caso de Uso\n";
							cout << "	>";
							getline(cin, ci);
							if(ci == "0")
								throw 3;
							else
								okEstudiante = ctrlOL->seleccionarEstudiante(ci);
						}
						//asignarCargo
						cout << endl << "Finalmente ingrese el sueldo acordado para la contratacion y presione [ENTER]\n";
						cout << "	>";
						getline(cin, int_aux);
						stringstream(int_aux) >> sueldo;
						ctrlOL->asignarCargo(sueldo);
						cout << endl << "El puesto laboral ha sido asignado" << endl;
					} else {
						cout << endl << "No existen Estudiantes Inscriptos para la Oferta Laboral seleccionada\n";
						cout << "Fin del Caso de Uso.\n";
					}
				}else {
					cout << endl << "No existen Estudiantes Inscriptos para la Oferta Laboral seleccionada\n";
					cout << "Fin del Caso de Uso.\n";
					break;
				};
				break;
			}
			case 7: { // CU Modificar Estudiante
			//listarEstudiantes
				// Fabrica* f = Fabrica::getInstancia();
				ICtrlEstudiante* ctrlE = f -> getICtrlEstudiante();
				set<DTEstudiante*> * Ests = ctrlE->listarEstudiantes();
				set<DTEstudiante*>::iterator itEst;
				if(!Ests->empty()) {
					cout << endl << "Estudiantes registrados:" << endl;
						for(itEst=Ests->begin() ; itEst!=Ests->end() ; itEst++) {
							DTEstudiante* est = *itEst;
							printDTEstudiante(est);
						}
				}
				else {
					cout << endl << "No existen Estudiantes Registrados en el Sistema.\n";
					cout << "Fin del Caso de Uso.\n";
					break;
				}
			//seleccionarEstudiante
				cout << endl << "Ingrese la C.I. del Estudiante que desea modificar seguida de [ENTER]. \n";
				cout << "	>";
				getline(cin, ci);
				okEstudiante = ctrlE->seleccionarEstudiante(ci);
				while(!okEstudiante) {
					cout << endl << "Error!!\n";
					cout << "La C.I. ingresada no corresponde a un Estudiante registrado en el sistema.\n";
					cout << "Ingrese una C.I. valida a continuacion y presione [ENTER] o ingrese 0 si desea salir del Caso de Uso.\n";
					cout << "	>";
					getline(cin, ci);
					if(ci == "0")
						throw 3;
					else
						okEstudiante = ctrlE->seleccionarEstudiante(ci);
				}

			/*Podriamos considerar llamar a consultarDatosEstudiante y mostrar solo la informacion de DatosBasicos,
			 Asignaturas y Carreras para mostrar como está el estudiante antes de modificarlo */

			//modificarEstudiante
				string nombre, apellido;
				int tel;
				cout << endl << "A continuacion se le solicitara actualizar los datos del Estudiante seleccionado.\n";
				cout << "	Ingrese el nombre del Estudiante seguido de [Enter]. \n";
				cout << " >";
				getline(cin, nombre);
				cout << " Ingrese el apellido del Estudiante seguido de [Enter]. \n";
				cout << " >";
				getline(cin, apellido);
				cout << " Ingrese la fecha de nacimiento del Estudiante: \n";
				Date* nac = solicitarFecha();
				cout << "	Ingrese el telefono del Estudiante sin espacios ni guiones, seguido de [Enter]. \n";
				cout << " >";
				getline(cin, int_aux);
				stringstream(int_aux) >> tel;
				ctrlE->modificarEstudiante(nombre, apellido, nac, tel);


			//addCarrera
				//Definicion de sets para imprimir luego
				DataEstudiante * dtEst = ctrlE->consultarDatosEstudiante();
				set<DTCarrera*> * carrerasInscripto = dtEst->getCarreras();
				set<DTCarrera*> * carrerasTodas = ctrlOL->listarCarreras();
				for(set<DTCarrera*>::iterator it1 = carrerasInscripto->begin() ; it1 != carrerasInscripto->end() ; it1++) {
					string cod = (*it1)->getCodigo();
					set<DTCarrera*>::iterator it2 = carrerasTodas->begin();
					bool encontreCarrera = false;
					while(it2 != carrerasTodas->end() && not encontreCarrera) {
						if (cod == (*it2)->getCodigo() ) {
							encontreCarrera = true;
							carrerasTodas->erase(it2);
						} else	it2++;
					}
				}
				set<DTCarrera*> * carrerasNoInscripto = carrerasTodas;

				bool error;
				do {
					error = false;
					try {
						cout << "A continuacion tiene la posibilidad de inscribir al Estudiante a nuevas Carreras.\n";
						cout << "Ingrese los codigos de cada Carrera a agregar seguidos de [ENTER].\n" ;
						//listarCarreras
						printCarreras(carrerasNoInscripto);
						cout << "Cuando no desee agregar mas Carreras, ingrese 0 y presione [ENTER]. \n";
						cout << " >";
						getline(cin, carr);
						while (carr != "0") {
							ctrlE->addCarrera(carr);
							cout << " >";
							getline(cin, carr);
						}
					} catch (const std::invalid_argument& e) {
						cout << "Error!! ??????" << endl;
						cout << e.what() << endl;
						error = true;
					}
				} while (error);
				//quitCarrera
				do {
					error = false;
					try {
						cout << "A continuacion tiene la posibilidad de borrar al Estudiante de las Carreras a las que esta inscripto.\n";
						cout << "Ingrese los codigos de cada Carrera a borrar seguidos de [ENTER].\n" ;
						//listarCarrerasDeEstudiante
						// se actualizan las carreras a las que está inscripto por si se agergó alguna
						DataEstudiante * dtEst = ctrlE->consultarDatosEstudiante();
						carrerasInscripto = dtEst->getCarreras();
						printCarreras(carrerasInscripto);
						cout << "Cuando no desee eliminar mas Carreras, ingrese 0 y presione [ENTER].\n";
						cout << " >";
						getline(cin, carr);
						while (carr != "0") {
							ctrlE->quitCarrera(carr);
							cout << " >";
							getline(cin, carr);
						}
					} catch (const std::invalid_argument& e) {
						cout << "Error!!" << endl;
						cout << e.what() << endl;
						error = true;
					}
				} while (error);
				//addAsignatura
				int nota;
				do {
					error = false;
					try{
						cout << "A continuacion tiene la posibilidad de agregar Asignaturas salvadas por el Estudiante.\n";
						cout << "Para cada Asignatura a agregar se solicitara el codigo de la misma, la fecha en la que fue aprobada"
								"y la nota de aprobacion.\n";
						cout << "Cuando no desee agregar mas aprobaciones ingrese [0] en el codigo de la Asignatura.\n";
						cout << "Ingrese el codigo de la Asignatura a agregar: \n";
						cout << " >";
						getline(cin, asign);
						while (asign != "0") {
							cout << " Ingrese la fecha de Aprobacion de la Asignatura: \n";
							Date* aprob = solicitarFecha();
							cout << "	Ingrese la nota de aprobacion seguida de [Enter]. \n";
							cout << " >";
							getline(cin, int_aux);
							stringstream(int_aux) >> nota;
							ctrlE->addAsignatura(aprob, nota, asign);
							cout << "Ingrese el codigo de la Asignatura a agregar, o [0] para terminar con esta funcionalidad.\n";
							cout << " >";
							getline(cin, asign);
						}
					} catch (const std::invalid_argument& e) {
						cout << "Error!!" << endl;
						cout << e.what() << endl;
						error = true;
					}
				} while (error);

			//quitAsignatura
			do {
				error = false;
				try {
				cout << "A continuacion tiene la posibilidad de eliminar Asignaturas salvadas por el Estudiante.\n";
				cout << "Cuando no desee eliminar mas aprobaciones ingrese [0] en el codigo de la Asignatura.\n";
				cout << "Ingrese el codigo de la Asignatura a eliminar: \n";
				cout << " >";
				getline(cin, asign);
				while(asign != "0"){
					ctrlE->quitAsignatura(asign);
					cout << "Ingrese el codigo de la Asignatura a eliminar o [o] para terminar con esta funcionalidad: \n";
					cout << " >";
					getline(cin, asign);
				}
				} catch (const std::invalid_argument& e) {
					cout << "Error!!" << endl;
					cout << e.what() << endl;
					error = true;
				}
			} while (error);
				delete ctrlE;
				/*Tambien hay posibilidad de llamar a consultarDatosEstudiante y mostrarle como quedaron los datos,
				 * asignaturas y carreras del estudiante*/
				break;

			}
			case 8: { // CU Modificar Llamado
			//listarOfertasActivas
				ICtrlOfertaActiva* ctrlOA = f -> getICtrlOfertaActiva();
				set<FullDTOferta*> * Ofs = ctrlOA->listarOfertasActivas();
				set<FullDTOferta*>::iterator itOf;
				if(!Ofs->empty()) {
					cout << endl << "Ofertas Activas:" << endl;
					for(itOf=Ofs->begin() ; itOf!=Ofs->end() ; itOf++) {
						FullDTOferta* of = *itOf;
						printFullDTOferta(of);
					}
				}
				else {
					cout << endl << "No existen Ofertas Activas en el Sistema.\n";
					cout << "Fin del Caso de Uso.\n";
					delete ctrlOA;
					break;
				}
			//seleccionarOfertaActiva
				cout << endl << "Ingrese el Numero de Expediente de la Oferta que desea modificar y presione [ENTER]. \n";
				cout << "	>";
				getline(cin, int_aux);
				stringstream(int_aux) >> numExp;
				okOferta = ctrlOA->seleccionarOfertaActiva(numExp);
				while(!okOferta) {
					cout << endl << "Error!!\n";
					cout << "El Numero de Expediente ingresado no corresponde a una Oferta Activa del Sistema.\n";
					cout << "Ingrese un Numero de Expediente valido a continuacion y presione [ENTER] "
							"o ingrese [0] si desea salir del Caso de Uso.\n";
					cout << "	>";
					getline(cin, int_aux);
					stringstream(int_aux) >> numExp;
					if (numExp == 0) {
						delete ctrlOA;
						throw 3;
					}	
					else okOferta = ctrlOA->seleccionarOfertaActiva(numExp);
				}
				//modificarOferta
				bool modDatos = false;
				bool actAsignaturas = false;
				cout << endl << "A continuacion se le presenta la posibilidad de modificar los datos de la Oferta Laboral. \n";
				cout << "Ingrese: [1] si desea modificar los datos de la Oferta. \n";
				cout << "	 [2] si desea proceder a la proxima fase de modificacion. \n";
				cout << "	 [0] si desea salir del Caso de Uso sin hacer modificaciones. \n";
				cout << "	>";
				getline(cin, int_aux);
				stringstream(int_aux) >> criterio;
				while (criterio != 0 && criterio != 1 && criterio != 2) {
					cout << "El comando ingresado no es valido. \n";
					cout << "Ingrese [1], [2] o [0]. \n";
					cout << "	>";
					getline(cin, int_aux);
					stringstream(int_aux) >> criterio;
				}
				if (criterio == 1) {
					DataOfertaRestringida * dtOf = solicitarDatosOferta();
					ctrlOA->modificarOferta(dtOf);
					modDatos = true;
				}
				else if (criterio == 0) {
					delete ctrlOA;
					throw 3;
				}
				bool goOn = false;
				bool sePuedeAgregar = true;
				bool sePuedeQuitar = true;
				do {
					if (!goOn)
						cout << endl << "A continuación podra modificar la lista de Asignaturas requeridas por la Oferta Laboral." << endl;
					bool accion;
					bool okAsignatura;
					bool error = false;
					do {
						if (error) {
							cout << "Error!! \n";
							cout << "Ha ingresado un comando invalido. \n";
						}
						if (sePuedeAgregar) cout << "Ingrese [1] si desea agregar una Asignatura a la lista de Requerimientos de la Oferta. \n";
						if (sePuedeQuitar) cout << "Ingrese [0] si desea quitar una Asignatura a la lista de Requerimientos de la Oferta. \n";
						cout << "Para finalizar el Caso de Uso ingrese [2]. \n";
						cout << "	>" ;
						getline(cin, int_aux);
						stringstream(int_aux) >> criterio;
						error = ((criterio != 0 && criterio != 1 && criterio != 2) || (!sePuedeAgregar && criterio ==1)
								|| (!sePuedeQuitar && criterio == 0));
					} while (error);
					if (criterio != 2) {
						if (criterio == 0) {
							sePuedeQuitar = printAsignaturasRequeridas(numExp);
							int_aux = "quitar";
							accion = false;
						}
						else {
							sePuedeAgregar = printAsignaturasNoRequeridas(numExp);
							int_aux = "agregar";
							accion = true;
						}
						if ((criterio == 1 && sePuedeAgregar) || (criterio == 0 && sePuedeQuitar)) {
							bool salir = false;
							cout << endl << "Ingrese el codigo de la asignatura que desea " << int_aux << " o presione [0] para salir." << endl;
							cout << "	>" ;
							getline(cin, asign);
							if (asign != "0") {
								okAsignatura = ctrlOA->seleccionarAsignatura(accion, asign);
								while (!okAsignatura && !salir) {
									cout << "No se puede realizar la accion requerida con el codigo de Asignatura ingresado. \n";
									cout << "Ingrese el codigo de una Asignatura valida para " << int_aux << " o presione [0] para salir del Caso de Uso. \n";
									cout << "	>" ;
									getline(cin, asign);
									if (asign != "0") {
										okAsignatura = ctrlOA->seleccionarAsignatura(accion, asign);
									}
									else {
										salir = true;
										goOn = false;
										cout << "Fin del Caso de Uso. \n";
									}
								}
								if (!salir) {
									actAsignaturas = true;
									if (accion) {
										ctrlOA->agregarAsignaturaRequerida();
										cout << "La Asignatura " << asign << " ha sido agregada con exito de la lista de requerimientos. \n \n";
									}
									else {
										ctrlOA->quitarAsignaturaRequerida();
										cout << "La Asignatura " << asign << " ha sido quitada con exito de la lista de requerimientos. \n \n";
									}
									goOn = true;
								}
							}
							else {
								goOn = false;
								cout << "Fin del Caso de Uso. \n";
							}	
						}	
					}
					else {
						goOn = false;
						cout << "Fin del Caso de Uso. \n";
						if (!modDatos && !actAsignaturas) cout << "No se han realizado modificaciones. \n";
					}
				} while (goOn);
				if (modDatos)
					cout << "Los datos de la Oferta Laboral han sido modificados. \n";
				if (actAsignaturas)
					cout << "Las Asignaturas requeridas por la Oferta Laboral han sido actualizadas. \n";
				delete ctrlOA;
				break;
			}
			case 9: { //CU Dar de Baja Llamado
			//listar todas las ofertas
				set<DTOferta*> * ofs = ctrlOL->obtenerOfertasTodas();
				set<DTOferta*>::iterator it;
				if(!ofs->empty()) {
					cout << endl << "Ofertas Registradas:"<<endl;
					int cantOfertas = 0;
					for(it = ofs->begin(); it != ofs->end() ; it++) {
						cantOfertas++;
						DTOferta* ofs = *it;
						cout << "	Oferta " << cantOfertas << ":" << endl;
						cout << "		Numero de expediente: " << ofs->getNumeroDeExpediente() << endl;
						cout << "		Titulo: " << ofs->getTitulo() << "" << endl;
					};
				}
				else {
					cout << endl << "No existen Ofertas Registradas en el Sistema. \n";
					throw 2;
				};
			//seleccionarOferta
				cout << endl << "Ingrese el Numero de Expediente de la Oferta Laboral que desea dar de baja "
						"y presione [ENTER]. \n";
				cout << "	>";
				getline(cin, int_aux);
				stringstream(int_aux) >> numExp;
				okOferta = ctrlOL->seleccionarOferta(numExp);
				while(!okOferta) {
					cout << endl << "Error!!\n";
					cout << endl << "El Numero de Expediente ingresado no corresponde a una Oferta registrada en el Sistema.\n";
					cout << "Ingrese un Numero de Expediente valido a continuacion y presione [ENTER] "
							"o ingrese 0 si desea salir del Caso de Uso.\n";
					cout << "	>";
					getline(cin, int_aux);
					stringstream(int_aux) >> numExp;
					if(numExp == 0)
						throw 3;
					else
						okOferta = ctrlOL->seleccionarOferta(numExp);
				}
			//darDeBaja()
				ctrlOL->darDeBaja();
				cout << endl << "La oferta ha sido dada de baja con exito!\n";
				break;
			}
			case 10: { //CU Mostrar Notificaciones de Estudiante
			//listarEstudiantes
				// Fabrica* f = Fabrica::getInstancia();
				ICtrlEstudiante* ctrlE = f -> getICtrlEstudiante();
				set<DTEstudiante*> * Ests = ctrlE->listarEstudiantes();
				set<DTEstudiante*>::iterator itEst;
				if(!Ests->empty()) {
					cout << endl << "Estudiantes registrados:" << endl;
						for(itEst=Ests->begin() ; itEst!=Ests->end() ; itEst++) {
							DTEstudiante* est = *itEst;
							printDTEstudiante(est);
						}
				}
				else {
					cout << "No existen estudiantes registrados en el sistema.\n";
					cout << "Fin del Caso de Uso.\n";
					break;
				}
			//seleccionarEstudiante
				cout << endl << "Ingrese la C.I. del Estudiante que desea modificar seguida de [ENTER]. \n";
				cout << "	>";
				getline(cin, ci);
				okEstudiante = ctrlE->seleccionarEstudiante(ci);
				//if (okEstudiante) cout << "El estudiante seleccionado es correcto.\n";
				while(!okEstudiante) {
					cout << endl << "Error!!\n";
					cout << "La C.I. ingresada no corresponde a un Estudiante registrado en el sistema.\n";
					cout << "Ingrese una C.I. valida a continuacion y presione [ENTER] o ingrese 0 si desea salir del Caso de Uso.\n";
					cout << "	>";
					getline(cin, ci);
					if(ci == "0")
						throw 3;
					else
						okEstudiante = ctrlE->seleccionarEstudiante(ci);
				}
			//mostrarNotificaciones
				set<FullDTOferta*> * Nots = ctrlE->mostrarNotificacionesDeEstudiante();
				set<FullDTOferta*>::iterator itNot;
				if(!Nots->empty()) {
					cout << endl << "Notificaciones:" << endl;
						for(itNot=Nots->begin() ; itNot!=Nots->end() ; itNot++) {
							FullDTOferta* no = *itNot;
							printFullDTOferta(no);
							/*
							cout << "NUMERO DE EXPEDIENTE: " << no->getNumeroDeExpediente() << "	OFERTA: " << no->getTitulo() << endl;
							cout << "EMPRESA: " << no->getEmpresa() << "	UBICACION: " << no->getUbicacionSucursal() << endl;
							float min = no->getSueldoMin();
							float max = no->getSueldoMax();
							cout << "	RANGO SALARIAL: " << min << " - " << max << endl;
							cout << "	VIGENCIA: " << no->getComienzoLlamado() << " - " << no->getFinLlamado() << endl;
							cout << endl;
							*/
						}
				}
				else {
					cout << endl << "No existen notificaciones para este estudiante en el Sistema.\n";
					cout << "Fin del Caso de Uso.\n";
					break;
				}
				break;
			}
			case 11: { //Setear Fecha del Sistema
				cout << endl << "A continuacion se le solicitaran los datos para setear la Fecha del Sistema: \n";
				Date* newFecha = solicitarFecha();
				FS->setFecha(newFecha);
				cout << endl << "La Fecha del Sistema es: " << *newFecha << endl;
				break;
			}
			case 12: {
				salir = true;
				break;
			}
			default: {
				throw 1;
				break;
			}
			}
		}
		catch (int exc) {
			//cout<< endl << "Error: ";
			switch (exc) {
			case 1: { // Comando invalido
				cout<< "Comando invalido\n";
				/*
				cout<< endl << "Ingrese un comando valido \n";
				cout<< ">";
				getline(cin, int_aux);
				stringstream(int_aux) >> comando;
				*/
				break;
			}
			case 2: { //CU Abortado
				cout<< endl << "Caso de Uso Abortado por falta de Informacion en el Sistema.\n";
				break;
			}
			case 3: {
				cout << "Caso de Uso Cancelado por el Usuario. \n";
				break;
			}
			}// switch
		}
	}
	liberarMemoria();
	return 0;
}

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
	mngB->asociarEstudianteACarrera("4516231", "1011");
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
	set<string> * Lista = new set<string>;
	Lista->insert("6598");
	Lista->insert("5698");
	Lista->insert("4875");
	Lista->insert("9171");
	DataOferta * dtO = new DataOferta(
			45896,
			"Auditor de seguridad part-time junior",
			"Segurol S.A. busca estudiantes de Ingenieria en Computacion para unirse a su equipo.\n	Se requiere un nivel minimo de conocimiento en seguridad informatica y programacion.\n	Interesados enviar cv a oportunidades@segurol.com.uy",
			20,
			2000.0,
			3000.0,
			new Date(1, 6, 2015),
			new Date(20, 7, 2015),
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
			"Estamos buscando estudiantes avanzados de Ingenieria Electrica con perfil potencia.\n	Es imprescindible tener disponibilidad para viajar al interior del pais una vez por mes.\n	Se pagan viaticos ademas de sueldo.\n	Llamar al 25225323 int 1205 para mas detalles.",
			30,
			4000,
			5000,
			new Date(20, 5, 2015),
			new Date(30, 6, 2015),
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
			"Buscamos desarrollador C++ para importante proyecto internacional.\n	Llenar formulario con datos personales y cv en minisoft.uy/careers.",
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
			"Buscamos estudiantes de Ingenieria con Calculo 1 y 2 aprobadas.\n	Deben tener disponibilidad horaria y gusto por enseñar.\n	Enviar mail a academiayotexplico@gmail.com.",
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

Date * solicitarFecha(){
	string int_aux;
	int anio, mes, dia;
	cout << "	Anio >";
	getline(cin, int_aux);
	stringstream(int_aux) >> anio;
	while((anio<1888) or (anio>2100) or (int_aux == "")) {
		cout << "Anio fuera de rango, ingrese un anio entre 1888 y 2100.\n";
		cout << "	Anio >";
		getline(cin, int_aux);
		stringstream(int_aux) >> anio;
	}
	cout << "	Mes >";
	getline(cin, int_aux);
	stringstream(int_aux) >> mes;
	while((mes<1) or (mes>12) or (int_aux == "")) {
		cout << "Mes fuera de rango, ingrese un mes entre 1 y 12.\n";
		cout << "	Mes >";
		getline(cin, int_aux);
		stringstream(int_aux) >> mes;
	}
	cout << "	Dia >";
	getline(cin, int_aux);
	stringstream(int_aux) >> dia;
	if (mes == 1 or mes == 3 or mes== 5 or mes==7 or mes == 8 or mes == 10 or mes == 12 or int_aux == "") {
		while((dia<1) or (dia>31)) {
			cout << "Dia fuera de rango, ingrese un dia entre 1 y 31.\n";
			cout << "	Dia>";
			getline(cin, int_aux);
			stringstream(int_aux) >> dia;
		}
	}
	else if (mes != 2) {
		while((dia<1) or(dia>30)) {
			cout << "Dia fuera de rango, ingrese un dia entre 1 y 30.\n";
			cout << "	Dia>";
			getline(cin, int_aux);
			stringstream(int_aux) >> dia;
		}
	}
	else if (anio % 4 == 0)	{
		while((dia<1) or(dia>29)) {
			cout << "Dia fuera de rango, ingrese un dia entre 1 y 29.\n";
			cout << "	Dia>";
			getline(cin, int_aux);
			stringstream(int_aux) >> dia;
		}
	}
	else {
		while((dia<1) or(dia>28)) {
			cout << "Dia fuera de rango, ingrese un dia entre 1 y 28.\n";
			cout << "	Dia>";
			getline(cin, int_aux);
			stringstream(int_aux) >> dia;
		}
	}
	return new Date(dia, mes, anio);
}

DataOfertaRestringida * solicitarDatosOferta(){
	string tit, desc, int_aux;
	int h, puestos;
	float min, max;
	cout << "Ingrese el titulo de la nueva Oferta Laboral seguido de [Enter]. \n";
	cout << " >";
	getline(cin, tit);
	cout << "Ingrese la descripcion de la nueva Oferta Laboral y solamente al final presione [Enter]. \n";
	cout << " >";
	getline(cin, desc);
	cout << "Ingrese la cantidad de horas semanales que requerira el nuevo puesto de trabajo y luego presione [ENTER]. \n" ;
	cout << " >";
	getline(cin, int_aux);
	stringstream(int_aux) >> h;
	while(h>60) {
		cout << "Error!! \n";
		cout << "No se permite un llamado que exija mas de 60 horas semanales.\n";
		cout << "Ingrese la cantidad de horas semanales que requerira el nuevo puesto de trabajo y luego presione [ENTER]. \n" ;
		cout << " >";
		getline(cin, int_aux);
		stringstream(int_aux) >> h;
	}
	cout << "Ingrese el sueldo minimo ofrecido y luego presione [ENTER]. \n" ;
	cout << " >";
	getline(cin, int_aux);
	stringstream(int_aux) >> min;
	cout << "Ingrese el sueldo maximo ofrecido y luego presione [ENTER]. \n" ;
	cout << " >";
	getline(cin, int_aux);
	stringstream(int_aux) >> max;
	while (min > max) {
		cout << "Error!! \n";
		cout << "El sueldo minimo es mayor que el sueldo maximo de la Oferta Laboral.\n";
		cout << "Ingrese el sueldo minimo ofrecido y luego presione [ENTER]. \n" ;
		cout << " >";
		getline(cin, int_aux);
		stringstream(int_aux) >> min;
		cout << "Ingrese el sueldo maximo ofrecido y luego presione [ENTER]. \n" ;
		cout << " >";
		getline(cin, int_aux);
		stringstream(int_aux) >> max;
	}
	cout<< "Ingrese la fecha de comienzo del llamado: \n";
	Date* comienzo = solicitarFecha();
	cout<< "Ingrese la fecha de finalizacion del llamado: \n";
	Date* fin = solicitarFecha();
	while (*fin <= *comienzo) {
		cout << "Error!! \n";
		cout << "La fecha de finalizacion no es posterior a la fecha de comienzo de la Oferta Laboral.\n";
		delete comienzo;
		delete fin;
		comienzo = solicitarFecha();
		cout<< "Ingrese la fecha de finalizacion del llamado: \n";
		fin = solicitarFecha();
	}
	cout << "Ingrese la cantidad de puestos disponibles para la Oferta Laboral y luego presione [ENTER]. \n" ;
	cout << " >";
	getline(cin, int_aux);
	stringstream(int_aux) >> puestos;
	DataOfertaRestringida * dtO = new DataOfertaRestringida(tit, desc, h, min, max, comienzo, fin, puestos);
	return dtO;
}

void printDTEstudiante(DTEstudiante * est) {
	cout << endl << "CI: " << est->getCedula() << endl;
	cout << "Nombre: " << est->getNombre() << endl;
	cout << "Apellido: " << est->getApellido() << endl;
	cout << "Creditos obtenidos: " << est->getCreditosObtenidos() << endl;
	cout << "Fecha de nacimiento: " << *(est->getFechaNac()) << endl;
}

void printAsignaturasSalvadas(set<DTAsignaturaSalvada*> * asignaturas) {
	short i = 0;
	if (not asignaturas->empty()) cout << "Asignaturas aprobadas:" << endl;
	for (set<DTAsignaturaSalvada*>::iterator it = asignaturas->begin() ;
			it != asignaturas->end() ; it++) {
		i++;
		cout << "	Asignatura numero " << i << ":" << endl;
		cout << "		Nombre:" << (*it)->getNombre() << endl;
		cout << "		Codigo:" << (*it)->getCodigo() << endl;
		cout << "		Fecha de aprobacion:" << *((*it)->getFecha()) << endl;
		cout << "		Nota de aprobacion:" << (*it)->getNota() << endl;
	}
}

void printAplicaciones(set<DTAplicacion*> * aplicaciones) {
	short i = 0;
	if (not aplicaciones->empty()) cout << "Aplicaciones:" << endl;
	for (set<DTAplicacion*>::iterator it = aplicaciones->begin() ;
			it != aplicaciones->end() ; it++) {
		i++;
		cout << "	Aplicacion numero " << i << ":" << endl;
		cout << "		Titulo de la oferta: " << (*it)->getTituloOferta() << endl;
		cout << "		Numero de expediente: " << (*it)->getExpedienteOferta() << endl;
		cout << "		Empresa: " << (*it)->getEmpresa() << endl;
		cout << "		RUT de empresa: " << (*it)->getRutEmpresa() << endl;
		cout << "		Sucursal: " << (*it)->getSucursal() << endl;
		cout << "		Telefono de sucursal: " << (*it)->getTelefonoSuc() << endl;
		cout << "		Direccion de sucursal: " << (*it)->getDireccionSuc() << endl;
		cout << "		Seccion: " << (*it)->getSeccion() << endl;
		cout << "		Interno: " << (*it)->getInternoSeccion() << endl;
	}
}

void printCarreras(set<DTCarrera*> * carreras) {
	short i = 0;
	if (not carreras->empty()) {
		cout << "Carreras:" << endl;
		for (set<DTCarrera*>::iterator it = carreras->begin() ;
				it != carreras->end() ; it++) {
			i++;
			cout << "	Carrera numero " << i << ":" << endl;
			cout << "		Nombre: " << (*it)->getNombre() << endl;
			cout << "		Codigo: " << (*it)->getCodigo() << endl;
		};
	} else {
			cout << "No hay carreras que mostrar. \n";
	};
}

void printDataEstudiante(DataEstudiante * est){
	cout << "CI: " << est->getCedula() << endl;
	cout << "Nombre: " << est->getNombre() << endl;
	cout << "Apellido: " << est->getApellido() << endl;
	cout << "Creditos obtenidos: " << est->getCreditosObtenidos() << endl;
	cout << "Fecha de nacimiento: " << *(est->getFechaNac()) << endl;
	cout << "Telefono: " << est->getTelefono() << endl;
	printCarreras(est->getCarreras());
	printAsignaturasSalvadas(est->getAsignaturasSalvadas());
	printAplicaciones(est->getAplicaciones());
}

void printFullDTOferta(FullDTOferta * of){
	cout << endl << "Oferta: " << of->getTitulo() << endl;
	cout << "Numero de expediente: " << of->getNumeroDeExpediente() << endl;
	cout << "Publicada por: " << of->getEmpresa() << endl;
	cout << "Ubicacion: " << of->getUbicacionSucursal() << endl;
	cout << "Descripcion: " << of->getDescripcion() << endl;
	float min = of->getSueldoMin();
	float max = of->getSueldoMax();
	cout << "Carga horaria: " << of->getHorasSemanales() << " horas" << endl;
	cout << "Rango salarial: " << min << " - " << max << endl;
	cout << "Vigencia: " << *(of->getComienzoLlamado()) << " - " << *(of->getFinLlamado()) << endl;
	cout << "Puestos disponibles: " << of->getPuestosDisponibles() << endl;
	printAsignaturasRequeridas(of->getNumeroDeExpediente());
	cout << endl << "Actualmente hay " << of->getCantidadInscriptos() << " candidatos inscriptos a la Oferta" <<endl;
}

bool printAsignaturasNoRequeridas(int numExp) {
	ManejadorOfertaLaboral * mol = ManejadorOfertaLaboral::getInstance();
	OfertaLaboral * of = mol->getOfertaLaboral(numExp);
	set<string>* asignaturasRequeridas = of->getAsignaturasRequeridas();
	ManejadorBedelia * mb = ManejadorBedelia::getInstance();
	map<string, Asignatura*>* asignaturas = mb->getAsignaturas();
	short cantNoRequeridas = 0;
	for (map<string, Asignatura*>::iterator it1 = asignaturas->begin() ; it1 != asignaturas->end() ; it1++) {
		set<string>::iterator it2 = asignaturasRequeridas->begin();
		bool encontre = false;
		while (not encontre && it2 != asignaturasRequeridas->end()) {
			if ((*it2) == (*it1).second->getCodigo()) encontre = true;
			it2++;
		}
		if (not encontre) { //imprimo por ser asignatura no requerida
			cantNoRequeridas++;
			if (cantNoRequeridas == 1) cout << endl << "Asignaturas no requeridas por la oferta:" << endl;
			cout << "	Asignatura " << cantNoRequeridas << ":" << endl;
			cout << "		Nombre:" << (*it1).second->getNombre() << endl;
			cout << "		Codigo:" << (*it1).second->getCodigo() << endl;
		}
	}
	asignaturasRequeridas->clear();
	bool hayNoRequeridas = (cantNoRequeridas != 0);
	if (!hayNoRequeridas) cout << "Todas las Asignaturas del Sistema son requeridas por la Oferta Laboral. \n" << endl;
	return hayNoRequeridas;
}

bool printAsignaturasRequeridas(int numExp) {
	ManejadorOfertaLaboral * mol = ManejadorOfertaLaboral::getInstance();
	OfertaLaboral * of = mol->getOfertaLaboral(numExp);
	set<string>* asignaturasRequeridas = of->getAsignaturasRequeridas();
	ManejadorBedelia * mb = ManejadorBedelia::getInstance();
	map<string, Asignatura*>* asignaturas = mb->getAsignaturas();
	short cantRequeridas = 0;
	if (asignaturasRequeridas->empty()) {
		cout << endl << "La Oferta Laboral no tiene asignaturas requeridas. \n" << endl;
		asignaturasRequeridas->clear();
		return false;
	}	
	else {
		for (map<string, Asignatura*>::iterator it1 = asignaturas->begin() ; it1 != asignaturas->end() ; it1++) {
			set<string>::iterator it2 = asignaturasRequeridas->begin();
			bool encontre = false;
			while (not encontre && it2 != asignaturasRequeridas->end()) {
				if ((*it2) == (*it1).second->getCodigo()) encontre = true;
				it2++;
			}
			if (encontre) { //imprimo por ser asignatura requerida
				cantRequeridas++;
				cout << "	Asignatura " << cantRequeridas << ":" << endl;
				cout << "		Nombre:" << (*it1).second->getNombre() << endl;
				cout << "		Codigo:" << (*it1).second->getCodigo() << endl;
			}
		}
		asignaturasRequeridas->clear();
		return true;
	}	
}

void liberarMemoria() {
	ManejadorBedelia * mb = ManejadorBedelia::getInstance();
	mb->destroyInstance();
	ManejadorOfertaLaboral * mol = ManejadorOfertaLaboral::getInstance();
	mol->destroyInstance();
	FechaSistema * fecha = FechaSistema::getInstance();
	fecha->destroyInstance();
	CtrlOfertaLaboral * ctrlOL = CtrlOfertaLaboral::getInstance();
	ctrlOL->destroyInstance();
	Fabrica * f = Fabrica::getInstance();
	f->destroyInstance();
}
