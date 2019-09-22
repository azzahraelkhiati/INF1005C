/*
Écrire un programme qui lit les 7 lignes du fichier poeme.txt ci dessus et affiche la troisième ligne.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int main() {

	ifstream poeme("poeme.txt");

	vector<string> arr;
	string ligne;

	while (getline(poeme, ligne)) {
		arr.push_back(ligne);
	}

	arr.shrink_to_fit();

	cout << "La troisieme ligne du poeme est: " << arr[2]; //L'index est 2, car on commence a 0

	return 0;
}