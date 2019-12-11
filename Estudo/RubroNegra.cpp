#include <iostream>
#include <stdexcept>
#include <queue>

typedef std::string TValor;
typedef unsigned TChave;
enum Cor {PRETO, VERMELHO};

class Noh {
    friend class ArvoreRN;
    friend std::ostream& operator<<(std::ostream& saida, Noh* ptNoh);
    public:
        Noh(unsigned chave, TValor valor);
    private:
        Noh* Tio();
        void DesalocarRecursivo();
        TValor mValor;
        TChave mChave;
        Cor mCor;
        Noh* mEsq;
        Noh* mDir;
        Noh* mPai;
};

class ArvoreRN {
    public:
        ArvoreRN();
        ~ArvoreRN();
        void EscreverNivelANivel(std::ostream& saida);
        void Inserir(unsigned chave, TValor valor);
    private:
        void ArrumarInsercao(Noh* umNoh);
        void RotacionarDireita(Noh* umNoh);
        void RotacionarEsquerda(Noh* umNoh);
        Noh* mRaiz;
};

using namespace std;

// === classe Noh ==============================================================
Noh::Noh(TChave chave, TValor valor)
    : mValor(valor), mChave(chave), mCor(VERMELHO), mEsq(NULL), mDir(NULL), mPai(NULL) {
}

// Desaloca as subÃ¡rvores e depois a si prÃ³prio.
void Noh::DesalocarRecursivo() {
}

// === classe ArvoreRN =========================================================
ArvoreRN::ArvoreRN() : mRaiz(NULL) {
}

ArvoreRN::~ArvoreRN() {
    delete mRaiz;
}

Noh* Noh::Tio() {
	if(mPai->mPai == NULL)
		return NULL;
	else if(mPai == mPai->mPai->mDir) //Se for nulo retorna NULL
	{
		return mPai->mPai->mEsq;
	}
	else //(mPai == mPai->mPai->mEsq)
	{
		return mPai->mPai->mDir;
	}
}


// insere uma chave/valor na Ã¡rvore,
// chama ArrumarInsercao para corrigir eventuais problemas
void ArvoreRN::Inserir(unsigned chave, TValor valor) {
	Noh *objeto = new Noh(chave,valor);
	
	if(mRaiz == NULL)
		mRaiz = objeto;
	else
	{
		Noh *anterior = NULL;
		Noh *aux = mRaiz;
		while(aux != NULL) //Achar a posição
		{
			anterior = aux;
			if(objeto->mChave <= aux->mChave)
				aux = aux->mEsq;
			else
				aux = aux->mDir;
		}
		
		objeto->mPai = anterior;
		if(objeto->mChave <= anterior->mChave)
			anterior->mEsq = objeto;
		else
			anterior->mDir = objeto;
	}
	
	ArrumarInsercao(objeto);
}


// procedimento para manter balanceamento apÃ³s inserÃ§Ã£o
void ArvoreRN::ArrumarInsercao(Noh* umNoh) {
	// percorre a árvore do nó até a raiz,
	// ou ter arrumado o balanceamento
	
	while(umNoh != mRaiz and umNoh->mPai->mCor == VERMELHO)
	{
		Noh *tio = umNoh->Tio(); //Se foi NULL o tio é NIL(PRETO)
		Noh *avo = NULL;
		if(tio != NULL and tio->mCor == VERMELHO)
		{
			tio->mCor = PRETO;
			umNoh->mPai->mCor = PRETO;
			umNoh->mPai->mPai->mCor = VERMELHO;
			umNoh = umNoh->mPai->mPai;
		}
		else
		{
			//Pai é filho Direito e umNoh é filho direito
			if(umNoh->mPai == umNoh->mPai->mPai->mDir and umNoh == umNoh->mPai->mDir)
			{
				umNoh->mPai->mCor = PRETO;
				umNoh->mPai->mPai->mCor = VERMELHO;
				RotacionarEsquerda(umNoh->mPai->mPai);
				umNoh = umNoh->mPai;
			}
			//Pai é filho Esquerdo e um Noh é filho esquerdo
			else if(umNoh->mPai == umNoh->mPai->mPai->mEsq and umNoh == umNoh->mPai->mEsq)
			{
				umNoh->mPai->mCor = PRETO;
				umNoh->mPai->mPai->mCor = VERMELHO;
				RotacionarDireita(umNoh->mPai->mPai);
				umNoh = umNoh->mPai;
			}
			else if(umNoh->mPai == umNoh->mPai->mPai->mEsq and umNoh == umNoh->mPai->mDir)
			{
				umNoh->mCor = PRETO;
				avo = umNoh->mPai->mPai;
				avo->mCor = VERMELHO;
				RotacionarEsquerda(umNoh->mPai);
				RotacionarDireita(avo);
				umNoh = umNoh->mPai;
			}
			else //(umNoh->mPai == umNoh->mPai->mPai->mDir and umNoh == umNoh->mPai->mEsq)
			{
				umNoh->mCor = PRETO;
				avo = umNoh->mPai->mPai;
				avo->mCor = VERMELHO;
				RotacionarDireita(umNoh->mPai);
				RotacionarEsquerda(avo);
				umNoh = umNoh->mPai;
			}
		}
	}
	
	mRaiz->mCor = PRETO;
}

