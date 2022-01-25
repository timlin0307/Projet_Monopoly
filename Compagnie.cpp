/*
 * Compagnie.cpp
 *
 *  Created on: 18 déc. 2021
 *      Author: lucas
 */

#include <iostream>
#include <string>
using namespace std;
#include "Compagnie.h"
#include "Joueur.h"

Compagnie ::Compagnie(string nomcase, int loyer, int prixachat, string nomjoueur,int valhypo, Joueur* j, bool hypotheque)
:Propriete( nomcase, loyer, prixachat, nomjoueur, valhypo, hypotheque )
{
	appartient_a = j;
}

void Compagnie :: arreterSur(Joueur* j, int de)
{
	if (appartient_a == nullptr)
	{
		cout << "la case n'appartient à personne" << endl;
		cout << "le prix d'achat est de " << prixAchat << endl;
		cout << "votre solde de compte en banque est " << (*j).getSolde() << endl;
		cout << "souhaitez vous l'acheter ?" << endl;
		cout << "Si oui taper 1, si non taper 2" << endl;
		int achat;
		cin >> achat ;

		if (achat == 1)
		{
			(*j).debiter(prixAchat);
			nom_joueur = (*j).getNom();
			appartient_a = j;
			(*j).setNbCompagnie(1);
			cout << "Votre nouveau solde est de " << (*j).getSolde() << endl;
		}
	}

	else if (hypotheque == false )
	{
		cout << "la case appartient à " << (*appartient_a).getNom() << endl;
		this -> calcul_loyer(de);
		int a_payer = loyer;
		(*appartient_a).crediter(a_payer);
		(*j).debiter(a_payer);
		cout << "Votre nouveau solde est de " << (*j).getSolde() << endl;
	}
	else
	{
		cout << "la case appartient à " << (*appartient_a).getNom() << endl;
		cout << "elle est hypothéquée tu n'as rien a payé" << endl;
	}
}

void Compagnie :: calcul_loyer(int de)
{
	if ((*appartient_a).getNbCompagnie() == 1)
	{
		loyer = de *4;
	}
	else
	{
		loyer = de *10;
	}
}


Joueur * Compagnie :: getJoueur()
{
	return appartient_a;
}

void Compagnie :: setJoueur(Joueur * j)
{
	appartient_a = j;
}


Compagnie :: Compagnie()
:Propriete()
{
	appartient_a = nullptr;
}

void Compagnie :: ajout_hypotheque(Joueur *j)
{
	if (j == this->getJoueur() && !(this->getHypotheque()))
					{
						cout << "Voulez vous hypothequer ? " << this->getNom() << endl;
						cout << "Vous empaucherez " << this->getvalhypo() << endl;
						cout << "Si vous voulez hypothequer tapez 1 sinon tapez 0" << endl;
						int hypo;
						cin >> hypo;
						if (hypo)
						{
							this->setHypotheque(true);
							(*j).crediter(this->getvalhypo());
						}
					}
}


void Compagnie :: enleve_hypotheque(Joueur *j)
{
	if (j == this->getJoueur() && (this->getHypotheque()))
					{
						cout << "Voulez vous deshypothequer ? " << this->getNom() << endl;
						cout << "Vous débourserez " << ((this->getvalhypo())*1.1) << endl;
						cout << "Si vous voulez deshypothequer tapez 1 sinon tapez 0" << endl;
						int hypo;
						cin >> hypo;
						if (hypo)
						{
							this->setHypotheque(false);
							(*j).debiter((this->getvalhypo())*1.1);
						}
					}
}

void Compagnie :: supprime(Joueur j)
{
	if (j.getPion() == (*(this->getJoueur())).getPion())
					{
						this ->setJoueur(nullptr);
						string joueur1 = "";
						this -> setNomJoueur(joueur1);
						this -> setHypotheque(false);
					}
}

