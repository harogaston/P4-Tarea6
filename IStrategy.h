/*
 * IStrategy.h
 *
 *  Created on: Jun 2, 2015
 *      Author: marccio
 */

#ifndef ISTRATEGY_H_
#define ISTRATEGY_H_

class IStrategy {
public:
	virtual ~IStrategy();
	virtual void actualizarRequerimientos() = 0;
};

#endif /* ISTRATEGY_H_ */
