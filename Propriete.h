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
#include "Case.h"



class Propriete : public Case
{
protected :
	int loyer;
	int prixAchat;
	string nom_joueur; /* nom du joueur a "" si personne n'a la case */
	int val_hypotheque;
	bool hypotheque;



public :
	Propriete(string nomcase, int loyer, int prixachat, string nomjoueur, int valhypo, bool hypotheque = false );

	Propriete();
	void setLoyer(int);
	int getLoyer();
	void setPrixAchat(int);
	int getPrixAchat();
	void setNomJoueur(string);
	string getNomJoueur();
	void arreterSur(int);
	void setHypotheque(bool);
	bool getHypotheque();
	int getvalhypo();

};




#endif /* PROPRIETE_H_ */
