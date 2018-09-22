//Fonte : http://www2.dcc.ufmg.br/livros/algoritmos/cap3/codigo/c/3.1a3.2-lista-arranjo.c

/* ========================================================================== */
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#define INICIOARRANJO   1
#define MAXTAM          1000

typedef int TipoChave;

typedef int TipoApontador;

typedef struct {
  TipoChave Chave;
  /* outros componentes */
} TipoItem;

typedef struct {
  TipoItem Item[MAXTAM];
  TipoApontador Primeiro, Ultimo;
} TipoLista;

/* ========================================================================== */

void FLVazia(TipoLista *Lista)
{ Lista -> Primeiro = INICIOARRANJO;
  Lista -> Ultimo = Lista -> Primeiro;
}  /* FLVazia */

int Vazia(TipoLista Lista)
{ return (Lista.Primeiro == Lista.Ultimo);
}  /* Vazia */

void Insere(TipoItem x, TipoLista *Lista)
{ if (Lista -> Ultimo > MAXTAM) printf("Lista esta cheia\n");
  else { Lista -> Item[Lista -> Ultimo - 1] = x;
         Lista -> Ultimo++;
       }
}  /* Insere */

void Retira(TipoApontador p, TipoLista *Lista, TipoItem *Item)
{ int Aux;

  if (Vazia(*Lista) || p >= Lista -> Ultimo)
  { printf(" Erro   Posicao nao existe\n");
    return;
  }
  *Item = Lista -> Item[p - 1];
  Lista -> Ultimo--;
  for (Aux = p; Aux < Lista -> Ultimo; Aux++)
    Lista -> Item[Aux - 1] = Lista -> Item[Aux];
}  /* Retira */

void Imprime(TipoLista Lista)
{ int Aux;

  for (Aux = Lista.Primeiro - 1; Aux <= (Lista.Ultimo - 2); Aux++)
    printf("%d ", Lista.Item[Aux].Chave);

    printf("\n");
}  /* Imprime */

/* ========================================================================== */

TipoApontador procurarItem(TipoLista *Lista, TipoChave chave){

  int i;

  //Percorro todo o vetor de chave

  for (int i = 0; i < Lista -> Ultimo; i++){

    //Se a chave do item é igual a chave procurada, retorno o indice dele

    if(Lista -> Item[i].Chave == chave)
      return  i;
  }

  //Se não encotrei Item, retorno null

  return -1;

}//end procurarItem

void particionarLista(TipoLista * listaOriginal, TipoLista * novaLista, TipoApontador item){

    //Crio nova lista Vazia

    FLVazia(novaLista);

    //Add itens a partir do item passado ate o ultin=mo item valido que é igual ultimo -2

    int i;

    for(i = 1; novaLista->Item[i-1].Chave != listaOriginal->Item[listaOriginal->Ultimo - 2].Chave ; i++){

      Insere(listaOriginal->Item[i+item-1], novaLista);
    }//end for

    //Add ultimo da lista antiga a nova listaAux

    novaLista -> Ultimo = novaLista -> Item[i+1];

    //Retirar a partir do meu item apontado do meu vetor principal

    listaOriginal -> Ultimo = item+1;

}//end particionarLista

int main(int argc, char *argv[]){

  //Declarações

  TipoLista lista;
  TipoLista lista2;
  TipoItem item;
  int aux1, aux2;

  //Inici lista Vazia

  FLVazia(&lista);

  //add itens

  printf("Add itens: \n");

  for (int i = 0; i < 5; i++){

      scanf("%d", &aux1);
      item.Chave = aux1;
      Insere(item, &lista);

  }//end for i
  Imprime(lista);

  printf("Chave do item a ser procurado: ");
  scanf("%d", &aux1);
  aux2 = procurarItem(&lista, aux1);

  printf("Item %d com indice %d encontrado.\n", lista.Item[aux2].Chave, aux2 );

  particionarLista(&lista, &lista2, (TipoApontador)aux2);


  Imprime(lista);
  Imprime(lista2);

  return(0);

}//end main
