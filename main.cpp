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

#include "DataEstudiante.h"
#include "Date.h"
#include "DTAplicacion.h"
#include "DTAsignaturaSalvada.h"
#include "DTCarrera.h"
#include "DTEmpresa.h"

using namespace std;


int main()
{
    //*************************************************Declaracion de variables** *****************************************************
    int comando, RUT;
    string int_aux;
    //*************************************************Inicializacion del sistema *****************************************************

    Fabrica *f=Fabrica::getInstance();
    ICtrlOfertasLaborales* ctrlOL= f -> getICtrlOfertasLaborales();
    ICtrlOfertasActivas* ctrlOA = f -> getICtrlOfertasActivas();
	ICtrlEstudiantes* ctrlE = f -> getICtrlEstudiantes();
	Date Fecha_Actual = Date();
	
	
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
						cout<<"El RUT ingresado no corresponde a una Empresa registrada en el Sistema.\n"
						cout<<"Ingrese un RUT valido a continuacion y presione [ENTER] O ingrese 0 si desea salir del Caso de Uso.\n"
						cout<<">";
						getline(cin, int_aux);
						stringstream(int_aux) >> RUT;
						if(RUT==0) 
							break;
						else
							okEmpresa = ctrlOL->seleccionarEmpresa(RUT);
					}
				//listarSucursales
					set<DTSucursal*> Sucs = ctrlOL->listarSucursales(RUT);
					set<DTSucursal*>::iterator it;
					if(!Sucs.empty()) {
						cout<<"Sucursales:"<<endl;
						for(it=Sucs.begin() ; it!=Sucs.end() ; it++) {
							DTSucursal* Sucs = *it;
							cout<<"**Nombre: "<<Sucs->getNombre() <<" -Telefono: "<<Sucs->getTelefono() <<" -Direccion: "<<Sucs->getDireccion()<<endl;
						};
					else {
						cout<<"No existen Sucursales para esa Empresa. \n";
						throw 2;
					};
				//seleccionarSucursal	
					break;
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