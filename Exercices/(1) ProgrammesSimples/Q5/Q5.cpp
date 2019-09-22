/*
Écrire un programme qui affiche un nombre aléatoire entre 0 et 4

Autheur: Johnatan Gao
Date: 2019-09-22
*/

#include <iostream>;
#include <ctime>

using namespace std;

int main() {

	srand(time(NULL));

	for (unsigned int i = 0; i < 100; i++) {
		cout << "Le nombre aleatoire entre 0 et 4 est: " << rand()%5 << endl;
	}

	return 0;
}