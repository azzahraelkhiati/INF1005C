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
#include <string>
#include <typeinfo>
using namespace std;


int main() {

	int nombreEntree;
	string nombre;

	cout << "Entrer un nombre entre 0 et 999" << endl;
	cin >> nombreEntree;

	nombre = to_string(nombreEntree);

	while (nombre.length() > 3) {

		cout << "Entrer un nombre entre 0 et 999" << endl;
		cin >> nombreEntree;

		nombre = to_string(nombreEntree);
	
	}
		if (nombre.length() == 3) {
			cout << "Nombre aux centaines: " << nombre[0] << endl;
			cout << "Nombre aux dizaines: " << nombre[1] << endl;
			cout << "Nombre aux unites: " << nombre[2] << endl;
		}
		else if (nombre.length() == 2) {
			cout << "Nombre aux centaines: 0" << endl;
			cout << "Nombre aux dizaines: " << nombre[0] << endl;
			cout << "Nombre aux unites: " << nombre[1] << endl;
		}
		else {
			cout << "Nombre aux centaines: 0" << endl;
			cout << "Nombre aux dizaines: 0" << endl;
			cout << "Nombre aux unites: " << nombre[0] << endl;
		}


	return 0;

}