/*
 * Joueur.h
 *
 *  Created on: 15 janv. 2022
 *      Author: Yen-Ting Lin, lucas
 */

#ifndef JOUEUR_H_
#define JOUEUR_H_

#include <iostream>
#include <string>
using namespace std;

class Joueur {
	protected:
		int pionNum = 0;
		int solde;
		string nom;
		int nb_gare;
		int nb_comp;
	public:
		Joueur(int pn, int sol, string n);
		void operation();
		string getNom();
		int getPion();
		int getSolde();
		int getNbGare();
		int getNbCompagnie();
		void setPion(int);
		void setSolde(int sol);
		void setNbGare(int nbGare);
		void setNbCompagnie(int nbComp);
		void jouer();
		void crediter(int);
		void debiter(int);
};


#endif /* JOUEUR_H_ */
