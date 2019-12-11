#include <iostream>
using namespace std;

int main()
{
	int vetor[10];
	
	for(int i=0; i<10; i++)
		cin >> vetor[i];
	
	for(int i=0; i<10; i++)
	{
		if(vetor[i]<0)
			vetor[i] = 0;
	}
	
	for(int i=0; i<10; i++)
	{
		for(int j=i; j<10; j++)
		{
			if(vetor[i]==0)
			{
				swap(vetor[i],vetor[j]);
			}
		}
	}
	
	for(int i=0; i<10; i++)
		if(vetor[i]!=0)
			cout << vetor[i] << " ";
		
	return 0;
}
