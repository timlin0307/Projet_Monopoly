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

void Communaute::melanger() {
	string* tab = Communaute::lecture();
	random_shuffle(tab, tab+16);
	Communaute::ecriture(tab);
}

Communaute::Communaute(string nom):Case(nom) {
	Communaute::melanger();
}

string* Communaute::lecture() {
	string* tab = new string[16];
	ifstream monFlux("communauté.txt");
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

void Communaute::ecriture(string* tab) {
	string const nomFichier("communauté.txt");
	ofstream monFlux(nomFichier.c_str());
	if(monFlux)	{
	 	for(int i = 0 ; i < 16 ;i++)
	     	 monFlux << tab[i] << endl ;
	}
	else
	 	cout << "WARNING - Impossible d'ouvrir le fichier" << endl;    
}


