/*
 * Gare.cpp
 *
 *  Created on: 18 déc. 2021
 *      Author: lucas
 */

#include <iostream>
#include <string>
using namespace std;
#include "Gare.h"

Gare ::Gare(string nomcase, int loyer, int prixachat, string nomjoueur, int valhypo,  bool hypotheque)
:Propriete( nomcase, loyer, prixachat, nomjoueur, valhypo, hypotheque )
{

}

void Gare :: arreterSur(int de)
{
	Case casesuivante = *suivante ;
	Case casecourante = casesuivante ;
	for (int i=0; i<de; i++)
	{
		casecourante = casesuivante ;
		casesuivante = *casecourante.getSuivante() ;
	}
	cout << "vous êtes sur la case" << casecourante.getNom() << endl;
	if (nom_joueur == "")
	{
		cout << "la case n'appartient à personne" << endl;
		cout << "le prix d'achat est de " << prixAchat << endl;
		cout << "souhaitez vous l'acheter ?" << endl;
	}

	else
	{
		cout << "la case appartient à " << nom_joueur << endl;
	}
}

void Gare :: calcul_loyer()
{
	int i = 0;/* il faut qu'on puisse initialiser i au nb de gare de la personne */
	loyer = 25 * 2^(i);
}


