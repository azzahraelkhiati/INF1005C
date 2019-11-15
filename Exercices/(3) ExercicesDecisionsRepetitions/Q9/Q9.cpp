/*
Soit un fichier contenant une série de valeurs entières
12 56 3 5 6 90 45.
Écrire un programme qui demande à l'usager le nom du fichier et détermine le nombre de valeurs entières.

Auteur: Johnatan Gao
Date: 2019-09-22
*/

#include <iostream>;
#include <fstream>;
#include <ostream>;
#include <string>;
#include <ctime>;

using namespace std;

int main() {

	ofstream nouveauFichier;
	int nbValeursEntieres;

	do {
		cout << "Entrer le nom du fichier: ";
		string nomFichier;
		getline(cin, nomFichier);

		nouveauFichier.open(nomFichier);

	} while (nouveauFichier.fail());
	
	do {
		cout << "Entrer le nombre de valeurs entieres: ";
		cin >> nbValeursEntieres;
	} while (cin.fail());

	srand(time(NULL));
	
	for (int indexNb = 0; indexNb < nbValeursEntieres; indexNb++) {
		nouveauFichier << rand() << " ";
	}

	nouveauFichier.close();

	return 0;
}