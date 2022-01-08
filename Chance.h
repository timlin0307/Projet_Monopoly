/*
 * Chance.h
 *
 *  Created on: 8 janv. 2022
 *      Author: neyre
 */

#ifndef CHANCE_H_
#define CHANCE_H_
#include "Case.h"
#include <iostream>
using namespace std;

class Chance : public Case {
private:
	void melanger();
	string* lecture();
	void ecriture(string*);
public:
	Chance(string);
	string piocher();
	//virtual void arreterSur() override;
};




#endif /* CHANCE_H_ */
