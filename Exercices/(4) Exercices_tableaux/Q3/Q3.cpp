/*
Complétez le code suivant afin de copier tous éléments de tab1 inférieurs à un certain seuil, dans tab2.
Indice: la taille de tab2 doit être égale à celle de tab1 moins le nombre d'éléments non copiés.

Auteur: Johnatan Gao
Date: 2019-10-07
*/

#include <iostream>
#include <cstdlib> // Pour rand()
#include <ctime>
using namespace std;

int main()
{
	int tab1[100], tab2[100];
	unsigned int taille1, taille2, seuil;

	cout << "Entrez une taille inferieure a 100: " << endl;
	cin >> taille1;
	while (taille1 >= 100) {
		cout << "Taille invalide! Entrez une taille inferieure a 100: " << endl;
		cin >> taille1;
	}

	cout << "Entrez un seuil inferieur a 100" << endl;
	cin >> seuil;
	while (seuil >= 100) {
		cout << "Seuil invalid! Entrez un seuil inferieur a 100: " << endl;
		cin >> seuil;
	}

	// Le tableau est rempli de manière aléatoire avec des valeurs entre 0 et 99
	srand(time(0));
	for (int i = 0; i < taille1; i++) {
		tab1[i] = rand() % 100;
	}

	// À compléter



	// Affichage des deux tableaux
	for (int i = 0; i < taille1; i++) {
		cout << tab1[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < taille2; i++) {
		cout << tab2[i] << " ";
	}
	cout << endl;

}