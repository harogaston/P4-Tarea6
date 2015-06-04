/*
 * Date.cpp
 *
 *  Created on: Jun 1, 2015
 *      Author: marccio
 */

#include "Date.h"

Date::Date() {
	dd = 1;
	mm = 1;
	aaaa = 1990;
}

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
