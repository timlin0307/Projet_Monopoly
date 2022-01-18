/*
 * Gobelet.h
 *
 *  Created on: 17 déc. 2021
 *      Author: basti
 */
#include "De.h"
#include <iostream>
#include <random>
#include <ctime>

#ifndef GOBELET_H_
#define GOBELET_H_
class Gobelet : public De {
    protected:
	De des[2];
    public:
	Gobelet();
	int getValeur();
	bool Double();
};




#endif /* GOBELET_H_ */
