/*
 * Depart.cpp
 *
 *  Created on: 15 janv. 2022
 *      Author: lucas
 */


#include "Case.h"
#include <iostream>
#include <string>
using namespace std;
#include "Depart.h"

Depart :: Depart (string nomcase, int prix)
	: Case(nomcase) {
    gain = prix;
}

void Depart :: arreterSur(Joueur * j, int de) {
    j->crediter(gain);
}


