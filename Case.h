/*
 * Case.h
 *
 *  Created on: 22 déc. 2021
 *      Author: neyre
 */

#ifndef CASE_H_
#define CASE_H_
#include "joueur.h"
#include <iostream>
using namespace std;

class Case {
protected:
	string nom;
	Case* suivante;
public:
	Case(string);
	virtual void arreterSur(joueur*, int);
	string getNom();
	Case* getSuivante();
	void setNom(string);
	void setSuivante(Case*);
	void affiche();
	Case* deplacement(joueur*, int);
};





#endif /* CASE_H_ */
