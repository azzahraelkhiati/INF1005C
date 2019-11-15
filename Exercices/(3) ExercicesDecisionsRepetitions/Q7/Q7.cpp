/*
 Écrire un programme qui affiche un triangle d'`étoiles

 Auteur: Johnatan Gao
 Date: 2019-09-22
*/

#include <iostream>

using namespace std;

int main() {

	const int HAUTEUR_TRIANGLE = 5;
	int nbEtoiles;

	for (unsigned int indexHauteur = 0; indexHauteur < HAUTEUR_TRIANGLE; indexHauteur++) {
		
		nbEtoiles = indexHauteur + 1;
		for (unsigned int indexEtoile = 0; indexEtoile < nbEtoiles; indexEtoile++) {
			cout << "*";
		}

		cout << endl;
	
	}

	return 0;
}