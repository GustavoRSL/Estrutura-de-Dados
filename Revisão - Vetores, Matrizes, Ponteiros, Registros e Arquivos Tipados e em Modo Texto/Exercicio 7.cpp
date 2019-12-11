#include <iostream>
using namespace std;

int main()
{
	int matriz[10][10];
	
	for(int i=0; i<10; i++)
		for(int j=0; j<10; j++)
			cin >> matriz[i][j];
	
	cout << 1 << "." << endl;
	
	for(int i=0; i<10; i++)
	{
		for(int j=0; j<10; j++)
		{
			if(i==1)
			cout << matriz[7][j] << " ";
			if(i==7)
			cout << matriz[1][j] << " ";
			if(i!=1 and i!=7)
			cout << matriz[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << 2 << "." << endl;
	
	for(int i=0; i<10; i++)
	{
		for(int j=0; j<10; j++)
		{
			if(j==3)
			cout << matriz[i][9] << " ";
			if(j==9)
			cout << matriz[i][3] << " ";
			if(j!=3 and j!=9)
			cout << matriz[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << 3 << "." << endl;
	int aux = 9;
	
	for(int i=0; i<10; i++)
	{
		for(int j=0; j<10; j++)
		{
			if(i==j)
			{
			cout << matriz[i][aux] << " ";
			aux--;
			}
			if(i+j==9)
			cout << matriz[i][i] << " ";
			
			if(i!=j and i+j!=9)
			cout << matriz[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << 4 << "." << endl;
	
	for(int i=0; i<10; i++)
	{
		for(int j=0; j<10; j++)
		{
			if(i!=4 and j!=9)
			cout << matriz[i][j] << " ";
			if(i==4)
			cout << matriz[9][j] << " ";
			if(j==9)
				if(i!=4)
				cout << matriz[4][i] << " ";
		}
		cout << endl;
	}
	
	return 0;
}
