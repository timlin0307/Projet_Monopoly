/*
 * joueur.cpp
 *
 *  Created on: 2021/12/17
 *      Author: Yen-Ting Lin
 */

#include "joueur.h"
#include <string>
using namespace std;

joueur::joueur(int pn, int sol, string n) {
	pionNum = pn;
	solde = sol;
	nom = n;
	courante = nullptr;
}

Case* joueur::getCase() {
	return this->courante;
}

void joueur::setCase(Case* c) {
	this->courante = c;
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

void joueur::afficheNom() {
	cout << nom << endl;
}
