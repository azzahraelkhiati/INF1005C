/**
*  Simples fonctions pour faire des tests unitaires.
*  \author Francois-R.Boyer@PolyMtl.ca
*  \date 2014-10
*  \file
*/
#pragma once
#include <iostream>
#include <string>
#include <thread>
#pragma comment(lib, "../Debug/Z test.lib")
static const char CIN_INTERDIT[] = "";
static const bool COUT_INTERDIT = true;
void simulerCinCout(const std::string& texte, bool coutInterdit = false);
void restaureCinCout();
void restaureCinCoutSiPasInterdit();
const std::string stringCoutDuTest();
typedef void* HANDLE;
void fonctionDeLimiteDeTemps(HANDLE filAppelant, int limiteMillisecondes, volatile bool* aFini);
HANDLE descripteurDuFilActuel();
void tempsExpire(int numeroLigne, const std::string& texteA);
extern bool estDansLeDebogueur;
void commencerLimiteDeTemps(int limiteMillisecondes, volatile bool& aFini);
void terminerLimiteDeTemps();
static const int LIMITE_DE_TEMPS_POUR_EXECUTER_UN_TEST = 500;

#define TESTER2(a, texteA) {\
		volatile bool fonctionAFini_ = false;\
		if (!estDansLeDebogueur) commencerLimiteDeTemps(LIMITE_DE_TEMPS_POUR_EXECUTER_UN_TEST, fonctionAFini_);\
		try {\
			a\
			fonctionAFini_ = true;\
		}\
		catch (...) {\
			tempsExpire(__LINE__, texteA);\
		}\
		if (!estDansLeDebogueur) terminerLimiteDeTemps();\
	}

#define TESTER(a) TESTER2(a, #a)

#define ESPERE_EGALITE(a, b) {\
		nTests++;\
		TESTER2( espereEgalite(__LINE__, #a, a, #b, b); , #a );\
	}

extern int nTests, nTestsPasse;

std::ostream& couleurBon(std::ostream& o);
std::ostream& couleurErreur(std::ostream& o);
std::ostream& couleurAvertissement(std::ostream& o);
std::ostream& couleurNormal(std::ostream& o);

template <typename T>
void affichageValeurTest(const T& valeur) {
	std::cerr << valeur;
}
template <>
void affichageValeurTest(const std::string& valeur);

template <typename T>
void affichageTest(int numeroLigne, const char* texteA, const T& a, const char* texteB, const T& b, const char* texteOperateur, bool testPasse) {
	restaureCinCoutSiPasInterdit();
	std::cerr << "  " << numeroLigne << ": " << texteA << texteOperateur << texteB << " (";
	affichageValeurTest(a);
	std::cerr << texteOperateur;
	affichageValeurTest(b);
	std::cerr << ")" << " ? ";
	if (testPasse) {
		std::cerr << couleurBon << "oui" << couleurNormal;
		nTestsPasse++;
	}
	else
		std::cerr << couleurErreur << "NON!" << couleurNormal;
	std::cerr << std::endl;
}
template <typename A, typename B>
void espereEgalite(int numeroLigne, const char* texteA, const A& a, const char* texteB, const B& b) {
	affichageTest(numeroLigne, texteA, a, texteB, b, " == ", a == b);
}

/// reponsePrevue est une chaine contenant des parties de texte séparées par des '\n'.
/// Chaque parties doit se trouver dans la sortie, dans le même ordre, pour être considéré correct.
void verifieCout(const std::string& reponsePrevue);

void affichageStatistiquesTests();
