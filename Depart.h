/*
 * Depart.h
 *
 *  Created on: 15 janv. 2022
 *      Author: lucas
 */

#ifndef DEPART_H_
#define DEPART_H_

#include "Case.h"
#include <iostream>
#include <string>
using namespace std;

class Depart : public Case {
    protected:
	int gain;

    public:
	Depart (string nom, int prix);
	void arreterSur(Joueur * , int );
};



#endif /* DEPART_H_ */
