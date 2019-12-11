#include<iostream>
using namespace std;

class Noh {
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

class ABB {
	private:
		Noh* Raiz;
	public:
		ABB();
		~ABB();
		void Insere(int Valor);
		void Remove(int Valor);
		void Transplanta(Noh* Antigo,Noh* Novo);
		void Ordem(Noh* Atual);
		void PreOrdem(Noh* Atual);
		void Ordem(){Ordem(Raiz);}
		void PreOrdem(){PreOrdem(Raiz);}
		int Nivel(int Valor);
		Noh* Busca(Noh* Aux);
		Noh* Minimo(Noh* Atual);
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
	//Criação de novo Noh
	Noh* Novo = new Noh(Valor);
	//Se Arvore estiver vazia Novo entra como raiz.
	if(Raiz == NULL){
		Raiz = Novo;
	}
	//Caso nao.
	else{
		//Criação de 2 nos o Atual e o Antecessor dele.
		Noh* Atual = Raiz;
		Noh* Antecessor = NULL;
		//Achar o Noh folha seguindo entre esquerda e direita da arvore
		while(Atual != NULL){
			//Antecessor fica como pai do atual.
			Antecessor = Atual;
			//Se o valor for menor que o do Noh comparado ele segue para a esquerda.
			if(Atual->nDado > Valor){
				Atual = Atual->Esq;
			}
			//Se o valor for maior que o do Noh comparado ele segue para a direita.
			else {
				Atual = Atual->Dir;
			}
		}
		//Pai do novo aponta para o Antecessor a ele.
		Novo->Pai = Antecessor;
		//Se o Valor do Novo for menor que o do Pai entra na esquerda.
		if(Antecessor->nDado > Novo->nDado){
			Antecessor->Esq = Novo;
		}
		//Se o Valor do Novo for maior que o do Pai entra na direita.
		else{
			Antecessor->Dir = Novo;
		}
	}
}

Noh* ABB::Busca(Noh* Aux){
	//Criar um Noh como a Raiz da arvore
	Noh* Atual = Raiz;
	//Rodar o Atual até que ache um Noh folha
	while(Atual != NULL){
		//Se os Dado do Noh atual for igual ao do Buscado retornar Noh Atual.
		if(Atual->nDado == Aux->nDado){
			return Atual;
		}
		//Se valor do Aux for menor seguir pelo caminho esquerdo.
		else if(Atual->nDado > Aux->nDado){
			Atual = Atual->Esq;
		}
		//Se valor do Aux for maior seguir caminho pelo caminho direito.
		else{
			Atual = Atual->Dir;
		}
	}
	return Atual;
}

void ABB::Transplanta(Noh* Antigo,Noh* Novo){
	if(Raiz == Antigo){
		Raiz = Novo;
	}
	else if(Antigo == Antigo->Pai->Esq){
		Antigo->Pai->Esq = Novo;
	}
	else {
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

void ABB::Remove(int Valor){
	Noh* Aux = new Noh(Valor);
	Noh* Remover = Busca(Aux);
	if(Remover == NULL){
		cout << "ERRO";
	}
	else{
		if(Remover->Esq == NULL){
			Transplanta(Remover,Remover->Dir);
		}
		else if(Remover->Dir == NULL){
			Transplanta(Remover,Remover->Esq);
		}
		else{
			Noh* Sucessor = Minimo(Remover->Dir);
			if(Sucessor->Pai != Remover){
				Transplanta(Sucessor,Sucessor->Dir);
				Sucessor->Dir = Remover->Dir;
				Sucessor->Dir->Pai = Sucessor;
			}
			Transplanta(Remover,Sucessor);
			Sucessor->Esq = Remover->Esq;
			Sucessor->Esq->Pai = Sucessor;
		}
	}	
}

int ABB::Nivel(int Valor){
	Noh* Atual = Raiz;
	int Contador = 0;
	while(Atual != NULL and Atual->nDado != Valor){
		Contador++;
		if(Atual->nDado > Valor){
			Atual = Atual->Esq;
		}
		else{
			Atual = Atual->Dir;
		}
	}
	return Contador;
}

void ABB::Ordem(Noh* Atual){
	if(Atual!=NULL){
		Ordem(Atual->Esq);
		cout << Atual->nDado << "/" << Nivel(Atual->nDado) << " ";
		Ordem(Atual->Dir);
	}
}

void ABB::PreOrdem(Noh* Atual){
	if(Atual != NULL){
		cout << Atual->nDado << "/" << Nivel(Atual->nDado) << " ";
		PreOrdem(Atual->Esq);
		PreOrdem(Atual->Dir);
	}
}

int main(){
	char comando;
	ABB Arvore;
	int Valor;
	cin >> comando;
	do{
		switch(comando){
		case'i':
			cin >> Valor;
			Arvore.Insere(Valor);
			break;
		case'r':
			cin >> Valor;
			Arvore.Remove(Valor);
			break;
		case'o':
			Arvore.Ordem();
			break;
		case'p':
			Arvore.PreOrdem();
			break;
		case'f':
			break;
		default:
			cout << "Comando Inválido!" << endl;
		}
		cin >> comando;
	}while(comando!='f');
	return 0;
}

