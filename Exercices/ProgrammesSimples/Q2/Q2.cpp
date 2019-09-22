/*
Écrire un programme qui lit une chaîne de caractères et affiche son nombre de caractères.

Autheur: Johnatan Gao
Date: 2019-09-22
*/

#include <iostream>;
#include <string>;

using namespace std;

/*
Cette methode pour enlever les espaces dans les strings vient de StackOverFlow par Matt Price
https://stackoverflow.com/questions/83439/remove-spaces-from-stdstring-in-c 
*/

template<typename T, typename P>
T remove_if(T beginning, T end, P pred)
{
	T dest = beginning;
	for (T itr = beginning; itr != end; ++itr)
		if (!pred(*itr))
			* (dest++) = *itr;
	return dest;
}

int main() {

	cout << "Entrer une chaine de caractere: ";
	string chaine;
	getline(cin, chaine);

	chaine.erase(remove_if(chaine.begin(), chaine.end(), isspace), chaine.end());

	cout << "Le nombre de caracteres dans la chaine qui ne sont pas des espaces est de: " << chaine.length() << endl;

	return 0;

}