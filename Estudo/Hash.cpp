#include <iostream>
using namespace std;

const int UMPRIMO = 39;

int funcaoHash(string chave, int limite){
    int pos = 0;
    for (unsigned i = 0; i < chave.length(); i++)
        pos = (UMPRIMO * pos + chave[i]) % limite;
    return pos;
}

class Noh{
	friend class Hash;
	private:
		string Chave;
		string Valor;
		Noh* Proximo;
	public:
		Noh(string C,string V){
			Chave = C;
			Valor = V;
			Proximo = NULL;
		}
};

class Hash{
	private:
		Noh** Elementos;
		int Capacidade;
	public:
		Hash();
		~Hash();
		void Insere(string Chave,string Valor);
		string Busca(string C,Noh* List);
		void Recupera(string Chave);
		void AlteraValor(string Chave,string NovoValor);
		void RemoveElemento(string Chave);
		void percorre();
};

Hash::Hash(){
	Capacidade = 20;
	Elementos = new Noh*[Capacidade];
	for(int i=0; i<Capacidade; i++){
		Elementos[i] = NULL;
	}
}

Hash::~Hash(){
	for(int i=0; i<Capacidade; i++){
		Noh* Atual = Elementos[i];
		while(Atual != NULL){
			Noh* Aux = Atual;
			Atual = Atual->Proximo;
			delete Aux;
		}
	}
	delete[] Elementos;
}

void Hash::Insere(string Chave,string Valor){
	int Pos = funcaoHash(Chave,Capacidade);
	Noh* Atual = Elementos[Pos];
	if(Atual == NULL){
		Noh* Novo =  new Noh(Chave,Valor);
		Elementos[Pos] = Novo;
	}
	else{
		if(Busca(Chave,Atual) == "NaoEncontrado"){
			Noh* Novo =  new Noh(Chave,Valor);
			while(Atual->Proximo != NULL){
				Atual = Atual->Proximo;
			}
			Atual->Proximo = Novo;
		}
		else{
			cout << "Chave Repitida!" << endl;
		}
	}
}

string Hash::Busca(string C, Noh* List){
	string Resultado = "NaoEncontrado";
	bool Achou = false;
	while(List != NULL and Achou == false){
		if(List->Chave == C){
			Achou = true;
			Resultado = "Achou!";
		}
		else{
			List = List->Proximo;
		}
	}
	return Resultado;
}

void Hash::Recupera(string Chave){
	int Pos = funcaoHash(Chave,Capacidade);
	Noh* Atual = Elementos[Pos];
	if(Busca(Chave,Atual) == "NaoEncontrado"){
		cout << "Objeto Nao Encontrado" << endl;
	}
	else{
		cout << "Objeto Encontrado" << endl;
	}
}

void Hash::AlteraValor(string Chave,string NovoValor){
	int Pos = funcaoHash(Chave,Capacidade);
	Noh* Atual = Elementos[Pos];
	if(Busca(Chave,Atual) == "NaoEncontrado"){
		cout << "Erro ao alterar a Chave inexistente" << endl;
	}
	else{
		while(Atual->Chave != Chave and Atual != NULL){
			Atual = Atual->Proximo;
		}
		cout << "Valor Antigo " << "[" << Atual->Valor << "]" << endl;
		Atual->Valor = NovoValor;
		cout << "Valor Novo " << "[" << Atual->Valor << "]" << endl;
	}
}

void Hash::RemoveElemento(string C){
	int Pos = funcaoHash(C,Capacidade);
	Noh* Atual = Elementos[Pos];
	Noh* Anterior;
	if(Busca(C,Atual) == "NaoEncontrado"){
		cout << "Erro ao remover a Chave inexistente" << endl;
	}
	else{
		if(Elementos[Pos]->Chave == C){
			Noh* Aux = Elementos[Pos];
			Elementos[Pos] = Elementos[Pos]->Proximo;
			delete Aux;
		}
		else{
			while(Atual->Chave != C and Atual != NULL){
				Anterior = Atual;
				Atual = Atual->Proximo;
			}
			cout << Atual->Chave << " Removido!" << endl;
			Anterior->Proximo = Atual->Proximo;
			delete Atual;
		}
	}
}

void Hash::percorre(){
    Noh* atual;
    for (int i = 0; i < Capacidade; i++) {
        cout << i << ":";
        atual = Elementos[i];
        while (atual != NULL) {
            cout << "[" << atual->Chave << "/"
                 << atual->Valor << "]->";
            atual = atual->Proximo;
        }
        cout << "NULL  ";
    }
}


int main(){
	Hash th;
    int qtdade;
    string chave;
    string valor;
    cout << "Inserçao" << endl;
     // insercao na tabela
    cin >> qtdade;
    for (int i=0; i < qtdade; i++) {
        cin >> chave;
        cin >> valor;
        th.Insere(chave,valor);
    }
	cout << "Altera" << endl;
    // altera valores
    cin >> qtdade;
    for (int i=0; i < qtdade; i++) {
        cin >> chave;
        cin >> valor;
        th.AlteraValor(chave,valor);
    }
	cout << "Remove" << endl;
    // remove valores
    cin >> qtdade;
    for (int i=0; i < qtdade; i++) {
        cin >> chave;
        th.RemoveElemento(chave);
    }
	cout << "Recupera" << endl;
    // recupera valores
    cin >> qtdade;
    for (int i=0; i < qtdade; i++) {
        cin >> chave;
        th.Recupera(chave);
    }
	
	// percorre a tabela
    cout << endl;
    th.percorre();
    cout << endl;


	return 0;
}
