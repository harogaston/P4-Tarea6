/*
 * IObserver.h
 *
 *  Created on: Jun 2, 2015
 *      Author: marccio
 */

#ifndef IOBSERVER_H_
#define IOBSERVER_H_

class IObserver {
	virtual ~IObserver();
	virtual void notificar() = 0;
};

#endif /* IOBSERVER_H_ */
