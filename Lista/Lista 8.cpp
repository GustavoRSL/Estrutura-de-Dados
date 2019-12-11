#include <iostream>
#include <climits>
using namespace std;

#define TAM_max 20

class Noh{
	friend class Deque;
	private:
		Noh* nAnterior;
		Noh* nProximo;
		string nDado;
	public:
		Noh(string Dado);
};

Noh::Noh(string Dado) {
    nDado = Dado;
    nProximo = NULL;
    nAnterior = NULL;
}

class Deque{
	private:
		Noh* Esq;
		Noh* Dir;
		int Tamanho;
		int Capacidade;
	public:
		Deque(int Cap);
		~Deque();
		void InsereEsq(string Valor);
		void InsereDir(string Valor);
		string RemoveEsq();
		string RemoveDir();
};

Deque::Deque(int Cap){
	Esq = NULL;
	Dir = NULL;
	Tamanho = 0;
	Capacidade = Cap;
}

Deque::~Deque(){
	Noh* iter = Esq;
    Noh* proximo = NULL;
    while (iter != NULL) {
        proximo = iter->nProximo;
        delete iter;
        iter = proximo;
	}
}

void Deque::InsereEsq(string Valor){
	Noh* Novo = new Noh(Valor);
	if(Tamanho == 0){
		Novo->nAnterior = NULL;
		Novo->nProximo = NULL;
		Esq = Novo;
		Dir = Novo;
		Tamanho++;
	}
	else{
		Novo->nAnterior = NULL;
		Novo->nProximo = Esq;
		Esq->nAnterior = Novo;
		Esq = Novo;
		Tamanho++;
	}
}

void Deque::InsereDir(string Valor){
	Noh* Novo = new Noh(Valor);
	Noh* Aux = NULL;
	if(Tamanho == 0){
		Esq = Novo;
		Dir = Novo;
		Tamanho++;
	}
	else{
		Aux = Dir;
		Dir->nProximo = Novo;
		Dir = Novo;
		Dir->nAnterior = Aux;
		Tamanho++;
	}
}

string Deque::RemoveEsq(){
	string Dado;
	Noh* Aux = NULL;
	if(Tamanho == 0){
		cerr << "Deque Vazio!!!" << endl;
	}
	else if(Tamanho == 1){
		Dado = Esq->nDado;
		Esq = NULL;
		Dir = NULL;
		Tamanho--;
	}
	else {
		Aux = Esq;
		Dado = Aux->nDado;
		Esq = Aux->nProximo;
		Esq->nAnterior = NULL;
		delete Aux;
		Tamanho--;
	}
	return Dado;
}

string Deque::RemoveDir(){
	Noh* Aux = NULL;
	string Dado;
	if(Tamanho == 0) {
		cerr << "Deque Vazio!!!" << endl;
	}
	else if(Tamanho == 1) {
		Dado = Esq->nDado;
		Esq = NULL;
		Dir = NULL;
		Tamanho--;
	}
	else {
		Aux = Dir;
		Dado = Aux->nDado;
		Dir = Aux->nAnterior;
		Dir->nProximo = NULL;
		delete Aux;
		Tamanho--;
	}
	return Dado;
}



int main() {
	int Cap;
	cin >> Cap;
	int i = 0;
	Deque Comandos(Cap);
	cin.ignore();
	string Passos;
	getline(cin,Passos);
	while(Passos!="sair"){
		if(Passos == "undo"){
			if(i == 0)
				cout << "ERRO" << endl;
			else{
				cout << "desfazer: " << Comandos.RemoveDir() << endl;
				i--;
			}
		}
		else {
			if(i < Cap){
				Comandos.InsereDir(Passos);
				i++;
			}
			else if(i == Cap){
				cout << "esqueci: " << Comandos.RemoveEsq() << endl;
				Comandos.InsereDir(Passos);
			}
		}
	getline(cin,Passos);		
	}
	cout << endl;
	return 0;
}

