/*
Écrire un programme qui vérifie si un nombre donné par l'usager est compris entre 10 et 30. Utiliser if.

Autheur: Johnatan Gao
Date: 2019-09-22
*/

#include <iostream>

using namespace std;

bool inRange(unsigned int nb);

int main() {

	cout << "Entrer un nombre qui est compris entre 10 et 30: ";
	unsigned int nb;
	cin >> nb;
	
	while (!inRange(nb) || cin.fail()) {

		cout << "Vous devez entrer un nombre qui est entre 10 et 30: ";
		cin.clear();

		cin >> nb;
	}

	cout << "Le nombre entre est: " << nb << endl;

	return 0;
}

bool inRange(unsigned int nb) {
	
	if (nb > 30 || nb < 10) {
		return false;
	}

	return true;

}