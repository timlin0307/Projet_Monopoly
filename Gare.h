/*
 * Gare.h
 *
 *  Created on: 18 déc. 2021
 *      Author: lucas
 */

#ifndef GARE_H_
#define GARE_H_

#include <iostream>
#include <string>
using namespace std;
#include "Propriete.h"

/* herite de propriete
 * protected : nom de la case
 *
 * public : getNom
 * setNom
 *
 */

class Gare : public Propriete
{
protected :
	/* rien à mettre on herite de propriete */

public :
	Gare(string nomcase, int loyer, int prixachat, string nomjoueur, int valhypo, bool hypotheque = false);
	void arreterSur(int);
	void calcul_loyer();


};




#endif /* GARE_H_ */
