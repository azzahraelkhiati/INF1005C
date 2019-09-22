/*
Écrire un programme qui lit un entier, un caractère, un réel, une phrase, un mot et ensuite affiche ces valeurs.

Autheur: Johnatan Gao
Date: 2019-09-22
*/

#include <iostream>
#include <string>

using namespace std;

int main(){

	cout << "Entrer un entier: ";
	int entier;
	cin >> entier;

	cout << endl;

	cout << "Entrer un caractere: ";
	char caractere;
	cin >> caractere;

	cout << endl;

	cout << "Entrer un reel: ";
	double reel;
	cin >> reel;

	cout << endl;

	cin.ignore();

	cout << "Entrer une phrase: ";
	string phrase;
	getline(cin, phrase);

	cout << endl;

	cout << "Entrer un mot: ";
	string mot;
	cin >> mot;

	cout << endl;

	cout << "L'entier est: " << entier << endl;
	cout << "Le caractere est: " << caractere << endl;
	cout << "Le reel est: " << reel << endl;
	cout << "La phrase est: " << phrase << endl;
	cout << "Le mot est: " << mot << endl;

	return 0;
}