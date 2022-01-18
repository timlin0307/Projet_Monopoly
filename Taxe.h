/*
 * Taxe.h
 *
 *  Created on: 15 janv. 2022
 *      Author: lucas
 */

#ifndef TAXE_H_
#define TAXE_H_

#include "Case.h"
#include <iostream>
#include <string>
using namespace std;

class Taxe : public Case {
    protected:
	int prix_a_payer;

    public:
	Taxe (string nom, int prix);
	void arreterSur(Joueur * , int );
};

#endif /* TAXE_H_ */
