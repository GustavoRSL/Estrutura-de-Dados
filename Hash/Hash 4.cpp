#include <iostream>
using namespace std;

class InfoHash {
	friend class Hash;
	InfoHash(string Palavra,string Significado);
	string hPalavra;
	string hSignificado;
};

InfoHash::InfoHash(string Palavra,string Significado) {
	hPalavra = Palavra;
	hSignificado = Significado;
}

class Hash {
	private:
		unsigned mCapacidade;
		unsigned mTamanho;
		InfoHash* Removido;
		InfoHash** Dicionario;
	public:
		Hash();
		~Hash();
		void Insere(string Palavra,string Significado);
		void Busca(string Palavra);
		unsigned Posicao(string Palavra);
};

Hash::Hash() {
	mTamanho = 0;
	mCapacidade = 23;
	Removido = NULL;
	Dicionario = new InfoHash*[mCapacidade];
	for(unsigned i = 0; i < mCapacidade; i++){
		Dicionario[i] = NULL;
	}
}

Hash::~Hash(){
	for(unsigned i=0; i<mTamanho; i++){
		Dicionario[i] = NULL;
	}
	delete Removido;
	delete[] Dicionario;
}

unsigned Hash::Posicao(string Palavra){
	unsigned Pos = 1;
	unsigned Tam = unsigned(Palavra.length());
	for(unsigned i =0; i<Tam; i++){
		Pos = 7 * Pos + Palavra[i];
	}
	return Pos % mCapacidade;
}

void Hash::Insere(string Palavra,string Significado){
	if(mTamanho < mCapacidade){
		InfoHash* Novo = new InfoHash(Palavra,Significado);
		unsigned Pos = Posicao(Palavra);
		while(Dicionario[Pos] != NULL and Dicionario[Pos]->hPalavra != Palavra){
			Pos++;
			Pos %= mCapacidade;
		}
		if(Dicionario[Pos] == NULL){
			mTamanho++;
			Dicionario[Pos] = Novo;
		}
		else{
			cout << "Palavra repitida" << endl;
		}
	}
}

void Hash::Busca(string Palavra){
	unsigned Pos = Posicao(Palavra);
	unsigned Contador = 0;
	bool Achou = false;
	while(Contador < mCapacidade and Achou == false){
		if(Dicionario[Pos] != NULL){
			if(Dicionario[Pos]->hPalavra == Palavra){
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
		else{
			if(Pos+1 == mCapacidade){
				Pos = 0;
			}
			else {
				Pos++;
			}
			Contador++;
		}
	}
	if(Dicionario[Pos]->hPalavra == Palavra){
		cout << "[" << Dicionario[Pos]->hPalavra << "] " << "=> " << Dicionario[Pos]->hSignificado << endl;
	}
	else{
		cout << "[" << Palavra << "] " << "=> " << "NULL" << endl;
	}
}

int main() {
	Hash Aurelio;
	int Quant_Palavras;
	string Palavra;
	string Significado;
	cin >> Quant_Palavras;
	for(int i=0; i<Quant_Palavras; i++){
		cin >> Palavra;
		cin.ignore();
		getline(cin,Significado);
		Aurelio.Insere(Palavra,Significado);
	}
	string Busca;
	cin >> Busca;
	while(Busca!="-1"){
		Aurelio.Busca(Busca);
		cin >> Busca;
	}
	
	return 0;
}

