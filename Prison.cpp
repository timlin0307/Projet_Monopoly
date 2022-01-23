/*
 * Prison.cpp
 *
 *  Created on: 18 janv. 2022
 *      Author: neyre
 */

#include <string>
#include "Case.h"
#include "Prison.h"
#include "Gobelet.h"
#include "Joueur.h"


Prison::Prison(string nom):Case(nom) {
	
}

int Prison :: sortir(Joueur *j) /* on retourne un int qui est la valeure du lancé si il a fait un double ou s'il a payé sinon c'est 0*/
								/* du coup ne pas faire lancer le dé le tour de jeu se fera dans cette méthode*/
{
	if ((*j).getPrison() == 0)
	{
		cout << " vous avez déja passé trois tours en prison vous devez payer 50 euros " << endl;
		(*j).debiter(50);
		(*j).setPrison(-1);
		Gobelet g = Gobelet();
		int dep = g.getValeur();
		Case * case_courante = (*j).getCase();
		(*case_courante).deplacement(j, dep);
	}

	else if ((*j).getPrison() == -1)
	{
		cout << " Pas normal vous ne devriez pas pouvoir sortir de prison " << endl;
	}
	else
	{
		cout << "vous etes en prison pour encore " << (*j).getPrison() << endl;
		cout << " vous pouvez sortir en payant 50 euros " << endl;
		cout << "tapez 1 si voulez payer, taper 2 sinon et vous lancerez les dés pour faire un double " << endl;
		int sortir;
		cin >> sortir ;
		bool boucle = true;
		while (boucle)
		{

		try {
				if (sortir == 1 || sortir == 2)
				{
					throw (sortir);
				}
				else
				{
					string except = "Vous ne pouvez pas rentrer cette valeure. Veuillez recommencer ";
					throw (except);
				}
			}
		catch (string except)
		{
		cout << except << "\n" ;
		}
		catch (int sortir)
		{
			if (sortir == 1 )
			{
				cout << " vous avez aller pouvoir lancer le dé " << endl;
				(*j).debiter(50);
				(*j).setPrison(-1);
				Gobelet g = Gobelet();
				int dep = g.getValeur();
				Case * case_courante = (*j).getCase();
				(*case_courante).deplacement(j, dep);
			}
			else
			{
				cout << "si vous faites un double vous sortez " << endl;
				Gobelet g = Gobelet();
				if (g.Double())
				{
					cout << "vous avez fait un double vous sortez de prison " << endl;
					(*j).setPrison(-1);
					int dep = g.getValeur();
					Case * case_courante = (*j).getCase();
					(*case_courante).deplacement(j, dep);
				}
				else
				{
					cout << "vous n'avez pas fait de double vous restez en prison " << endl;
				}

			}


		}
		}
	}
}

