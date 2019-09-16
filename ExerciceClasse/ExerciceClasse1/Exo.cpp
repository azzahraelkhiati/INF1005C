#include <iostream>
#include <string>
using namespace std;

int main() {

	cout << "Entrer un entier: ";
	int entier;
	cin >> entier;

	cout << "Entrer un caractere: ";
	char caractere;
	cin >> caractere;

	cout << "Entrer un reel: ";
	double reel;
	cin >> reel;

	/*
	Sans le ignore, le programme va continuer a lire suite a la lecture du reel (getline => skip)
	*/

	cin.ignore(); 

	cout << "Entrer une phrase: ";
	string phrase;
	getline(cin, phrase);

	cout << "Entrer un mot: ";
	string mot;
	cin >> mot;

	cout << entier << endl << caractere << endl << reel << endl << phrase << endl << mot << endl;

	return 0;
}