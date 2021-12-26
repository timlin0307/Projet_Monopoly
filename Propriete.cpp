/*
 * Propriete.cpp
 *
 *  Created on: 18 déc. 2021
 *      Author: lucas
 */

#include <iostream>
#include <string>
using namespace std;
#include "Propriete.h"

void Propriete :: setLoyer(int loyer)
{
	this -> loyer = loyer;
}

int Propriete :: getLoyer()
{
	return(loyer);
}

void Propriete :: setPrixAchat(int prix)
{
	prixAchat = prix;
}

int Propriete :: getPrixAchat()
{
	return(prixAchat);
}

void Propriete :: setNomJoueur(string nom)
{
	nom_joueur = nom;
}

string Propriete :: getNomJoueur()
{
	return(nom_joueur);
}
