//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//DESCRIPTION:	PROGRAMME QUI POSSEDE UNE FONCTION QUI A POUR BUT DE FAIRE LE CALCUL POUR TROUVER LES		//
//				DE NEWTON. ENSUITE, IL TESTE DANS LA FONCTION MAIN 4 PAIRES DE VALEURS POUR VERIFIER.		//
//																											//
//FILE:	  Exo4.cpp																							//
//AUTHOR: Johnatan Gao																						//
//DATE:   11 Septembre 2019																					//
//Cree:   11 Septembre 2019																					//
//																											//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cmath>
using namespace std;



double bin(double n, double k) {

	const int VALEUR_INITIALE = 1;
	double nombreBin = VALEUR_INITIALE;

	for (k; k < n; k++) {
		nombreBin *= (k + 1) / (n - k);
	}

	return ceil(nombreBin);
}

//for(int i = k

int main() {

	cout << boolalpha;
	cout << (252 == bin(10, 5)) << endl;
	cout << (10 == bin(5, 2)) << endl;
	cout << (126 == bin(9, 4)) << endl;
	cout << (5005 == bin(15, 9)) << endl;

	return 0;

}

