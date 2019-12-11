#include <iostream>
#include <string>

typedef char TipoDado;

using namespace std;

class noh {
    friend class Pilha;
    private:
        TipoDado dado;
        noh* prox;
};

// Pilha dinamicamente encadeada
class Pilha {
    private:
        noh* topo;
        int tamanho;
        
    public:
        Pilha();
        ~Pilha();

        // Coloca um dado na pilha.
        void push(TipoDado d) { empilha(d); }
        void empilha(TipoDado d);

        // Retira e retorna um valor da pilha. Requer que a pilha nÃ£o esteja vazia.
        TipoDado desempilha();
        TipoDado pop() { return desempilha(); } 
        
        int rTamanho();

        bool vazia();
};

Pilha::Pilha() {
    tamanho = 0;
    topo = NULL;
}

Pilha::~Pilha() {
    while (topo != NULL) {
        desempilha();
    }
}

void Pilha::empilha(TipoDado d) {
    // primeiro criamos o novo nÃ³
    noh* temp = new noh;
    temp->dado = d;
    temp->prox = topo;
    topo = temp;
    tamanho++;    
}

// Retira e retorna um valor da pilha. Requer que a pilha nÃ£o esteja vazia.
TipoDado Pilha::desempilha() {
    TipoDado removido = topo->dado;
    noh* temp = topo;
    topo = topo->prox;
    delete temp;
    tamanho--;
    return removido;    
}

int Pilha::rTamanho(){
		return tamanho;
}

bool Pilha::vazia() {
    return (topo == NULL);
}

int main() {
	Pilha pilhaAbre;
	Pilha pilhaFecha;
	
	char Frase[254];
	for(int i=0; i<254; i++)
		Frase[i] = 0;
		
	cin.getline(Frase,254);
	
	for(int i=0; Frase[i]!=0; i++){
		if(Frase[i]=='(')
		pilhaAbre.push('(');
		
		if(Frase[i]==')')
		pilhaFecha.push(')');
	}
	
	int Des = 0;
	
	if(pilhaAbre.rTamanho() == pilhaFecha.rTamanho())
		cout << "correto";
	
	if(pilhaAbre.rTamanho()>pilhaFecha.rTamanho() and Des == 0){
		while(pilhaFecha.rTamanho() > 0){
		pilhaAbre.desempilha();
		pilhaFecha.desempilha();
		Des++;
		}
		Des+=1;
		for(int i=0; Des!=0; i++){
			if(Frase[i] == '(')
			Des--;
			
			if(Des==0)
			cout << i;
			
		}
	}
	
	if(pilhaAbre.rTamanho()<pilhaFecha.rTamanho() and Des == 0){
		while(pilhaAbre.rTamanho() > 0){
		pilhaAbre.desempilha();
		pilhaFecha.desempilha();
		Des++;
		}
		Des+=1;
		for(int i=0; Des!=0; i++){
			if(Frase[i] == ')')
			Des--;
			
			if(Des==0)
			cout << i;
		}
		
	}
	
    return 0;
}
