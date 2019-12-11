#include <iostream>
using namespace std;

class Noh{
	friend class Pilha;
	
	private:
		char nDados;
		Noh* nProx;
};

class Pilha{
	private:
		Noh* Topo;
		int Tamanho;
	public:
		Pilha();
		~Pilha();
		void Insere(const char Valor);
		void Remove();
		bool Vazia() const;
		int rTamanho();
		
};

Pilha::Pilha(){
	Topo = NULL;
	Tamanho = 0;
}

Pilha::~Pilha(){
	while(Topo != NULL)
		Remove();
}

void Pilha::Insere(const char Valor){
		Noh* Temp = new Noh;     //Cria um novo Noh
		Temp->nDados = Valor;	 //Novo Noh receber valores para seus atribuitos (nDados e nProx)
		Temp->nProx = Topo;		 //nProx sempre aponta para o antigo Topo
		Topo = Temp;			 //Novo Topo passar a ser o Novo Noh
		Tamanho++;				 //Tamanho incrementa
}

void Pilha::Remove(){
	Noh* Temp;					 //Criar outro Noh.
	Temp = Topo;				 //Noh Temporario vira Topo.
	Topo = Topo->nProx;			 //Topo passa a ser o antigo Topo(nProx).
	delete Temp;				 //Deleta o endereço do Noh
	Tamanho--;					 //Tamanho é decrementado
}


bool Pilha::Vazia() const{
	return (Topo==NULL);
}


int Pilha::rTamanho(){
	return Tamanho;
}
int main(){
	Pilha pilhaA;
	Pilha pilhaC;
	int Aux = 0;
	int ContB = 0;
	char Letras[256];
	
	for (int i = 0; i < 127; i++){
		Letras[i] = 0;
	}
	
	cin >> Letras;
	
	for(int i=0;Letras[i]!=0; i++){
		if(Letras[i] == 'A' and ContB == 0){
			pilhaA.Insere('A');
			pilhaC.Insere('C');
			pilhaC.Insere('C');
		}
		
		if(Letras[i] == 'B' and ContB == 0){
			ContB++;
			for(int j=(i+1); Letras[j]!='B' and Letras[j]=='C'; j++){
				if(pilhaC.Vazia())
				
				pilhaC.Remove();
			}
		}
		
		if(Letras[i] == 'B' and ContB == 1 and pilhaC.rTamanho() == 0){
			for(int j=(i+1); Letras[j]!=0 and Letras[j]=='A'; j++){
				if(pilhaA.Vazia())
				
				pilhaA.Remove();
			}
		}
		Aux = i;
	}
	if(Letras[Aux+1]==0 and pilhaA.rTamanho() == 0 and pilhaC.rTamanho() == 0)
	cout << "sim" << " " << pilhaA.rTamanho() << " " << pilhaC.rTamanho();
	else 
	cout << "nao" << " " << pilhaA.rTamanho() << " " << pilhaC.rTamanho();
	
	return 0;
}
