/*
Même question que la question 3 à l'aide d'un while et d'une variable booléene.

Auteur: Johnatan Gao
Date: 2019-09-22
*/

#include <iostream>

using namespace std;

int main() {

	const int MINIMUM = 0;
	const int MAXIMUM = 50;

	bool trouve = false;
	int nbEntree, nbEssais = 0;

	while (!trouve) {
	
		cout << "Entrer un nombre Aleatoire: ";
		cin >> nbEntree;

		if (nbEntree >= 0 && nbEntree <= 50) {
			trouve = true;
			cout << "Felicitation vous avez entrer un chiffre entre 0 et 50" << endl;
		}
		else {
		
			if (nbEntree < 0) {
				cout << "Trop petit" << endl;
			}
			else if (nbEntree > 50) {
				cout << "Trop grand" << endl;
			}
		}
	}


	return 0;
}