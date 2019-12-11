#include <iostream>
using namespace std;

int main()
{
	int vet[8];
	
	for(int i=0; i<8; i++)
		cin >> vet[i];
		
	for(int i=0; i<8; i++)
	{
		for(int j=0; j<=i; j++)
		{
			for(int u=j; u<=i; u++)
			{
				if(vet[j]>vet[u])
				swap(vet[j],vet[u]);
			}
			cout << vet[j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}
