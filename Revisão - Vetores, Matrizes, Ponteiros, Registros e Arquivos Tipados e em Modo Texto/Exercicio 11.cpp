#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;

struct Geometria 
{
	char figura;
	int raio;
	int base;
	int altura;
	int lados[3];
};
int main()
{
	Geometria poligono[5];
	
	for(int i=0; i<5; i++)
	{
		cin >> poligono[i].figura;
		if(poligono[i].figura == 'C')
		cin >> poligono[i].raio;
		
		if(poligono[i].figura == 'R')
		cin >> poligono[i].base >> poligono[i].altura;
		
		if(poligono[i].figura == 'T')
		{
			for(int i = 0; i<3; i++)
			cin >> poligono[i].lados[i];
		}
	}
	
	for(int i=0; i<5; i++)
	{
		if(poligono[i].figura == 'C')
		cout << "Circulo" << " " << 2*M_PI*poligono[i].raio << " " << M_PI*poligono[i].raio*poligono[i].raio << endl;
		
		if(poligono[i].figura == 'T')
		cout << "Triangulo" << " " << ((poligono[i].lados[0]+poligono[i].lados[1])+poligono[i].lados[2])  << " " <<endl;
	}
	return 0;
}
