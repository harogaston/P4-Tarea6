#ifndef ICTRLOFERTAACTIVA_H_
#define ICTRLOFERTAACTIVA_H_

class ICtrlOfertaActiva {
public:
	virtual ~ICtrlOfertaActiva() {};

	virtual set<FullDTOferta> listarOfertasActivas() = 0;
	virtual bool seleccionarOfertaActiva(int) = 0;
	virtual set<DTEstudiante> listarNoInscriptos() = 0;
	virtual bool seleccionarEstudiante(string) = 0;
	virtual void inscribirEstudiante() = 0;
	virtual void ingresarDatosOferta(DataOfertaRestringida) = 0;
	virtual bool seleccionarAsignatura(bool, string) = 0;
	virtual void agregarAsignaturaRequerida() = 0;
	virtual void quitarAsignaturaRequerida() = 0;
};

#endif /* ICTRLOFERTAACTIVA_H_ */
