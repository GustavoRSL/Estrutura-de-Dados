#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int leitura;
	int auxi;
	int vetor[100];
	ifstream arquivoL("entrada.txt");
	ofstream arquivoS("saida.txt");
	if(arquivoL)
	{
		for(int i=0; arquivoL>>leitura; i++)
		{
			vetor[i] = leitura;
			auxi = i;
		}
	}
	
	for(int i=auxi; i>=0; i--)
		arquivoS << vetor[i] << " ";
	
	return 0;
}
