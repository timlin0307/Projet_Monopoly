/*
 * Taxe.cpp
 *
 *  Created on: 15 janv. 2022
 *      Author: lucas
 */

#include "Case.h"
#include <iostream>
#include <string>
using namespace std;
#include "Taxe.h"

Taxe :: Taxe (string nomcase, int prix)
: Case(nomcase)
{
	prix_a_payer = prix;
}

void Taxe :: arreterSur(joueur * j, int de)
{
	j->debiter(prix_a_payer);
}
