#include <iostream>
using namespace std;

class Noh{
	friend class Circular;
	private:
		int nDado;
		Noh* nProximo;
	public:
		Noh(int Valor);
};

Noh::Noh(int Valor){
	nDado = Valor;
	nProximo = NULL;
};

class Circular{
	private:
		Noh* Primeiro;
		Noh* Ultimo;
		int Tamanho;
	public:
		Circular();
		~Circular();
		void Preencher(int N);
		void Remove(int Avanco);
		bool Vazia();
};

Circular::Circular(){
	Primeiro = NULL;
	Ultimo = NULL;
	Tamanho = 0;
};

Circular::~Circular(){
    Noh* Aux = Primeiro;
    Noh* Proximo = NULL;
    while(Aux->nProximo != Ultimo){
        Proximo = Aux->nProximo;
        delete Aux;
        Aux = Proximo;
    }
    Aux = Ultimo;    
	delete Aux;	
}

void Circular::Preencher(int N){
	Noh* Novo = new Noh(N);
	if(Vazia()){
		Primeiro = Novo;
		Ultimo = Novo;
		Novo->nProximo = Primeiro;
	}
	else{
		Ultimo->nProximo = Novo;
		Ultimo = Novo;
		Novo->nProximo = Primeiro;
	}
	Tamanho++;
};

void Circular::Remove(int Avanco){
	int Sobrevivente;
	int Num = Avanco;
	Noh* Aux = Primeiro;
	Noh* Anterior = NULL;
	if(Vazia())
		cerr << "Operacao invalida" << endl;
	else{
		if(Tamanho == 1){
			Sobrevivente = Aux->nDado;
		}
		else{
			while(Tamanho!=1){
				for(int i=0; i<Num; i++){
					Anterior = Aux;
					Aux = Aux->nProximo;
				}
				Anterior->nProximo = Aux->nProximo;
				delete Aux;
				Aux = Anterior->nProximo;
				Primeiro = Aux;
				Ultimo = Aux;
				Sobrevivente = Aux->nDado;
				Tamanho--;
			}
		}
		cout << Sobrevivente;
	}
}

bool Circular::Vazia() {
	return (Primeiro == NULL and Ultimo == NULL);
}

int main() {
	Circular BattleRoyale;
	int N;
	int Avanco;
	cin >> N >> Avanco;
	if(N>0){
		for(int i=1; i<=N; i++){
			 BattleRoyale.Preencher(i);
		}
	BattleRoyale.Remove(Avanco);
	}
	else{
		 cout << "Operacao invalida" << endl;
	}
	return 0;
}

