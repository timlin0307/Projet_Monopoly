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


using namespace std;

class joueur {
private:
	int pionNum = 0;
	int solde;
	string nom;
public:
	joueur(int pn, int sol, string n);
	void operation();
	string getNom();
	int getPion();
	int getSolde();
	void setPion(int);
	void setSolde(int sol);
	void jouer();
	void crediter(int);
	void debiter(int);
	void afficheNom();
};

#endif /* JOUEUR_H_ */
