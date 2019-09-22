/*
Écrire un programme à l'aide d'une boucle while afin que l'usager trouve un nombre aléatoire entre [0,50]. 
Le programme doit guider l'usager à trouver ce nombre en donnant les informations suivantes: trop grand, trop petit. 
Afficher le nombre d'essais.

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

	cout << "Entrer un nombre aleatoire: ";
	cin >> nbEntree;

	while (nbEntree < 0 || nbEntree > 50) {
	
		if (nbEntree < 0) {
			cout << "Trop petit" << endl;
		}
		else if (nbEntree > 50) {
			cout << "Trop grand" << endl;
		}
		
		cout << "Entrer un nombre aleatoire: ";
		cin >> nbEntree;

	}

	cout << "Felication vous avez entrer un nombre entre 0 et 50";

	return 0;
}