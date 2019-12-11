#include <iostream>
using namespace std;

class Heap{
	private:
	    int Capacidade;
		int* Dados;
		int Tamanho;
	public:
		Heap();
		~Heap();
		int Pai(int i);
		int Esq(int i);
		int Dir(int i);
		void CorrigeDescendo(int i);
		void CorrigeSubindo(int i);
		void RetiraRaiz();
		void Insere(int Dado);
		void Imprime();
};

Heap::Heap(){
	Capacidade = 20;
	Dados = new int[Capacidade];
	Tamanho = 0;
}

Heap::~Heap(){
	delete[] Dados;
}

int Heap::Pai(int i){
	return (i-1)/2;
}

int Heap::Esq(int i){
	return (i*2)+1;
}

int Heap::Dir(int i){
	return (i*2)+2;
}

void Heap::CorrigeDescendo(int i){
	int E = Esq(i);
	int D = Dir(i);
	int Maior = i;
	if((E <= Tamanho-1) and Dados[E] > Dados[Maior]){
		Maior = E;
	}
	if((D <= Tamanho-1) and Dados[D] > Dados[Maior]){
		Maior = D;
	}
	if(Maior != i){
		swap(Dados[i],Dados[Maior]);
		CorrigeDescendo(Maior);
	}
}	

void Heap::CorrigeSubindo(int i){
	int P = Pai(i);
	if(P >= 0 and Dados[i] > Dados[P]){
		swap(Dados[i],Dados[P]);
		CorrigeSubindo(P);
	}
}

void Heap::RetiraRaiz(){
	if(Tamanho == 0){
		cout << "Heap Vazio!" << endl;
	}
	else{
		cout << "[" << Dados[0] << "]" << "Removido!" << endl;
		swap(Dados[0],Dados[Tamanho-1]);
		Tamanho--;
		CorrigeDescendo(0);
	}
}

void Heap::Insere(int Dado){
	if(Tamanho == Capacidade){
		cout << "Capacidade Maxima excedida!" << endl;
	}
	else{
		Dados[Tamanho] = Dado;
		CorrigeSubindo(Tamanho);
		Tamanho++;
	}
}

void Heap::Imprime(){
	for(int i=0; i<Tamanho; i++){
		cout << "[" <<Dados[i] << "], ";
	}
	cout << endl;
}

int main(){
	Heap Rip;
	int Valor;
	char comando;
	do{
		cin >> comando;
		switch(comando){
			case 'i':
				cin >> Valor;
				Rip.Insere(Valor);
				break;
			case 'r':
				Rip.RetiraRaiz();
				break;
			case 'd':
				Rip.Imprime();
				break;
		}
	}while(comando != 'f');
	return 0;
}
