/*
 * Arrestation.cpp
 *
 *  Created on: 15 janv. 2022
 *      Author: lucas
 */

#include "Case.h"
#include <iostream>
#include <string>
using namespace std;
#include "Arrestation.h"

Arrestation  :: Arrestation (string nomcase, int num)
: Case(nomcase)
{
	num_prison = num;
}

void Arrestation :: arreterSur(joueur * j, int de)
{
	/* changer la case*/
}




