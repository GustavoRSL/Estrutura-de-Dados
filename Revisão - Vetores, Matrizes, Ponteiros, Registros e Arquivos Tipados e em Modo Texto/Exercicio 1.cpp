#include <iostream>
using namespace std;

int main()
{	
	int vetor[9];
	
	for(int i=0;i<9;i++)
		cin >> vetor[i];
	
	int contador;
	for(int i=0; i<9; i++)
	{
		for(int divisor=2;divisor<=vetor[i];divisor++)
		{
			if(vetor[i]%divisor==0)
			{
				contador++;
			}
		}
		
		if(contador==1)
			cout << vetor[i] << " " << i << endl;
			
		contador=0;
	}
    
    return 0;
}
