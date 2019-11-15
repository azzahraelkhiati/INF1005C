/*
Écrire un programme qui lit 2 chaînes de caractères et affiche la première et la dernière lettre des deux chaînes.

Autheur: Johnatan Gao
Date: 2019-09-22
*/

#include <iostream>;
#include <string>;

using namespace std;

int main() {

	const unsigned int NB_CHAINE = 2;

	string tableauChaine[NB_CHAINE];

	for (unsigned int indexChaine = 0; indexChaine < NB_CHAINE; indexChaine++) {
	
		cout << "Entrer une chaine de caractere: ";
		getline(cin, tableauChaine[indexChaine]);
	
	}

	for (unsigned int indexChaine = 0; indexChaine < NB_CHAINE; indexChaine++) {
		
		cout << "La premiere lettre de \"" << tableauChaine[indexChaine] << "\" est: " << tableauChaine[indexChaine][0] << endl;
		cout << "La derniere lettre de \"" << tableauChaine[indexChaine] << "\" est: " << tableauChaine[indexChaine][tableauChaine[indexChaine].length() - 1] << endl;
	
	}



	return 0;
}