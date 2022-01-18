/*
 * Plateau.cpp
 *
 *  Created on: 22 déc. 2021
 *      Author: neyre
 */

#include "Case.h"
#include "Plateau.h"
#include "Gare.h"
#include "Terrain.h"
#include "Compagnie.h"
#include "Chance.h"
#include "Communaute.h"
#include "Propriete.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

void Plateau::ajouterCase(string nom, int i) {
	
	string sep = "-";
	vector<string> words{};
	size_t pos;
	while ((pos = nom.find(sep)) != string::npos) {// tant qu'on trouve un caractère séparateur
		words.push_back(nom.substr(0, pos));		// comme un append
		nom.erase(0, pos + sep.length());			// on supprime ce qui a déjà été examiné
	}
	
	string type = words[0];
	
	if (type=="TERRAIN") {
		Case* premiere = new Case(nom);
		(*premiere).setNum(i);
		premiere->setSuivante(this->tete);
		this->tete = premiere;
	}
	else if (type=="GARE") {
		Case* premiere = new Gare(nom, 50, 50, "", 25);
		(*premiere).setNum(i);
		premiere->setSuivante(this->tete);
		this->tete = premiere;
	}
	else if (type=="COMPAGNIE") {
		Case* premiere = new Compagnie(nom, 50, 50, "", 25);
		(*premiere).setNum(i);
		premiere->setSuivante(this->tete);
		this->tete = premiere;
	}
	else if (type=="CHANCE") {
		Case* premiere = new Chance(nom, "chance.txt");
		(*premiere).setNum(i);
		premiere->setSuivante(this->tete);
		this->tete = premiere;
	}
	else if (type=="COMMUNAUTE") {
		Case* premiere = new Communaute(nom, "communaute.txt");
		(*premiere).setNum(i);
		premiere->setSuivante(this->tete);
		this->tete = premiere;
	}
	else if (type=="PRISON") {
		Case* premiere = new Case(nom);
		(*premiere).setNum(i);
		premiere->setSuivante(this->tete);
		this->tete = premiere;
	}
	else if (type=="TAXE") {
		Case* premiere = new Case(nom);
		(*premiere).setNum(i);
		premiere->setSuivante(this->tete);
		this->tete = premiere;
	}
	else if (type=="GRATUIT") {
		Case* premiere = new Case(nom);
		premiere->setSuivante(this->tete);
		this->tete = premiere;
	}
	else {
		Case* premiere = new Case(nom);
		(*premiere).setNum(i);
		premiere->setSuivante(this->tete);
		this->tete = premiere;
	}
	
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
	for (int i=0; i<40; i++) {
		Plateau::ajouterCase(tab[i], 39-i);
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

Case* Plateau::getCase(int i) {
	Case* courante = tete->getSuivante();
	for (int j=0; j<i-1; j++) {
		courante = courante->getSuivante();
	}
	return courante;
}

