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

class Case;

class Joueur {
	protected:
		int pionNum = 0;
		int solde;
		string nom;
		int nb_gare;
		int nb_comp;
		Case* courante;
	public:
		Joueur(int pn, int sol, string n, int nbg=0, int nbc=0);
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
		void afficheNom();
		Case* getCase();
		void setCase(Case*);
};


#endif /* JOUEUR_H_ */
