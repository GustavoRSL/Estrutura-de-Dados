#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;


int main()
{
	int N,M;
	cin >> N >> M;
	// N = Linhas
	// M = Colunas
	
	int **matriz =(int **)malloc(N * sizeof (int *));
	
	
	for(int i=0; i<N; i++)
	matriz[i] = (int *)malloc(M * sizeof(int));
	
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			cin >> matriz[i][j];
	
	int busca;
	cin >> busca;
	
	bool achou = false;
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			if(matriz[i][j]== busca)
				achou = true;
				
	if(achou ==  false)
	cout << 0;
	else
	cout << 1;
	
	return 0;
}
