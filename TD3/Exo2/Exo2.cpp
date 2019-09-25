/*
 Écrivez un programme qui permet de demander à l’utilisateur un entier n ≥
2 (le programme doit redemander si le nombre est inférieur, mais vous n’avez pas à vérifier que c’est
bien un entier) et indique si ce nombre est premier ou non. Le programme affiche aussi les diviseurs
de ce nombre s’il n’est pas premier. Vous devez résoudre l’exercice en utilisant une seule boucle et
respecter l’affichage de ces exemples.
Auteur: Johnatan Gao
Date: 2019-09-25

*/

#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

bool isPremier(int n, string* diviseurs);

int main() {

	cout << "Entrer un entier qui est plus grand ou egale a 2: ";
	int n;
	cin >> n;

	string diviseurs = "";

	if (isPremier(n, &diviseurs)) {
		cout << "Pour n = " << n << ": Le nombre " << n << " est premier." << endl;
	}
	else {
		cout << "Pour n = " << n << ": Le nombre " << n << " n'est pas premier." << endl << "Les diviseurs de " << n << " sont " << diviseurs;
	}

	return 0;
}

bool isPremier(int n, string* diviseurs) {

	bool isPremier = true;

	for (int diviseur = 2; diviseur < n; diviseur++) {


		if (n % diviseur == 0) {
			isPremier = false;
			diviseurs -> append(to_string(diviseur));
			diviseurs -> append(",");
		}

	}

	return isPremier;
}