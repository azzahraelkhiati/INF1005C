#include "test.hpp"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

static const int LARGEUR = 18;
static const int HAUTEUR = 9;

static const char TERRE = 'T';
static const char MONTAGNE = 'M';
static const char EAU = 'E';

// Fonctions à écrire :
void lireCarte(const string& nomFichier, char carte[HAUTEUR][LARGEUR]);
bool verifierPeutMarcher(const char carte[HAUTEUR][LARGEUR], const int positionX, const int positionY);
int faireMarcherVoyageur(const char carte[HAUTEUR][LARGEUR], int& positionX, int& positionY);

// Fonctions déjà écrites :
void afficherCarte(const char carte[HAUTEUR][LARGEUR], const int positionX, const int positionY);
void prochainDeplacement(int& deltaX, int& deltaY);

// Fonctions utilisées pour les tests :
void fixerDeplacementInteractif();
void fixerListeDeDeplacement(const int deplacements[][2], int nDeplacements);

void test_tout();
void test_lireCarte();
void test_verifierPeutMarcher();
void test_faireMarcherVoyageur();
