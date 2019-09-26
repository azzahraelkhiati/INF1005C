/*
�crivez un programme qui demande � un premier utilisateur de saisir un entier que le
second doit deviner. Le deuxi�me joueur a le droit � autant de tentatives qu�il souhaite. A chaque
�chec, le programme lui indique si l�entier cherch� est plus grand ou plus petit que sa proposition. Le
programme affiche � la fin le nombre de tentatives �coul�s pour deviner ce nombre.

File: Exo4.cpp
Auteur: Johnatan Gao
Date: 2019-09-26
*/

#include <iostream>

using namespace std;

int main() {

	cout << "Entrer un entier n que le second joueur doit deviner: ";
	int nbADeviner;
	int nbRentree;
	int nbTentative = 0;

	bool devine = false;

	cin >> nbADeviner;
	
	for (int nbEspace = 0; nbEspace < 50; nbEspace++) { //Pour creer des espaces
		cout << endl;
	}

	do {
	
		cout << "Entrer le nombre que vous pensez que c'est bon: ";
		cin >> nbRentree;

		if (nbRentree == nbADeviner) {
			devine = true;
			cout << "Felication le nombre etait: " << nbADeviner << endl;
			cout << "Nombre de tentative est de: " << nbTentative;
		}
		else {
		
			if (nbRentree < nbADeviner) {
				cout << "Trop petit" << endl;
			}
			else {
				cout << "Trop grand" << endl;
			}

			nbTentative += 1;
		
		}

	} while (!devine);


	return 0;
}