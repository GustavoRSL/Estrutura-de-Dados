#include <iostream>
using namespace std;

typedef int Dado;

class Noh {
    friend class Fila;
    private:
        Dado mDado;
        Noh* mPtProx;
};

class Fila {
	private:
        Noh* mPrimeiro;
        Noh* mUltimo;
        unsigned mTamanho;
    public:
        // Constroi uma fila vazia.
        Fila();
        // Desaloca memÃ³ria de todos os nÃ³s da fila.
        ~Fila();
        // Remove e retorna o primeiro item da fila.
        Dado Remover();
        // Insere um item no final da fila.
        void Inserir(const Dado& d);
        // Retorna o primeiro item da fila sem remover.
        Dado Proximo() const;
        // Remove todos os itens da fila.
        void LimparTudo();
        // Consulta a quantidade de itens na fila.
        unsigned Tamanho() const { return mTamanho; }
        // Consulta se a fila estÃ¡ vaiza.
        bool Vazia() const;
};


Fila::Fila(){
	mPrimeiro = NULL;
	mUltimo = NULL;
	mTamanho = 0;
}

Fila::~Fila() {
	while(mUltimo!=NULL)
		Remover();
}

void Fila::Inserir(const Dado& d) {
	Noh* temp = new Noh;
	temp->mDado = d;
	temp->mPtProx = NULL;
	if(mUltimo != NULL)
	mUltimo->mPtProx = temp;
	
	mUltimo = temp;
	
	if(Vazia())
	mPrimeiro = temp;
	
	mTamanho++;
}

Dado Fila::Remover() {
	int Remove;
	Noh* temp = new Noh;
	Remove = mPrimeiro->mDado;
	temp = mPrimeiro;
	mPrimeiro = mPrimeiro->mPtProx;
	if(Vazia())
	mUltimo = NULL;

	delete temp;
	mTamanho--;
	return Remove;
}

Dado Fila::Proximo() const {
	return mPrimeiro->mDado;
}

void Fila::LimparTudo() {
	while(mUltimo!=NULL)
		Remover();
}

bool Fila::Vazia() const {
	return (mPrimeiro == NULL);
}

int main() {
    Fila fila;
    Dado valor;
    char comando;
    do {
        cin >> comando;
        switch (comando) {
            case 'i': // inserir
                cin >> valor;
                fila.Inserir(valor);
                break;
            case 'r': // remover
                cout << fila.Remover() << endl;
                break;
            case 'l': // limpar tudo
                fila.LimparTudo();
                break;
            case 't': // escrever tamanho
                cout << fila.Tamanho() << endl;
                break;
            case 'e': // espiar proximo
                cout << fila.Proximo() << endl;
                break;
            case 'f': // finalizar
                // vai verificar adiante
                break;
            default:
                cerr << "comando invÃ¡lido\n";
        }
    } while (comando != 'f'); // finalizar execuÃ§Ã£o
    while (not fila.Vazia()) {
        cout << fila.Remover() << ' ';
    }
    cout << endl;
    return 0;
}
