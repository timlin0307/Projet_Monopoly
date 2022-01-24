/*
 * Terrain.h
 *
 *  Created on: 18 déc. 2021
 *      Author: lucas
 */

#ifndef TERRAIN_H_
#define TERRAIN_H_

#include <iostream>
#include <string>
using namespace std;
#include "Propriete.h"
#include "Joueur.h"



class Terrain : public Propriete
{
protected :
	string couleur;
	int * list_loyer; /* terrain nu , 1 , 2 ,3 ,4 maisons, hotel -> on sait que liste de dim 6*/
	int prix_maison;
	int nb_maisons;  /* 5 maisons = 1 hotel */
	Joueur * appartient_a;


public :
	Terrain(string nomcase, int loyer, int prixachat, string nomjoueur,
			int valhypo,string couleur, int * list_loyer, int prix_maison, int nb_maisons =0,Joueur* appartient_a= nullptr, bool hypotheque = false);
	Terrain();
	void arreterSur(Joueur* j, int de);
	void calcul_loyer();
	int get_NBmaisons();
	void ajoute_maison();
	Joueur * getJoueur();
	void setJoueur(Joueur *);

	void ajout_hypotheque(Joueur *);
};




#endif /* TERRAIN_H_ */
