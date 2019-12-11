#include <iostream>
using namespace std;

int main()
{
	int matriz[10][10];
	int maior;
	int menor;
	int auxi;
	int auxj;
	
	for(int i=0; i<10; i++)
		for(int j=0; j<10; j++)
			cin >> matriz[i][j];
			
	for(int i=0; i<10; i++)
	{	
		for(int j=0; j<10; j++)
		{
			if(matriz[i][j]>maior)
			{
				maior =  matriz[i][j];
				auxi = i;
			}
		}
	}
	
	menor = maior;
	
	for(int j=0; j<10; j++)
	{
		if(matriz[auxi][j]<menor)
		{
			menor = matriz[auxi][j];
			auxj = j;
		}
	}
	
	cout << menor << endl;
	cout << auxi << " " << auxj << endl;
	
	return 0;
}
