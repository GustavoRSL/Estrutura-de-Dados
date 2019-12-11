#include <iostream>
#include <fstream>
using namespace std;

class Noh{
		friend class ABB;
		private:
			Noh* Esq;
			Noh* Dir;
			Noh* Pai;
			int Posicao[10];
			string Word;
		public:
			Noh(string Word);
};

Noh::Noh(string Palavra){
	Esq = NULL;
	Dir = NULL;
	Pai = NULL;
	Word = Palavra;
}

class ABB{
		private:
			Noh* Raiz;
		public:
			void Insere(string Palavra);
			void Busca();
			bool Repete(string Achar);
};

void ABB::Insere(string Palavra){
	
}

bool Repete(string Palavra){
	
}

int main(){
	ifstream ArquivoLer("entrada.txt");
	string Palavras[50];
	int VetorPosiçoes[50];
	ABB Muda;
	int contador = 0;
	int i = 0;
	int o = 0;
	if(ArquivoLer){
		while(ArquivoLer >> Palavras[i]){
			i++;
		}
		for(int j=0; j<i; j++){
			o = 0;
			for(int u=0; u<i; u++){
				if(Palavras[j] == Palavras[u]){
					VetorPosiçoes[o] = u;
					o++;
				}
					
				}
			}
			if(Muda.Repete(Palavras[j]) == false){
				Muda.Insere(Palavras[j]);
			}
		}
	}
	else{
		cout << "Arquivo Nao Encontrado!!!" << endl;
	}
	return 0;
}
