/*
 * Gratuit.cpp
 *
 *  Created on: 24 janv. 2022
 *      Author: neyre
 */

#include "Gratuit.h"

Gratuit::Gratuit(string nom):Case(nom) {
	
}

void Gratuit::arreterSur(Joueur* j, int de) {
	cout << "Vous ne payez rien. Ouf !" << endl;
}