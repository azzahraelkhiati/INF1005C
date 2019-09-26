/*
OKAy
*/


#include <iostream>

using namespace std;

const int TAILLE_MAX = 1000;
void sDoublons(int args[], int tailleTableau);
void afficherTableau(int tab[], int n);

int main() {

	
	int n;

	cout << "Entrer une valeur n (entre 0 et 999): ";
	cin >> n;

	while (n > TAILLE_MAX) {
		cout << "Entrer une valeur n (entre 0 et 999): ";
		cin >> n;
	}

	int tab[TAILLE_MAX]; //Initialise le tableau de taille max 

	for (int indexTableau = 0; indexTableau < n; indexTableau++){
	
		cout << "Entrer un nombre: ";
		cin >> tab[indexTableau];
	}

	cout << "Pour n = " << n;
	
	afficherTableau(tab, n);

	sDoublons(tab, n);

	afficherTableau(tab, n);

}

void sDoublons(int args[], int tailleTableau) {

	int newTab[TAILLE_MAX];

	for (int index = 0; index < tailleTableau; index++) {
	
		int tmp = args[index];

		for (int indexN = index; indexN < tailleTableau; indexN++) {
		
			if (tmp != args[indexN]) {
				newTab[indexN] = args[indexN];

			}
			else {
				tailleTableau -= 1;
			}
			
			if (indexN >= tailleTableau) {
				args = newTab;
			}

		}


	}

}

void afficherTableau(int tab[], int n) {

	for (int index = 0; index < n; index++) {
		if (index == 0) {
			cout << " [";
		}

		cout << tab[index];

		if (index < n - 1) {
			cout << ",";
		}
		else {
			cout << "]" << endl;
		}

	}

}