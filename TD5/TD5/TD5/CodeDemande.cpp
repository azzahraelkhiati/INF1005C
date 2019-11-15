////////////////////////////////////////////////////////////////////////////////
/// VOTRE ENT�TE ICI
////////////////////////////////////////////////////////////////////////////////


#pragma region "Inclusions" //{

#include "CodeFourni.hpp"

#include "CodeDemande.hpp"

#include <iostream>

#include <ciso646>
#include <cstddef>
#include <cstdint>

#include <fstream>
#include <string>

#include "gsl/span"
#include "cppitertools/range.hpp"

using namespace std;
using namespace gsl;
using namespace iter;

#pragma endregion //}




#pragma region "Globaux" //{

#pragma region "Fonctions" //{

EnteteDib
lireEnteteFichier(fstream& fichier)
{
	// TODO: Lire l'ent�te DIB du fichier donn� et la retourner.
	EnteteDib entD = construireDibVide();
	EnteteBmp entB = construireBmpVide();

	fichier.seekg(sizeof(entB), ios::beg); //skip le bmp
	fichier.read((char*)& entD, sizeof(entD)); //no need to do a huge while loop cause c++ is smart

	return entD;
}


void
lireDonneesImage(fstream& fichier, Image& image)
{
	EnteteDib d = construireDibVide();
	EnteteBmp b = construireBmpVide();
	// TODO: Se positionner au d�but du tableau de pixels dans le fichier.
	fichier.seekg(sizeof(b) + sizeof(d), ios::beg); //skip the bmp header and the div header

	// TODO: Pour chaque ligne de l'image, lire la ligne et sauter le padding.
	unsigned largeur = image.largeur;
	unsigned hauteur = image.hauteur;
	unsigned padding = calculerTaillePadding(image);

	////////////CREATION OF THE MATRIX/////////////

	for (int hauteur : range(hauteur)) {
		//read the pixels
		for (int largeur : range(largeur)) {
			Pixel p = {};
			fichier.read((char*) &p, sizeof(p));
			image.pixels[hauteur][largeur] = p;
		}
		//skip the padding
		fichier.seekg(sizeof(padding), ios::cur);
	}

}


void
ecrireDonneesImage(fstream& fichier, const Image& image)
{
	// TODO: Se positionner au d�but du tableau de pixels dans le fichier (apr�s
	//       les ent�tes).
	EnteteBmp eB = construireBmpVide();
	EnteteDib eD = construireDibVide();

	fichier.seekp(sizeof(eB) + sizeof(eD), ios::beg); //skip the padding

	// TODO: �crire les donn�es (pixels) de l'image dans le fichier.
	unsigned padding = calculerTaillePadding(image);

	char octetVide;

	for (int hauteur : range(image.hauteur)) {
		for (int largeur : range(image.largeur)) {
			Pixel p = image.pixels[hauteur][largeur];
			fichier.write((char*)&p, sizeof(p));
		}
		fichier.write((char*)&octetVide, sizeof(padding)); //cette ligne est problematique
		//fichier.seekg(padding, ios::cur);
	}
}


void
ecrireImage(const string& nomFichier, const Image& image, bool& ok)
{
	// TODO: Ouvrir un fichier en �criture binaire.
	fstream fichier(nomFichier, ios::out | ios::binary);

	if (!fichier.fail()) {
		
		fichier.seekp(0, ios::beg); //On se place au debut
		// Si l'ouverture n'a pas �chou�e :
			// TODO: Construire les ent�tes � partir de l'image.
		EnteteBmp eB = construireEnteteBmp(image);
		EnteteDib eD = construireEnteteDib(image);
		
		// TODO: �crire les ent�tes dans le fichier.
		fichier.write((char*) &eB, sizeof(eB));
		fichier.write((char*) &eD, sizeof(eD));
		
		// TODO: �crire les donn�es (pixels) de l'image dans le fichier.
		ecrireDonneesImage(fichier, image);
		
	}
	else {
		ok = false;
	}
}


Image
allouerImage(unsigned largeur, unsigned hauteur)
{

	Image img = {};
	// Si la largeur ET la hauteur ne sont pas nulles :
	if (largeur != 0 && hauteur != 0) {
	// TODO: Affecter les dimensions � l'image.
		img.largeur = largeur;
		img.hauteur = hauteur;
		// TODO: Allouer un tableau dynamique de pixels pour l'image.
		//       On veut Image::hauteur de lignes qui ont chacune
		//       Image::largeur de pixels.
		img.pixels = new Pixel*[hauteur];
		for (int i : range(hauteur)) {
			img.pixels[i] = new Pixel[largeur];
		}
	
	}
		
	return img; // TODO: Retourner ce qu'il faut.
}


void
desallouerImage(Image& image)
{
	// Si le tableau dynamique de l'image n'est pas nul :
		// TODO: D�sallouer le tableau 2D.
}


Image
copierImage(const Image& image)
{
	// TODO: Allouer une image de la m�me taille que celle donn�e.

	// TODO: Copier tous les pixels.
	return {}; // TODO: Retourner ce qu'il faut.
}


Image
lireImage(const string& nomFichier, bool& ok)
{
	// TODO: Ouvrir le fichier en lecture binaire.

	// Si l'ouverture n'a pas �chou�e :
		// TODO: Lire l'ent�te DIB.

		// TODO: Allouer une image selon le contenu du DIB.

		// TODO: Lire les pixels du fichier.
	return {};  // TODO: Retourner ce qu'il faut.
}


Image
extraireRectangle(const Image& image, const Rectangle& zone)
{
	// Si la zone demand�e est valide :
		// TODO: Allouer une image de la taille de la zone � extraire.

		// TODO: Copier les pixels de la zone.
	return {};  // TODO: Retourner ce qu'il faut.
}

#pragma endregion //}

#pragma endregion //}
