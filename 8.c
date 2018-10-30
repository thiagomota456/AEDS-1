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
/*
Void lerArquivo(TipoPilha * pilha, char * nomeDoArquivo){

  FILE *arq;
  char nomeDoArquivo[100];
  TipoItem itemAuxiliar;

  //Abro arquivo

  arq = fopen( nomeDoArquivo, "rb");

  //Testa se arquivo foi lido corretamente

  if (arq == NULL){

      printf("Problemas na abertura do arquivo\n");
      return 0;
  }

  //Lê todos os arquivos

  while (fread( &itemAuxiliar, sizeof(TipoItem), 1, arq) == 1 ) {

    printf("%s\n", itemAuxiliar.Nome);
    printf("%d\n", itemAuxiliar.Nota);

  }//end while

  fclose(arq);

}//end lerArquivo
*/
int main(){

  FILE *arq;
  char nomeDoArquivo[100], nome[100];
  int nota;
  TipoItem itemAuxiliar;

  arq = fopen( "banco.dat", "rb");

  if (arq == NULL){

      printf("Problemas na abertura do arquivo\n");
      return 0;
  }

  //fread(void *ptr, size_t size, size_t nmemb, FILE *stream)

  while (fread( &itemAuxiliar, sizeof(TipoItem), 1, arq) == 1 ) {

    printf("%s\n", itemAuxiliar.Nome);
    printf("%d\n", itemAuxiliar.Nota);

  }

  fclose(arq);

  return 0;
}
