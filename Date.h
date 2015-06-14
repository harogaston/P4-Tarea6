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
