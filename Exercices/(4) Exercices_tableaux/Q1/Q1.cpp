/*
Écrire un programme qui initialise un tableau de 10 valeurs aléatoires et trouve la valeur maximum.

Auteur: Johnatan Gao
Date: 2019-09-23
*/

#include <iostream>
#include <ctime>

using namespace std;

int main() {

	srand(unsigned(time(nullptr))); //Do not use NULL since NULL is defined as 0
	const int TAILLE = 10;

	int tableau[TAILLE];

	int max = rand();
	tableau[0] = max;

	for (int index = 1; index < TAILLE; index++) {

		tableau[index] = rand();

		if (max < tableau[index]) {
			max = tableau[index];
		}
		
	}

	return 0;
}