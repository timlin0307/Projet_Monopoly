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
	Compagnie();
	void arreterSur(Joueur*, int);
	void calcul_loyer(int de);
	Joueur * getJoueur();
	void setJoueur(Joueur *);

	void ajout_hypotheque(Joueur *);
	void enleve_hypotheque(Joueur *);

	void supprime(Joueur);


};



#endif /* COMPAGNIE_H_ */
