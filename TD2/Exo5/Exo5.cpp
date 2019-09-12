//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//DESCRIPTION:	PROGRAMME QUI DEMANDE A L'UTILISATEUR D'ENTRER UN TEXTE ET LE PROGRAMME VA AFFICHER LA		//
//				POSITION DE LAPREMIERE INSTANCE DE "INF" DANS LE TEXTE										//
//																											//
//FILE:	  Exo5.cpp																							//
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

	string texte;
	int positionTexte = VALEUR_INITIALE;

	cout << "Entrer une phrase: " << endl;
	getline(cin, texte);

	while (positionTexte + 2 < texte.length()) {
		
		if(texte[positionTexte] == 'I' && texte[positionTexte+1] == 'N' && texte[positionTexte + 2] == 'F'){
			cout << "La position de INF est: " << positionTexte << endl;
			break;
		}
		else {
		
			if (positionTexte >= texte.length() - 2) {
				cout << "Ne s'y trouve pas";
			}

			positionTexte += 1;
		
		}
	
	}

	return  0;

}
