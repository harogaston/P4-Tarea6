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
 * Archivo: Date.cpp
 *******************************************************************************/

#include "Date.h"

#include <ctime>

Date::Date()
	{
		time_t rawtime;
		struct tm *fecha_actual;
		time (&rawtime);
		fecha_actual=localtime (&rawtime);
		this->aaaa=fecha_actual->tm_year+1900;
		this->mm=fecha_actual->tm_mon+1;
		this->dd=fecha_actual->tm_mday;
	};

Date::Date(int dd, int mm, int aaaa) {
	this->dd = dd;
	this->mm = mm;
	this->aaaa = aaaa;
}

bool  Date::operator == (Date derecha) {
	return (this->dd == derecha.dd && this->mm == derecha.mm && this->aaaa== derecha.aaaa);
};

bool Date::operator != (Date derecha){
	return (this->dd != derecha.dd || this->mm != derecha.mm || this->aaaa!= derecha.aaaa);
};

bool Date::operator < (Date derecha) {
	return ((this->aaaa<derecha.aaaa)||((this->aaaa==derecha.aaaa)&&(this->mm<derecha.mm))
	||((this->aaaa==derecha.aaaa)&&(this->mm==derecha.mm)&&(this->dd<derecha.dd)));
};

bool Date::operator > (Date derecha) {
	return ((this->aaaa>derecha.aaaa)||((this->aaaa==derecha.aaaa)&&(this->mm>derecha.mm))
	||((this->aaaa==derecha.aaaa)&&(this->mm==derecha.mm)&&(this->dd>derecha.dd)));
};

bool Date::operator <= (Date derecha){
	return ((this->aaaa<derecha.aaaa)||((this->aaaa==derecha.aaaa)&&(this->mm<derecha.mm))
	||((this->aaaa==derecha.aaaa)&&(this->mm==derecha.mm)&&(this->dd<=derecha.dd)));
};

bool Date::operator >= (Date derecha) {
	return ((this->aaaa>derecha.aaaa)||((this->aaaa==derecha.aaaa)&&(this->mm>derecha.mm))
	||((this->aaaa==derecha.aaaa)&&(this->mm==derecha.mm)&&(this->dd>=derecha.dd)));
};

ostream & operator << (ostream &o, Date d){
	o<<d.aaaa<<'/';
	d.mm<10? o<<'0'<<d.mm : o<<d.mm;
	o<<'/';
	d.dd<10? o<<'0'<<d.dd : o<<d.dd;
	o<<' ';
	return o;
}

Date::~Date() {
}

int Date::getAaaa(){
	return aaaa;
}

int Date::getDd(){
	return dd;
}

int Date::getMm(){
	return mm;
}
