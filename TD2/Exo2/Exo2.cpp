//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//DESCRIPTION:	PROGRAMME QUI DEMANDE A L'UTILISATEUR D'ENTRER UNE VALEUR ENTIERE POSITIVE < 999, ENSUITE	//
//				IL VA AFFICHER A L'UTILISATEUR LE CHIFFRE A LA POSITION DES CENTAINES, DES DIZAINES ET DES	//
//				UNITES.																						//
//																											//																											//
//FILE:	  Exo2.cpp																							//
//AUTHOR: Johnatan Gao																						//
//DATE:   11 Septembre 2019																					//
//CREE:   11 Septembre 2019																					//
//																											//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

bool inRange(int nombreEntree); //Prototype => Fait en sorte que le programme connait l'existence de la fonction

int main() {

	int nombreEntree;
	

	cout << "Entrer un nombre entre 0 et 999" << endl;
	cin >> nombreEntree;

	while(!inRange(nombreEntree)) {
		cin.clear(); //Missing piece for it to work
		cout << "Vous devez entrer un nombre entre 0 et 999" << endl;
		cin >> nombreEntree;
	}
	
	if (inRange(nombreEntree)) {
		cout << "Nombre aux centaines: " << nombreEntree / 100 << endl;
		cout << "Nombre aux dizaines: " << (nombreEntree % 100) / 10 << endl;
		cout << "Nombre aux unites: " << (nombreEntree % 100) % 10 << endl;
	}
	

	return 0;

}

bool inRange(int nombreEntree) {

	if (nombreEntree < 0 || 
		nombreEntree > 999) {
		return false;
	}

	return true;

}