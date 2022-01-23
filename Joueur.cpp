/*
 * Joueur.cpp
 *
 *  Created on: 15 janv. 2022
 *      Author: Yen-Ting Lin, lucas
 */


#include "Joueur.h"
#include <typeinfo>
#include "Propriete.h"
#include "Terrain.h"
#include "Gare.h"
#include "Compagnie.h"

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
	Case* depart = board->getCase(41);
	courante = depart;
}

void Joueur :: hypothequer ()
{
	Case * case_courante = courante;
	int encore = 1;
	while (encore)
	{
		Case* casesuivante = (*case_courante).getSuivante();
		for (int i=0; i<41; i++ )
		{
			if (typeid(*case_courante) == Propriete)
			{
				if (this == (*(*case_courante).getJoueur()) & !(*(*case_courante).getHypotheque()))
				{
					cout << "Voulez vous hypothequer ? " << (*case_courante).getNom() << endl;
					cout << "Vous empaucherez " << case_courante->getvalhypo() << endl;
					cout << "Si vous voulez hypothequer tapez 1 sinon tapez 0" << endl;
					int hypo;
					cin >> hypo;
					if (hypo)
					{
						case_courante->setHypotheque(true);
						solde += case_courante->getvalhypo();
					}
				}
			}

		case_courante = casesuivante ;
		casesuivante = (*case_courante).getSuivante();


		}
		cout << "voulez revoir vos cases pour voir celles que vous voulez hypothequer si oui tapez 1 sinon tapez 0 " << endl;

		cin >> encore ;
	}
}

void Joueur :: revendre_maison ()
{

}
