/*
 * Jeu.cpp
 *
 *  Created on: 1 janv. 2022
 *      Author: basti
 */

#include "Jeu.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

Jeu::Jeu(){
	tourdejeu = 1;  //on commence la préparation du jeu avec le compteur à 0
	nb_joueurs = 0;
	cout << "Combien y-a-t-il de joueurs ?" << endl;
	cin >> nb_joueurs; // On demande et enregistre le nombre de joueurs
	joueurs = new Joueur*[nb_joueurs];
}

// Le compteur s'incrémente à chaque appel, et reviens à 1 (premier joueur) après avoir appelé le dernier joueur.
int Jeu::compteur(){
	tourdejeu++; // Croit à chaque appel
	if (tourdejeu>nb_joueurs){ // Boucle entre [1 , nb_joueurs]
		tourdejeu=1;
	}
	return tourdejeu;
}

int Jeu::getNbjoueurs(){
	return nb_joueurs;
}

void Jeu::setNbjoueurs(int nb_joueurs){
	this->nb_joueurs = nb_joueurs;
}

void Jeu::setJoueurs(){
	int money = 5000; // argent de départ pour chaque joueur
	string nom;
	for(int i=0; i<nb_joueurs; i++) {
		cout << "Qui est le joueur " << i+1 << " ? " << endl; // Pour plus de clarté pour le joueur, on fait commencer le numéro des joueurs à 1 (donc décale tout de 1)
		cin >> nom;
		Joueur* j = new Joueur(i, money, nom, 0, 0); // On créé un nouvel objet Joueur pour chaque itération, que l'on met dans joueur[i]
		joueurs[i] = j;
		/*
		i correspond au numéro du pion associé au joueur (pour l'instant)
		0 car 0 gares et 0 compagnies au début*/
	}
}

Joueur** Jeu::getJoueurs(){
	return joueurs;
}

void Jeu::afficheJoueurs(){
	cout << "Liste des joueurs : " << endl;
	for(int i=0; i<nb_joueurs; i++) {
		cout << joueurs[i]->getNom() << endl; // Affiche le nom de l'élément i de la liste joueurs (donc nom du joueur i+1)
	}
	cout << "------------------" << endl;
}

// Retourne le nom du joueur qui doit jouer à ce tour
string Jeu::getJoueur_actuel(){
	return (*joueurs[tourdejeu-1]).getNom() ; // On prend l'élément tourdejeu-1 car le compteur commence à 1 (décalé de 1 à droite)
}

void Jeu::launchGame(Plateau* board) {
	setJoueurs();
	afficheJoueurs();
	for (int i=0; i<nb_joueurs; i++) {
		joueurs[i]->initCase(board);
	}
	int de;
	while (nb_joueurs > 1) {
		cout << "C'est au tour de " << joueurs[tourdejeu-1]->getNom() << " de jouer" << endl;
		Gobelet lancer = Gobelet();
		de = lancer.getValeur();
		cout << "Lancer de d� : " << de << endl;
		Case* from = joueurs[tourdejeu-1]->getCase();
		from->affiche();
		Case* landing = from->deplacement(joueurs[tourdejeu-1], de);
		landing->arreterSur(joueurs[tourdejeu-1], de);
		joueurs[tourdejeu-1]->setCase(landing);
		compteur();
	}
}

void Jeu::lireJoueurs(Plateau* board) {

	string* tab;
	ifstream monFlux("joueurs.txt");
	int i = 0;
	if(monFlux) {
		string ligne;
		while (getline(monFlux, ligne)) {
			i++;
		}
	}
	monFlux.close();
	tab = new string[i];
	nb_joueurs = i;

	ifstream flux("joueurs.txt");
	int j = 0;
	if(flux) {
		string ligne;
		while (getline(flux, ligne)) {
			tab[j] = ligne;
			j++;
		}
	}
	flux.close();

	for (int k=0; k<nb_joueurs; k++) {
		string ligneJoueur = tab[k];

		string sep = "-";
		vector<string> categ{};
		size_t pos;
		while ((pos = ligneJoueur.find(sep)) != string::npos) {
			categ.push_back(ligneJoueur.substr(0, pos));
			ligneJoueur.erase(0, pos + sep.length());
		}

		string name = categ[0];
		string id = categ[1];
		string cases = categ[2];
		string gares = categ[3];
		string cies = categ[4];
		string solde = categ[5];
		string current = categ[6];

		string sepg = ",";
		vector<string> numgares{};
		size_t posg;
		while ((posg = gares.find(sepg)) != string::npos) {
			numgares.push_back(gares.substr(0, posg));
			gares.erase(0, posg + sepg.length());
		}
		int Ngares = numgares.size();

		string sepc = ",";
		vector<string> numcies{};
		size_t posc;
		while ((posc = cies.find(sepc)) != string::npos) {
			numcies.push_back(cies.substr(0, posc));
			cies.erase(0, posc + sepc.length());
		}
		int Ncies = numcies.size();

		string sepca = ",";
		vector<string> numcases{};
		size_t posca;
		while ((posca = cases.find(sepca)) != string::npos) {
			numcases.push_back(cases.substr(0, posca));
			cases.erase(0, posca + sepca.length());
		}
		numcases.push_back(cases);

		Joueur* j = new Joueur(stoi(id), stoi(solde), name, Ngares, Ncies);
		joueurs[k] = j;

		vector<string>::iterator it;
		for (it=numcases.begin(); it!=numcases.end(); it++) {
			int numcase = stoi(*it);
			Case* ter = board->getCase(numcase);
			ter->affiche();
			(*((Terrain*)ter)).setJoueur(joueurs[k]);
		}
	}
}

void Jeu::lirePartie(Plateau* board) {
	lireJoueurs(board);
	afficheJoueurs();
	for (int i=0; i<nb_joueurs; i++) {
		joueurs[i]->initCase(board);
	}
	int de;
	while (nb_joueurs > 1) {
		cout << "C'est au tour de " << joueurs[tourdejeu-1]->getNom() << " de jouer" << endl;
		Gobelet lancer = Gobelet();
		de = lancer.getValeur();
		cout << "Lancer de d� : " << de << endl;
		Case* from = joueurs[tourdejeu-1]->getCase();
		from->affiche();
		Case* landing = from->deplacement(joueurs[tourdejeu-1], de);
		landing->arreterSur(joueurs[tourdejeu-1], de);
		joueurs[tourdejeu-1]->setCase(landing);
		compteur();
	}
}
