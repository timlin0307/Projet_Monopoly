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
#include <algorithm>
using namespace std;

void Chance::melanger() {							// pour mélanger le paquet de cartes
	string* tab = Chance::lecture();
	random_shuffle(tab, tab+16);					// échange l'étiquetage entre valeurs et adresses
	Chance::ecriture(tab);
}
	
string* Chance::lecture() {							// pour lire dans le fichier txt
	string* tab = new string[16];
	ifstream monFlux("chance.txt");
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
	return res;
}

void Chance::ecriture(string* tab) {				// pour écrire dans le txt
	string const nomFichier("chance.txt");
	ofstream monFlux(nomFichier.c_str());
	if(monFlux)	{
		for(int i = 0 ; i < 16 ;i++)
			monFlux << tab[i] << endl ;
	}
	else
		cout << "WARNING - Impossible d'ouvrir le fichier" << endl;
}


Chance::Chance(string nom):Case(nom) {				// constructeur d'une case Chance, qui mélange une fois le paquet en début de partie
	Chance::melanger();
}

string Chance::piocher() {							// pioche la première carte du paquet et la remet au talon
	string* tab = Chance::lecture();
	string* newTab = new string[16];
	for (int i = 0; i < 15; i++) {
		newTab[i] = tab[i+1];
	}
	newTab[15] = tab[0];
	Chance::ecriture(newTab);
	return tab[0];
}
