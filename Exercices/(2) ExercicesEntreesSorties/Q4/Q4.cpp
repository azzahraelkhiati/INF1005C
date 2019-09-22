/*
Écrire un programme qui lit les 7 lignes du fichier poeme.txt et les écrit dans un nouveau fichier nouveau.txt.

Autheur: Johnatan Gao
Date: 2019-09-22
*/

#include <iostream>
#include <string>
#include <fstream>
#include <ostream>
#include <vector>

using namespace std;

int main() {

	ifstream file("poeme.txt");

	string line;
	vector<string> texte;

	while (getline(file, line)) {
		texte.push_back(line);
	}

	file.close();

	ofstream output("nouveau.txt");

	for (int n = 0; n < texte.size(); n++) {
		output << texte[n] << endl;
	}

	output.close();

	return 0;
}