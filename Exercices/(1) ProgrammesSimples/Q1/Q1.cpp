/*
Écrire un programme qui lit un nombre réel, affiche sa racine carrée et sa valeur au cube.

Autheur: Johnatan Gao
Date: 2019-09-22
*/

#include <iostream>;
#include <cmath>;

using namespace std;

int main() {

	cout << "Entrer un nombre reel: ";
	double nbReel;

	cin >> nbReel;

	cout << "La racine carree de " << nbReel << " est de: " << sqrt(nbReel) << endl;
	cout << "La valeur au cube de " << nbReel << " est de: " << pow(nbReel, 3) << endl;

	return 0;
}