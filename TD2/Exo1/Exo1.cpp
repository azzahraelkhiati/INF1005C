//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//DESCRIPTION:	PROGRAMME QUI DEMANDE A L'UTILISATEUR D'ENTRER DEUX VALEURS: UN VOLTAGE ET UNE RESISTANCE	//
//				POUR ENSUITE AFFICHER LA PUISSANCE DISSIPEE													//
//																											//
//FILE:	  Exo1.cpp																							//
//AUTHOR: Johnatan Gao																						//
//DATE:   11 Septembre 2019																					//
//CREE:   11 Septembre 2019																					//
//																											//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

int main() {

	//Initialisation des valeurs
	double voltage, resistance;

	//Entree de l'utilisateur pour le voltage
	cout << "Entrer un voltage (en volt)" << endl;
	cin >> voltage;

	//Entree de l'utilisateur pour la resistance
	cout << "Entrer une resistance (en ohms)" << endl;
	cin >> resistance;

	//Affichage de la puissance dissipee en watts
	cout << "La puissance dissipee est " << voltage * voltage / resistance << " watts";


	return 0;
}