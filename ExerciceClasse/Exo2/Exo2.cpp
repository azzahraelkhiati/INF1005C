//Un programme qui ouvre un fichier et le ferme

#include <iostream>
#include <string>
#include <fstream>
#include <ostream>

using namespace std;

int main() {

	ifstream myFile("helloWorld.txt");

	if (myFile.fail()) {
		cout << "Lecture impossible" << endl;
	}
	else {
		
		string line;
		getline(myFile, line);

		ofstream fileWrite("write.txt");

		if (fileWrite.fail()) {
			cout << "Ecriture impossible" << endl;
		}
		else {
			fileWrite << line << " LOL";
		}
	
	}

	return 0;
}