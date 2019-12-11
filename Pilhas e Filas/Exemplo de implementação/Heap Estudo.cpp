#include <iostream>
using namespace std;

class Heap{
	private:
		int* vetDados;
		int Tamanho;
		int Capacidade;
	public:
		Heap();
		~Heap();
		void corrigeDescendo(int i);
		void corrigeSubindo(int i);
		void Insere(int Valor);
		void Remove();
		void imprime();
};

Heap::Heap(){
	Tamanho = 0;
	Capacidade = 20;
	vetDados = new int[20];
}
Heap::~Heap(){
		delete[] vetDados;
}

void Heap::Insere(int Valor){
		vetDados[Tamanho] = Valor;
		Tamanho++;
}

void Heap::Remove(){
		swap(vetDados[0],vetDados[Tamanho-1]);
		Tamanho--;
		corrigeDescendo(0);
}

void Heap::imprime(){
		for(int i=0; i<Tamanho; i++)
			cout << vetDados[i] << " ";
}

void Heap::corrigeDescendo(int i){
	int esq = (2*i)+1;
	int dir = (2*i)+2;
	int maior = i;
	if(esq < Tamanho and vetDados[esq]>vetDados[maior])
		maior = esq;
	if(dir < Tamanho and vetDados[dir]>vetDados[maior])
		maior = dir;
	if(maior!=i){
		swap(vetDados[maior],vetDados[i]);
		corrigeDescendo(maior);	
	}
}

void Heap::corrigeSubindo(int i){
	int pai = (i-1)/2;
	if(i > 0 and vetDados[i]>vetDados[pai]){
		swap(vetDados[i],vetDados[pai]);
		corrigeSubindo(pai);
	}	
}

int main(){

	return 0;
}
