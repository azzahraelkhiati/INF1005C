/*
On dispose du fichier notes.txt qui contient les données d’évaluation d’un
ensemble d’élèves pour un cours donné. Chaque ligne contient respectivement le matricule, la note de
l’intra, la moyenne des labs, et la note du final.

Auteur: Johnatan Gao
Date: 2019-09-26
*/

#include <iostream>
#include <fstream>
#include <ostream>


using namespace std;
const int MAX_NB_ELEVES = 50;

//Structure d'Eleve
struct Eleve {

	int matricule,
		noteIntra,
		noteLab,
		noteFinal;

	double moyenne; 

};

//Structure d'une classe qui contient une liste d'Eleve
struct Classe {

	Eleve listeEleves[MAX_NB_ELEVES]; 
	int nbEleve;

};

double calculerMoyenneClasse(Classe classe);
Eleve trouverMeilleurNoteLab(Classe classe);
Eleve trouverMeilleurMoyenne(Classe classe);
void afficherResultat(double moyenneClasse, Eleve meilleurNoteLab, Eleve meilleurMoyenne);
void ecrireResultat(ofstream& outputFile, double moyenneClasse, Eleve meilleurNoteLab, Eleve meilleurMoyenne);
void lireFichierClasse(ifstream& inputFile, Classe& classe);

int main() {

	ifstream inputFile("notes.txt");
	Classe classeEleves;

	lireFichierClasse(inputFile, classeEleves);

	double moyenneClasse = calculerMoyenneClasse(classeEleves);
	Eleve meilleurNoteLab = trouverMeilleurNoteLab(classeEleves);
	Eleve meilleurMoyenne = trouverMeilleurMoyenne(classeEleves);
	ofstream outputFile("evelaution.txt");

	afficherResultat(moyenneClasse, meilleurNoteLab, meilleurMoyenne);
	ecrireResultat(outputFile, moyenneClasse, meilleurNoteLab, meilleurMoyenne);
		
	return 0;

}

void lireFichierClasse(ifstream& inputFile, Classe& classe) {

	if (!inputFile.fail()) {

		classe.nbEleve = 0;

		while (!ws(inputFile).eof()) {

			inputFile >> classe.listeEleves[classe.nbEleve].matricule
				>> classe.listeEleves[classe.nbEleve].noteIntra
				>> classe.listeEleves[classe.nbEleve].noteLab
				>> classe.listeEleves[classe.nbEleve].noteFinal;

			classe.nbEleve++;

		}

	}
}


void ecrireResultat(ofstream& outputFile, double moyenneClasse, Eleve meilleurNoteLab, Eleve meilleurMoyenne) {

	if (!outputFile.fail()) {
		outputFile << "La moyenne de la classe est : " << moyenneClasse << endl;
		outputFile << "L'etudiant ayant la matricule: " << meilleurNoteLab.matricule << " a la meilleure note " << meilleurNoteLab.noteLab << " dans les labs" << endl;
		outputFile << "L'etudiant ayant la matricule: " << meilleurMoyenne.matricule << " a la meilleure moyenne " << meilleurMoyenne.moyenne << endl;
	}
	else {
		cout << "Ecriture impossible" << endl;
	}

	outputFile.close();

}


void afficherResultat(double moyenneClasse, Eleve meilleurNoteLab, Eleve meilleurMoyenne) {

	cout << "La moyenne de la classe est : " << moyenneClasse << endl;
	cout << "L'etudiant ayant la matricule: " << meilleurNoteLab.matricule << " a la meilleure note " << meilleurNoteLab.noteLab << " dans les labs" << endl;
	cout << "L'etudiant ayant la matricule: " << meilleurMoyenne.matricule << " a la meilleure moyenne " << meilleurMoyenne.moyenne << endl;

}

Eleve trouverMeilleurMoyenne(Classe classe) {

	Eleve eleveMeilleurMoyenne;

	double meilleurMoyenne = (0.3 * classe.listeEleves[0].noteIntra +
		0.3 * classe.listeEleves[0].noteLab +
		0.4 * classe.listeEleves[0].noteFinal);

	for (int index = 1; index < classe.nbEleve; index++) {
		double moyenneClasse =
			(0.3 * classe.listeEleves[index].noteIntra +
				0.3 * classe.listeEleves[index].noteLab +
				0.4 * classe.listeEleves[index].noteFinal);

		if (meilleurMoyenne < moyenneClasse) {
			meilleurMoyenne = moyenneClasse;
			eleveMeilleurMoyenne = classe.listeEleves[index];
		}

	}

	eleveMeilleurMoyenne.moyenne = meilleurMoyenne;

	return eleveMeilleurMoyenne;

}


Eleve trouverMeilleurNoteLab(Classe classe) {

	int meilleurNote = classe.listeEleves[0].noteLab;
	Eleve meilleurEnLab = {};

	for (int index = 1; index < classe.nbEleve; index++) {
	
		if (meilleurNote < classe.listeEleves[index].noteLab) {
			meilleurNote = classe.listeEleves[index].noteLab;
			meilleurEnLab = classe.listeEleves[index];
		}
	
	}

	return meilleurEnLab;
}



double calculerMoyenneClasse(Classe classe) {

	double moyenneClasse = 0;

	for (int index = 0; index < classe.nbEleve; index++) {
		moyenneClasse +=
			(0.3 * classe.listeEleves[index].noteIntra +
				0.3 * classe.listeEleves[index].noteLab +
				0.4 * classe.listeEleves[index].noteFinal);
	}

	moyenneClasse /= classe.nbEleve;

	return moyenneClasse;
}

