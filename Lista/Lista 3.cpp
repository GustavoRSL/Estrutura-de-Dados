#include <iostream>

using namespace std;

typedef int Dado;

class noh {
    friend class lista;
    private:
        const Dado dado;
        noh* proximo;
    public:
        noh(Dado d = 0);
};

noh::noh(Dado d) : dado(d) {
    proximo = NULL;
}

class lista {
    private:
        noh* primeiro;
        noh* ultimo;
        int tamanho;
    public:
        lista();
        ~lista();
        void insere(Dado dado);
        void insere(Dado dado, int pos);
        void remove(int posicao);
        int procura(Dado valor);
        void imprime();
        inline bool vazia();
};

// constrói uma lista inicialmente vazia
lista::lista() {
    tamanho = 0;
    primeiro = NULL;
    ultimo = NULL;
}

lista::~lista() {
    noh* iter = primeiro;
    noh* proximo = NULL;
    while (iter != NULL) {
        proximo = iter->proximo;
        delete iter;
        iter = proximo;
    }
}

// método básico que *percorre* a lista, imprimindo seus elementos
void lista::imprime() {
    noh* aux = primeiro;
    while (aux != NULL) {
        cout << aux->dado << " ";
        aux = aux->proximo;
    }
    cout << endl;
}

// insere por padrão no final da lista
void lista::insere(Dado dado) {
	noh* Novo = new noh(dado);
    if(vazia()){
		primeiro = Novo;
	}
	else{
		ultimo->proximo = Novo;
	}
	ultimo = Novo;
	tamanho++;
}

// insere um dado em uma determinada posição da lista
void lista::insere(Dado dado, int posicao) {
    if(vazia()){
		insere(dado);
	}
	else if(posicao == 0){
		noh* Novo = new noh(dado);
		Novo->proximo = primeiro;
		primeiro = Novo;
		tamanho++;
	}
	else if(posicao == (tamanho-1)){
		insere(dado);
	}
	else{
		noh* Novo = new noh(dado);
		noh* Aux = primeiro;
		int posAux = 0;
		while(posAux < (posicao-1)){
			Aux = Aux->proximo;
			posAux++;
		}
		Novo->proximo = Aux->proximo;
		Aux->proximo = Novo;
		tamanho++;
	}	
}

// remove o item da posição passada por parâmetro
// Atenção - o código deve tratar de posição inválidas
void lista::remove(int posicao) {
    if(vazia())
		cerr << "Lista Vaiza!!!";
	else if(posicao < 0 or posicao >= tamanho)
		cerr << "Posição invalida!!!";
	else{
			if(posicao == 0){
				noh* Aux = primeiro;
				primeiro = Aux->proximo;
				delete Aux;
				tamanho--;
				if(vazia())
					ultimo = NULL;
			}
			else if(posicao == (tamanho-1)){
				noh* Aux = primeiro;
				while(Aux->proximo->proximo != NULL)
					Aux = Aux->proximo;
				ultimo = Aux;
				delete Aux->proximo;
				tamanho--;
				Aux->proximo = NULL;
			}
			else{
				noh* Aux = primeiro;
				noh* Anterior = Aux;
				int posAux = 0;
				while(posAux != posicao){
					posAux++;
					Anterior = Aux;
					Aux = Aux->proximo;
				}
				Anterior->proximo = Aux->proximo;
				tamanho--;
				Aux->proximo = NULL;
				delete Aux;
				if(primeiro == NULL)
					ultimo = NULL;
			}
		}
}

// procura por um elemento e retorna a posição ou -1 se não encontrado
int lista::procura(Dado valor) {
    noh* Aux = primeiro;
    int posicao = 0;
    bool busca = false;
    while(Aux != NULL){
		if(Aux->dado == valor){
			busca = true;
			Aux = NULL;
		}
		else{
			Aux = Aux->proximo;
			posicao++;
		}
	}
	if(busca == false)
		posicao = -1;
	
	return posicao;
}

// verifica se a lista está vazia
inline bool lista::vazia() {
    return (primeiro == NULL);
}

int main() { // NÃO MODIFIQUE!
    lista minhaLista;
    char opcao;
    int valor, pos;
    cin >> opcao;
    while (opcao != 'Q') {
        switch(opcao) {
            case 'I':
                cin >> valor;
                minhaLista.insere(valor);
                break;
            case 'W':
                cin >> valor;
                cin >> pos;
                minhaLista.insere(valor, pos);
                break;
            case 'P':
                cin >> valor;
                cout << minhaLista.procura(valor) << endl;
                break;
            case 'R':
                cin >> pos;
                minhaLista.remove(pos);
                break;
            case 'V':
                cout << minhaLista.vazia() << endl;
                break;
        }
        cin >> opcao;
    }
    minhaLista.imprime();
    return 0;
}
