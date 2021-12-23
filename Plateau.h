/*
 * Plateau.h
 *
 *  Created on: 22 déc. 2021
 *      Author: neyre
 */

#ifndef PLATEAU_H_
#define PLATEAU_H_
#include "Case.h"
#include <iostream>
using namespace std;

class Plateau {
private:
	Case* tete;
	void ajouterCase(string);
	string* lecture();
public:
	Plateau();
	void affiche();
};


#endif /* PLATEAU_H_ */
