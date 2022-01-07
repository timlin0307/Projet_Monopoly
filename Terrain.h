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
/* herite de propriete
 * protected : nom de la case
 *
 * public : arreterSur()
 * getNom
 * setNom
 *
 */

class Terrain : public Propriete
{
protected :
	string couleur;
	int * list_loyer; /* terrain nu , 1 , 2 ,3 ,4 maisons, hotel -> on sait que liste de dim 6*/
	int prix_maison;
	int prix_hotel;
	int nb_maisons; /*! construction uniforme*/ /* 5 maisons = 1 hotel */


public :
	Terrain(string nomcase, int loyer, int prixachat, string nomjoueur, int valhypo,string couleur,
			int * list_loyer, int prix_maison, int prix_hotel,int nb_maisonsbool, bool hypotheque = false);
	void arreterSur(int);
	void calcul_loyer();
	void set_NBmaisons(int);/* je pense on peut ne pas mettre d'argument et juste on ne peut augmenter que de 1 par 1 le nb de maison*/
	int get_NBmaisons();


};




#endif /* TERRAIN_H_ */
