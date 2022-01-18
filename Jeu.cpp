/*
 * jeu.cpp
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
	this->nb_joueurs = nb_joueurs;
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
	int money;
	money = 5000;
	joueurs = new Joueur*[nb_joueurs];
	cout << "Qui sont les joueurs ?" << endl;
	for(int i=0; i<nb_joueurs ; i++){
		string nom;
		cout << "joueur" << i << endl;
		cin >> nom;
		Joueur joue = joueur(i, money, nom);
		Joueur* personne = &joue;
		joueurs[i] = personne;
	}
}

Joueur** Jeu::getJoueurs(){
	return joueurs;
}
