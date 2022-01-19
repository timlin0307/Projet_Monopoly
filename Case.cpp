/*
 * Case.cpp
 *
 *  Created on: 22 déc. 2021
 *      Author: neyre
 */

#include "Case.h"
#include "Joueur.h"
#include "Plateau.h"
#include <iostream>
using namespace std;

Case::Case(string nom) {
	this->nom = nom;
	this->suivante = nullptr;
	this->numCase = 0;
}

string Case::getNom() {
	return nom;
}
	
Case* Case::getSuivante() {
	return suivante;
}

void Case::setNom(string nom) {
	this->nom = nom;
}
	
void Case::setSuivante(Case* suivante) {
	this->suivante = suivante;
}

void Case::affiche() {
	cout << nom << endl;
}

void Case::arreterSur(Joueur* j, int de) {
	cout << "Fonction virtuelle générique" << endl;
}

Case* Case::deplacement(Joueur* j, int de) {
	Case* casesuivante = suivante ;
	Case* casecourante = casesuivante ;
	for (int i=0; i<de; i++) {
		casecourante = casesuivante;

		if (((*casecourante).getNum() == 0) & ((*j).get200() == true))
		{
			(*j).crediter(200);
		}

		casesuivante = casecourante->getSuivante() ;
	}
	cout << "Vous êtes arrivé(e) sur la case : " << casecourante->getNom() << endl;
	return casecourante;
}

void Case::setNum(int num) {
	numCase = num;
}

int Case::getNum() {
	return numCase;
}

