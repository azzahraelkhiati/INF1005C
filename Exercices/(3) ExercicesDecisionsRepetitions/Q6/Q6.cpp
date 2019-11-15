/*
Écrire un programme  qui affiche  un carré de 5 par 5 étoiles.

Author: Johnatan Gao
Date: 2019-09-22
*/

#include <iostream>

using namespace std;

int main() {

	const unsigned int HAUTEUR_CARREE = 5;

	for (int indexHauteur = 0; indexHauteur < HAUTEUR_CARREE; indexHauteur++) {
		
		for (int indexEtoile = 0; indexEtoile < HAUTEUR_CARREE; indexEtoile++) {
			
			cout << "*";

		}
		
		cout << endl;
	}

	return 0;
}