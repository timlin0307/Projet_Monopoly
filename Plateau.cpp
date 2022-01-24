/*
 * Plateau.cpp
 *
 *  Created on: 22 déc. 2021
 *      Author: neyre
 */

#include "Plateau.h"
#include "Gare.h"
#include "Terrain.h"
#include "Compagnie.h"
#include "Chance.h"
#include "Communaute.h"
#include "Propriete.h"
#include "Arrestation.h"
#include "Prison.h"
#include "Depart.h"
#include "Taxe.h"
#include "Gratuit.h"
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
		//Case* premiere = new Case(nom);
		int prixAchat = stoi(words[1]);
		string couleur = words[2];
		int* loyers = new int[5];
		loyers[0] = stoi(words[3]);
		loyers[1] = stoi(words[4]);
		loyers[2] = stoi(words[5]);
		loyers[3] = stoi(words[6]);
		loyers[4] = stoi(words[7]);
		int prixMaison = stoi(words[8]);
		Case* premiere = new Terrain(nom, 0, prixAchat, "", prixAchat/2, couleur, loyers, prixMaison);
		(*premiere).setNum(i);
		premiere->setSuivante(this->tete);
		this->tete = premiere;
	}
	else if (type=="GARE") {
		Case* premiere = new Gare(nom, 0, 50, "", 25);
		(*premiere).setNum(i);
		premiere->setSuivante(this->tete);
		this->tete = premiere;
	}
	else if (type=="COMPAGNIE") {
		Case* premiere = new Compagnie(nom, 0, 150, "", 75);
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
		Case* premiere = new Prison(nom);
		(*premiere).setNum(i);
		premiere->setSuivante(this->tete);
		this->tete = premiere;
	}
	else if (type=="TAXE") {
		int montant = stoi(words[1]);
		Case* premiere = new Taxe(nom, montant);
		(*premiere).setNum(i);
		premiere->setSuivante(this->tete);
		this->tete = premiere;
	}
	else if (type=="GRATUIT") {
		Case* premiere = new Gratuit(nom);
		(*premiere).setNum(i);
		premiere->setSuivante(this->tete);
		this->tete = premiere;
	}
	else if (type=="ARRESTATION") {
		Case* premiere = new Arrestation(nom);
		(*premiere).setNum(i);
		premiere->setSuivante(this->tete);
		this->tete = premiere;
	}
	else if (type=="DEPART") {
		int gain = 200;
		Case* premiere = new Depart(nom, gain);
		(*premiere).setNum(i);
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

