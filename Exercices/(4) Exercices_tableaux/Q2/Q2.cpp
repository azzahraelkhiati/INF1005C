/*
Écrire un programme qui initialise un tableau de 10 valeurs aléatoires et trouve la moyenne du tableau.

Auteur: Johnatan Gao
Date: 2019-10-07
*/

#include <iostream>;
#include <ctime>;
using namespace std;

int main() {

	srand((unsigned)time(nullptr)); //initialise the random number generator using time as seed

	const int TAILLE_TABLEAU = 10;
	double somme = 0;
	int tableau[TAILLE_TABLEAU];
	int element;

	for (int index = 0; index < TAILLE_TABLEAU; index++) {
		
		element = rand();
		tableau[index] = element;

		somme += element;

	}

	double moyenne = somme / TAILLE_TABLEAU;
	cout << moyenne;
}