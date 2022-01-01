/*
 * pion.cpp
 *
 *  Created on: 2021/12/17
 *      Author: Yen-Ting Lin
 */

#include "pion.h"

pion::pion(joueur* j, Case* p, string n) {
	Joueur = j;
	Position = p;
	nom = n;
}

joueur* pion::getJoueur() {
	return Joueur;
}

Case* pion::getPosition() {
	return Position;
}

string pion::getNom() {
	return nom;
}

void pion::setJoueur(joueur* j) {
	Joueur = j;
}

void pion::setPosition(Case* p) {
	Position = p;
}

void pion::setNom(string n) {
	nom = n;
}

void pion::setPion() {
}

void pion::deplacer() {

}
