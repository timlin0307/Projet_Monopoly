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

Terrain ::Terrain(string nomcase, int loyer, int prixachat, string nomjoueur,
		int valhypo, string couleur, int * list_loyer, int prix_maison, int prix_hotel,int nb_maisons, bool hypotheque)
:Propriete( nomcase, loyer, prixachat, nomjoueur, valhypo, hypotheque )
{
	this -> couleur = couleur;
	this -> list_loyer = list_loyer;
	this -> prix_maison = prix_maison;
	this -> prix_hotel = prix_hotel;
	this -> nb_maisons = nb_maisons;
}

void Terrain :: arreterSur(int de)
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

void Terrain :: calcul_loyer()
{
	if (nb_maisons == 0)
	{
		/* verif si le joueur a les cases de la meme couleur si oui *2 terrain nu */
	}
	else
	{
		loyer = list_loyer[nb_maisons];
	}
}

void Terrain :: set_NBmaisons(int n)
{
	nb_maisons = n;/* on doit avoir une construction uniforme et posséder tous les terrains de la couleur*/
}

int Terrain :: get_NBmaisons()
{
	return nb_maisons;
}
