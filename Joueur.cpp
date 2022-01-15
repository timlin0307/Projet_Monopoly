/*
 * Joueur.cpp
 *
 *  Created on: 15 janv. 2022
 *      Author: lucas
 */


#include "joueur.h"

joueur::joueur(int pn, int sol, string n) {
	pionNum = pn;
	solde = sol;
	nom = n;
}

void joueur::operation() {
}

string joueur::getNom() {
	return nom;
}

int joueur::getPion() {
	return pionNum;
}

int joueur::getSolde() {
	return solde;
}

void joueur::setPion(int pn) {
	pionNum = pn;
}

void joueur::setSolde(int sol) {
	solde = sol;
}

void joueur::jouer() {
}

void joueur::crediter(int amount) {
	solde += amount;
}

void joueur::debiter(int amount) {
	solde -= amount;
}
