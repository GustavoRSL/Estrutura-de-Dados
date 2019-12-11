#include<iostream>
using namespace std;

class Noh{
	friend class AVL;
	private:
		Noh* Dir;
		Noh* Esq;
		Noh* Pai;
		int Dado;
		int Altura;
	public:
		Noh(int Valor);
		~Noh();
};

Noh::Noh(int Valor){
	Dir = NULL;
	Esq = NULL;
	Pai = NULL;
	Dado = Valor;
	Altura = 0;
}

Noh::~Noh(){
	delete Esq;
	delete Dir;
}

class AVL{
	private:
		Noh* Raiz;
		int Tamanho;
	public:
		AVL();
		~AVL();
		int InformarAltura(Noh* umNoh);
		void AtualizaAltura(Noh* umNoh);
		int FatorBalanceamento(Noh* umNoh);
		Noh* RotacaoEsq(Noh* umNoh);
		Noh* RotacaoDir(Noh* umNoh);
		Noh* RotacaoEsqDir(Noh* umNoh);
		Noh* RotacaoDirEsq(Noh* umNoh);
		void InsereRecursivamente(int Valor);
		Noh* InsereRecAux(Noh* umNoh,int Valor);
		Noh* ArrumaBalanceamento(Noh* umNoh);
		void RemoveRecursivamente(int Valor);
		Noh* RemoveRecAux(Noh* umNoh,int Valor);
		void Transplanta(Noh* Antigo,Noh* Novo);
		Noh* Minimo(Noh* umNoh);
		
};

AVL::AVL(){
	Raiz = NULL;
	Tamanho = 0;
}

AVL::~AVL(){
	delete Raiz;
}

int AVL::InformarAltura(Noh* umNoh){
	if(umNoh == NULL){
		return 0;
	}
	else{
		return umNoh->Altura;
	}
}

void AVL::AtualizaAltura(Noh* umNoh){
	int AlturaArvEsq = InformarAltura(umNoh->Esq);
	int AlturaArvDir = InformarAltura(umNoh->Dir);
	if(AlturaArvEsq > AlturaArvDir){
		umNoh->Altura = 1 + AlturaArvEsq;
	}
	else{
		umNoh->Altura = 1 + AlturaArvDir;
	}
}

int AVL::FatorBalanceamento(Noh* umNoh){
	int AlturaArvEsq = InformarAltura(umNoh->Esq);
	int AlturaArvDir = InformarAltura(umNoh->Dir);
	int FatorBal = AlturaArvEsq - AlturaArvDir;
	return FatorBal;
}

Noh* AVL::RotacaoEsq(Noh* umNoh){
	//Aux receber Noh referencia a direita.
	Noh* Aux = umNoh->Dir;
	//Noh apontador direita aponta para Aux Esq.
	umNoh->Dir = Aux->Esq;
	//Se Aux Esq for diferente de NULL para de Esq aponta para umNoh.
	if(Aux->Esq != NULL){
		Aux->Esq->Pai = umNoh;
	}
	//Pai de aux aponta para Pai de umNoh
	Aux->Pai = umNoh->Pai;
	//Se umNoh for igual a Raiz, Raiz passar a ser AUX.
	if(umNoh == Raiz){
		Raiz = Aux;
	}
	else if(umNoh == umNoh->Pai->Esq){
		umNoh->Pai->Esq = Aux;
	}
	else{
		umNoh->Pai->Dir = Aux;
	}
	Aux->Esq = umNoh;
	umNoh->Pai = Aux;
	
	AtualizaAltura(Aux);
	AtualizaAltura(umNoh);
	
	return Aux;
}

Noh* AVL::RotacaoDir(Noh* umNoh){
	Noh* Aux = umNoh->Esq;
	umNoh->Esq = Aux->Dir;
	if(Aux->Dir != NULL){
		Aux->Dir->Pai = umNoh;
	}
	Aux->Pai = umNoh->Pai;
	if(umNoh == Raiz){
		Raiz = Aux;
	}
	else if(umNoh == umNoh->Pai->Esq){
		umNoh->Pai->Esq = Aux;
	}
	else{
		umNoh->Pai->Dir = Aux;
	}
	Aux->Dir = umNoh;
	umNoh->Pai = Aux;
	
	AtualizaAltura(Aux);
	AtualizaAltura(umNoh);
	
	return Aux;
}

Noh* AVL::RotacaoEsqDir(Noh* umNoh){
	umNoh->Esq = RotacaoEsq(umNoh->Esq);
	return RotacaoDir(umNoh);
}

Noh* AVL::RotacaoDirEsq(Noh* umNoh){
	umNoh->Dir = RotacaoDir(umNoh->Dir);
	return RotacaoEsq(umNoh);
}

