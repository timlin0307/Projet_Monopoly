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
#include "Plateau.h"
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
		bool touche_200;
		int tour_prison; /* -1 s'il n'est pas en prison ou juste en visite,
							sinon affiche le nombre de tour qui lui reste à faire avant
							d'être obliger de payer pour sortir */

	public:
		Joueur(int pn, int sol, string n, int nbg, int nbc);
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
		void set200(bool);
		bool get200();
		void setPrison(int);
		int getPrison();
		void initCase(Plateau*);
};


#endif /* JOUEUR_H_ */
