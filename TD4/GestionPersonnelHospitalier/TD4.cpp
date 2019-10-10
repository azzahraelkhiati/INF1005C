////////////////////////////////////////////////////////////////////////////////
/// TD4 Automne 2019.
/// \file    TD4.cpp
/// \authors
/// \authors   Basé sur un squelette écrit par Sofiene Beji et François-R Boyer
////////////////////////////////////////////////////////////////////////////////


#pragma region "Inclusions" //{

#include <ciso646>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include "cppitertools/range.hpp"
#include "cppitertools/enumerate.hpp"
#include "gsl/span"
#include <vector>

using namespace std;
using namespace iter;
using namespace gsl;

#pragma endregion //}



#pragma region "Déclaration" //{

#pragma region "Constantes" //{

static const unsigned TAILLE_MAX = 50;

const int SALAIRE_BASE = 80;

#pragma endregion //}


#pragma region "Structures" //{

struct Specialite {  ///< Décrit l'expertise d'un médecin. 
	string domaine;  ///< Domaine de la spécialité.
	int niveau;      ///< Niveau d'expertise du médecin dans cette spécialité.
};

struct Medecin { 
	string nom;
	int horaires;          ///< Nombre de cases horaire travaillés par ce médecin.
	Specialite specialite; ///< Spécialité du médecin (voir ci-dessus).
};

struct Infirmier {
	string nom;
	string prenom;
	int nbChambres; ///<  Nombre de chambres sous la responsabilité de cet infirmier.
};

struct Personnel { ///< L'ensemble de personnel de l'hôpital.
	Medecin   medecins[TAILLE_MAX];   ///< L'ensemble des médecins de l'hôpital.
	Infirmier infirmiers[TAILLE_MAX]; ///< L'ensemble des infirmiers de l'hôpital.

	int nMedecins;   ///< Nombre de médecins considérés dans medecins.
	int nInfirmiers; ///< Nombre d'infirmiers considérés dans infirmiers.
};

#pragma endregion //}

#pragma region "Fonctions" //{

Infirmier creerInfirmier(const string& nom, const string& prenom, int nbChambres);

Medecin creerMedecin(const string& nom, int horaires, const string& domaine, int niveau);

void ajouterInfirmier(Personnel& personnel, const Infirmier& infirmier);

void ajouterMedecin(Personnel& personnel, const Medecin& medecin);

void modifierNiveauExpertiseMedecin(Personnel& personnel, const string& nom, int niveau);

void retirerPersonnel(Personnel& personnel, const string& nom);

int calculerRemunerationMedecin(const Medecin& medecin);

Medecin rechercherMedecinPlusExperimentee(const Personnel& personnel, const string& domaine);

Personnel lireFichiers(const string& fichierInfirmier,const string& fichierMedecins);

void afficherMedecins(const Personnel& personnel);

void afficherInfirmiers(span<const Infirmier> infirmiers);

void afficherInformationMedecin(const Medecin& medecin);

void afficherInformationInfirmier(const Infirmier& infirmier);

#pragma endregion //}

#pragma endregion //}


int main()
{
	//TODO: 1 Recuperez des fichiers Infirmiers.txt et Medecins,txt l'ensemble des personnels.
	Personnel listePersonnel = lireFichiers("Infirmiers.txt", "Medecins.txt");

	//TODO: 2 Modifiez le niveau d'expertise du medecin Kyle.
	modifierNiveauExpertiseMedecin(listePersonnel, "Kyle", 5);

	//TODO: 3 Retirer Lamontagne de l'ensemble du personnel.
	retirerPersonnel(listePersonnel, "Lamontagne");
	
	//TODO: 4 Calucler et afficher la remuneration du medecin le plus experimenté en Dermatologie.
	cout << calculerRemunerationMedecin(rechercherMedecinPlusExperimentee(listePersonnel, "Dermatologie"));

	//TODO: 5 Afficher l'ensemble des infirmers.

	//TODO: 6 Afficher l'ensemble des medecins.
	
}

#pragma region "Définitions" //{

#pragma region "Fonctions" //{

Medecin creerMedecin(const string& nom, int horaires, const string& domaine, int niveau)
{
	//TODO: Créer un médecin à partir des informations en paramètres.

	Medecin tmp;
	tmp.nom = nom;
	tmp.horaires = horaires;

	Specialite med;
	med.domaine = domaine;
	med.niveau = niveau;

	tmp.specialite = med;

	return tmp;
}

Infirmier creerInfirmier(const string& nom, const string& prenom, int nbChambres)
{
	//TODO: Créer un infirmier à partir des informations en paramètres.

	Infirmier tmp;
	tmp.nom = nom;
	tmp.prenom = prenom;
	tmp.nbChambres = nbChambres;


	return tmp;
}

void ajouterMedecin(Personnel& personnel, const Medecin& medecin)
{
	//TODO: Ajouter le medecin dans personnel.

	personnel.medecins[personnel.nMedecins] = medecin;
	personnel.nMedecins++;

}

