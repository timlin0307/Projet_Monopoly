/*
 * joueur.h
 *
 *  Created on: 2021/12/17
 *      Author: Yen-Ting Lin
 */

#ifndef JOUEUR_H_
#define JOUEUR_H_

#include <iostream>
#include <string>
#include "pion.h"
using namespace std;

class joueur {
	protected:
		pion Pion;
		int solde;
		string nom;
	public:
		joueur(pion pi, int sol, string n);
		void operation();
		string getNom();
		joueur getPion();
		int getSolde();
		void setPion();
		void setSolde(int sol);
		void jouer();
		void crediter();
		void debiter();
};

#endif /* JOUEUR_H_ */
