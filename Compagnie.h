/*
 * Compagnie.h
 *
 *  Created on: 18 déc. 2021
 *      Author: lucas
 */

#ifndef COMPAGNIE_H_
#define COMPAGNIE_H_

#include <iostream>
#include <string>
using namespace std;
#include "Propriete.h"
#include "Case.h"
#include "Joueur.h"


class Compagnie : public Propriete
{
protected :
	Joueur * appartient_a;

public :
	Compagnie(string nomcase, int loyer, int prixachat, string nomjoueur, int valhypo, Joueur* appartient_a= nullptr, bool hypotheque = false);
	void arreterSur(Joueur*, int);
	void calcul_loyer(int de);
	Joueur * getJoueur();
	void setJoueur(Joueur *);


};



#endif /* COMPAGNIE_H_ */
