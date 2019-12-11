#include <iostream>
using namespace std;

class Noh{
	friend class Pilha;
	private:
		Noh* Prox;
		int Dado;
};

class Pilha{
	private:
		Noh* Topo;
		int Tamanho;
	public:
		Pilha();
		~Pilha();
		void Insere(int Valor);
		int Remove();
		void Imprime();
		bool Vazia();
};

Pilha::Pilha(){
	Topo = NULL;
	Tamanho = 0;
}

Pilha::~Pilha(){
	while(not Vazia()){
		Remove();
	}
}

void Pilha::Insere(int Valor){
	Noh* Novo = new Noh;
	Novo->Dado = Valor;
	if(Topo == NULL){
		Novo->Prox = NULL;
		Topo = Novo;
	}
	else{
		Novo->Prox = Topo;
		Topo = Novo;
		Tamanho++;
	}
}

int Pilha::Remove(){
	int Dado;
	if(Topo != NULL){
		Noh* Lixo = Topo;
		Topo = Topo->Prox;
		Dado = Lixo->Dado;
		delete Lixo;
		Tamanho--;
	}
	else{
		cerr << "Pilha Vazia!" << endl;
	}
	return Dado;
}

void Pilha::Imprime(){
	Noh* Inicio = Topo;
	while(Inicio != NULL){
		cout << "[" << Inicio->Dado << "]" << endl;
		Inicio = Inicio->Prox;
	}
}

bool Pilha::Vazia(){
	return (Topo==NULL);
}

int main()
{
	Pilha Aux;
	Pilha Pila;
	int Valor;
	char comando;
	do{
		cin >> comando;
		switch(comando){
			case 'i':
				cin >> Valor;
				Pila.Insere(Valor);
				break;
			case 'r':
				Pila.Remove();
				break;
			case 'd':
				Pila.Imprime();
				break;
			case 'b':
				int Busca;
				int Auxiliar;
				cin >> Busca;
				while(not Pila.Vazia()){
					Auxiliar = Pila.Remove();
					if(Auxiliar != Busca){
						Aux.Insere(Auxiliar);
					}
				}
				while(not Aux.Vazia()){
					Pila.Insere(Aux.Remove());
				}
				break;
			case 'f':
				cout << "Programa Finalizada!" << endl;
				break;
			default:
				cout  << "Comando Inválido!" << endl;
				break;
		}
	}while(comando != 'f');
	
	return 0;
}

