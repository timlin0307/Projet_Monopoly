/*
 * Arrestation.cpp
 *
 *  Created on: 15 janv. 2022
 *      Author: lucas
 */

#include "Case.h"
#include <iostream>
#include <string>
using namespace std;
#include "Arrestation.h"

Arrestation  :: Arrestation (string nomcase)
: Case(nomcase)
{
}

void Arrestation :: arreterSur(Joueur * j, int de)
{

	(*j).set200(false);
	(*j).setPrison(3);
	Case* from = (*j).getCase();
	Case* landing = (*from).deplacement(j, 21);
	cout <<"Vous êtes maintenant en prison " << (*landing).getNom() << endl;
	cout << "Vous allez devoir attendre 3 tours ou payer " << endl;
}




