#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

struct Alunos
{
	string nome;
	float media;
	int faltas;
};

int main()
{
	int N;
	
	cin >> N;
	
	Alunos *Info = new Alunos[N];
	
	for(int i=0; i<N; i++)
		cin >> Info[i].nome >> Info[i].media >> Info[i].faltas; 
	
	int Min;
	
	for(int i=0; i<N-1; i++)
	{
		Min = i;
		for(int j=i+1; j<N; j++)
		{
			if(Info[j].media < Info[Min].media)
			Min = j;
			
			swap(Info[Min],Info[i]);
		}
	}
	
	for(int i=N-1; i>=0; i--)
		cout << Info[i].nome << endl; 
		
	return 0;
}
