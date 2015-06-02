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
