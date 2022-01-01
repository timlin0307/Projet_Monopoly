/*
 * de.cpp
 *
 *  Created on: 30 déc. 2021
 *      Author: basti
 */

#include "de.h"

de::de() {
	nbFaces=6 ;
	this->valeur = 1 + rand() % 6;
}
de::de(int nbFaces){
	this->nbFaces=nbFaces;
	valeur =1 + rand() % nbFaces;
}

int de::getNbfaces(){
	return nbFaces;
}

int de::getValeur(){
	return valeur;
}
