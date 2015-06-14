#============================================================================
#Programación 4 - Laboratorio 6 - Año 2015
#
# Profesor: Pablo Milanese
# Grupo: 17
# Integrantes: Juan Pablo Copello - jpcopel@gmail.com
#			   Gastón Haro - harogaston@gmail.com
#			   Sofía Honty - sofisho@gmail.com
#			   Marccio Silva - marcciosilva@gmail.com
#
# Archivo: makefile
#============================================================================

PARAMETROS = -Wall -Wextra

all: Lab6

Aplica.o: Aplica.h Aplica.cpp DTAplicacion.h DTEstudiante.h Entrevista.h
	g++ -c Aplica.cpp $(PARAMETROS)
	
Asignatura.o: Asignatura.h Asignatura.cpp DTAsignaturaSalvada.h OfertaLaboral.h Salva.h
	g++ -c Asignatura.cpp $(PARAMETROS)
	
Carrera.o: Carrera.h Carrera.cpp Asignatura.h DTCarrera.h
	g++ -c Carrera.cpp $(PARAMETROS)

DataEstudiante.o: DataEstudiante.h DataEstudiante.cpp DTAplicacion.h DTAsignaturaSalvada.h DTCarrera.h
	g++ -c DataEstudiante.cpp $(PARAMETROS)
	
DataOferta.o: DataOferta.h DataOferta.cpp Date.h DTAsignatura.h
	g++ -c DataOferta.cpp $(PARAMETROS)
	
DataOfertaRestringida.o: DataOfertaRestringida.h DataOfertaRestringida.cpp
	g++ -c DataOfertaRestringida.cpp $(PARAMETROS)

Date.o: Date.h Date.cpp
	g++ -c Date.cpp $(PARAMETROS)
	
DTAplicacion.o: DTAplicacion.h DTAplicacion.cpp
	g++ -c DTAplicacion.cpp $(PARAMETROS)

DTAsignatura.o: DTAsignatura.h DTAsignatura.cpp
	g++ -c DTAsignatura.cpp $(PARAMETROS)
	
DTAsignaturaSalvada.o: DTAsignaturaSalvada.h DTAsignaturaSalvada.cpp Date.h
	g++ -c DTAsignaturaSalvada.cpp $(PARAMETROS)

DTCarrera.o: DTCarrera.h DTCarrera.cpp
	g++ -c DTCarrera.cpp $(PARAMETROS)
	
DTEmpresa.o: DTEmpresa.h DTEmpresa.cpp
	g++ -c DTEmpresa.cpp $(PARAMETROS)
	
DTEstudiante.o: DTEstudiante.h DTEstudiante.cpp Date.h
	g++ -c DTEstudiante.cpp $(PARAMETROS)
	
DTOferta.o: DTOferta.h DTOferta.cpp Date.h
	g++ -c DTOferta.cpp $(PARAMETROS)

DTSeccion.o: DTSeccion.h DTSeccion.cpp
	g++ -c DTSeccion.cpp $(PARAMETROS)
	
DTSucursal.o: DTSucursal.h DTSucursal.cpp
	g++ -c DTSucursal.cpp $(PARAMETROS)
	
Empresa.o: Empresa.h Empresa.cpp DTEmpresa.h DTSeccion.h DTSucursal.h Sucursal.h
	g++ -c Empresa.cpp $(PARAMETROS)
	
Entrevista.o: Entrevista.h Entrevista.cpp Date.h
	g++ -c Entrevista.cpp $(PARAMETROS)
	
Estudiante.o: Estudiante.h Estudiante.cpp Aplica.h Carrera.h DataEstudiante.h DTEstudiante.h IObserver.h Notificacion.h Salva.h
	g++ -c Estudiante.cpp $(PARAMETROS)

FechaSistema.o: FechaSistema.h FechaSistema.cpp Date.h
	g++ -c FechaSistema.cpp $(PARAMETROS)
	
