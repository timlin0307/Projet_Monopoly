/*
 * De.cpp
 *
 *  Created on: 30 déc. 2021
 *      Author: basti
 */

#include "De.h"

De::De() {
	nbFaces = 6 ;
	this->valeur = 1 + rand() % 6;
}
De::De(int nbFaces){
	this->nbFaces = nbFaces;
	valeur = 1 + rand() % nbFaces;
}

int De::getNbfaces(){
	return nbFaces;
}

int De::getValeur(){
	return valeur;
}
