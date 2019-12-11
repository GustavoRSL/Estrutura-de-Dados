#include <iostream>
using namespace std;

struct treinamento
{
	int dia;
	int codigo;
	float distancia;
	float tempo;
};

struct silvestre
{
	int codigo;
	string nome;
	int idade;
	int peso;
	char genero;
	int participacao;
	float tempototal;
	float distanciatotal;
	struct treinamento;
};

int main()
{
	int corredores;
	int contador = 0;
	bool macho = false;
	bool laco = false;
	int maior = 0;
	int auxi;
	
	cin >> corredores;
	
	treinamento dados[20];
	silvestre corrida[corredores];
	
	for(int i=0; i<corredores; i++)
	{
		cin >> corrida[i].codigo >> corrida[i].nome >> corrida[i].idade >> corrida[i].peso >> corrida[i].genero;
	}
	
	for(int i=0; i<corredores; i++)
	{
		corrida[i].participacao = 0;
	}
	
	for(int i=0; laco==false ; i++)
	{
		cin >> dados[i].dia;
		
		if(dados[i].dia == -1)
		laco = true;
		
		if(dados[i].dia != -1)
		{
			contador++;
			cin >> dados[i].codigo >> dados[i].distancia >> dados[i].tempo;
		}
	}
	
	for(int i=0; i<corredores; i++)
	{
		for(int j=0; j<contador; j++)
		{
			if(corrida[i].codigo == dados[j].codigo)
			{
				corrida[i].tempototal += dados[j].tempo;
				corrida[i].distanciatotal += dados[j].distancia;
				corrida[i].participacao++;
			}
		}
	}
	
	for(int i=0; i<corredores; i++)
	{
		if(corrida[i].genero == 'M')
		{
			macho = true;
			if(corrida[i].idade > maior)
			{
				maior = corrida[i].idade;
				auxi = i;
			}
		}	
	}
	if(macho == true)
	cout << corrida[auxi].nome << " " << corrida[auxi].distanciatotal << endl;
	else
	cout << -1 << endl;
	
	maior = 0;
	
	for(int i=0; i<corredores; i++)
	{
		if(corrida[i].participacao > maior)
		{
			maior = corrida[i].participacao;
			auxi = i;
		}
	}

	cout << corrida[auxi].nome << " " << corrida[auxi].idade << endl;
	
	for(int i=0; i<corredores; i++)
	{
		cout << corrida[i].nome << " " << corrida[i].tempototal/corrida[i].participacao << endl;
	}
	
	return 0;
}
