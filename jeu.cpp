/*
 * jeu.cpp
 *
 *  Created on: 1 janv. 2022
 *      Author: basti
 */

#include "jeu.h"
#include <iostream>
using namespace std;

jeu::jeu(){
	tourdejeu=0;
	cout<<"Combien y-a-t-il de joueurs ?"<<endl;
	cin>>nb_joueurs;
	this->nb_joueurs=nb_joueurs;
	joueurs=nullptr;
}

int jeu::compteur(){
	tourdejeu++;
	if (tourdejeu>nb_joueurs){
		tourdejeu=1;
	}
	return tourdejeu;
}

int jeu::getNbjoueurs(){
	return nb_joueurs;
}

void jeu::setNbjoueurs(int nb_joueurs){
	this->nb_joueurs=nb_joueurs;
}

void jeu::setJoueurs(){
	int money;
	money =5000;
	joueurs=new joueur*[nb_joueurs];
	cout<<"Qui sont les joueurs ?"<<endl;
	for(int i=0; i<nb_joueurs ; i++){
		string nom;
		cout<<"joueur" <<i<<endl;
		cin>>nom;
		joueur joue =joueur(i,money, nom);
		joueur* personne= &joue;
		joueurs[i] = personne;
	}
}

joueur** jeu::getJoueurs(){
	return joueurs;
}
