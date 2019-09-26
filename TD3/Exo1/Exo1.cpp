/*
Somme r�elle : Soit la somme (voir l'enonce)

On admet que Sn tend vers +inf. �crivez un programme
qui permet de d�terminer pour un entier n donn� par l�utilisateur le plus petit entier a tel que Sn plus petit ou egale a.
Vous n�avez pas � consid�rer les probl�mes li�s � la pr�cision des calculs.

Auteur: Johnatan Gao
Date: 2019-09-25

*/

#include <iostream>

using namespace std;

double sommation(int n);

int main() {

	cout << "Entrer un entier n";
	int n;
	cin >> n;

	cout << sommation(n);


	return 0;
}

double sommation(int n) {

	double somme = 1;

	for (int k = 2; k < n; k++) {
		somme += (1 / k);
	}

	return somme;

}