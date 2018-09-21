#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#define MAX 10

/* ========================================================================= */

typedef int TipoChave;

typedef struct {
  int Chave;
  /* outros componentes */
} TipoItem;

typedef struct TipoCelula *TipoApontador;

typedef struct TipoCelula {
  TipoItem Item;
  TipoApontador Prox;
} TipoCelula;

typedef struct {
  TipoApontador Primeiro, Ultimo;
} TipoLista;

/* ========================================================================= */

void FLVazia(TipoLista *Lista)
{ Lista -> Primeiro = (TipoApontador) malloc(sizeof(TipoCelula));
  Lista -> Ultimo = Lista -> Primeiro;
  Lista -> Primeiro -> Prox = NULL;
}

int Vazia(TipoLista Lista)
{ return (Lista.Primeiro == Lista.Ultimo);
}

void Insere(TipoItem x, TipoLista *Lista)
{ Lista -> Ultimo -> Prox = (TipoApontador) malloc(sizeof(TipoCelula));
  Lista -> Ultimo = Lista -> Ultimo -> Prox;
  Lista -> Ultimo -> Item = x;
  Lista -> Ultimo -> Prox = NULL;
}

void Retira(TipoApontador p, TipoLista *Lista, TipoItem *Item)
{ /*  ---   Obs.: o item a ser retirado e  o seguinte ao apontado por  p --- */
  TipoApontador q;
  if (Vazia(*Lista) || p == NULL || p -> Prox == NULL)
  { printf(" Erro   Lista vazia ou posi  c   a o n  a o existe\n");
    return;
  }
  q = p -> Prox;
  *Item = q -> Item;
  p -> Prox = q -> Prox;
  if (p -> Prox == NULL) Lista -> Ultimo = p;
  free(q);
}

void Imprime(TipoLista Lista)
{ TipoApontador Aux;
  Aux = Lista.Primeiro -> Prox;
  while (Aux != NULL)
    { printf("%d ", Aux -> Item.Chave);
      Aux = Aux -> Prox;
    }
    printf("\n");
}

/* ========================================================================== */

//Retorna o item anterior ao procurado

TipoApontador  ProcurarItem( TipoLista * lista, int chaveDoItemProcurado){

  //Percorro toda a lista

  for (TipoApontador i = lista -> Primeiro; i -> Prox != NULL; i = i -> Prox) {

    //Se encontrar algum elemento da lista que a chave é igual a procurada

    if(i ->Prox -> Item.Chave == chaveDoItemProcurado )

      //retorno o endereço desse item

      return i;
  }

  return NULL;

}//end ProcurarItem

TipoLista  particionarLista(TipoLista * lista,TipoApontador ponteiro_para_celula_onde_item_esta){

    //Declaro e inicio a lista axiliar

    TipoLista listaAux;
    FLVazia(&listaAux);

    //Add elemento pedido ao procximo do elemeto inicial

    listaAux.Primeiro -> Prox = ponteiro_para_celula_onde_item_esta;

    //Add ultimo da lista1 a lista 2

    listaAux.Ultimo  = lista -> Ultimo -> Prox;

    //Add ultimo da lista passada como o elemeto recebido

    lista -> Ultimo = ponteiro_para_celula_onde_item_esta ;

    //Add proximo da ultima celula igual a null

    ponteiro_para_celula_onde_item_esta -> Prox = NULL;

    //retorno endereço da nova lista

    return listaAux;

}

int main(int argc, char *argv[])
{

  //Declarações

  TipoLista lista;
  TipoLista lista2;
  TipoItem item;
  TipoApontador ponteiro_para_celula_onde_item_esta;
  int number;

  //Criei uma lista vazia

  FLVazia(&lista);

for(int i = 0; i < 10; i++){

  //Leio int

  printf("Add 10 itens a lista: ");
  scanf("%d",&number);

  //Add a tipo int

  item.Chave = number;

  //Add item a lista

  Insere(item, &lista);

}//end for i

  Imprime(lista);

  ponteiro_para_celula_onde_item_esta = ProcurarItem( &lista, 3);

  printf("Item encontrado = %d\n", ponteiro_para_celula_onde_item_esta->Item.Chave );
  printf("Item procurado = %d\n", ponteiro_para_celula_onde_item_esta->Prox ->Item.Chave );

  lista2  = particionarLista(&lista, ponteiro_para_celula_onde_item_esta);

  printf("Lista partida em 2 sendo uma do primeiro elemto ao anterio do procurado\nE outra do procurado ao fim da primeira lista.\n");

  Imprime(lista);
  Imprime(lista2);


}//end main
