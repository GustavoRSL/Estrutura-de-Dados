#include <iostream>
using namespace std;

class Noh{
	friend class Fila;
	private:
		Noh* Prox;
		int Dado;
};

class Fila{
	private:
		Noh* Inicio;
		Noh* Fim;
		int Tamanho;
	public:
		Fila();
		~Fila();
		void Insere(int Dado);
		void Imprime();
		int Remove();
		int RemoveInicio();
		bool Vazia();
};

Fila::Fila(){
	Inicio = NULL;
	Fim = NULL;
	Tamanho = 0;
}

Fila::~Fila(){
	while(not Vazia())
		Remove();
}

void Fila::Insere(int Dado){
	Noh* Novo = new Noh;
	Novo->Dado = Dado;
	Novo->Prox = NULL;
	if(Inicio == NULL){
		Inicio = Novo;
		Fim  = Novo;
	}
	else{
		Fim->Prox = Novo;
		Fim = Novo;
	}
	Tamanho++;
}

int Fila::Remove(){
	int Retorno;
	if(Fim == NULL){
		cerr << "Fila Vazia!" << endl;
	}
	if(Fim != NULL){
		Noh* Lixo = Inicio;
		Inicio = Inicio->Prox;
		Retorno = Lixo->Dado;
		delete Lixo;
		Tamanho--;
		if(Inicio == NULL){
			Fim = NULL;
		}
	}
	return Retorno;
}

bool Fila::Vazia(){
	return (Fim==NULL);
}

void Fila::Imprime(){
	Noh* Aux = Inicio;
	while(Aux != NULL){
		cout << "[" << Aux->Dado << "]" << endl;
		Aux = Aux->Prox;
	}
}

int main(){
	Fila Filha;
	Fila Aux;
	int Auxilia;
	int Busca;
	int Valor;
	char comando;
	do{
		cin >> comando;
		switch(comando){
			case 'i':
				cin >> Valor;
				Filha.Insere(Valor);
				break;
			case 'r':
				cout << "[" << Filha.Remove() << "]" << endl;
				break;
			case 'f':
				cout << "Programa Finalizado!" << endl;
				break;
			case 'd':
				Filha.Imprime();
				break;
			case 'b':
				cin >> Busca;
				while(not Filha.Vazia()){
					Auxilia = Filha.Remove();
					if(Auxilia != Busca){
						Aux.Insere(Auxilia);
					}
				}
				while(not Aux.Vazia()){
					Filha.Insere(Aux.Remove());
				}
				break;
			default:
				cout << "Comando Invalido!" << endl;
		}
	}while(comando != 'f');
	return 0;
}
