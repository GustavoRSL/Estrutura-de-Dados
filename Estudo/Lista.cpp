#include <iostream>
using namespace std;

class Noh{
	friend class Lista;
	private:
		Noh* Prox;
		Noh* Anterior;
		int Dado;
};

class Lista{
	private:
		Noh* Inicio;
		Noh* Fim;
		int Tamanho;
	public:
		Lista();
		~Lista();
		void InsereInicio(int Dado);
		void InsereFim(int Dado);
		void InsereEspecifico(int Dado, int Pos);
		void ImprimeEsquerda();
		void ImprimeDireita();
		int RemoveEsquerda();
		int RemoveDireita();
		int RemoveEspecifica(int Pos);
		bool Vazia();
};

Lista::Lista(){
	Inicio = NULL;
	Fim = NULL;
	Tamanho = 0;
}

Lista::~Lista(){
	while(not Vazia()){
		//Remove();
	}
}

void Lista::InsereInicio(int Dado){
	Noh* Novo = new Noh;
	Novo->Prox = NULL;
	Novo->Anterior = NULL;
	Novo->Dado = Dado;
	if(Inicio == NULL){
		Inicio = Novo;
		Fim = Novo;
		Tamanho++;
	}
	else{
		Novo->Prox = Inicio;
		Inicio->Anterior = Novo;
		Inicio = Novo;
		Tamanho++;
	}
}

void Lista::InsereFim(int Dado){
	Noh* Novo = new Noh;
	Novo->Prox = NULL;
	Novo->Anterior = NULL;
	Novo->Dado = Dado;
	if(Inicio == NULL){
		Inicio = Novo;
		Fim = Novo;
		Tamanho++;
	}
	else{
		Novo->Anterior = Fim;
		Fim->Prox = Novo;
		Fim = Novo;
		Tamanho++;
	}
}

void Lista::InsereEspecifico(int Dado, int Pos){
	Noh* Novo = new Noh;
	Novo->Prox = NULL;
	Novo->Anterior = NULL;
	Novo->Dado = Dado;
	
	Noh* Aux = Inicio;
	int PosAux = 0;
	if(Inicio == NULL){
		InsereInicio(Dado);
	}
	else if(Pos == 0){
		InsereInicio(Dado);
	}
	else if(Pos == (Tamanho-1) or Pos >= Tamanho){
		InsereFim(Dado);
	}
	else{
		while(PosAux < (Pos-1)){
			Aux = Aux->Prox;
			PosAux++;
		}
		Novo->Prox = Aux->Prox;
		Novo->Anterior = Aux;
		Aux->Prox->Anterior = Novo;
		Aux->Prox = Novo;
		Tamanho++;
	}
}

void Lista::ImprimeEsquerda(){
	Noh* Aux = Inicio;
	while(Aux != NULL){
		cout << "[" << Aux->Dado << "]";
		Aux = Aux->Prox;
	}
	cout << endl;
}

void Lista::ImprimeDireita(){
	Noh* Aux = Fim;
	while(Aux != NULL){
		cout << "[" << Aux->Dado << "]";
		Aux = Aux->Anterior;
	}
	cout << endl;
}

int Lista::RemoveEsquerda(){
	int Retorno;
	if(Fim != NULL){
	  Noh* Lixo = Inicio;
	  Inicio = Inicio->Prox;
	  if(Inicio != NULL){
	  Inicio->Anterior = NULL;
	  }
	  Retorno = Lixo->Dado;
	  delete Lixo;
	  Tamanho--;
	  if(Inicio == NULL){
		  Fim = NULL;
	  }
	}
	else{
		cout << "Lista Vazia!!!" << endl;
	}
	return Retorno;
}

int Lista::RemoveDireita(){
	int Retorno;
	if(Fim != NULL){
	  Noh* Lixo = Fim;
	  Fim = Fim->Anterior;
	  Fim->Prox = NULL;
	  Retorno = Lixo->Dado;
	  delete Lixo;
	  Tamanho--;
	}
	else{
		cout << "Lista Vazia!!!" << endl;
	}
	return Retorno;
}

int Lista::RemoveEspecifica(int Pos){
	int PosAux = 0;
	int Retorno = 0;
	if(not Vazia()){
		if(Pos == 0){
			RemoveEsquerda();
		}
		else if(Pos == (Tamanho-1) or Pos >= Tamanho){
			RemoveDireita();
		}
		else{
			Noh* Temp = Inicio;
			while(Temp != NULL and Pos != PosAux){
				Temp = Temp->Prox;
				PosAux++;
			}
			Temp->Anterior->Prox = Temp->Prox;
			Tamanho--;
		}
	}
	else{
		cout << "Lista Vazia!!!" << endl;
	}
	return Retorno;
}

bool Lista::Vazia(){
	return (Inicio == NULL);
}

int main(){
	Lista List;
	int Valor;
	int Pos;
	char comando;
	do{
		cin >> comando;
		switch(comando){
			case 'i':
				cin >> Valor;
				List.InsereInicio(Valor);
				break;
			case 'o':
				cin >> Valor;
				List.InsereFim(Valor);
				break;
			case 'p':
				cin >> Valor >> Pos;
				List.InsereEspecifico(Valor,Pos);
			case 'e':
				List.ImprimeEsquerda();
				break;
			case 'd':
				List.ImprimeDireita();
				break;
			case 'j':
				List.RemoveEsquerda();
				break;
			case 'k':
				List.RemoveDireita();
				break;
			case 'x':
				cin >> Pos;
				List.RemoveEspecifica(Pos);
				break;
			case 'f':
				cout << "Programa Finalizado!" << endl;
				break;
			default:
				cout << "Comando Invalido!" << endl;
		}
	}while(comando != 'f');

	return 0;
}
