/*
Même question que la question 3, mais avec un do..while.

Auteur: Johnatan Gao
Date: 2019-09-22
*/

#include <iostream>

using namespace std;

int main() {

	const int MINIMUM = 0;
	const int MAXIMUM = 50;

	int nbEssais = 0;
	int nbEntree;

	do {

		cout << "Entrer un nombre aleatoire: ";
		cin >> nbEntree;
		cin.clear();
		nbEssais++;

		if (nbEntree < MINIMUM) {
			cout << "Trop petit" << endl;
		}
		else if (nbEntree > MAXIMUM) {
			cout << "Trop grand" << endl;
		}
		else {
			cout << "Felicitation vous avez entree un nombre entre 0 et 50" << endl;
		}

		cout << "Le nombre d'essais est de: " << nbEssais << endl;

	} while (nbEntree < MINIMUM || nbEntree > MAXIMUM);

	return 0;
}