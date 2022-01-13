/*
 * Communaute.h
 *
 *  Created on: 22 déc. 2021
 *      Author: neyre
 */

#ifndef COMMUNAUTE_H_
#define COMMUNAUTE_H_
#include "Case.h"

#include <iostream>
using namespace std;

class Communaute : public Case {
private:
	void melanger();
	string fileName;
	
public:
	Communaute(string, string);
	string piocher();
	string* lecture();
	void ecriture(string*);
	void arreterSur();
};


#endif /* COMMUNAUTE_H_ */
