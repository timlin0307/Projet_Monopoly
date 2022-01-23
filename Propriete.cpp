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

Propriete :: Propriete(string nomcase, int loyer, int prixachat, string nomjoueur, int valhypo, bool hypotheque ) /* on ne met pas Case casesuiv dans le constructeur ? */
: Case(nomcase)
{
	this -> loyer = loyer;
	prixAchat = prixachat;
	nom_joueur = nomjoueur;
	val_hypotheque = valhypo;
	this -> hypotheque = hypotheque;
}

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

void Propriete :: setHypotheque(bool b)
{
	hypotheque = b;
}


bool Propriete :: getHypotheque()
{
	return hypotheque;
}

int Propriete :: getvalhypo()
{
	return val_hypotheque;
}
