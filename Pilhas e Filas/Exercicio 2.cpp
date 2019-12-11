#include <iostream>

typedef int Dado;

class Noh {
    friend class Pilha;
    private:
        Dado mDado; // poderia ser outro tipo de variÃ¡vel
        Noh* mPtProx;
};

class Pilha {
	private:
        Noh* mPtTopo;
        unsigned mTamanho;
    public:
        // ConstrÃ³i pilha vazia.
        Pilha();
        // Destrutor que desaloca memÃ³ria.
        ~Pilha();
        // Retira e retorna o valor que estiver no mPtTopo da pilha.
        // Escreve uma mensagem de erro se nÃ£o for possÃ­vel desempilhar.
        Dado Desempilhar(); // retorna o mPtTopo da Pilha
        // Insere um valor na pilha.
        void Empilhar(const Dado& d);
        // Apagar todos os dados da pilha.
        void LimparTudo();
        // Informa quantos valores existem na pilha.
        unsigned Tamanho() { return mTamanho; }
        // Retorna o valor que estÃ¡ no mPtTopo sem desempilhar.
        Dado Topo() const;
        // Informa se a pilha estÃ¡ Vazia.
        bool Vazia() const;
};

using namespace std;
//Contrutor sempre zerar atributos da classe Pilha.
Pilha::Pilha() {
	mPtTopo = NULL;
	mTamanho = 0;
}
//Chamar Desempilhar enquanto o topo não for nulo. 
Pilha::~Pilha(){
	while(mPtTopo != NULL)
		Desempilhar();

}

Dado Pilha::Desempilhar(){
	//Criar variavel para remover.
	int remove;
	//Criar ponteiro do tipo Noh.
	Noh* temp;
	//Remover receber valor do ponteiro que esta apontando para o Dado do Topo.
	remove = mPtTopo->mDado;
	//Ponteiro temporario recebe endereço de memoria do Topo;
	temp = mPtTopo;
	//Ponteiro do Topo recebe o endereço de memoria do Proximo Noh.
	mPtTopo = mPtTopo->mPtProx;
	//Remover o antigo Topo.
	delete temp;
	//Diminuir o tamanho da Pilha.
	mTamanho--;
	//Retornar o valor do antigo Topo(O que foi removido).
	return remove;
}

void Pilha::Empilhar(const Dado& d){
	Noh* temp = new Noh;
	temp->mDado = d;
	temp->mPtProx = mPtTopo;
	mPtTopo = temp;
	mTamanho++; 
}

void Pilha::LimparTudo() {
	while(mPtTopo != NULL)
		Desempilhar();
}

Dado Pilha::Topo() const {
	return mPtTopo->mDado;
}

bool Pilha::Vazia() const {
	return (mPtTopo == NULL);
}

int main() {
    Pilha pilha;
    Dado valor;
    char comando;
    do {
        cin >> comando;
        switch (comando) {
            case 'i': // inserir
                cin >> valor;
                pilha.Empilhar(valor);
                break;
            case 'r': // remover
                cout << pilha.Desempilhar() << endl;
                break;
            case 'l': // limpar tudo
                pilha.LimparTudo();
                break;
            case 't': // consultar tamanho
                cout << pilha.Tamanho() << endl;
                break;
            case 'e': // espiar
                cout << pilha.Topo() << endl;
                break;
            case 'f': // finalizar
                // checado no do-while
                break;
            default:
                cerr << "comando invÃ¡lido\n";
        }
    } while (comando != 'f'); // finalizar execuÃ§Ã£o
    while (not pilha.Vazia()) {
        cout << pilha.Desempilhar() << ' ';
    }
    cout << endl;
    return 0;
}
