/*
Écrire un programme qui ouvre un fichier et le ferme.

Autheur: Johnatan Gao
Date: 2019-09-22
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {

	ifstream file("text.txt");
	string text;

	while (getline(file, text)) {
		cout << text << endl;
	};

	file.close();

	return 0;
}