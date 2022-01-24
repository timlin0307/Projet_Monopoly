/*
 * Gratuit.h
 *
 *  Created on: 24 janv. 2022
 *      Author: neyre
 */

#ifndef GRATUIT_H_
#define GRATUIT_H_

#include "Case.h"
#include "Joueur.h"

class Gratuit:public Case {
public:
	Gratuit(string);
	void arreterSur(Joueur*, int);
};

#endif /* GRATUIT_H_ */
