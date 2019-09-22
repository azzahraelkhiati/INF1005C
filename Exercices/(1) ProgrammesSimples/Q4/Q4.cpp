/*
Tester la fonction srand(unsigned int seed)

Autheur: Johnatan Gao
Date: 2019-09-22

*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	//srand(time(NULL));
	srand(1);

	for (int i = 0;  i < 10; i++) {
		
		cout << rand() << endl;
	}
	
}