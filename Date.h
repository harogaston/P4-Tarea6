/*
 * Date.h
 *
 *  Created on: Jun 1, 2015
 *      Author: marccio
 */

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
	virtual ~Date();
	int getAaaa();
	int getDd();
	int getMm();
};

#endif /* DATE_H_ */
