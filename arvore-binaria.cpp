#include<iostream>
using namespace std;

struct No {

	int chave;
	No *esq;
	No *dir;

};

struct ArvoreBinaria{
	No *raiz;
	
	void Criar();
	No * Inserir(No *noAtual, int valor);
	bool Pesquisar(No *noAtual,int valor);
	void Inserir_semretorno(int valor);
	void Imprimir_Ordem(No* noAtual);
	void Imprimir_PreOrdem(No* noAtual);
	void Imprimir_PosOrdem(No* noAtual);
};

void ArvoreBinaria::Criar(){
	raiz=NULL;
}

No * ArvoreBinaria::Inserir(No *noAtual, int valor){
	
	if(noAtual==NULL){
	    noAtual= new No;
	    noAtual->dir=NULL;
	    noAtual->esq=NULL;
	    noAtual->chave=valor;
	}
	
	else if(valor<noAtual->chave){
		noAtual->esq= Inserir(noAtual->esq, valor);
	
	}
	else {
	    noAtual->dir= Inserir(noAtual->dir, valor);
	}
	
	return noAtual;
}


bool ArvoreBinaria::Pesquisar(No* noAtual, int valor){

	if(noAtual==NULL){
		return false;
	}
	
	else if(noAtual->chave== valor){
		return true;
	}
	
	else{
	    if(valor<noAtual->chave){
	   		Pesquisar(noAtual->esq, valor);
	    }
	    else {
	       Pesquisar(noAtual->dir, valor);
	    }
	}
}

void ArvoreBinaria::Inserir_semretorno(int valor){
	raiz=Inserir(raiz, valor);
}

void ArvoreBinaria::Imprimir_Ordem(No* noAtual){
	if(noAtual!=NULL){
	    Imprimir_Ordem(noAtual->esq);
		cout<<noAtual->chave<<endl;
	    Imprimir_Ordem(noAtual->dir);
	}
}
void ArvoreBinaria::Imprimir_PreOrdem(No * noAtual){
	if(noAtual!=NULL){
		cout<<noAtual->chave<<endl;
	    Imprimir_PreOrdem(noAtual->esq);
	    Imprimir_PreOrdem(noAtual->dir);
	}
}
void ArvoreBinaria::Imprimir_PosOrdem(No * noAtual){
	if(noAtual!=NULL){
	    Imprimir_PosOrdem(noAtual->esq);
	    Imprimir_PosOrdem(noAtual->dir);
	    cout<<noAtual->chave<<endl;
	}
}

int main(){
	
	ArvoreBinaria arv;
	arv.Criar();
	arv.Inserir_semretorno(10);	
	arv.Inserir_semretorno(5);
	arv.Inserir_semretorno(4);	
	arv.Inserir_semretorno(9);
	arv.Inserir_semretorno(8);
	arv.Inserir_semretorno(7);
	arv.Inserir_semretorno(6);
	arv.Inserir_semretorno(3);
	arv.Inserir_semretorno(2);
	arv.Inserir_semretorno(1);

	if(arv.Pesquisar(arv.raiz,1)){
	   cout<<"Elemento encontrado."<<endl;
	
	}

   else{
    	cout<<"Elemento NÃO encontrado."<<endl;
	}
	
	cout<<"**** ARVORE EM ORDEM ****" <<endl;
	arv.Imprimir_Ordem(arv.raiz);
	
	cout<<" \n **** ARVORE PRE ORDEM ****"<<endl;
	arv.Imprimir_PreOrdem(arv.raiz);
	
	cout<<" \n **** ARVORE POS ORDEM ****"<<endl;
	arv.Imprimir_PosOrdem(arv.raiz);

	return 0;
}
