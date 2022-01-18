/*
 * Jeu.cpp
 *
 *  Created on: 1 janv. 2022
 *      Author: basti
 */

#include "Jeu.h"
#include <iostream>
using namespace std;

Jeu::Jeu(){
	tourdejeu = 0;
	cout << "Combien y-a-t-il de joueurs ?" << endl;
	cin >> nb_joueurs;
	joueurs = nullptr;
}

int Jeu::compteur(){
	tourdejeu++;
	if (tourdejeu>nb_joueurs){
		tourdejeu=1;
	}
	return tourdejeu;
}

int Jeu::getNbjoueurs(){
	return nb_joueurs;
}

void Jeu::setNbjoueurs(int nb_joueurs){
	this->nb_joueurs = nb_joueurs;
}

void Jeu::setJoueurs(){
	int money = 5000;
	string nom;
	this->joueurs[nb_joueurs] = {0};
	for(int i=0; i<nb_joueurs; i++) {
		cout << "Qui est le joueur " << i+1 << " ? " << endl;
		cin >> nom;
		joueurs[i] = new Joueur(i, money, nom, 0, 0);
	}
}

Joueur** Jeu::getJoueurs(){
	return joueurs;
}

void jeu::afficheJoueurs() {
	for (int i=0; i<nb_joueurs; i++) {
		(*joueurs[i]).afficheNom();
	}
}
