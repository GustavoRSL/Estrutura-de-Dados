#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

struct Hidrocarboneto
{
	int C;
	int H;
};

int main()
{
	Hidrocarboneto *quimica = new Hidrocarboneto;
	
	cin >> quimica->C >> quimica->H;
	
	cout << (12*quimica->C)+(1*quimica->H);
	return 0;
}
