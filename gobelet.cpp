/*
 * gobelet.cpp
 *
 *  Created on: 30 déc. 2021
 *      Author: basti
 */

#include "gobelet.h"

gobelet::gobelet():de(){
	std::srand(std::time(nullptr));
	de de1;
	de de2;
	des[0]= de1;
	des[1]= de2;
}

bool gobelet::Double() {
	return des[0].getValeur()==des[1].getValeur();
}

int gobelet::getValeur(){
	return des[0].getValeur()+des[1].getValeur();
}
