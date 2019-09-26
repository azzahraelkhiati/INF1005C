/*
 Écrivez un programme qui permet de demander à l’utilisateur un entier n plus petit ou egale 2 (le programme doit redemander si le nombre est inférieur, mais vous n’avez pas à vérifier que c’est
bien un entier) et indique si ce nombre est premier ou non. Le programme affiche aussi les diviseurs
de ce nombre s’il n’est pas premier. Vous devez résoudre l’exercice en utilisant une seule boucle et
respecter l’affichage de ces exemples.

File: Exo2.cpp
Auteur: Johnatan Gao
Date: 2019-09-26
*/

#include <iostream>
#include <cmath>
#include <string>


using namespace std;

void verifierNombre(int diviseur, int n, string& diviseurs, bool& isPrime);
bool isSuperiorOrEqual(int nombreEntre, int nombreCompare);
void afficherResultat(bool isPrime, int n, string diviseurs);

int main() {

	const int VALEUR_INITIALE = INT_MIN;
	const int PREMIER_NOMBRE_PREMIER = 2;

	int n = VALEUR_INITIALE,
		diviseur = PREMIER_NOMBRE_PREMIER;

	bool boucleFini = false, isPrime = true;

	string diviseurs = "";

	do {

		if (!isSuperiorOrEqual(n, 2)) { //On va redemander a l'utilisateur de rentrer un nombre tq celui-ci est inferieur a 2
			cout << "Entrer un entier n superieur que 2: ";
			cin >> n;
		}
		else {

			verifierNombre(diviseur, n, diviseurs, isPrime); //On verifie si le nombre est divisible pas le diviseur
			diviseur += 1; //on increment le diviseur

			if (diviseur > n / 2) { //On termine la boucle si on depasse la moitie du n
				boucleFini = true;
			}
		}

	} while (!boucleFini);

	afficherResultat(isPrime, n, diviseurs); //On affiche le resultat de la boucle

	return 0;
}

void afficherResultat(bool isPrime, int n, string diviseurs) {

	if (isPrime) {
		cout << "Pour n = " << n << " : Le nombre " << n << " est premier.";
	}
	else {
		cout << "Pour n = " << n << " : Le nombre " << n << " n'est pas premier." << endl;
		cout << right << "Les diviseurs de " << n << " sont : " << diviseurs.substr(0, diviseurs.length() - 1);
	}
}


void verifierNombre(int diviseur, int n, string& diviseurs, bool& isPrime) {

	if (n % diviseur == 0) {
		diviseurs.append(to_string(diviseur));
		diviseurs.append(",");
		isPrime = false;
	}
}

bool isSuperiorOrEqual(int nombreEntre, int nombreCompare) {

	if (nombreEntre < nombreCompare) {
		return false;
	}
	return true;

}