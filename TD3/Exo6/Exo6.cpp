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
#include <vector>

using namespace std;
const int MAX_NB_ELEVES = 50;

struct Eleve {

	int matricule,
		noteIntra,
		noteLab,
		noteFinal;

	double moyenne;

};

struct Classe {

	Eleve listeEleves[MAX_NB_ELEVES];

	int nbEleve;

};

double calculerMoyenneClasse(Classe classe);
Eleve trouverMeilleurNoteLab(Classe classe);
Eleve trouverMeilleurMoyenne(Classe classe);

int main() {

	ifstream inputFile("notes.txt");
	Classe classeEleves;
	Eleve etudiant;

	if (!inputFile.fail()) {
		
		classeEleves.nbEleve = 0;

		while (!ws(inputFile).eof()) {
		
			inputFile >> classeEleves.listeEleves[classeEleves.nbEleve].matricule
				>> classeEleves.listeEleves[classeEleves.nbEleve].noteIntra
				>> classeEleves.listeEleves[classeEleves.nbEleve].noteLab
				>> classeEleves.listeEleves[classeEleves.nbEleve].noteFinal;
			
			classeEleves.nbEleve++;

		}

		cout << "La moyenne de la classe est : " << calculerMoyenneClasse(classeEleves) << endl;
		cout << "L'etudiant ayant la matricule: " << trouverMeilleurNoteLab(classeEleves).matricule << " a la meilleure note " << trouverMeilleurNoteLab(classeEleves).noteLab << " dans les labs" << endl;
		cout << "L'etudiant ayant la matricule: " << trouverMeilleurMoyenne(classeEleves).matricule << " a la meilleure moyenne " << trouverMeilleurMoyenne(classeEleves).moyenne << endl;

		ofstream outputFile("evelaution.txt");
	
		if (!outputFile.fail()) {
			outputFile << "La moyenne de la classe est : " << calculerMoyenneClasse(classeEleves) << endl;
			outputFile << "L'etudiant ayant la matricule: " << trouverMeilleurNoteLab(classeEleves).matricule << " a la meilleure note " << trouverMeilleurNoteLab(classeEleves).noteLab << " dans les labs" << endl;
			outputFile << "L'etudiant ayant la matricule: " << trouverMeilleurMoyenne(classeEleves).matricule << " a la meilleure moyenne " << trouverMeilleurMoyenne(classeEleves).moyenne << endl;
		}
		else {
			cout << "Ecriture impossible" << endl;
		}
		

		outputFile.close();

	}
	else {
		cout << "Fichier introuvable" << endl;
	}

	inputFile.close();


	return 0;

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
	Eleve meilleurEnLab;

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

