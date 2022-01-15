/*
 * Plateau.cpp
 *
 *  Created on: 22 déc. 2021
 *      Author: neyre
 */

#include "Case.h"
#include "Plateau.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

void Plateau::ajouterCase(string nom) {
	Case* premiere = new Case(nom);
	premiere->setSuivante(tete);
    tete = premiere;
}

string* Plateau::lecture() {
    string* tab = new string[40];
    ifstream monFlux("cases.txt");
    string* res = nullptr;
    if(monFlux) {
    	int i = 0;
     	string ligne;
    	while (getline(monFlux,ligne)) {
         	tab[39-i] = ligne;   
    		i++;
    	}
    	res = tab;
    }
    monFlux.close();
    return res;
}

Plateau::Plateau() {
	tete = nullptr;
	string* tab = Plateau::lecture();
	Case* premiere = new Case(tab[0]);
	premiere->setSuivante(tete);
	tete = premiere;
	for (int i=1; i<40; i++) {
		Plateau::ajouterCase(tab[i]);
	}
	premiere->setSuivante(tete);
}

void Plateau::affiche() {
	Case* courante = tete;
	for (int i=0; i<40; i++) {
		courante->affiche();
		courante = courante->getSuivante();
	}
}

Case Plateau::getCase(int i) {
	Case courante = *((*tete).getSuivante());
	for (int j=0; j<i-1; j++) {
		courante = *courante.getSuivante();
	}
	return courante;
}