FirmaContrato.o: FirmaContrato.h FirmaContrato.cpp Estudiante.h OfertaLaboral.h
	g++ -c FirmaContrato.cpp $(PARAMETROS)
	
FullDTOferta.o: FullDTOferta.h FullDTOferta.cpp Date.h
	g++ -c FullDTOferta.cpp $(PARAMETROS)
	
ManejadorBedelia.o: ManejadorBedelia.h ManejadorBedelia.cpp Asignatura.h Carrera.h DataEstudiante.h Date.h DTEstudiante.h Estudiante.h FullDTOferta.h
	g++ -c ManejadorBedelia.cpp $(PARAMETROS)
	
ManejadorOfertaLaboral.o: ManejadorOfertaLaboral.h ManejadorOfertaLaboral.cpp Aplica.h Asignatura.h DataOfertaRestringida.h Date.h DTAplicacion.h DTEstudiante.h DTOferta.h FirmaContrato.h FullDTOferta.h OfertaLaboral.h
	g++ -c ManejadorOfertaLaboral.cpp $(PARAMETROS)

Notificacion.o: Notificacion.h Notificacion.cpp FullDTOferta.h OfertaLaboral.h
	g++ -c Notificacion.cpp $(PARAMETROS)
	
OfertaLaboral.o: OfertaLaboral.h OfertaLaboral.cpp Aplica.h DataOfertaRestringida.h Date.h DTAplicacion.h DTOferta.h FirmaContrato.h FullDTOferta.h
	g++ -c OfertaLaboral.cpp $(PARAMETROS)

Salva.o: Salva.h Salva.cpp
	g++ -c Salva.cpp $(PARAMETROS)
	
Seccion.o: Seccion.h Seccion.cpp DataOferta.h OfertaLaboral.h Sucursal.h
	g++ -c Seccion.cpp $(PARAMETROS)
	
Sucursal.o: Sucursal.h Sucursal.cpp DataOferta.h DTSeccion.h DTSucursal.h OfertaLaboral.h
	g++ -c Sucursal.cpp $(PARAMETROS)

	
main.o: main.cpp ControladorOfertaLaboral.h DataEstudiante.h DataOferta.h Date.h DTAplicacion.h DTAsignaturaSalvada.h DTCarrera.h DTEmpresa.h ManejadorEstudiantes.h ManejadorOfertasActivas.h ManejadorOfertasLaborales.h
	g++ -c main.cpp $(PARAMETROS)

	
Lab6: Aplica.o Asignatura.o Carrera.o DataEstudiante.o DataOferta.o DataOfertaRestringida.o Date.o DTAplicacion.o DTAsignatura.o DTAsignaturaSalvada.o DTCarrera.o DTEmpresa.o DTEstudiante.o DTOferta.o DTSeccion.o DTSucursal.o Empresa.o Entrevista.o Estudiante.o FechaSistema.o FirmaContrato.o FullDTOferta.o ManejadorBedelia.o ManejadorOfertaLaboral.o Notificacion.o OfertaLaboral.o Salva.o Seccion.o Sucursal.o main.o
	g++ Aplica.o Asignatura.o Carrera.o DataEstudiante.o DataOferta.o DataOfertaRestringida.o Date.o DTAplicacion.o DTAsignatura.o DTAsignaturaSalvada.o DTCarrera.o DTEmpresa.o DTEstudiante.o DTOferta.o DTSeccion.o DTSucursal.o Empresa.o Entrevista.o Estudiante.o FechaSistema.o FirmaContrato.o FullDTOferta.o ManejadorBedelia.o ManejadorOfertaLaboral.o Notificacion.o OfertaLaboral.o Salva.o Seccion.o Sucursal.o -o Lab6

	
clean:
	rm -f Date.o
	rm -f DtGolosina.o
	rm -f DtAlfajor.o
	rm -f DtCaramelo.o
	rm -f Golosina.o
	rm -f Alfajor.o
	rm -f Caramelo.o
	rm -f Fabricante.o
	rm -f Main.o
	rm -f Lab1
	
	
 