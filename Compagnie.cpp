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

Compagnie ::Compagnie(string nomcase, int loyer, int prixachat, string nomjoueur,int valhypo, joueur* j, bool hypotheque)
:Propriete( nomcase, loyer, prixachat, nomjoueur, valhypo, hypotheque )
{
	appartient_a = j;
}

void Compagnie :: arreterSur(joueur j, int de)
{
	if (nom_joueur == "")
	{
		cout << "la case n'appartient à personne" << endl;
		cout << "le prix d'achat est de " << prixAchat << endl;
		cout << "votre solde de compte en banque est" << j.getSolde() << endl;
		cout << "souhaitez vous l'acheter ?" << endl;
		cout << "Si oui taper 1, si non taper 2" << endl;
		int achat;
		cin >> achat ;
		/*
		 * cin pour savoir oui ou non avec des exceptions.
		 */
		if (achat == 1)
		{
			j.setSolde(j.getSolde()-prixAchat);
			nom_joueur = j.getNom();
			appartient_a = &j;
		}
	}

	else
	{
		cout << "la case appartient à " << nom_joueur << endl;
		/*
		 * on récupère le nom dans la liste en la parcourant
		 */
		this -> calcul_loyer(de);
		int a_payer = loyer;
		(*appartient_a).setSolde(a_payer);
		j.setSolde(a_payer);
	}
}

void Compagnie :: calcul_loyer(int de)
{
	loyer = de *4;/* il faut pouvoir séparer les différents cas */
}



