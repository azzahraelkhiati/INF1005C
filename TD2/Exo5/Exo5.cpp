//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//DESCRIPTION:	PROGRAMME QUI DEMANDE A L'UTILISATEUR D'ENTRER UN TEXTE ET LE PROGRAMME VA AFFICHER LA		//
//				POSITION DE LA PREMIERE INSTANCE DE "INF" DANS LE TEXTE, PUIS IL VA AFFICHER LA M�ME PHRASE	//
//				MAIS EN REMPLA�ANT INF PAR LOG.																//
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


	string texte;
	int position;

	cout << "Entrer une phrase: ";
	getline(cin, texte);

	position = texte.find("INF");

	if (position == -1) {
		cout << "Ne s'y trouve pas" << endl;
	}
	else {
		cout << "La position de INF dans le texte est : " << position << endl;
		texte.replace(position, 3 , "LOG");
		cout << texte << endl;
	}

	

	

	return  0;

}
