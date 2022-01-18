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
	tourdejeu = 0;  //on commence la préparation du jeu avec le compteur à 0
	cout << "Combien y-a-t-il de joueurs ?" << endl;
	cin >> nb_joueurs; // On demande et enregistre le nombre de joueurs
	joueurs[0] = nullptr;
}

// Le compteur s'incrémente à chaque appel, et reviens à 1 (premier joueur) après avoir appelé le dernier joueur.
int Jeu::compteur(){
	tourdejeu++; // Croit à chaque appel
	if (tourdejeu>nb_joueurs){ // Boucle entre [1 , nb_joueurs]
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
	int money = 5000; // argent de départ pour chaque joueur
	string nom;
	this->joueurs[nb_joueurs] = {0}; // On initialise joueurs en tableau à nb_joueurs éléments nuls (de type Joueur*)
	for(int i=0; i<nb_joueurs; i++) {
		cout << "Qui est le joueur " << i+1 << " ? " << endl; // Pour plus de clarté pour le joueur, on fait commencer le numéro des joueurs à 1 (donc décale tout de 1)
		cin >> nom;
		joueurs[i] = new Joueur(i, money, nom, 0, 0); /* On créé un nouvel objet Joueur pour chaque itération, que l'on met dans joueur[i]
		i correspond au numéro du pion associé au joueur (pour l'instant)
		0 car 0 gares et 0 compagnies au début*/
	}
}

Joueur** Jeu::getJoueurs(){
	return joueurs;
}

void Jeu::afficheJoueurs(){
	cout << "Liste des joueurs : " << "\n";
	for(int i=0; i<nb_joueurs; i++) {
		cout << joueurs[i]->getNom() << "\n"; // Affiche le nom de l'élément i de la liste joueurs (donc nom du joueur i+1)
	}
	cout << "------------------" << endl;
}

// Retourne le nom du joueur qui doit jouer à ce tour
string Jeu::getJoueur_actuel(){
	return joueurs[tourdejeu-1]->getNom ; // On prend l'élément tourdejeu-1 car le compteur commence à 1 (décalé de 1 à droite)
}
