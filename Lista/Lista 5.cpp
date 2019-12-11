#include <iostream>
using namespace std;

class Noh {
	friend class Lista;
	private:
		Noh* nProximo;
		Noh* nAnterior;
		int nDado;
		string nNome;
	public:
		Noh(int D,string N);
};

Noh::Noh(int D,string N) {
	nDado = D;
	nNome = N;
	nAnterior = NULL;
	nProximo = NULL;
}

class Lista{
	private:
		Noh* Primeiro;
		Noh* Ultimo;
		int Tamanho;
	public:
		Lista();
		~Lista();
		void Insere(int D, string N);
		void Remove(int Matricula);
		void Direta();
		void Reversa();
};

Lista::Lista(){
	Primeiro = NULL;
	Ultimo = NULL;
	Tamanho = 0;
}

Lista::~Lista(){
	Noh* Aux = Ultimo;
	Noh* Lixo;
	while(Aux != NULL){
		Lixo = Aux;
		Aux = Aux->nAnterior;
		delete Lixo;
	}
	Ultimo = NULL;
}

void Lista::Insere(int D, string N){
		Noh* Novo = new Noh(D, N);
		if(Primeiro == NULL) {
			Primeiro = Novo;
			Ultimo = Novo;
			Tamanho++;
		}
		else {
			Primeiro->nAnterior = Novo;
			Novo->nProximo = Primeiro;
			Primeiro = Novo;
			Tamanho++;
		}
}

void Lista::Remove(int Matricula) {
	Noh* Aux = Primeiro;
	Noh* Anterior;
	bool Remover = false;
	while(Aux->nDado != Matricula and Aux->nProximo != NULL){
		Aux = Aux->nProximo;
	}
	if(Aux->nDado == Matricula){
		Remover = true;
		Anterior = Aux->nAnterior;
		Anterior->nProximo = Aux->nProximo;
		Aux->nProximo->nAnterior = Anterior;
		delete Aux;
		Tamanho--;
	}
	if(Remover == false)
		cout << "ERRO" << endl;
}

void Lista::Direta() {
	Noh* Aux = Primeiro;
	while(Aux != NULL) {
		cout << Aux->nDado << " " << Aux->nNome << " ";
		Aux = Aux->nProximo;
	}
}

void Lista::Reversa() {
	Noh* Aux = Ultimo;
	while(Aux != NULL) {
		cout << Aux->nDado << " " << Aux->nNome << " ";
		Aux = Aux->nAnterior;
	}
}

int main() {
	Lista Dupla;
	int D;
	int Matricula;
	string N;
	string comando;
	cin >> comando;
	while(comando != "t"){
		if(comando == "i"){
			cin >> D >> N;
			Dupla.Insere(D,N);
		}
		if(comando == "r"){
			cin >> Matricula;
			Dupla.Remove(Matricula);
		}
		if(comando == "ed"){
			Dupla.Direta();
		}
		if(comando == "er"){
			Dupla.Reversa();
		}
		cin >> comando;
	}
	
	return 0;
}
