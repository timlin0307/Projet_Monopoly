/*
 * pion.cpp
 *
 *  Created on: 2021/12/17
 *      Author: Yen-Ting Lin
 */

#include "Pion.h"

Pion::Pion(Joueur* j, Case* p, string n) {
	joueur = j;
	Position = p;
	nom = n;
}

Joueur* Pion::getJoueur() {
	return Joueur;
}

Case* Pion::getPosition() {
	return Position;
}

string Pion::getNom() {
	return nom;
}

void Pion::setJoueur(joueur* j) {
	Joueur = j;
}

void Pion::setPosition(Case* p) {
	Position = p;
}

void Pion::setNom(string n) {
	nom = n;
}

void Pion::setPion() {
}

void Pion::deplacer() {

}
