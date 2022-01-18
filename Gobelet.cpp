/*
 * Gobelet.cpp
 *
 *  Created on: 30 déc. 2021
 *      Author: basti
 */

#include "Gobelet.h"

Gobelet::Gobelet():De() {
	std::srand(std::time(nullptr));
	De de1;
	De de2;
	des[0] = de1;
	des[1] = de2;
}

bool Gobelet::Double() {
	return des[0].getValeur()==des[1].getValeur();
}

int Gobelet::getValeur(){
	return des[0].getValeur()+des[1].getValeur();
}
