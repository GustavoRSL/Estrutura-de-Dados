#include <iostream>
using namespace std;

class Noh{
	friend class Pilha;
	private:
		Noh* nProx;
		int nDado;
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
		int Espia();
		void RemoveTudo();
		bool Vazia();
};

Pilha::Pilha(){
		Topo = NULL;
		Tamanho = 0;
}

Pilha::~Pilha(){
		while(Topo!=NULL)
			Remove();
}

void Pilha::Insere(int Valor){
		Noh* Temp = new Noh;
		Temp->nDado = Valor;
		Temp->nProx = Topo;
		Topo = Temp;
		Tamanho++;
}

int Pilha::Remove(){
		Noh* Temp;
		int Lixo;
		Lixo = Topo->nDado;
		Temp = Topo;
		Topo = Topo->nProx;
		Tamanho--;
		delete Temp;
		return Lixo;
}

int Pilha::Espia(){
		return Topo->nDado;
}

void Pilha::RemoveTudo(){
		while(Topo!=NULL)
			Remove();
}

bool Pilha::Vazia(){
		return (Topo==NULL);
}

int main(){


	return 0;
}
