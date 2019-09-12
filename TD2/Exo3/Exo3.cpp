//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//DESCRIPTION:	PROGRAMME QUI DEMANDE A L'UTILISATEUR D'ENTRER UN MOT, UNE LETTRE ET UN ENTIER POSITIF N ET	// 																
//				VA ENSUITE AFFICHER LE NOMBRE DE FOIS QUE CETTE LETTRE APPARAIT DANS LE MOT A PARTIR DE LA	//
//				POSITION N																					//
//																											//																											//
//FILE:	  Exo3.cpp																							//
//AUTHOR: Johnatan Gao																						//
//DATE:   11 Septembre 2019																					//
//Cree:   11 Septembre 2019																					//
//																											//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
using namespace std;

int main() {

	const int VALEUR_INITIALE = 0;
	string mot;
	char lettre;
	int position;

	int nombreLettre = VALEUR_INITIALE;

	cout << "Entrer un mot: " << endl;
	getline(cin, mot); //Cela accepte les espaces aussi

	cout << "Entrer une lettre" << endl;
	cin >> lettre;

	cout << "Entrer un entier n" << endl;
	cin >> position;

	for (position; position < mot.length(); position++) {
		if (mot[position] == lettre) {
			nombreLettre += 1;
		}
	}

	cout << "Le nombre de " << lettre << " dans " << mot << " est de : " << nombreLettre;


	return 0;
}