/*
 * Terrain.cpp
 *
 *  Created on: 18 déc. 2021
 *      Author: lucas
 */


#include <iostream>
#include <string>
using namespace std;
#include "Terrain.h"
#include "Joueur.h"


Terrain :: Terrain(string nomcase, int loyer, int prixachat, string nomjoueur,
		int valhypo,string couleur, int * list_loyer, int prix_maison, int nb_maisons, Joueur* jref, bool hypotheque)
:Propriete( nomcase, loyer, prixachat, nomjoueur, valhypo, hypotheque )
{
	this -> couleur = couleur;
	this -> list_loyer = list_loyer;
	this -> prix_maison = prix_maison;
	this -> nb_maisons = nb_maisons;
	this -> appartient_a = jref;
}


void Terrain :: arreterSur(Joueur* j, int de)
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
			cout << "Votre nouveau solde est de " << (*j).getSolde() << endl;
		}
	}

	else if (hypotheque == false )
	{
		cout << "la case appartient à " << (*appartient_a).getNom() << endl;
		this -> calcul_loyer();
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

void Terrain :: calcul_loyer()
{
	if (nb_maisons == 0)
	{
		loyer = list_loyer[0];/* verif si le joueur a les cases de la meme couleur si oui *2 terrain nu */
	}
	else
	{
		loyer = list_loyer[nb_maisons];
	}
}


int Terrain :: get_NBmaisons()
{
	return nb_maisons;
}

void Terrain :: set_NBmaisons(int n)
{
	nb_maisons=n;
}

void Terrain :: ajoute_maison()
{
	cout << "vous avez actuellement " << nb_maisons <<endl;
	cout <<  "voulez-vous en racheter une ou plusieurs, sachaant que vous ne pouvez pas exceder 5 maisons qui est équivalent à un hotel ?" << endl;
	int nb;
	cin >> nb ;

	try {
		if (nb + nb_maisons <= 5)
		{
			throw (nb);
		}
		else
		{
			string except = "Vous ne pouvez pas construire autant de maisons. Veuillez recommencer ";
			throw (except);
		}
	}
	catch (int nb) {
	cout << "On va rajouter " << nb << " maisons " << "\n" ;
	(*appartient_a).debiter(nb*prix_maison);
	nb_maisons = nb_maisons + nb;
	cout << "votre nouveau solde de compte en banque est " << (*appartient_a).getSolde() << endl;
	cout <<  "Vous avez maintenant " << nb << " maisons " << endl;
	}
	catch (string except) {
	cout << except << "\n" ;
	}
}



Joueur * Terrain :: getJoueur()
{
	return appartient_a;
}

void Terrain :: setJoueur(Joueur * j)
{
	appartient_a = j;
}




Terrain :: Terrain()
:Propriete()
{
	this -> couleur = "test";
	this -> list_loyer = new int (1);
	this -> prix_maison = 0;
	this -> nb_maisons = 0;
	this -> appartient_a = nullptr;
}


void Terrain :: ajout_hypotheque(Joueur *j)
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


void Terrain :: enleve_hypotheque(Joueur *j)
{
	if (j == this->getJoueur() && (this->getHypotheque()))
					{
						cout << "Voulez vous deshypothequer ? " << this->getNom() << endl;
						cout << "Vous debourserez " << (this->getvalhypo())*1.1 << endl;
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

void Terrain :: moins_maison(Joueur * j)
{
	if (j == this->getJoueur() && ((this->get_NBmaisons()) != 0) )
	{
			cout << "vous avez actuellement " << this->get_NBmaisons() <<endl;
			cout <<  "voulez-vous en revendre une ou plusieurs, sachant que vous ne pouvez pas avoir moins de 0 maisons ?" << endl;
			cout << "Si vous ne voulez pas vendre de maisons tapez 0 sinon tapez le nombre de maisons que vous voulez vendre " << endl;
			int nb;
			cin >> nb ;

			if (nb!=0)
			{
				int encore = 1;
				while (encore)
				{

					try {
						if ((this->get_NBmaisons())-nb >0)
						{
							throw (nb);
						}
						else
						{
							string except = "Vous ne pouvez pas enlever autant de maisons. Veuillez recommencer ";
							throw (except);
						}
						}
					catch (int nb) {
					cout << "On va enlever " << nb << " maisons " << "\n" ;
					(*appartient_a).crediter(nb*prix_maison /2);
					this->set_NBmaisons( this->get_NBmaisons()  - nb);
					cout << "votre nouveau solde de compte en banque est " << (*appartient_a).getSolde() << endl;
					cout <<  "Vous avez maintenant " << (this->get_NBmaisons())-nb << " maisons " << endl;
					encore = 0;
					}
					catch (string except) {
					cout << except << "\n" ;
					}
				}
			}
	}

}

void Terrain :: plus_maison(Joueur * j)
{
	if (j == this->getJoueur() && ((this->get_NBmaisons()) <5) )
	{
		cout << "vous avez actuellement " << this->get_NBmaisons() <<endl;
		cout <<  "voulez-vous en racheter une ou plusieurs, sachant que vous ne pouvez pas exceder 5 maisons qui est équivalent à un hotel ?" << endl;
		cout << "Si vous ne voulez pas ajouter de maisons tapez 0 sinon tapez le nombre de maisons que vous voulez " << endl;
		int nb;
		cin >> nb ;

		if (nb!=0)
		{
			int encore = 1;
			while (encore)
			{

				try {
					if (nb + nb_maisons <= 5)
					{
						throw (nb);
					}
					else
					{
						string except = "Vous ne pouvez pas construire autant de maisons. Veuillez recommencer ";
						throw (except);
					}
					}
				catch (int nb) {
				cout << "On va rajouter " << nb << " maisons " << "\n" ;
				(*appartient_a).debiter(nb*prix_maison);
				this->set_NBmaisons(nb + this->get_NBmaisons());
				cout << "votre nouveau solde de compte en banque est " << (*appartient_a).getSolde() << endl;
				cout <<  "Vous avez maintenant " << this->get_NBmaisons() << " maisons " << endl;
				encore = 0;
				}
				catch (string except) {
				cout << except << "\n" ;
				}
			}
		}
	}
}


void Terrain :: supprime(Joueur j)
{
	if (j.getPion() == (*(this->getJoueur())).getPion())
					{
						this ->setJoueur(nullptr);
						string joueur1 = "";
						this -> setNomJoueur(joueur1);
						this -> setHypotheque(false);
						this -> set_NBmaisons(0);
					}
}

