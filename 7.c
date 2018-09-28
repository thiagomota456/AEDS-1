#include <stdlib.h>
#include <sys/time.h>
#include <stdio.h>
#define MAX 10

typedef struct TipoCelula *TipoApontador;

typedef int TipoChave;

typedef struct TipoItem {
  TipoChave Chave;
  /* outros componentes */
} TipoItem;

typedef struct TipoCelula {
  TipoItem Item;
  TipoApontador Prox;
} TipoCelula;

typedef struct TipoFila {
  TipoApontador Frente, Tras;
} TipoFila;

void FFVazia(TipoFila *Fila)
{ Fila->Frente = (TipoApontador) malloc(sizeof(TipoCelula));
  Fila->Tras = Fila->Frente;
  Fila->Frente->Prox = NULL;
}

int Vazia(TipoFila Fila)
{ return (Fila.Frente == Fila.Tras); }

void Enfileira(TipoItem x, TipoFila *Fila)
{ Fila->Tras->Prox = (TipoApontador) malloc(sizeof(TipoCelula));
  Fila->Tras = Fila->Tras->Prox;
  Fila->Tras->Item = x;
  Fila->Tras->Prox = NULL;
}

void Desenfileira(TipoFila *Fila, TipoItem *Item)
{ TipoApontador q;
  if (Vazia(*Fila)) { printf("Erro fila esta vazia\n"); return; }
  q = Fila->Frente;
  Fila->Frente = Fila->Frente->Prox;
  *Item = Fila->Frente->Item;
  free(q);
}

void Imprime(TipoFila Fila)
{ TipoApontador Aux;
  Aux = Fila.Frente->Prox;
  while (Aux != NULL)
    { printf("%d\n", Aux->Item.Chave);
      Aux = Aux->Prox;
    }
}



int main(){

	FILE *PonteiroDeArquivo;
  TipoFila fila;
  TipoItem estouChateadoComAImbecilDeUmaAmiga;
  char nomeDoArquivo[100];
  char opcao;
  int conteudoDoItem;

  //Inicio fila vazia

  FFVazia(&fila);

  //Lê nome do arquivo

  printf("Digite o nome do arquivo: ");
  scanf("%s", nomeDoArquivo);

	//Abri arquivo para leitura

	PonteiroDeArquivo = fopen(nomeDoArquivo, "r");

	//Testa se realizoua a litura correta,

	if(PonteiroDeArquivo == NULL){

		printf("ERRO: NAO FOI POSSIVEL ABRIR O ARQUIVO\n");
		return 0;
	}

  //Leio o arquivo
  while( fscanf(PonteiroDeArquivo, "%c", &opcao) != EOF){

    //Se linha pede pra add, eu add item

    if(opcao == 'a'){

      //Leio conteudoDoItem

      fscanf(PonteiroDeArquivo, "%d", &conteudoDoItem);

      //Add Conteudo passado a um item

      estouChateadoComAImbecilDeUmaAmiga.Chave = conteudoDoItem;

      //Add a a fila

      Enfileira(estouChateadoComAImbecilDeUmaAmiga, &fila);

    }//end if a

    if(opcao == 'b'){

      //Retira fila elemento da fila e quarda em estouChateadoComAImbecilDeUmaAmiga

      Desenfileira(&fila, &estouChateadoComAImbecilDeUmaAmiga);

    }//end if b

    if(opcao == 'c'){

      //imprime lista

      printf("\n");
      printf("Processos na fila:\n");

      Imprime(fila);

    }//end if c

  }//end while

  return 0;

}//end main
