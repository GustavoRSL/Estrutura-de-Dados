#include <iostream>

using namespace std;

typedef string Texto;

class noh {
    friend class lista;
    private:
        const Texto palavra;
        noh* proximo;
    public:
        noh(Texto p);
};

noh::noh(Texto p) : palavra(p) {
    proximo = NULL;
}

class lista {
    private:
        noh* primeiro;
        noh* ultimo;
        int tamanho;
    public:
        lista();
        lista(const lista& umaLista);
        lista& operator=(const lista& umaLista);
        lista operator+(const lista& umaLista) const;
        ~lista();
        void insere(Texto palavra);
        void imprime() const;
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

// insere no inicio da lista
void lista::insere(Texto palavra) {
    noh* novo = new noh(palavra);
    novo->proximo = primeiro;
    primeiro = novo;
    if (tamanho == 0)
        ultimo = novo;
    ++tamanho;
}

// método básico que *percorre* a lista, imprimindo seus elementos
void lista::imprime() const {
    noh* iter = primeiro;
    while (iter != NULL) {
        cout << iter->palavra << " ";
        iter = iter->proximo;
    }
    cout << endl;
}

// construtor de cópia
lista::lista(const lista& umaLista) {
    // IMPLEMENTAR
    
}

// sobrecarga do operador de atribuição - retorna a própria lista
lista& lista::operator=(const lista& umaLista) {
    // IMPLEMENTAR
    noh* A = this->primeiro;
    noh* Aux;
    while(A != NULL){
		Aux = A;
		A = A->proximo;
		delete Aux;
	}
	noh* B = umaLista.primeiro;
	while(B!=NULL){
		this->insere(B->palavra);
		B = B->proximo;
	}
	
	return *this;
}

// concatenacao de listas
lista lista::operator+(const lista& umaLista) const {
    // IMPLEMENTAR
    lista Retorno;
    lista Certa;
	noh* A = this->primeiro;
	noh* B = umaLista.primeiro;
	if(A != NULL and B != NULL){
		while(A != NULL){
			Retorno.insere(A->palavra);
			A = A->proximo;
			}
		while(B != NULL){
			Retorno.insere(B->palavra);
			B = B->proximo;
		}
	}
	if(A != NULL and B == NULL){
		while(A != NULL){
			Retorno.insere(A->palavra);
			A = A->proximo;
		}
		
	}
	if(B != NULL and A == NULL){
		while(B != NULL){
			Retorno.insere(B->palavra);
			B = B->proximo;
		}
	}
	noh* Ret = Retorno.primeiro;
	while(Ret != NULL){
		Certa.insere(Ret->palavra);
		Ret = Ret->proximo;
	}
	return Certa;
}

int main() { // NÃO MODIFIQUE!
    lista listaA;
    lista listaB;
    string opcao;
    string palavra;
    char idLista;
    do {
        cin >> opcao;
        if (opcao == "i") {
            cin >> idLista >> palavra;
            if (idLista == 'a')
                listaA.insere(palavra);
            else
                listaB.insere(palavra);
        }
        else if (opcao == "a=b") {
            listaA = listaB;
        }
        else if (opcao == "b=a") {
            listaB = listaA;
        }
        else if (opcao == "s") {
            lista soma = listaA + listaB;
            soma.imprime();
        }
        else if (opcao == "e") {
            // escreve _uma copia_ da lista indicada
            cin >> idLista;
            lista* ptLista = (idLista == 'a') ? &listaA : &listaB;
            lista copiaDaLista(*ptLista);
            copiaDaLista.imprime();
        }
    } while (opcao != "t");
    return 0;
}
