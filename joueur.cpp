/*
 * joueur.cpp
 *
 *  Created on: 2021/12/17
 *      Author: Yen-Ting Lin
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

void joueur::crediter() {
}

void joueur::debiter() {
}
