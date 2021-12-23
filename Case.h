/*
 * Case.h
 *
 *  Created on: 22 déc. 2021
 *      Author: neyre
 */

#ifndef CASE_H_
#define CASE_H_
#include <iostream>
using namespace std;

class Case {
private:
	string nom;
	Case* suivante;
public:
	Case(string);
	void arreterSur();
	string getNom();
	Case* getSuivante();
	void setNom(string);
	void setSuivante(Case*);
	void affiche();
};





#endif /* CASE_H_ */
