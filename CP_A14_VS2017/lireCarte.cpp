#include "jeu.hpp"

void lireCarte(const string& nomFichier, char carte[HAUTEUR][LARGEUR]) {
	//#error Commenter cette ligne pour compiler ce fichier.
	//TODO: Lire le fichier et placer les données dans le tableau carte.

	ifstream input(nomFichier);
	int hauteur = 0, largeur = 0;

	while (!ws(input).eof()) {

		input >> carte[hauteur][largeur % LARGEUR];
		largeur++;

		if (largeur % LARGEUR == 0) {
			hauteur++;
		}

	}

}

//----------------------------------------------------------------------------

void test_lireCarte() {
	cerr << "Test lireCarte:";
	cerr << endl;
	// Décommenter/commenter pour faire des tests à la main ou pas:
	//char carte[HAUTEUR][LARGEUR];
	//lireCarte("montreal.txt", carte);
	//afficherCarte(carte, -1,-1);

	// Tests automatisés:
	{
	string lignesDeCarteDeMontreal[] = {
		"EEEEEEEEEEEEEEEETT",
		"EEEEEEEEEEEEEETTTT",
		"EEEEEEEEEEEETTTTTE",
		"EEEEEEEEEETTTTTTEE",
		"EEEEEETTTTTTTTTEEE",
		"EEEETTTTMMMTTTTEEE",
		"EETTTTTTMMMTTTEEEE",
		"ETTTTTTTTTTEEEEEEE",
		"EETTTTTTTTEEEEEEEE"
	};
	
	char carteLue[HAUTEUR][LARGEUR] = {};
	simulerCinCout(CIN_INTERDIT, COUT_INTERDIT);
	TESTER( lireCarte("montreal.txt", carteLue); )
	for (int i = 0; i < HAUTEUR; i++) {
		string lu = string(carteLue[i], LARGEUR);
		string& espere = lignesDeCarteDeMontreal[i];
		ESPERE_EGALITE(lu, espere);
	}

	affichageStatistiquesTests();
	}
}
