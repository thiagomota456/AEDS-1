#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#define MAX 10

// typedef int TipoChave;
//typedef struct {
//  int Chave;
  /* outros componentes */
//} TipoItem;

typedef char TipoChave[100];
typedef struct {
  TipoChave Nome;
  int Nota;
} TipoItem;

typedef struct TipoCelula *TipoApontador;
typedef struct TipoCelula {
  TipoItem Item;
  TipoApontador Prox;
} TipoCelula;
typedef struct {
  TipoApontador Fundo, Topo;
  int Tamanho;
} TipoPilha;

void FPVazia(TipoPilha *Pilha)
{ Pilha->Topo = (TipoApontador) malloc(sizeof(TipoCelula));
  Pilha->Fundo = Pilha->Topo;
  Pilha->Topo->Prox = NULL;
  Pilha->Tamanho = 0;
}

int Vazia(TipoPilha Pilha)
{ return (Pilha.Topo == Pilha.Fundo); }

void Empilha(TipoItem x, TipoPilha *Pilha)
{ TipoApontador Aux;
  Aux = (TipoApontador) malloc(sizeof(TipoCelula));
  Pilha->Topo->Item = x;
  Aux->Prox = Pilha->Topo;
  Pilha->Topo = Aux;
  Pilha->Tamanho++;
}

void Desempilha(TipoPilha *Pilha, TipoItem *Item)
{ TipoApontador q;
  if (Vazia(*Pilha)) { printf("Erro: lista vazia\n"); return; }
  q = Pilha->Topo;
  Pilha->Topo = q->Prox;
  *Item = q->Prox->Item;
  free(q);  Pilha->Tamanho--;
}

int Tamanho(TipoPilha Pilha)
{ return (Pilha.Tamanho); }

//Recebe como parametro endereço de uma pilha e string e grava na pilha itens contidos no arquivo que a string guarda o nome

void lerArquivo(TipoPilha * pilha, char * nomeDoArquivo){

  FILE *arq;
  TipoItem itemAuxiliar;

  //Abro arquivo

  arq = fopen( nomeDoArquivo, "rb");

  //Testa se arquivo foi lido corretamente

  if (arq == NULL){

      printf("Problemas na abertura do arquivo\n");
      return;
  }

  //Lê todos os arquivos

  while (fread( &itemAuxiliar, sizeof(TipoItem), 1, arq) == 1 ) {

    Empilha( itemAuxiliar, pilha);

  }//end while

  fclose(arq);

}//end lerArquivo



int main(){

  char nomeDoArquivo[100];
  TipoPilha pilha;
  TipoItem itemAuxiliar;

  //Inicio pilha

  FPVazia(&pilha);

  printf("Digite o nome do arquivo: ");
  scanf("%s", nomeDoArquivo);

  while (!Vazia(pilha)) {
    Desempilha( &pilha, &itemAuxiliar);
    printf("%s\n",itemAuxiliar.Nome);
  }

  return 0;
}
