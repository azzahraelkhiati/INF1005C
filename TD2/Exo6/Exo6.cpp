//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//DESCRIPTION:	PROGRAMME QUI DEMANDE A L'UTILISATEUR D'ENTRER DEUX NOMBRES ET IL VA AFFICHER LE PPCM DE	//
//				CES DEUX NOMBRES EN UTILISANT UNE FONCTION PPCM(n1,n2).										//
//																											//
//FILE:	  Exo6.cpp																							//
//AUTHOR: Johnatan Gao																						//
//DATE:   11 Septembre 2019																					//
//Cree:   11 Septembre 2019																					//
//																											//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

const int VALEUR_INITIAL = 1;

int ppcm(int n1, int n2) {
	
	bool ppcmTrouve = false;
	int multiple = VALEUR_INITIAL;

	while (!ppcmTrouve) {
		
		if ((n1 * multiple) % n2 == 0) {
			ppcmTrouve = true;
		}
		else {
			multiple += 1;
		}
	
	}

	return n1 * multiple;

}


int main() {
	
	int n1, n2;

	cout << "Entrer un nombre n1: " << endl;
	cin >> n1;

	cout << "Entrer un nombre n2: " << endl;
	cin >> n2;

	cout << "Le ppcm de " << n1 << " et de " << n2 << " est de: " << ppcm(n1,n2) << endl;
}