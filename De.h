/*
 * De.h
 *
 *  Created on: 17 déc. 2021
 *      Author: basti
 */
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <random>
#include <ctime>
using namespace std;

#ifndef DE_H_
#define DE_H_
class De {
    protected:
	int nbFaces;
	int valeur;
    public:
	De();
	De(int nbFaces);
	int getNbfaces();
	int getValeur();
};


#endif /* DE_H_ */
