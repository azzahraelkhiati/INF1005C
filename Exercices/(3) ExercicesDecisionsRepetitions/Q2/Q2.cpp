/*
Écrire un programme qui affiche 10 nombres aléatoires entre 34 et 56. Utiliser for.

Autheur: Johnatan Gao
Date: 2019-09-22
*/

#include <iostream>
#include <ctime>

using namespace std;

int main() {

	const unsigned int NOMBRE_NB_ALEATOIRES = 10;
	srand(time(NULL)); //Le seed va etre base sur le temps qui change constamment

	for (unsigned int index = 0; index < NOMBRE_NB_ALEATOIRES; index++) {
	
		cout << 34 + rand() % (56 - 34) << endl;
	
	}

	return 0;
}