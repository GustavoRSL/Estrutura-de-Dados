#include <iostream>
#include <fstream>
using namespace std;

int Fibbo(int N)
{
	if(N==0)
		return 0;
	if(N==1)
		return 1;
	else
		return Fibbo(N-1) + Fibbo(N-2);
}

int main()
{
	string nome;
	int N;
	cin >> nome >> N;
	ofstream arquivoS(nome.c_str());
	
	for(int i=0; i<N; i++)
	{
		if(Fibbo(i)%2==0)
		arquivoS << Fibbo(i) << " ";
	}
	
	return 0;
}
