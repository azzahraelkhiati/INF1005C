#include "jeu.hpp"

int faireMarcherVoyageur(const char carte[HAUTEUR][LARGEUR], int& positionX, int& positionY) {
	//#error Commenter cette ligne pour compiler ce fichier.
	//TODO: Tant que le voyageur peut marcher:
	
	//TODO:   D�placer le voyageur du prochain d�placement � faire.
	//TODO:   Afficher la carte
	//TODO:   Compter le nombre de d�placements non nuls.
	//TODO: La valeur de retour doit �tre le nombre de d�placements, et positionX et positionY doivent avoir la position finale du voyageur (� la position o� il ne peut plus marcher).
	
	int deltaX = 0, deltaY = 0;
	int nbDeplacement = 0;

	int positionInitX = positionX;
	int positionInitY = positionY;

	while (positionX >= 0 && positionY >= 0 && positionX < LARGEUR && positionY < HAUTEUR) {

		//Demande les prochains deplacement
		prochainDeplacement(deltaX, deltaY);

		//Modifiy the positions 
		if (deltaX != -100 && deltaY != -100) {
			positionX += deltaX;
			positionY += deltaY;
			afficherCarte(carte, positionX, positionY);

			nbDeplacement += abs(deltaX);
			nbDeplacement += abs(deltaY);

		}
		else {
			break;
		}

	}
	

	return nbDeplacement;
}

//----------------------------------------------------------------------------

void test_faireMarcherVoyageur() {
	cerr << "Test faireMarcherVoyageur:";
	cerr << endl;
	// D�commenter/commenter pour faire des tests � la main ou pas:
	char carte[HAUTEUR][LARGEUR];
	lireCarte("montreal.txt", carte);
	int positionX, positionY; cout << "Entrer position X Y: "; cin >> positionX >> positionY;
	cout << faireMarcherVoyageur(carte, positionX, positionY) << " deplacements, ";
	cout << "position finale " << positionX << ", " << positionY << endl;

	// Tests automatis�s:
	{
	char carte[HAUTEUR][LARGEUR];
	for (int i = 0; i < HAUTEUR; i++) {
		for (int j = 0; j < LARGEUR && j < i; j++)
			carte[i][j] = 'T';
		for (int j = i; j < LARGEUR; j++)
			carte[i][j] = 'E';
	}
	
	int nDeplacements, x, y;
	
	x = 0; y = 2;
	int deplacements1[][2] = {
		{ 1, 0 },
		{ 0, 1 },
		{ 1, 0 },
		{ 1, 0 }
	};
	fixerListeDeDeplacement(deplacements1, 4);
	simulerCinCout(CIN_INTERDIT);
	TESTER( nDeplacements = faireMarcherVoyageur(carte, x, y); )
	ESPERE_EGALITE(nDeplacements, 4);
	ESPERE_EGALITE(x, 3);
	ESPERE_EGALITE(y, 3);
	verifieCout(
		",*~~~~~~~~~~~~~~~~\n"
		",*,~~~~~~~~~~~~~~~\n"
		",,*~~~~~~~~~~~~~~~\n"
		",,,*~~~~~~~~~~~~~~"
		);
	
	x = 0; y = 2;
	int deplacements2[][2] = {
		{ 1, 0 },
		{ 0, 1 },
		{ 0, 0 },
		{ 1, 0 },
		{ 1, 0 }
	};
	fixerListeDeDeplacement(deplacements2, 5);
	simulerCinCout(CIN_INTERDIT);
	TESTER( nDeplacements = faireMarcherVoyageur(carte, x, y); )
	ESPERE_EGALITE(nDeplacements, 4);
	verifieCout(
		",*~~~~~~~~~~~~~~~~\n"
		",*,~~~~~~~~~~~~~~~\n"
		",*,~~~~~~~~~~~~~~~\n"
		",,*~~~~~~~~~~~~~~~\n"
		",,,*~~~~~~~~~~~~~~"
		);

	x = 0; y = 3;
	int deplacements3[][2] = {
		{ 1, 0 },
		{ -1, 0 },
		{ -1, 0 }
	};
	fixerListeDeDeplacement(deplacements3, 3);
	simulerCinCout(CIN_INTERDIT);
	TESTER( nDeplacements = faireMarcherVoyageur(carte, x, y); )
	ESPERE_EGALITE(nDeplacements, 3);
	verifieCout(
		",*,~~~~~~~~~~~~~~~\n"
		"*,,~~~~~~~~~~~~~~~\n"
		",,,~~~~~~~~~~~~~~~"
		);
	ESPERE_EGALITE(x, -1);
	ESPERE_EGALITE(y, 3);

	fixerDeplacementInteractif();
	
	affichageStatistiquesTests();
	}
}
