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
CC=g++
FLAGS=-c -std=c++11 -Wall -Werror
SOURCES=Aplica.cpp Asignatura.cpp Carrera.cpp CtrlEstudiante.cpp CtrlOfertaActiva.cpp CtrlOfertaLaboral.cpp DataEstudiante.cpp DataOferta.cpp DataOfertaRestringida.cpp Date.cpp DTAplicacion.cpp DTAsignatura.cpp DTAsignaturaSalvada.cpp DTCarrera.cpp DTEmpresa.cpp DTEstudiante.cpp DTOferta.cpp DTSeccion.cpp DTSucursal.cpp Empresa.cpp Entrevista.cpp EstrategiaDos.cpp EstrategiaUno.cpp Estudiante.cpp Fabrica.cpp FechaSistema.cpp FirmaContrato.cpp FullDTOferta.cpp main.cpp ManejadorBedelia.cpp ManejadorOfertaLaboral.cpp Notificacion.cpp OfertaLaboral.cpp Salva.cpp Seccion.cpp Sucursal.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=main

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(FLAGS) $< -o $@

clean:
	rm -f $(OBJECTS)
	rm -f main
