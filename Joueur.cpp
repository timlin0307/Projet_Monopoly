/*
 * Joueur.cpp
 *
 *  Created on: 15 janv. 2022
 *      Author: lucas
 */


#include "Joueur.h"

Joueur::Joueur(int pn, int sol, string n) {
	pionNum = pn;
	solde = sol;
	nom = n;
}

void Joueur::operation() {
}

string Joueur::getNom() {
	return nom;
}

int Joueur::getPion() {
	return pionNum;
}

int Joueur::getSolde() {
	return solde;
}

void Joueur::setPion(int pn) {
	pionNum = pn;
}

void Joueur::setSolde(int sol) {
	solde = sol;
}

void Joueur::jouer() {
}

void Joueur::crediter(int amount) {
	solde += amount;
}

void Joueur::debiter(int amount) {
	solde -= amount;
}
