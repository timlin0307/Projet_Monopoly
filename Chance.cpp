/*
 * Chance.cpp
 *
 *  Created on: 8 janv. 2022
 *      Author: neyre
 */

#include "Chance.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

void Chance::melanger() {							// pour mélanger le paquet de cartes
	string* tab = Chance::lecture();
	random_shuffle(tab, tab+16);					// échange l'étiquetage entre valeurs et adresses
	Chance::ecriture(tab);
}
	
string* Chance::lecture() {							// pour lire dans le fichier txt
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

void Chance::ecriture(string* tab) {				// pour écrire dans le txt
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


Chance::Chance(string nom, string fileName):Case(nom) {				// constructeur d'une case Chance, qui mélange une fois le paquet en début de partie
	this->fileName = fileName;
	Chance::melanger();
}

string Chance::piocher() {							// pioche la première carte du paquet et la remet au talon
	cout << "Vous avez pioché la carte : " << endl;
	string* tab = Chance::lecture();
	string* newTab = new string[16];
	for (int i = 0; i < 15; i++) {
		newTab[i] = tab[i+1];
	}
	newTab[15] = tab[0];
	Chance::ecriture(newTab);
	return tab[0];
}

void Chance::arreterSur() {
	cout << "fonction dérivée";
	string ligne = Chance::piocher();
		
	string sep = "-";
	vector<string> words{};
	size_t pos;
	while ((pos = ligne.find(sep)) != string::npos) {// tant qu'on trouve un caractère séparateur
		words.push_back(ligne.substr(0, pos));		// comme un append
		ligne.erase(0, pos + sep.length());			// on supprime ce qui a déjà été examiné
	}
		
	string type = words[0];
	if (type=="PION") {
		cout << "test" << endl;
	}
	else if (type=="GAIN") {
		cout << "test" << endl;
	}
	else if (type=="LIBERE") {
		cout << "test" << endl;
	}
	else if (type=="PERTE") {
		cout << "test" << endl;
	}
	else if (type=="REPARATION") {
		cout << "test" << endl;
	}
}
