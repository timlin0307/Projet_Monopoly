/*
 * jeu.h
 *
 *  Created on: 1 janv. 2022
 *      Author: basti
 */

#ifndef JEU_H_
#define JEU_H_
#include <string>
#include "joueur.h"
using namespace std;

class jeu {
protected :
	joueur* *joueurs;
	int tourdejeu;
	int nb_joueurs;

public :
	jeu();
	int compteur();
	int getNbjoueurs();
	void setNbjoueurs(int nb_joueurs);
	void setJoueurs();
	joueur** getJoueurs();
};



#endif /* JEU_H_ */
