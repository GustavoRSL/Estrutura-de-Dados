#include <iostream>
using namespace std;

typedef int Dado; // para facilitar a troca de int para outro tipo
 
// pilha implementada em arranjo 
class Pilha {
    private:
        int capacidade;
        Dado *dados;
        int tamanho;
        int posTopo;
    public:
        Pilha(int cap = 100);
        ~Pilha();
        void empilha(Dado valor);
        Dado desempilha();
        Dado espia(); // acessa elemento do topo, mas não retira
        void depura(); // imprime os dados do vetor da pilha sem removê-los (desempilhar)
        void info();  // imprime informações da pilha (tamanho e  posição do topo)
};

//Construtor
Pilha::Pilha(int cap){
	capacidade = cap;
	dados = new Dado[cap];
	tamanho = 0;
	posTopo = -1;
}
//Empilha
void Pilha::empilha(Dado valor){
	dados[tamanho++] = valor;
	posTopo++;
}
//Desempilha
Dado Pilha::desempilha(){
	tamanho--;
	posTopo--;
	return dados[posTopo+1];
}
//Espia
Dado Pilha::espia(){
	return dados[posTopo];
}
//Depura
void Pilha::depura(){
	for(int i=0; i<tamanho; i++)
	cout << dados[i] << " ";
	
	cout << endl;
}
//Info
void Pilha::info(){
		cout << tamanho << " " << posTopo;
}

//Destrutor
Pilha::~Pilha(){
	delete[] dados;
}


int main()
{
	Pilha pilha(20);
	Dado valor;
	
	for(int i=0; i<5; i++){
	 cin >>  valor;
	 pilha.empilha(valor);
	}
	
	for(int i=0; i<3; i++){
		cout << pilha.desempilha() << " ";
	}
	cout << endl;
	
	for(int i=0; i<4; i++){
	 cin >>  valor;
	 pilha.empilha(valor);
	}
	
	for(int i=0; i<3; i++){
		cout << pilha.desempilha() << " ";
	}
	cout << endl;
	
	cout << pilha.espia() << endl;
	pilha.depura();
	pilha.info();
	
	return 0;
}
