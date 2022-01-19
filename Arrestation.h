/*
 * Arrestation.h
 *
 *  Created on: 15 janv. 2022
 *      Author: lucas
 */

#ifndef ARRESTATION_H_
#define ARRESTATION_H_

#include "Case.h"
#include <iostream>
#include <string>
using namespace std;

class Arrestation : public Case {
protected:
	int num_prison;

public:
	Arrestation (string nom, int num);
	void arreterSur(Joueur * , int );
};




#endif /* ARRESTATION_H_ */
