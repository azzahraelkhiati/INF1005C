/*
Ecrivez un programme permettant à l’utilisateur de saisir un nombre n et un tableau de
taille n (fixez une borne supérieure pour la valeur de n, puisque nous n’avons pas vu comment faire
des tableaux dont la taille n’est pas connue à la compilation). Le programme supprime ensuite les
doublons et affiche le tableau après la suppression. La suppression des valeurs doit être faite dans une
fonction séparée, qui ne fait ni lecture du clavier ni affichage à l’écran. Noter qu’une fonction qui
reçoit un tableau en paramètre peut modifier ce tableau et c’est le tableau original qui sera modifié; la
fonction devrait donc retourner uniquement le nombre de valeurs qui restent.

Auteur: Johnatan Gao
Date: 2019-09-26
*/


#include <iostream>
using namespace std;

const int MAX_SIZE = 999;

int effacerDoublons(int t[], int &n);
void afficherTableau(int t[], int n);

int main()
{

	int tab[MAX_SIZE];
	int n;

	do {
		cout << "Entrer la grandeur du tableau (doit etre plus ou egale a 999) : ";
		cin >> n;
	} while (n < 0 || n > 999);

	for (int index = 0; index < n; index++) {
		cout << "Entrez un nombre du tableau : ";
		cin >> tab[index];
	}

	effacerDoublons(tab, n);
	afficherTableau(tab, n);
}


int effacerDoublons(int tab[] , int &n) {
	for (int i = 0; i < n - 1; i++) { 
		for (int j = i + 1; j < n; j++) {
			if (tab[i] == tab[j]) {
				for (int k = j + 1; k <= n; k++) {
					tab[k - 1] = tab[k];
				}
				n--;
				j--;
			}
		}
	}
	return n;
}

void afficherTableau(int tab[], int n) {
	for (int i = 0; i < n; i++) {
		cout << " " << tab[i];
	}
}
