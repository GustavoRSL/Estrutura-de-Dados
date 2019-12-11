#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream arquivoE("entrada.txt");
	ofstream arquivoS("saida.txt");
	
	int N;
	
	if(arquivoE)
	{
		arquivoE >> N;
	}
	
	int vetor[N];
	
	for(int i=0; i<N; i++)
	{
		arquivoE >> vetor[i];
	}
	
	
	for(int i=0; i<N; i++)
	{
		for(int j=i+1; j<N; j++)
		{
			if(vetor[i]==vetor[j])
				vetor[j]= -1;
		}
		if(vetor[i]>= 0)
		arquivoS << vetor[i] << " ";
	}
	
	return 0;
}