void AVL::InsereRecursivamente(int Valor){
	Raiz = InsereRecAux(Raiz,Valor);
}

Noh* AVL::InsereRecAux(Noh* umNoh,int Valor){
	if(umNoh == NULL){
		Noh* Novo = new Noh(Valor);
		return Novo;
	}
	else{
		if(Valor < umNoh->Dado){
			umNoh->Esq = InsereRecAux(umNoh->Esq,Valor);
			umNoh->Esq->Pai = umNoh;
		}
		else{
			umNoh->Dir = InsereRecAux(umNoh->Dir,Valor);
			umNoh->Dir->Pai = umNoh;	
		}
	}
	return ArrumaBalanceamento(umNoh);
}

Noh* AVL::ArrumaBalanceamento(Noh* umNoh){
	AtualizaAltura(umNoh);
	int FatorBal = FatorBalanceamento(umNoh);
	if(FatorBal >= -1 and FatorBal <= 1){
		return umNoh;
	}
	else{
		if(FatorBal > 1 and FatorBalanceamento(umNoh->Esq) >= 0){
			return RotacaoDir(umNoh);
		}
		else if(FatorBal > 1 and FatorBalanceamento(umNoh->Esq) < 0){
			return RotacaoEsqDir(umNoh);
		}
		else if(FatorBal < -1 and FatorBalanceamento(umNoh->Dir) <= 0){
			return RotacaoEsq(umNoh);
		}
		else if(FatorBal < -1 and FatorBalanceamento(umNoh->Dir) > 0){
			return RotacaoDirEsq(umNoh);
		}
	}
}

void AVL::RemoveRecursivamente(int Valor){
	Raiz = RemoveRecAux(Raiz,Valor);
}

Noh* AVL::RemoveRecAux(Noh* umNoh,int Valor){
	if(umNoh == NULL){
		cout << "Noh nao encontrado!" << endl;
	}
	else{
		Noh* NovaRaiz = umNoh;
		if(Valor < umNoh->Dado){
			umNoh->Esq = RemoveRecAux(umNoh->Esq,Valor);
		}
		else if(Valor > umNoh->Dado){
			umNoh->Dir = RemoveRecAux(umNoh->Dir,Valor);
		}
		else{
			if(umNoh->Esq == NULL){
				NovaRaiz = umNoh->Dir;
				Transplanta(umNoh,umNoh->Dir);
			}
			else if(umNoh->Dir == NULL){
				NovaRaiz = umNoh->Esq;
				Transplanta(umNoh,umNoh->Esq);
			}
			else{
				Noh* Sucessor = Minimo(umNoh->Dir);
				NovaRaiz = Sucessor;
				if (Sucessor->Pai != umNoh) {
				Transplanta(Sucessor, Sucessor->Dir);
				Noh* Auxiliar = Sucessor->Pai;
				while (Auxiliar != umNoh->Dir) {
					AtualizaAltura(Auxiliar);
					Auxiliar = Auxiliar->Pai;
				}
				  Sucessor->Dir = ArrumaBalanceamento(umNoh->Dir);
				  Sucessor->Dir->Pai = Sucessor;
				}
				Transplanta(umNoh, Sucessor);
				Sucessor->Esq = umNoh->Esq;
				Sucessor->Esq->Pai = Sucessor;
			}
			delete umNoh;
		}
		if (NovaRaiz == NULL)
		  return NULL;
		else
		  return ArrumaBalanceamento(NovaRaiz);  
	}
}

void AVL::Transplanta(Noh* Antigo, Noh* Novo){
	if(Antigo == Raiz){
		Raiz = Novo;
	}
	else if(Antigo == Antigo->Pai->Esq){
		Antigo->Pai->Esq = Novo;
	}
	else{
		Antigo->Pai->Dir = Novo;
	}
	if(Novo != NULL){
		Novo->Pai = Antigo->Pai;
	}
}

Noh* AVL::Minimo(Noh* umNoh){
	Noh* Atual = umNoh;
	if(Raiz== NULL){
		cout << "Arvore Vazia!" << endl;
	}
	else{
		while(Atual->Esq != NULL){
			Atual = Atual->Esq;
		}
	}
	return Atual;
}

int main(){
    AVL minhaArvore;
    char opcao;
	int valor;
    do {
        cin >> opcao;
        switch (opcao) {
            case 'i': // Inserir
                cin >> valor;
                minhaArvore.InsereRecursivamente(valor);
                break;
            case 'r': // Escrever nÃ³s nÃ­vel a nÃ­vel
				cin >> valor;
                minhaArvore.RemoveRecursivamente(valor);
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

