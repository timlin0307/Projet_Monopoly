/*
 * Communaute.cpp
 *
 *  Created on: 22 déc. 2021
 *      Author: neyre
 */

#include "Communaute.h"
#include "Joueur.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

string* Communaute::lecture() {					// pour lire dans le fichier txt
	string* tab = new string[16];
	ifstream monFlux(this->fileName);
	string* res = nullptr;
	if(monFlux) {
	   	int i = 0;
	    string ligne;
	    while (getline(monFlux,ligne)) {
	      	tab[i] = ligne;   
	    	i++;
	   	}
	    res = tab;
	}
	monFlux.close();
	return res;
}

void Communaute::ecriture(string* tab) {		// pour écrire dans le fichier txt
	string const nomFichier(this->fileName);
	ofstream monFlux(nomFichier.c_str());
	if(monFlux)	{
	 	for(int i = 0 ; i < 16 ;i++)
	     	 monFlux << tab[i] << endl ;
	}
	else
	 	cout << "WARNING - Impossible d'ouvrir le fichier" << endl;    
	monFlux.close();
}

void Communaute::melanger() {   				// pour mélanger le paquet de cartes
	string* tab = Communaute::lecture();
	random_shuffle(tab, tab+16);
	Communaute::ecriture(tab);
}

string Communaute::piocher() {					// pioche la premiere carte du paquet et la remet au talon
	cout << "Vous avez pioché la carte : " << endl;
	string* tab = Communaute::lecture();
	string* newTab = new string[16];
	for (int i = 0; i < 15; i++) {
		newTab[i] = tab[i+1];
	}
	newTab[15] = tab[0];
	Communaute::ecriture(newTab);
	return tab[0];
}

Communaute::Communaute(string nom, string fileName):Case(nom) {	// constructeur qui mélange une fois le paquet en début de partie
	this->fileName = fileName;
	Communaute::melanger();
}


void Communaute::arreterSur(Joueur* j, int de) {
	cout << "Fonction virtuelle redéfinie dans une classe dérivée" << endl;
	string ligne = Communaute::piocher();
	
	string sep = "-";
	vector<string> words{};
	size_t pos;
	while ((pos = ligne.find(sep)) != string::npos) {// tant qu'on trouve un caractère séparateur
		words.push_back(ligne.substr(0, pos));		// comme un append
	    ligne.erase(0, pos + sep.length());			// on supprime ce qui a déjà été examiné
	}
	cout << ligne << endl;
	string type = words[0];
	if (type=="ANNIVERSAIRE") {
		cout << "anniv" << endl;
	}
	else if (type=="GAIN") {
		string montant = words[1];
		int credit = stoi(montant);
		cout << "Vous avez pioché une carte qui vous fait gagner de l'argent +" << credit << " euros" << endl;
		j->crediter(credit);
	}
	else if (type=="LIBERE") {
		cout << "libre" << endl;
	}
	else if (type=="PERTE") {		
		string montant = words[1];
		int debit = stoi(montant);
		cout << "Vous avez pioché une carte qui vous fait perdre de l'argent -" << debit << " euros" << endl;
		j->debiter(debit);
	}
	else if (type=="DILEMNE") {
		cout << "dilemne" << endl;
	}
	else if (type=="PION") {
		cout << "Vous avez pioché une carte qui vous ordonne de vous déplacer" << endl;
		string numero = words[1];
		int num = stoi(numero);
		Case* from = j->getCase();
		int numFrom = (*from).getNum();
		int delta = num-numFrom;
		Case* landing = from->deplacement(j, delta);
		cout << numero << endl;
	}
}
