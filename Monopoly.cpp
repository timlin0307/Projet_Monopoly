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
#include "Chance.h"
#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;


int main() {
	
	Plateau plateau = Plateau();
	plateau.affiche();
	Case* departure = plateau.getCase(8);
	departure->affiche();
	cout << typeid(*departure).name() << endl;
	
	joueur j = joueur(0, 0, "Lucas");
	departure->arreterSur(&j, 6);
	cout << j.getSolde() << endl;
	//departure.deplacement(&j, 6);
	
	/*Communaute com = Communaute("Caisse de com", "communaute.txt");
	string s = com.piocher();
	cout << s << endl;
	
	Chance ch = Chance("Chance", "chance.txt");
	string s2 = ch.piocher();
	cout << s2 << endl;*/
	
	return 0;
}
