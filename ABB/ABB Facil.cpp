#include <iostream>
using namespace std;

class Noh{
	friend class ABB;
		private:
			Noh* Esq;
			Noh* Dir;
			Noh* Pai;
			int nDado;
		public:
			Noh(int Valor);
};

Noh::Noh(int Valor){
	Esq = NULL;
	Dir = NULL;
	Pai = NULL;
	nDado = Valor;
}

class ABB{
		private:
			Noh* Raiz;
		public:
			ABB();
			~ABB();
			void Insere(int Valor);
			void Remove();
			void Transplanta(Noh* Antigo, Noh* Novo);
			void Ordem();
			void PosOrdem();
			void PreOrdem();
			int Nivel(int Valor);
			Noh* Minimo(Noh* Atual);
			Noh* BuscaAux(Noh* Aux);
	
};

ABB::ABB(){
	Raiz = NULL;
}

ABB::~ABB(){
	Noh* Atual = Raiz;
	if(Atual != NULL){
		Ordem(Atual->Esq);
		Ordem(Atual->Dir);
		delete Atual;
	}
}

void ABB::Insere(int Valor){
	Noh* Novo = new Noh(Valor);
	if(Raiz == NULL){
		Novo = Raiz;
	}
	else{
		Noh* Atual = Raiz;
		Noh* Antecessor = NULL;
		while(Atual!=NULL){
			Antecessor = Atual;
			if(Atual->nDado > Valor){
				Atual = Atual->Esq;
			}
			else{
				Atual = Atual->Dir;
			}
		}
		Novo->Pai = Antecessor;
		if(Antecessor->nDado > Valor){
			Antecessor->Esq = Novo;
		}
		else{
			Antecessor->Dir = Novo;
		}
	}
}

Noh* ABB::BuscaAux(Noh* Aux){
	Noh* Atual = Raiz;
	while(Atual!=NULL){
		if(Atual->nDado == Aux->nDado){
			return Atual;
		}
		else if(Atual->nDado > Aux->nDado){
			Atual = Atual->Esq;
		}
		else{
			Atual = Atual->Dir;
		}
	}
	return Atual;
}

void ABB::Transplanta(Noh* Antigo, Noh* Novo){
	if(Raiz == Antigo){
		Raiz = Novo;
	}
	else if(Antigo == Antigo->Pai->Esq){
		Antigo->Pai->Esq = Novo;
	}
	else{
		Antigo->Pai->Dir = Novo;
	}
	if(Novo != NULL){
		Novo->Pai = Antigo->Pai;
	}
}

Noh* ABB::Minimo(Noh* Atual){
	while(Atual->Esq != NULL){
		Atual = Atual->Esq;
	}
	return Atual;
}


int main(){

	return 0;
}
