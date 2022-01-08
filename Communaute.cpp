/*
 * Communaute.cpp
 *
 *  Created on: 22 déc. 2021
 *      Author: neyre
 */

#include "Communaute.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

void Communaute::melanger() {   				// pour mélanger le paquet de cartes
	string* tab = Communaute::lecture();
	random_shuffle(tab, tab+16);
	Communaute::ecriture(tab);
}

string Communaute::piocher() {					// pioche la premiere carte du paquet et la remet au talon
	string* tab = Communaute::lecture();
	string* newTab = new string[16];
	for (int i = 0; i < 15; i++) {
		newTab[i] = tab[i+1];
	}
	newTab[15] = tab[0];
	Communaute::ecriture(newTab);
	return tab[0];
}

Communaute::Communaute(string nom):Case(nom) {	// constructeur qui mélange une fois le paquet en début de partie
	Communaute::melanger();
}

string* Communaute::lecture() {					// pour lire dans le fichier txt
	string* tab = new string[16];
	ifstream monFlux("communaute.txt");
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

void Communaute::ecriture(string* tab) {		// pour écrire dans le fichier txt
	string const nomFichier("communaute.txt");
	ofstream monFlux(nomFichier.c_str());
	if(monFlux)	{
	 	for(int i = 0 ; i < 16 ;i++)
	     	 monFlux << tab[i] << endl ;
	}
	else
	 	cout << "WARNING - Impossible d'ouvrir le fichier" << endl;    
}


