/*
 * Date.cpp
 *
 *  Created on: Jun 1, 2015
 *      Author: marccio
 */

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
