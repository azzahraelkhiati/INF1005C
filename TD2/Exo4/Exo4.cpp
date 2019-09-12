//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//DESCRIPTION:	PROGRAMME QUI DEMANDE A L'UTILISATEUR D'ENTRER DEUX NOMBRE (N ET K). ENSUITE IL VA FAIRE	//
//				LE CALCUL POUR TROUVER LES BINOMES DE NEWTON EN UTILISANT UNE FONCTION BIN(N,K)				//
//																											//
//FILE:	  Exo4.cpp																							//
//AUTHOR: Johnatan Gao																						//
//DATE:   11 Septembre 2019																					//
//Cree:   11 Septembre 2019																					//
//																											//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

const int VALEUR_INITIALE = 1;

double bin(double n, double k) {

	double nombreBin = VALEUR_INITIALE;

	while (k < n) {
		
		nombreBin *= (k + 1) / (n - k);
		k += 1;
	
	}

	return nombreBin;
}


int main() {

	double n, k;

	cout << "Entrer un nombre n (le degre du polynome)" << endl;
	cin >> n;

	cout << "Entrer un nombre k (le coefficient)" << endl;
	cin >> k;

	while (k<0 || k >n) {
		cout << "Entrer un nombre k >= 0 et k <= n" << endl;
		cin >> k;
	}
	
	cout << bin(n, k) << endl;

	return 0;

}

