/*
 * Joueur.cpp
 *
 *  Created on: 15 janv. 2022
 *      Author: Yen-Ting Lin, lucas
 */


#include "Joueur.h"

Joueur::Joueur(int pn, int sol, string n, int nbg, int nbc) {
	pionNum = pn;
	solde = sol;
	nom = n;
	nb_gare = nbg;
	nb_comp = nbc;
	courante = nullptr;
	touche_200 = true;
	tour_prison = -1;
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

Case* Joueur::getCase() {
	return this->courante;
}

void Joueur::setCase(Case* c) {
	this->courante = c;
}

void Joueur::afficheNom() {
	cout << nom << endl;
}

void Joueur :: set200(bool b)
{
	touche_200 = b;
}

bool Joueur :: get200()
{
	return (touche_200);
}

void Joueur :: setPrison(int n)
{
	tour_prison = n;
}

int Joueur :: getPrison()
{
	return tour_prison;
}

void Joueur :: initCase(Plateau* board) {
	Case* depart = board->getCase(40);
	courante = depart;
}

