/*
 * Case.h
 *
 *  Created on: 22 déc. 2021
 *      Author: neyre
 */

#ifndef CASE_H_
#define CASE_H_
#include "Joueur.h"
#include <iostream>
using namespace std;

class Case {
protected:
	string nom;
	Case* suivante;
	int numCase;
public:
	Case(string);
	Case();
	virtual void arreterSur(Joueur*, int) ;
	string getNom();
	Case* getSuivante();
	void setNom(string);
	void setSuivante(Case*);
	void affiche();
	Case* deplacement(Joueur*, int);
	void setNum(int);
	int getNum();

	void hypothequer (Joueur *, Plateau *);
	void deshypothequer (Joueur *, Plateau *);
	void revendre_maison (Joueur *, Plateau *);
	void acheter_maison (Joueur *, Plateau *);
};





#endif /* CASE_H_ */
