// Tabela Hash com tratamento de colisão por endereçamento aberto
#include <iostream>
#include <stdexcept>

typedef int TValor; // tipo do valor armazenado

class InfoHash {
    friend class Hash; // essa classe só deve ser usada na classe Hash
    InfoHash();
    InfoHash(const std::string& chave, const TValor& valor);
    std::string mChave;
    TValor mValor;
};

class Hash {
    public:
        Hash(unsigned capacidade = 50);
        ~Hash();
        // Mostra todos as posições de armazenamento da hash.
        void EscreverEstrutura(std::ostream& saida) const;
        // Insere uma cópia do valor. Não permite inserção de chave repetida.
        void Inserir(const std::string& chave, const TValor& valor);
        // Remove um item da hash associado com a chave dada.
        void Remover(const std::string& chave);
        // Retorna o valor associado a uma chave.
        TValor Valor(const std::string& chave) const;
    protected:
        // Retorna a posicao em que uma chave está armazenada na estrutura.
        unsigned Buscar(const std::string& chave) const;
        // Retorna a posicao em que uma chave deveria ficar na estrutura.
        unsigned Posicao(const std::string& chave) const;

        InfoHash** mVetPtDados;
        InfoHash* REMOVIDO; // ponteiro especial a ser usado para marcar posições de elemento removido
        unsigned mCapacidade;
        unsigned mTamanho;
};

using namespace std;

InfoHash::InfoHash()
    : mChave(), mValor() {
}

InfoHash::InfoHash(const std::string& chave, const TValor& valor)
    : mChave(chave), mValor(valor) {
}

Hash::Hash(unsigned capacidade) // capacidade tem valor default
    : mVetPtDados(new InfoHash*[capacidade]), REMOVIDO(new InfoHash()), mCapacidade(capacidade), mTamanho(0) {
    // inicializar todas as posições de armazenamento com NULL indicando posição VAZIA
    for(unsigned i = 0; i < capacidade; i++) {
		mVetPtDados[i] = NULL;
	}
}

Hash::~Hash() {
    // desalocar memória de cada item (InfoHash) armazenado
    for(unsigned i=0; i<mTamanho; i++){
		mVetPtDados[i] = NULL;
	}	
    // desalocar o ponteiro especial REMOVIDO
    delete REMOVIDO;
    // desalocar o vetor de ponteiros
    delete[] mVetPtDados;
}

unsigned Hash::Buscar(const std::string& chave) const {
    // Retorna a posicao em que uma chave está armazenada na estrutura. Protegido.
    unsigned Pos = Posicao(chave);
    unsigned Contador = 0;
    bool Achou = false;
    while(Contador < mCapacidade and Achou == false){
		if(mVetPtDados[Pos] != NULL and mVetPtDados[Pos] != REMOVIDO){
			if(mVetPtDados[Pos]->mChave == chave){
				Achou = true;
			}
			else{
				if(Pos+1 == mCapacidade){
					Pos = 0;
				}
				else{
					Pos++;
				}
				Contador++;
			}
		}
		else {
		  if(Pos+1 == mCapacidade){
			Pos = 0;
		  }
	   	  else{
			Pos++;
		  }
		  Contador++;
		}
	}
	if(mVetPtDados[Pos] != NULL and mVetPtDados[Pos]->mChave == chave)
		return Pos;
	else
		throw invalid_argument("chave nao encontrada");
}

void Hash::EscreverEstrutura(std::ostream& saida) const {
    // Mostra todos as posições de armazenamento da hash. Ajuda a debugar.
    for (unsigned i = 0; i < mCapacidade; ++i) {
        saida << '[' << i;
        if (mVetPtDados[i] != NULL) {
            if (mVetPtDados[i] == REMOVIDO)
                saida << "/removido";
            else
                saida << '/' << mVetPtDados[i]->mChave << '/' << mVetPtDados[i]->mValor;
        }
        saida << "] ";
    }
}

void Hash::Inserir(const string& chave, const TValor& valor) {
    // Insere uma cópia do valor. Não permite inserção de chave repetida.
    if(mTamanho < mCapacidade){
		InfoHash* Novo = new InfoHash(chave,valor);
		int Pos = Posicao(chave);
		while(mVetPtDados[Pos] != NULL and mVetPtDados[Pos]->mChave != chave and mVetPtDados[Pos] != REMOVIDO){
			Pos++;
			Pos %= mCapacidade;
		}	
		if(mVetPtDados[Pos] == NULL or mVetPtDados[Pos] == REMOVIDO){
			mTamanho++;
			mVetPtDados[Pos] = Novo; 
		}
		else
			throw invalid_argument("chave repetida");
	}
	else{
		Inserir(chave,valor);
	}
}

unsigned Hash::Posicao(const string& chave) const {
    // Retorna a posição de armazenamento de uma chave, 0 <= posicao < mCapacidade. Protegido.
    unsigned pos = 1;
    unsigned tamanho = unsigned(chave.length());
    for (unsigned i = 0; i < tamanho; ++i)
        pos = 7 * pos + chave[i];
    return pos % mCapacidade;
}

void Hash::Remover(const std::string& chave) {
    // Remove um item da hash associado com a chave dada.
    unsigned Pos = Buscar(chave);
    delete mVetPtDados[Pos];
    mVetPtDados[Pos] = REMOVIDO;
    mTamanho--;
}

TValor Hash::Valor(const std::string& chave) const {
    // Retorna o valor associado a uma chave.
    unsigned Pos = Buscar(chave);
    return mVetPtDados[Pos]->mValor;
}

int main() {
    unsigned capacidade;
    cin >> capacidade;
    Hash tabela(capacidade);
    char operacao;
    string chave;
    TValor valor;
    do {
        try {
            cin >> operacao;
            switch (operacao) {
                case 'i': // inserir
                    cin >> chave >> valor;
                    tabela.Inserir(chave, valor);
                    break;
                case 'r': // remover
                    cin >> chave;
                    tabela.Remover(chave);
                    break;
                case 'c': // consultar
                    cin >> chave;
                    valor = tabela.Valor(chave);
                    cout << valor << endl;
                    break;
                case 'd': // debug (mostrar estrutura)
                    tabela.EscreverEstrutura(cout);
                    cout << endl;
                    break;
                case 'f': // finalizar
                    // vai testar depois
                    break;
                default:
                    cerr << "operação inválida\n";
            }
        }
        catch (exception& e) {
            // ignorar a mensagem que explica o erro e só escrever ERRO.
            cout << "ERRO" << endl;
        }
    } while (operacao != 'f');
    return 0;
}
