/*
 * gobelet.h
 *
 *  Created on: 17 déc. 2021
 *      Author: basti
 */
#include "de.h"
#include <iostream>
#include <random>
#include <ctime>

#ifndef GOBELET_H_
#define GOBELET_H_
class gobelet : public de {
private :
	de des[2];
public :
	gobelet();
	int getValeur();
	bool Double();
};




#endif /* GOBELET_H_ */
