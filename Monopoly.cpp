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
using namespace std;

int main() {
	
	Plateau plateau = Plateau();
	plateau.affiche();
	
	Communaute com = Communaute("Caisse de com");
	string s = com.piocher();
	cout << s << endl;
	string s2 = com.piocher();
	cout << s2 << endl;
	
	Chance ch = Chance("Chance");
	string s3 = ch.piocher();
	cout << s3 << endl;
	string s4 = ch.piocher();
	cout << s4 << endl;
	return 0;
}
