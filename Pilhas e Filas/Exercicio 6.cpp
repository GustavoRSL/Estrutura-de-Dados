#include <iostream>

typedef int Dado;

class Fila {
		protected:
        unsigned mCapacidade;
        Dado* mDados;
        unsigned mPosInicio; // indica a posicao do primeiro
        unsigned mPosFim;    // indica a posicao do ultimo
        unsigned mTamanho;
    public:
        Fila(unsigned cap = 80);
        ~Fila();
        // Remove e retorna o primeiro elemento da fila.
        Dado Desenfileira();
        // Insere um valor na fila. Retorna um booleano que informa se a inserÃ§Ã£o foi realmente
        // realizada.
        bool Enfileirar(const Dado& valor);
        // Escreve todo o conteÃºdo do armazenamento da fila na saÃ­da de dados.
        void EscreverConteudo(std::ostream& saida) const;
        // Retorna tamanho, capacidade, inicio e fim da fila.
        void Info(unsigned* ptTam, unsigned* ptCap, unsigned* ptIni, unsigned* ptFim) const;
        // Retorna o primeiro elemento da fila, sem removÃª-lo.
        Dado Proximo() const;
        // Retorna a quantidade de elementos na fila.
        unsigned Tamanho() const { return mTamanho; }
        // Consulta se a fila estÃ¡ vazia.
        bool Vazia() const;
        
};

using namespace std;

Fila::Fila(unsigned cap) { // cap tem valor default
	mCapacidade = cap;
	mDados = new Dado[mCapacidade];
	mPosInicio = -1;
	mPosFim = -1;
	mTamanho = 0;
}

Fila::~Fila() {
		
}

// Remove e retorna o primeiro elemento da fila.
Dado Fila::Desenfileira() {
	if(mTamanho == 0)
		cout << "Fila Vazia!!!";
	
	int aux = mDados[mPosInicio];
	if(mPosInicio == mPosFim){
		mPosFim = -1;
		mPosInicio = -1;
	}
	else
		mPosInicio = (mPosInicio+1)%mCapacidade;
	
	mTamanho--;
	return aux;
}

// Insere um valor na fila. Retorna um booleano que informa se a inserÃ§Ã£o foi realmente realizada.
bool Fila::Enfileirar(const Dado& valor){
	unsigned Menosum = -1;
	
	if(mTamanho == mCapacidade)
		return false;	
	if(mPosInicio == Menosum)
		mPosInicio++;
		
	mPosFim = (mPosFim+1)%mCapacidade;
	mDados[mPosFim] = valor;
	mTamanho++;
	return true;	
}

// Escreve todo o conteÃºdo do armazenamento (comeÃ§ando da posiÃ§Ã£o zero) da fila na saÃ­da de dados.
void Fila::EscreverConteudo(ostream& saida) const {
		for(unsigned i=0; i < mCapacidade; i++){
			cout << mDados[i] << " ";
		}
}

// Retorna tamanho, capacidade, inicio e fim da fila.
void Fila::Info(unsigned* ptTam, unsigned* ptCap, unsigned* ptIni, unsigned* ptFim) const {
	*ptTam = mTamanho;
	*ptCap = mCapacidade;
	*ptIni = mPosInicio;
	*ptFim = mPosFim;
}

// Retorna o primeiro elemento da fila, sem removÃª-lo.
Dado Fila::Proximo() const {
	return mDados[mPosInicio];
}

// Consulta se a fila estÃ¡ vazia.
bool Fila::Vazia() const {
	unsigned menosum = -1;
	return (mPosInicio == menosum);
}

int main() {
    unsigned tamanho, capacidade, inicio, fim;
    cin >> capacidade;
    Fila fila(capacidade);
    Dado valor;
    char comando;
    cin >> comando;
    while (comando != 't') {
        switch (comando) {
        case 'e': // enfileirar
            cin >> valor;
            if (not fila.Enfileirar(valor))
                cout << "FILA CHEIA!\n";
            break;
        case 'd': // desenfileirar
            if (fila.Vazia())
                cout << "ERRO\n";
            else {
                valor = fila.Desenfileira();
                cout << valor << endl;
            }
            break;
        case 'p': // proximo
            if (fila.Vazia())
                cout << "ERRO\n";
            else
                cout << fila.Proximo() << endl;
            break;
        case 'i': // informaÃ§Ãµes sobre a fila
            fila.Info(&tamanho, &capacidade, &inicio, &fim);
            cout << "tamanho=" << tamanho << " capacidade=" << capacidade << " inicio=" << inicio
                 << " fim=" << fim << endl;
            fila.EscreverConteudo(cout);
            break;
        case 't':
            // vai testar novamente no while
            break;
        default:
            cout << "comando invÃ¡lido\n";
        }
        cin >> comando;
    }
    return 0;
}
