//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//DESCRIPTION:	PROGRAMME QUI DEMANDE A L'UTILISATEUR D'ENTRER UN NOMBRE QUI REPRSENTE LA HAUTEUR DU		//
//				TRIANGLE DONT LE PROGRAMME VA AFFICHER														//
//																											//
//FILE:	  Exo7.cpp																							//
//AUTHOR: Johnatan Gao																						//
//DATE:   11 Septembre 2019																					//
//Cree:   11 Septembre 2019																					//
//																											//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

int main() {

	int hauteur, positionLigne, indice;
	const int POSITION_LIGNE_INITIALE = 1;
	const int VALEUR_INITIALE_INDICE = 0;

	cout << "Entrer la hauteur du triangle" << endl;
	cin >> hauteur;

	positionLigne = POSITION_LIGNE_INITIALE;
	
	while (positionLigne <= hauteur) {
		
		indice = VALEUR_INITIALE_INDICE;

		while (indice < hauteur - positionLigne) {
			cout << " ";
			indice += 1;
		}

		indice = VALEUR_INITIALE_INDICE;

		while (indice < 2 * positionLigne - 1) {
			cout << "*";
			indice += 1;
		}

		cout << endl;
		positionLigne += 1;
		
	}


}