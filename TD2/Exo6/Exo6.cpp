//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//DESCRIPTION:	PROGRAMME QUI DEMANDE A L'UTILISATEUR D'ENTRER UN NOMBRE QUI REPRSENTE LA HAUTEUR DU		//
//				TRIANGLE DONT LE PROGRAMME VA AFFICHER														//
//																											//
//FILE:	  Exo6.cpp																							//
//AUTHOR: Johnatan Gao																						//
//DATE:   11 Septembre 2019																					//
//Cree:   11 Septembre 2019																					//
//																											//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main() {

	const int POSITION_LIGNE_INITIALE = 1;
	const int VALEUR_INITIALE_INDICE = 0;
	
	int hauteur, positionLigne, indice;

	ifstream myFile;
	myFile.open("hauteur.txt");

	if (myFile.is_open()) {

		myFile >> hauteur;
		myFile.close();
	}
	else {

		cout << "Impossible d'ouvrir le fichier" << endl;
	}

	ofstream triangleFile;
	triangleFile.open("triangle.txt");


	positionLigne = POSITION_LIGNE_INITIALE;
	while (positionLigne <= hauteur) {

		indice = VALEUR_INITIALE_INDICE;

		while (indice < hauteur - positionLigne) {
			triangleFile << " ";
			indice += 1;
		}

		indice = VALEUR_INITIALE_INDICE;

		while (indice < 2 * positionLigne - 1) {
			triangleFile << "*";
			indice += 1;
		}

		triangleFile << endl;
		positionLigne += 1;

	}

	triangleFile.close();

	return 0;
}
	
	