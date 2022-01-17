/*
 * Chance.h
 *
 *  Created on: 8 janv. 2022
 *      Author: neyre
 */

#ifndef CHANCE_H_
#define CHANCE_H_
#include "Case.h"
#include "joueur.h"
#include <iostream>
using namespace std;

class Chance : public Case {
private:
	void melanger();
	string fileName;
	
public:
	Chance(string, string);
	string* lecture();
	void ecriture(string*);
	string piocher();
	void arreterSur(joueur*, int);
};




#endif /* CHANCE_H_ */
