/*
 * pion.h
 *
 *  Created on: 2021/12/17
 *      Author: Yen-Ting Lin
 */

#ifndef PION_H_
#define PION_H_

#include <iostream>
#include <string>
#include "joueur.h"
#include "Case.h"
using namespace std;

class pion {
	protected:
		joueur* Joueur;
		Case* Position;
		string nom;
	public:
		pion(joueur* j, Case* p, string n);
		joueur* getJoueur();
		Case* getPosition();
		string getNom();
		void setJoueur(joueur* j);
		void setPosition(int p);
		void setNom(string n);
		void setPion();
		void deplacer();
};

#endif /* PION_H_ */
