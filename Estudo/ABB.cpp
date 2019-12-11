#include <iostream>
using namespace std;

class Noh{
	friend class ABB;
	private:
		Noh* Esq;
		Noh* Dir;
		Noh* Pai;
		int Dado;
	public:
		Noh(int Valor){
			Dado = Valor;
			Esq = NULL;
			Dir = NULL;
			Pai = NULL;
		}
};

class ABB{
	private:
		Noh* Raiz;
	public:
		ABB();
		~ABB();
		void Insere(int Valor);
		Noh* Minimo(Noh* umNoh);
		Noh* Maximo(Noh* umNoh);
		Noh* Busca(int Valor);
		void Ordem() { Ordem(Raiz); }
		void Ordem(Noh* umNoh);
		void PreOrdem() { PreOrdem(Raiz); }
		void PreOrdem(Noh* umNoh);
		void PosOrdem() { PosOrdem(Raiz); }
		void PosOrdem(Noh* umNoh);
		void Transplanta(Noh* Antigo,Noh* Novo);
		void Remove(int Valor);
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
		Raiz = Novo;
	}
	else{
		Noh* Atual = Raiz;
		Noh* Anterior = NULL;
		while(Atual != NULL){
			Anterior = Atual;
			if(Atual->Dado > Valor){
				Atual = Atual->Esq;
			}
			else{
				Atual = Atual->Dir;
			}
		}
		Novo->Pai = Anterior;
		if(Anterior->Dado > Valor){
			Anterior->Esq = Novo;
		}
		else{
			Anterior->Dir = Novo;
		}
	}
}

Noh* ABB::Minimo(Noh* umNoh){
	Noh* Atual = umNoh;
	if(Raiz== NULL){
		cout << "Arvore Vazia!" << endl;
	}
	else{
		while(Atual->Esq != NULL){
			Atual = Atual->Esq;
		}
	}
	return Atual;
}

Noh* ABB::Maximo(Noh* umNoh){
	Noh* Atual = umNoh;
	if(Raiz== NULL){
		cout << "Arvore Vazia!" << endl;
	}
	else{
		while(Atual->Dir != NULL){
			Atual = Atual->Dir;
		}
	}
	return Atual;
}

Noh* ABB::Busca(int Valor){
	Noh* Atual = Raiz;
	bool Achou = false;
	if(Raiz== NULL){
		cout << "Arvore Vazia!" << endl;
	}
	else{
		while(Achou == false and Atual != NULL){
			if(Atual->Dado == Valor){
				Achou = true;
			}
			else if(Atual->Dado > Valor){
				Atual = Atual->Esq;
			}
			else{
				Atual = Atual->Dir;
			}
		}
		if(Achou == false){
			cout << "Nao encontrado!" << endl;
		}
		else{
			cout << "Valor [" << Atual->Dado << "] Encontrado!" << endl;
			return Atual;
			
		}
	}
	return Atual;
}

void ABB::Ordem(Noh* umNoh){
	if(umNoh != NULL){
		Ordem(umNoh->Esq);
		cout << "[" << umNoh->Dado << "] ";
		Ordem(umNoh->Dir); 
	}
}

void ABB::PreOrdem(Noh* umNoh){
	if(umNoh != NULL){
		cout << "[" <<umNoh->Dado << "] ";
		PreOrdem(umNoh->Esq);
		PreOrdem(umNoh->Dir); 
	}
}

void ABB::PosOrdem(Noh* umNoh){
	if(umNoh != NULL){
		PosOrdem(umNoh->Esq);
		PosOrdem(umNoh->Dir);
		cout << "[" <<umNoh->Dado << "] "; 
	}
}

void ABB::Transplanta(Noh* Antigo,Noh* Novo){
	if(Antigo == Raiz){
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

void ABB::Remove(int Valor){
	Noh* Atual = Busca(Valor);
	if(Atual == NULL){
		cout << "Noh nao encontrado!" << endl;
	}
	else{
		if(Atual->Esq == NULL){
			Transplanta(Atual,Atual->Dir);
		}
		else if(Atual->Dir == NULL){
			Transplanta(Atual,Atual->Esq);
		}
		else{
			Noh* Sucessor = Minimo(Atual->Dir);
			if(Sucessor->Pai != Atual){
				Transplanta(Sucessor,Sucessor->Dir);
				Sucessor->Dir = Atual->Dir;
				Sucessor->Dir->Pai = Sucessor;
			}
			Transplanta(Atual,Sucessor);
			Sucessor->Esq = Atual->Esq;
			Sucessor->Esq->Pai = Sucessor;
		}
		cout << Atual->Dado << endl;
		delete Atual;
	}
}


int main(){
	ABB List;
	int Valor;
	char comando;
	do{
		cin >> comando;
		switch(comando){
			case 'i':
				cin >> Valor;
				List.Insere(Valor);
				break;
			case 'r':
				cin >> Valor;
				List.Remove(Valor);
				break;
			case 'b':
				cin >> Valor;
				List.Busca(Valor);
				break;
			case 'o':
				List.Ordem();
				break;
			case 'p':
				List.PreOrdem();
				break;
			case 's':
				List.PosOrdem();
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

