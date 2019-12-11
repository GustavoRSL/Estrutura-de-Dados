// Este programa é uma implementação mínima de Lista.
// Sem atributos tamanho e último, sem remoção, sem alteração, etc...
// Os métodos estão "no nó".

#include <iostream>

typedef int Dado;

class Noh;

// === Declaração da Lista ======
class Lista {
    public:
        // Cria Lista vazia.
        Lista();
        // Desaloca memória.
        ~Lista();
        // Insere um dado no fim da lista.
        void InserirNoFim(const Dado& dado);
        // Retorna um item da lista.
        Dado Item(unsigned pos);
        // Escreve todos os itens da lista.
        void Escrever(std::ostream& saida);
    protected:
        Noh* mPtPrimeiro;
};

// === Declaração do Noh ========
class Noh {
    public:
        Noh(Dado d, Noh* prox);
        ~Noh();
        void DesalocarProximos();
        void EscreverDadosAPartirDaqui(std::ostream& saida);
        Dado Item(unsigned distancia);
        void ProcurarUltimoEInserir(const Dado& dado);
    protected:
        Dado mDado;
        Noh* mPtProximo;
};

using namespace std;

// === Implementação do Noh =====
Noh::Noh(Dado d, Noh* prox)
    : mDado(d), mPtProximo(prox) {
}

Noh::~Noh() {
    cout << "Noh com o valor " << mDado << " desalocado.\n";
}

void Noh::DesalocarProximos() {
// desaloca todos os nós que aparecerem depois deste
    if (mPtProximo != NULL) {
        mPtProximo->DesalocarProximos();
        delete mPtProximo;
    }
}
void Noh::EscreverDadosAPartirDaqui(std::ostream& saida) {
// escreve o dado deste nó e todos os próximos, separados por vírgula
    saida << mDado;
    if (mPtProximo != NULL) {
        saida << ',';
        mPtProximo->EscreverDadosAPartirDaqui(saida);
    }
}

Dado Noh::Item(unsigned distancia) {
    // Retorna o item à distância especificada deste nó.
    unsigned posicao = 0;
    int retorno;
    Noh* Aux =  this;
    bool Busca = false;
    while(posicao < distancia and Aux->mPtProximo!=NULL){
		Aux = Aux->mPtProximo;
		posicao++;
	}
	if(posicao == distancia)
		Busca = true;
	retorno = Aux->mDado;
    // Escreve mensagem de erro e retorna dado default se a distância for inválida.
    if(Busca == false){
		cout << "Erro: posicao invalida!\n";
		retorno = 0;
	}
    return Dado(retorno); // se deu erro, retorna dado default só para o compilador não reclamar
}

void Noh::ProcurarUltimoEInserir(const Dado& dado) {
	Noh* Aux = this;
	Noh* Novo = new Noh(dado,NULL);
	while(Aux->mPtProximo != NULL)
		Aux = Aux->mPtProximo;
	Aux->mPtProximo = Novo;
}

// === Implementação da Lista ===
Lista::Lista()
    : mPtPrimeiro(NULL) {
// constrói uma Lista inicialmente vazia
}

Lista::~Lista() {
    if (mPtPrimeiro != NULL) {
        mPtPrimeiro->DesalocarProximos();
        delete mPtPrimeiro;
    }
}

void Lista::Escrever(ostream& saida) {
// escreve os elementos da lista na saida indicada
    saida << '[';
    if (mPtPrimeiro != NULL)
        mPtPrimeiro->EscreverDadosAPartirDaqui(saida);
    saida << "]\n";
}

void Lista::InserirNoFim(const Dado& dado) {
// insere um dado no final da lista
    if (mPtPrimeiro == NULL)
        mPtPrimeiro = new Noh(dado, NULL);
    else
        mPtPrimeiro->ProcurarUltimoEInserir(dado);
}

Dado Lista::Item(unsigned pos) {
    if (mPtPrimeiro != NULL)
        return mPtPrimeiro->Item(pos);
    cout << "Erro: posicao invalida!\n";
    return Dado(); // em caso de erro, retorna o dado default só para o compilador não reclamar
}

int main() {
    Lista lista;
    Dado valor;
    char opcao;
    int pos;
    cin >> opcao;
    while (opcao != 'f') {
        switch(opcao) {
            case 'i': // Inserir
                cin >> valor;
                lista.InserirNoFim(valor);
                lista.Escrever(cout);
                break;
            case 'p': // item na Posicao
                cin >> pos;
                cout << lista.Item(pos) << endl;
                break;
            default:
                cout << "Erro: opcao invalida!\n";
        }
        cin >> opcao;
    }
    return 0;
}
