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
/* herite de propriete
 * protected : nom de la case
 *
 * public : getNom
 * setNom
 *
 */

class Compagnie : public Propriete
{
protected :
	joueur * appartient_a;

public :
	Compagnie(string nomcase, int loyer, int prixachat, string nomjoueur, int valhypo, joueur* appartient_a= nullptr, bool hypotheque = false);
	void arreterSur(joueur*, int);
	void calcul_loyer(int de);


};



#endif /* COMPAGNIE_H_ */
