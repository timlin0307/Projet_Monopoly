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
#include "jeu.h"
#include "Chance.h"
#include "Prison.h"
#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;


int main() {
	
	Plateau plateau = Plateau();
	plateau.affiche();
	
	Jeu partie = Jeu();
	partie.launchGame(&plateau);
	
	Case* departure = plateau.getCase(30);
	departure->affiche();
	cout << typeid(*departure).name() << endl;
	
	Joueur j = Joueur(0, 0, "Lucas", 0, 0);
	j.setCase(departure);
	departure->arreterSur(&j, 6);
	cout << j.getSolde() << endl;
	Case* land = j.getCase();
	cout << typeid(*land).name() << endl;
	//(*land).sortir(&j);
	departure->deplacement(&j, 6);
	
	/*Communaute com = Communaute("Caisse de com", "communaute.txt");
	string s = com.piocher();
	cout << s << endl;
	
	Chance ch = Chance("Chance", "chance.txt");
	string s2 = ch.piocher();
	cout << s2 << endl;*/
	
	return 0;
}
