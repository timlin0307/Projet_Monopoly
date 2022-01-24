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
#include <typeinfo>

#include "Terrain.h"

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



void Case :: hypothequer (Joueur * j, Plateau *p)
{

	Terrain ter_test = Terrain();
	int encore = 1;
	cout << typeid(*(*p).getCase(1)).name() << endl;
	while (encore)
	{
		for (int i=1; i<40; i++ )
		{
			if (typeid(*(*p).getCase(i)) == typeid(ter_test) )
			{
				Case* ter =(*p).getCase(i);
				((Terrain*)ter)->ajout_hypotheque(j);
				cout << "votre solde est de " << j->getSolde() << endl;
			}

			if (typeid(*(*p).getCase(i)) == typeid(ter_test) )
			{
				Case* ter =(*p).getCase(i);
				((Terrain*)ter)->ajout_hypotheque(j);
				cout << "votre solde est de " << j->getSolde() << endl;
			}



		}
		cout << "voulez revoir vos cases pour voir celles que vous voulez hypothequer si oui tapez 1 sinon tapez 0 " << endl;

		cin >> encore ;
	}
}


Case::Case()
{
	this->nom = "test";
	this->suivante = nullptr;
	this->numCase = 0;
}