// rotaÃ§Ã£o Ã  esquerda, muda a raiz se necessÃ¡rio
void ArvoreRN::RotacionarEsquerda(Noh* umNoh) {
    Noh* Aux = umNoh->mDir;
    umNoh->mDir = Aux->mEsq;
    if(Aux->mEsq != NULL){
		Aux->mEsq->mPai = umNoh;
	}
	Aux->mPai = umNoh->mPai;
	if(umNoh == mRaiz){
		mRaiz = Aux;
	}
	else if(umNoh == umNoh->mPai->mEsq){
		umNoh->mPai->mEsq = Aux;
	}
	else{
		umNoh->mPai->mDir = Aux;
	}
	Aux->mEsq = umNoh;
	umNoh->mPai = Aux;
}

// rotaÃ§Ã£o Ã  direita, muda a raiz se necessÃ¡rio
void ArvoreRN::RotacionarDireita(Noh* umNoh) {
    Noh* Aux = umNoh->mEsq;
    umNoh->mEsq = Aux->mDir;
    if(Aux->mDir != NULL){
		Aux->mDir->mPai = umNoh;
	}
	Aux->mPai = umNoh->mPai;
	if(umNoh == mRaiz){
		mRaiz = Aux;
	}
	else if(umNoh == umNoh->mPai->mEsq){
		umNoh->mPai->mEsq = Aux;
	}
	else{
		umNoh->mPai->mDir = Aux;
	}
	Aux->mDir = umNoh;
	umNoh->mPai = Aux;
}

// Escreve o conteÃºdo da Ã¡rvore nÃ­vel a nÃ­vel
void ArvoreRN::EscreverNivelANivel(ostream& saida) {
    queue<Noh*> filhos;
    filhos.push(mRaiz);
    while (not filhos.empty()) {
        unsigned nroNohsNesteNivel = unsigned(filhos.size());
        for (unsigned i = 0; i < nroNohsNesteNivel; ++i) {
            Noh* ptNoh = filhos.front();
            filhos.pop();
            saida << ptNoh << ' ';
            if (ptNoh != NULL) {
                filhos.push(ptNoh->mEsq);
                filhos.push(ptNoh->mDir);
            }
        }
        cout << "\n";
    }
}

// Escreve um nÃ³ (ou NIL).
ostream& operator<<(ostream& saida, Noh* ptNoh) {
    static char vetLetrasCores[] = "PV";
    if (ptNoh == NULL)
        saida << "NIL";
    else
        saida << '[' << vetLetrasCores[ptNoh->mCor] << ':' << ptNoh->mChave << '/'
              << ptNoh->mValor << ']';
    return saida;
}

int main() {
    ArvoreRN arvore;
    char opcao;
    TChave chave;
    TValor valor;
    do {
        cin >> opcao;
        switch (opcao) {
            case 'i': // Inserir
                cin >> chave >> valor;
                arvore.Inserir(chave, valor);
                break;
            case 'e': // Escrever nÃ³s nÃ­vel a nÃ­vel
                arvore.EscreverNivelANivel(cout);
                break;
            case 'f': // Finalizar o programa
                // vai verificar depois
                break;
            default:
                cerr << "OpÃ§Ã£o invÃ¡lida\n";
        }
    } while (opcao != 'f');
    return 0;
}
