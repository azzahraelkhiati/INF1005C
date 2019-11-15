/*
Écrire un programme qui affiche le nombre d'occurrences de chacune des lettres suivantes 'a', 'e','i',
d'une phrase. Utiliser un case.

Auteur: Johnatan Gao
Date: 2019-09-22
*/

#include <iostream>
#include <string>

using namespace std;

template<class InputIterator, class Function>
Function for_each(InputIterator first, InputIterator last, Function fn)
{
	while (first != last) {
		fn(*first);
		++first;
	}
	return fn;      // or, since C++11: return move(fn);
}

int main() {

	string phrase;

	cout << "Entrer une phrase: ";
	getline(cin, phrase);

	for_each(phrase.begin(), phrase.end(), [](char& c) {
		c = ::tolower(c);
		});

	int cptA = 0, cptE = 0, cptI = 0;

	for (unsigned int indexCaractere = 0; indexCaractere < phrase.length(); indexCaractere++) {
		
		switch (phrase[indexCaractere]) {
		
		case 'a': 
			cptA++; 
			break;

		case 'e': 
			cptE++; 
			break;
		
		case 'i':
			cptI++;
			break;

		}

	}

	cout << "Le nombre de a est: " << cptA << endl;
	cout << "Le nombre de e est: " << cptE << endl;
	cout << "Le nombre de i est: " << cptI << endl;

	return 0;
}