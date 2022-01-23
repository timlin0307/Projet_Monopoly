/*
 * Jeu.h
 *
 *  Created on: 1 janv. 2022
 *      Author: basti
 */

#ifndef JEU_H_
#define JEU_H_
#include <string>
#include "Joueur.h"
using namespace std;

class Plateau;

class Jeu {
protected:
	int tourdejeu;
	int nb_joueurs;
	Joueur* joueurs[];
public:
	Jeu();
	int compteur();
	int getNbjoueurs();
	void setNbjoueurs(int nb_joueurs);
	void setJoueurs();
	Joueur** getJoueurs();
	void afficheJoueurs();
	string getJoueur_actuel();
	void launchGame(Plateau*);
};



#endif /* JEU_H_ */
