/*
 * jeu.cpp
 *
 *  Created on: 1 janv. 2022
 *      Author: basti
 */

#include "jeu.h"
#include <iostream>
using namespace std;

jeu::jeu(){
	tourdejeu=0;
	cout<<"Combien y-a-t-il de joueurs ?"<<endl;
	cin>>nb_joueurs;
	this->nb_joueurs=nb_joueurs;
}

int jeu::compteur(){
	tourdejeu++;
	if (tourdejeu>nb_joueurs){
		tourdejeu=1;
	}
	return tourdejeu;
}

void jeu::setNbjoueurs(int nb_joueurs){
	this->nb_joueurs=nb_joueurs;
}
