#include <iostream>
using namespace std;

class Noh{
	friend class Fila;
		private:
			Noh* nProx;
			int nDado;
};

class Fila{
		private:
			Noh* Primeiro;
			Noh* Ultimo;
			int Tamanho;
		public:
			Fila();
			~Fila();
			void Insere(int Valor);
			int Remove();
			int Espia();
			void RemoveTudo();
			bool Vazia();
};

Fila::Fila(){
		Primeiro = NULL;
		Ultimo = NULL;
		Tamanho = 0;
}

Fila::~Fila(){
		while(not Vazia())
			Remove();
}

void Fila::Insere(int Valor){
		Noh* Temp = new Noh;
		Temp->nDado = Valor;
		Temp->nProx = NULL;
		if(Ultimo!=NULL)
			Ultimo->nProx = Temp;
		Ultimo = Temp;
		if(Vazia())
			Primeiro = Temp;
		Tamanho++;
}

int Fila::Remove(){
		Noh* Temp;
		int Lixo;
		Lixo = Primeiro->nDado;
		Temp = Primeiro;
		Primeiro = Primeiro->nProx;
		if(Vazia())
			Ultimo = NULL;
		delete Temp;
		Tamanho--;
		return Lixo;
}

int Fila::Espia(){
		return Primeiro->nDado;
}

void Fila::RemoveTudo(){
		while(not Vazia())
			Remove();
}

bool Fila::Vazia(){
		return(Primeiro==NULL);
}


int main(){

	return 0;
}
