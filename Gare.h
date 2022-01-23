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



class Gare : public Propriete
{
protected :
	Joueur * appartient_a;

public :
	Gare(string nomcase, int loyer, int prixachat, string nomjoueur, int valhypo,Joueur* appartient_a= nullptr, bool hypotheque = false);
	void arreterSur(Joueur* , int);
	void calcul_loyer();
	Joueur * getJoueur();
	void setJoueur(Joueur *);

};




#endif /* GARE_H_ */
