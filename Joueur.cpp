/*
 * Joueur.cpp
 *
 *  Created on: 15 janv. 2022
 *      Author: Yen-Ting Lin, lucas
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

int Joueur::getNbGare() {
	return nb_gare;
}

int Joueur::getNbCompagnie() {
	return nb_comp;
}

void Joueur::setPion(int pn) {
	pionNum = pn;
}

void Joueur::setSolde(int sol) {
	solde = sol;
}

void Joueur::setNbGare(int nbGare) {
	nb_gare += nbGare;
}

void Joueur::setNbCompagnie(int nbComp) {
	nb_comp += nbComp;
}

void Joueur::jouer() {
}

void Joueur::crediter(int amount) {
	solde += amount;
}

void Joueur::debiter(int amount) {
	solde -= amount;
}
