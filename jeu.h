/*
 * jeu.h
 *
 *  Created on: 1 janv. 2022
 *      Author: basti
 */

#ifndef JEU_H_
#define JEU_H_

class jeu {
private :
	int tourdejeu;
	int nb_joueurs;

public :
	jeu();
	int compteur();
	void setNbjoueurs(int nb_joueurs);
};



#endif /* JEU_H_ */
