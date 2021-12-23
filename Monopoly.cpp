//============================================================================
// Name        : Monopoly.cpp
// Author      : me
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Case.h"
#include "Plateau.h"
#include "Communaute.h"
#include <iostream>
using namespace std;

int main() {
	
	Plateau plateau = Plateau();
	plateau.affiche();
	
	Communaute com = Communaute("Caisse de com");
	return 0;
}