void ajouterInfirmier(Personnel& personnel, const Infirmier& infirmier) 
{
	//TODO: Ajouter l'infirmier dans personnel.

	personnel.infirmiers[personnel.nInfirmiers] = infirmier;
	personnel.nInfirmiers++;

}

void modifierNiveauExpertiseMedecin(Personnel& personnel, const string& nom, int niveau)
{
	//TODO: Modifier le niveau d'expertise du médecin dont le nom est donné en paramètre.  On suppose que le nom identifie de manière unique un médecin.

	span<Medecin> spanMed(personnel.medecins, personnel.nMedecins);

	for (Medecin m : spanMed) {
		if (m.nom == nom) {
			m.specialite.niveau = niveau;
			break;
		}
	}

}

void retirerPersonnel(Personnel& personnel, const string& nom)
{
	//TODO: Retirer le médecin ou l'infirmier dont le nom est spécifié en paramètre.  On suppose que le nom identifie de manière unique une personne, médecin ou infirmier.

	span<Medecin> spanMedecin(personnel.medecins, personnel.nMedecins); 

	bool shift = false;

	for (auto&& [index, medecin] : enumerate(spanMedecin)) {
		
		if (medecin.nom == nom){
			shift = true;
			personnel.nMedecins--;
		}

		if (shift && index < personnel.nMedecins-1) {
			spanMedecin[index] = spanMedecin[index+1];
		}
	}

	if (!shift) {

		span<Infirmier> spanInfirmier(personnel.infirmiers, personnel.nInfirmiers);
	
		for (auto&& [index, infirmier] : enumerate(spanInfirmier)) {

			if (infirmier.nom == nom) {
				shift = true;
				personnel.nInfirmiers--;
			}

			if (shift && index < personnel.nInfirmiers-1) {
				spanInfirmier[index] = spanInfirmier[index + 1];
			}

		}
	
	}
	
}

int calculerRemunerationMedecin(const Medecin& medecin)
{
	//TODO: Déterminer la rémunération de medecin en utilisant la formule suivante: remuneration = horaires × (niveau + SALAIRE_BASE).

	int renumeration = medecin.horaires * (medecin.specialite.niveau + SALAIRE_BASE);

	return renumeration;
}

Medecin rechercherMedecinPlusExperimentee(const Personnel& personnel, const string& domaine)
{
	//TODO: Déterminer le médecin ayant le niveau d'expertise le plus haut dans le domaine indiqué en paramètre.

	span<const Medecin> spanMed(personnel.medecins, personnel.nMedecins);

	Medecin medExpert = {};

	for (auto&& [index, medecin] : enumerate(spanMed)){
		
		if (medecin.specialite.domaine == domaine && medecin.specialite.niveau > medExpert.specialite.niveau) {
			medExpert = spanMed[index];
		}
	}

	return medExpert;
}

Personnel lireFichiers(const string& nomFichierInfirmier, const string& nomFichiersMedecins)
{
	//TODO: Récupérer l'ensemble du personnel (infirmiers et medecins) à partir de deux fichiers. Les noms de ces deux fichiers sont donnés en paramètre.  Aucune validation des données n'est demandée.
	
	ifstream fichierInfirmier(nomFichierInfirmier);
	ifstream fichierMedecin(nomFichiersMedecins);

	Personnel listPersonnel = {};


	while (!ws(fichierInfirmier).eof()) {
		
		string nom, prenom;
		int nbChambre;

		fichierInfirmier >> nom >> prenom >> nbChambre;
		Infirmier inf = creerInfirmier(nom, prenom, nbChambre);
		ajouterInfirmier(listPersonnel, inf);

	}

	while (!ws(fichierMedecin).eof()) {
		
		string nom, domaine;
		int horaire, niveau;

		fichierMedecin >> nom >> horaire >> domaine >> niveau;
		Medecin med = creerMedecin(nom, horaire, domaine, niveau);
		ajouterMedecin(listPersonnel, med);

	}
	
	return listPersonnel;
}

void afficherInformationMedecin(const Medecin& medecin)
{
	//TODO: Afficher les informations relatives à un seul medecin, suivant l'exemple de la Figure 1 de l'énoncé.

	cout << medecin.nom 
		<< medecin.horaires 
		<< medecin.specialite.domaine 
		<< medecin.specialite.niveau;

}

void afficherInformationInfirmier(const Infirmier& infirmier)
{
	//TODO: Afficher les informations relatives à un seul infirmier, suivant l'exemple de la Figure 1 de l'énoncé. 
}

void afficherMedecins(const Personnel& personnel)
{
	//TODO: Afficher les medecins contenus dans le personnel, suivant l'exemple de la Figure 1 de l'énoncé.
}

void afficherInfirmiers(span<const Infirmier> infirmiers)
{
	//TODO: Afficher les infirmiers contenus dans le personnel, suivant l'exemple de la Figure 1 de l'énoncé.
}

#pragma endregion //}

#pragma endregion //}