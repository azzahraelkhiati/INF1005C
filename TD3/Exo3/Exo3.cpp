/*
 Écrivez un programme qui permet de demander à l’utilisateur
de saisir une chaine de caractère chaine et un nombre n dans l’intervalle [1..longueur (chaine)] et une
valeur booléenne. Suivant la valeur booléenne saisie le programme effectue une rotation de n
caractères en les déplaçant vers la droite ou vers la gauche. La rotation doit être effectuée dans une
fonction séparée, qui ne fait ni lecture du clavier ni affichage à l’écran.

File: Exo3.cpp
Auteur: Johnatan Gao
Date: 2019-09-26
*/

#include <iostream>
#include <string>

using namespace std;

string rotate(string chaine, int n, string val);

int main() {

	cout << "Entrer une chaine de caractere: " << endl;
	string chaine;

	getline(cin, chaine);

	cout << "Entrer un nombre n qui est plus grand ou egale a 1 et inferieur ou egale a la longueur de la chaine : ";
	int n;

	cin >> n;

	cout << "Entrer une valeur booleenne : (true pour la droite ou false pour la gauche) ";
	string val;
	cin >> val;

	string resultat = rotate(chaine, n, val);

	cout << "Le resultat = " << resultat;


	return 0;
}

string rotate(string chaine, int n, string val) {
	
	for (int nbCaractere = 0; nbCaractere < n; nbCaractere++) {
	
		if (val == "true" || val == "1") { //si bool est vrai, alors on rotate a partir de la droite vers la gauche

			char caractere = chaine[chaine.length() - 1];
			chaine.erase(chaine.length() - 1); //Enleve le dernier caractere
			chaine.insert(0, 1, caractere ); //Insert le caractere a la premiere position

		}
		else if (val == "false" || val == "0") { //si bool est faux, alors on rotate a partir de la gauche vers la droite
	
			char caractere = chaine[0]; //On prend le premier caractere
			chaine.replace(0, 1, "");
			chaine.push_back(caractere);
	
		}

	}

	
	return chaine;


}