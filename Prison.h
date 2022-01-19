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

class Prison : public Case {
private:
	string nomcase;
public:
	Prison(string);
};




#endif /* PRISON_H_ */
