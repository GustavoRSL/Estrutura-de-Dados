#include <iostream>
using namespace std;

typedef float Dado;

class noh {
  friend class listadup;
  private:
    const Dado dado;
    noh* proximo;
    noh* anterior;
  public:
    noh(Dado d = 0) : dado(d) {
      proximo = NULL;
      anterior = NULL;
    }
};

// lista dinamicamente encadeada
class listadup {
  private:
    noh* primeiro;
    noh* ultimo;
    int tamanho;
  public:
    listadup() {
      // constrói uma lista inicialmente vazia
      tamanho = 0;
      primeiro = NULL;
      ultimo = NULL;
    };
    ~listadup() {
      // destroi a lista
      noh* atual = primeiro;
      while (atual != NULL) {
        noh* aux = atual;
        atual = atual->proximo;
        delete aux;
      }
    };
    inline void insere(Dado dado) {
      // insere por padrão no final da lista
      noh* Novo = new noh(dado);
	  if(tamanho == 0){
		  primeiro = Novo;
		  ultimo = Novo;
		  tamanho++;
	  }
	  else{
		  Novo->anterior = ultimo;
		  ultimo->proximo = Novo;
		  ultimo = Novo;
		  tamanho++;
	  }
    };
    listadup* separa(int n) {
      // transfere os elementos a partir de n (indices iniciam em 0) para uma nova listadup
      // A nova lista deverá ser desalocada pelo subprograma que for fazer uso dela!
      // TODO - implementar
      if(n >= 0  and n < tamanho and tamanho > 0 ) {
      listadup* Nova = new listadup;
      noh* Aux = primeiro;
      noh* Anterior = NULL;
      noh* Deletar = NULL;
      int Contador = 0;
      
      if(n > 0){
		  while(Contador != n){
			  Anterior = Aux->anterior;
			  Aux = Aux->proximo;
			  Contador++;
		  }
		  while(Aux != NULL){
			  Deletar = Aux;
			  Nova->insere(Aux->dado);
			  Aux = Aux->proximo;
			  delete Deletar;
		  }
		  ultimo = Anterior;
		  ultimo->proximo = NULL;
		  Nova->primeiro->anterior = NULL;
	  }
	  else if(n == 0 and primeiro == ultimo){
		  Deletar = Aux;
		  Nova->insere(Aux->dado);
		  delete Aux;
		  primeiro = NULL;
		  ultimo = NULL;
		  Nova->primeiro->anterior = NULL;
	  }
	  else if(n == 0 and primeiro!=ultimo){
		  while(Aux != NULL){
			Deletar = Aux;
			Nova->insere(Aux->dado);
			Aux = Aux->proximo;
			delete Deletar;
		  }
		  primeiro = NULL;
		  ultimo = NULL;
		  Nova->primeiro->anterior = NULL;
	  }
	  return Nova;
	  }
	  else
		cerr << "erro" << endl;
	  
	  return NULL;
    };
    void imprime() {
      // método básico que *percorre* uma lista, imprimindo seus elementos
      noh* aux = primeiro;
      
      if (aux == NULL) {
        cout << "vazio!";
      } else {
        while (aux != NULL) {
          cout << aux->dado << " ";
          aux = aux->proximo;
        }
      }
      
      cout << " <> ";
      
      // imprime reverso (para mostrar duplo encadeamento)
      aux = ultimo;
      if (aux == NULL) {
        cout << "vazio!";
      } else {
        while (aux != NULL) {
          cout << aux->dado << " ";
          aux = aux->anterior;
        }
      }
      
      cout << endl;
    };
};


// NÃO MODIFICAR
int main() {
  listadup* minhaLista = new listadup;
  
  char opcao;
  float valor;

  do {
    cin >> opcao;

    switch(opcao) {
      case 'I':
        cin >> valor;
        minhaLista->insere(valor);
        break;
      case 'S':
        cin >> valor;
        listadup* outraLista = minhaLista->separa(valor);
        if (outraLista != NULL) {
          outraLista->imprime();
          delete outraLista;
        } 
        break;
    }
  } while (opcao != 'Q');

  minhaLista->imprime();
  
  delete minhaLista;

  return 0;
}
