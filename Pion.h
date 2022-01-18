/*
 * Pion.h
 *
 *  Created on: 2021/12/17
 *      Author: Yen-Ting Lin
 */

#ifndef PION_H_
#define PION_H_

#include <iostream>
#include <string>
#include "Joueur.h"
#include "Case.h"
using namespace std;

class Pion {
	protected:
		Joueur* joueur;
		Case* Position;
		string nom;
	public:
		pion(Joueur* j, Case* p, string n);
		Joueur* getJoueur();
		Case* getPosition();
		string getNom();
		void setJoueur(Joueur* j);
		void setPosition(Case* p);
		void setNom(string n);
		void setPion();
		void deplacer();
};

#endif /* PION_H_ */
