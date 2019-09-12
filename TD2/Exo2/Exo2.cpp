//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//DESCRIPTION:	PROGRAMME QUI DEMANDE A L'UTILISATEUR D'ENTRER UNE VALEUR N STRICTEMENT POSITIVE, ENSUITE	//
//				IL VA DEMANDER A L'UTILISATEUR D'ENTRER UNE SUITE COMPOSEE DE N VALEUR(S). FINALEMENT, IL	//
//				VA RETOURNER LA LONGUEUR DE LA PLUS GRANDE SUITE CROISSANTE									//
//																											//																											//
//FILE:	  Exo2.cpp																							//
//AUTHOR: Johnatan Gao																						//
//DATE:   11 Septembre 2019																					//
//CREE:   11 Septembre 2019																					//
//																											//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

int main() {

	//Initialisation des variables
	int nombreElements;

	const int VALEUR_INITIALE = 0;

	int cptLongueur = VALEUR_INITIALE, 
		cptLongueurTmp = VALEUR_INITIALE, 
		nombreAvant = VALEUR_INITIALE;

	int nombreEntree;

	//Entree de l'utilisateur pour le nombre d'elements
	cout << "Entrer un entier n strictement positif: ";
	cin >> nombreElements;

	//Verifier si le nombre qui a ete entre est strictement positif
	while (nombreElements <= 0) {
		cout << "Vous devez entrer un entier STRICTMENT positif " << endl;
		cin >> nombreElements;
	}

	for (int indiceElement = VALEUR_INITIALE; indiceElement < nombreElements; indiceElement++) {
		cout << "Entrer un nombre faisant partie de la suite" << endl;
		cin >> nombreEntree;

		if (indiceElement == 0 || nombreEntree > nombreAvant) {
			cptLongueurTmp += 1;
		}
		else {
			if (cptLongueurTmp > cptLongueur) {
				cptLongueur = cptLongueurTmp;
			}

			cptLongueurTmp = 1;

		}

		nombreAvant = nombreEntree;
	}

	if (cptLongueurTmp > cptLongueur) {
		cptLongueur = cptLongueurTmp;
	}

	//Affichage de la longueur de la plus longue suite croissante
	cout << "La longueur de la plus longue suite croissante est " << cptLongueur << endl;

	return 0;

}