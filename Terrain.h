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
	/* int prix_maison
	 * int prix_hotel
	 * nb de maisons ! construction uniforme
	 *  */

public :
	/* rien à mettre on herite de propriete */


};




#endif /* TERRAIN_H_ */
