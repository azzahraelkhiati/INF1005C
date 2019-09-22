/*
Soit le fichier valeurs.txt qui contient 4 valeurs
10 34.8 56.3 8.4
Écrire un programme qui lit les 4 valeurs du fichier valeurs.txt et les écrit dans un nouveau fichier nouvelles.txt

Autheur: Johnatan Gao
Date: 2019-09-22
*/

#include <iostream>
#include <fstream>
#include <ostream>
#include <vector>

using namespace std;

int main() {

	ifstream fichierLu("valeurs.txt");
	vector <double> listeValeurs;

	double valeur;

	while (fichierLu >> valeur) {
		listeValeurs.push_back(valeur);
	}

	ofstream fichierSortie("nouvelles.txt");

	for (int n = 0; n < listeValeurs.size(); n++) {
		fichierSortie << listeValeurs[n] << " "; //Le dernier est pour ajouter des espaces
	}

	return 0;
}