/*
 * Propriete.h
 *
 *  Created on: 18 déc. 2021
 *      Author: lucas
 */

#ifndef PROPRIETE_H_
#define PROPRIETE_H_
#include <iostream>
#include <string>
using namespace std;

/* herite de case
 * protected : nom de la case
 *
 * public : arreterSur()
 * getNom
 * setNom
 *
 */

class Propriete /*: public Case */
{
protected :
	int loyer;
	int prixAchat;
	string nom_joueur; /* nom du joueur a NULL si personne n'a la case */



public :
	void setLoyer(int);
	int getLoyer();
	void setPrixAchat(int);
	int getPrixAchat();
	void setNomJoueur(string);
	string getNomJoueur();
	/* calcul loyer
	 * pour pouvoir faire différence batiment non batiment,
	 * hypothèque ou non
	 * tout les terrains de la même couleur ??
	 * permet aussi de faire varier prix selon
	 * nb de gare, nb de compagnie de service public
	 *
	 *
	 *  */
};




#endif /* PROPRIETE_H_ */
