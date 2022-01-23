/*
 * Prison.h
 *
 *  Created on: 18 janv. 2022
 *      Author: neyre
 */

#ifndef PRISON_H_
#define PRISON_H_
#include <string>
#include "Case.h"
#include "Joueur.h"


class Prison : public Case {
private:
	string nomcase;
public:
	Prison(string);
	int sortir(Joueur *);
};




#endif /* PRISON_H_ */
