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
 * Archivo: Date.h
 *******************************************************************************/

#ifndef DATE_H_
#define DATE_H_

class Date {
private:
	int dd;
	int mm;
	int aaaa;

public:
	Date();
	Date(int dd, int mm, int aaaa);
	~Date();

	bool operator == (Date);
	bool operator != (Date);
	bool operator < (Date);
	bool operator > (Date);
	bool operator <= (Date);
	bool operator >= (Date);

	int getDd();
	int getMm();
	int getAaaa();
};

#endif /* DATE_H_ */
