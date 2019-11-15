#include "jeu.hpp"

bool verifierPeutMarcher(const char carte[HAUTEUR][LARGEUR], const int positionX, const int positionY) {
	//#error Commenter cette ligne pour compiler ce fichier.
	//TODO: Le voyageur ne peut pas marcher (la fonction retourne faux) si les coordonnées sont à l'extérieur de la carte ou la case dans le tableau est de l'eau.

	if (positionX < 0 || positionY < 0 || positionX >= LARGEUR || positionY >= HAUTEUR) {
		return false;
	}

	if (carte[positionY][positionX] == EAU) {
		return false;
	}


	return true;

}

//----------------------------------------------------------------------------

void test_verifierPeutMarcher() {
	cerr << "Test verifierPeutMarcher:";
	cerr << endl;
	// Décommenter/commenter pour faire des tests à la main ou pas:
	// char carte[HAUTEUR][LARGEUR];
	 //for (int i = 0; i < HAUTEUR; i++) for (int j = 0; j < LARGEUR; j++) carte[i][j] = 'T';
		
	 //int x,y; cout << "Entrer X Y: "; cin >> x >> y;
	 //cout << verifierPeutMarcher(carte, x, y) << endl;

	// Tests automatisés:
	{
	char carte[HAUTEUR][LARGEUR];
	for (int i = 0; i < HAUTEUR; i++)
		for (int j = 0; j < LARGEUR; j++)
			carte[i][j] = 'T';
	carte[0][0] = 'M';
	carte[1][2] = 'E';
	
	simulerCinCout(CIN_INTERDIT, COUT_INTERDIT);

	ESPERE_EGALITE(verifierPeutMarcher(carte, 0, 0), true);
	ESPERE_EGALITE(verifierPeutMarcher(carte, LARGEUR-1, 0), true);
	ESPERE_EGALITE(verifierPeutMarcher(carte, 0, HAUTEUR-1), true);
	ESPERE_EGALITE(verifierPeutMarcher(carte, LARGEUR-1, HAUTEUR-1), true);
	
	ESPERE_EGALITE(verifierPeutMarcher(carte, 2, 1), false);
	
	ESPERE_EGALITE(verifierPeutMarcher(carte, -1, 0), false);
	ESPERE_EGALITE(verifierPeutMarcher(carte, 0, -1), false);
	ESPERE_EGALITE(verifierPeutMarcher(carte, LARGEUR, 0), false);
	ESPERE_EGALITE(verifierPeutMarcher(carte, 0, HAUTEUR), false);
	
	affichageStatistiquesTests();
	}
}
