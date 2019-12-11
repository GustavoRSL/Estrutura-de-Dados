#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	
	ifstream palavras("palavras.txt");
	ifstream numeros("numeros.txt");
	ofstream arquivoS("frase.txt");
	
	string ler;
	int num;
		
	int vetor[50];
	string vector[50];
	
	int auxj;
	
	if(palavras)
	{
		for(int i=0; palavras >> ler; i++)
		{
			vector[i] = ler;
		}
	}
	
	if(numeros)
	{
		for(int i=0; numeros >> num; i++)
		{
			vetor[i] = num;
			auxj = i;
		}
	}
	
	if(arquivoS)
	{
		for(int i=0; auxj>=i; i++)
		{
			arquivoS << vector[(vetor[i]-1)] << " ";
		}
	}
		
	return 0;
}
