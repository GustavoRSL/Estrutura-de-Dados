#include <iostream>
using namespace std;

int main()
{
	int matriz[4][5];
	int matrix[5][2];
	int resultante[4][2];
	
	for(int i=0; i<4; i++)
		for(int j=0; j<5; j++)
			cin >> matriz[i][j];
			
	for(int i=0; i<5; i++)
		for(int j=0; j<2; j++)
			cin >> matrix[i][j];
			
	for(int i=0; i<4; i++)
		for(int j=0; j<2; j++)
			resultante[i][j] = 0;
			
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 2; j++) 
			for(int k = 0; k < 5; k++)
				resultante[i][j] += matriz[i][k]*matrix[k][j];

	
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<2; j++)
		{
			cout << resultante[i][j] << " ";
		}	
		cout << endl;
	}	
	

	return 0;
}
