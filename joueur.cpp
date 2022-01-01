/*
 * joueur.cpp
 *
 *  Created on: 2021/12/17
 *      Author: Yen-Ting Lin
 */

#include "joueur.h"

joueur::joueur(pion pi, int sol, string n) {
	Pion = pi;
	solde = sol;
	nom = n;
}

void joueur::operation() {
}

string joueur::getNom() {
	return nom;
}

joueur joueur::getPion() {
	return Pion;
}

int joueur::getSolde() {
	return solde;
}

void joueur::setPion() {
}

void joueur::setSolde(int sol) {
	solde = sol;
}

void joueur::jouer() {
}

void joueur::crediter() {
}

void joueur::debiter() {
}
