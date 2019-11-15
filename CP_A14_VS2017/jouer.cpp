#include "jeu.hpp"

// Les fonctions déjà écrites:

int main() {
	test_tout();
	
	char carte[HAUTEUR][LARGEUR];
	lireCarte("montreal.txt", carte);
	
	int positionX = 10, positionY = 5;
	cout << "Vous pouvez vous promener sur la carte suivante:" << endl;
	afficherCarte(carte, positionX, positionY);
	//int nDeplacements = faireMarcherVoyageur(carte, positionX, positionY);
	//cout << "Le voyageur a fait " << nDeplacements << " deplacements." << endl;
	//cout << "Sa position finale est " << positionX << ", " << positionY << endl;
}

void afficherCarte(const char carte[HAUTEUR][LARGEUR], const int positionX, const int positionY) {
	cout << endl;
	for (int y = 0; y < HAUTEUR; y++) {
		for (int x = 0; x < LARGEUR; x++) {
			if (x == positionX && y == positionY)
				cout << "*";
			else {
				switch (carte[y][x]) {
				case TERRE:    cout << ","; break;
				case MONTAGNE: cout << "M"; break;
				case EAU:      cout << "~"; break;
				}
			}
		}
		cout << endl;
	}
}

const int (*listeDeplacements)[2];
int nDeplacementsDansListe = 0;
int indexDuProchainDeplacement = -1;

void prochainDeplacement(int& deltaX, int& deltaY) {
	if (indexDuProchainDeplacement < 0) {
		cout << "Entrer un deplacement X Y: ";
		cin >> deltaX >> deltaY;
	}
	else if (indexDuProchainDeplacement < nDeplacementsDansListe) {
		const int* deplacement = listeDeplacements[indexDuProchainDeplacement++];
		deltaX = deplacement[0];
		deltaY = deplacement[1];
	}
	else 
		deltaX = deltaY = -100;
}
void fixerDeplacementInteractif() {
	nDeplacementsDansListe = 0;
	indexDuProchainDeplacement = -1;
}
void fixerListeDeDeplacement(const int deplacements[][2], int nDeplacements) {
	listeDeplacements = deplacements;
	nDeplacementsDansListe = nDeplacements;
	indexDuProchainDeplacement = 0;
}

//----------------------------------------------------------------------------

void test_tout() {
	test_lireCarte();
	test_verifierPeutMarcher();
	test_faireMarcherVoyageur();
}
