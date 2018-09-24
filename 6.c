//Fonte : http://www2.dcc.ufmg.br/livros/algoritmos/cap3/codigo/c/3.3a3.4-lista-apontadores.c

#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#define MAX 10

/*========================================================================= */

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

TipoLista  particionarLista(TipoLista * lista,TipoApontador aponta_item){

    //Declaro e inicio a lista axiliar

    TipoLista listaAux;
    FLVazia(&listaAux);

    //Add elemento pedido ao procximo do elemeto inicial

    listaAux.Primeiro -> Prox = aponta_item -> Prox;

    //Add ultimo da lista1 a lista 2

    listaAux.Ultimo  = lista -> Ultimo -> Prox;

    //Add ultimo da lista passada como o elemeto recebido

    lista -> Ultimo = aponta_item ;

    //Add proximo da ultima celula igual a null

    aponta_item -> Prox = NULL;

    //retorno endereço da nova lista

    return listaAux;

}//end particionarLista

void menu(){
  printf("1. Criar lista vazia\n");
  printf("2. Inserir elemento\n");
  printf("3. Retirar elemento\n");
  printf("4. Localizar um item na lista dada a sua chave.\n");
  printf("5. Particionar a lista em duas a partir de determinado item.\n");
  printf("6. Imprimir lista\n");
  printf("7. Sair\n");
}//end menu

//Todas as manipulações são feitas sobre a lista criada inicialmente, não sendo assecivel ao ususario a lista 2 quando particionado já que não era obrigatorio fazer isso

int main(int argc, char *argv[]){

  //Declarações

  TipoLista lista;
  TipoLista lista2;
  TipoItem item;
  TipoApontador aponta_item;
  int number, opcao, aux;

  do{
      //Printo opções para o usuario

      menu();
      printf("\nEscolha uma da opções listadas: ");
      scanf("%d", &opcao);

      //Chama o metodo adequado

      switch (opcao) {
        case 1:

          //Criei uma lista vazia

          FLVazia(&lista);
          printf("Lista Vazia Criada\n\n");

        break;

      case 2:

        //Add intens

        printf("Quantos itens deseja add: ");
        scanf("%d",&aux);

        for(int i = 0; i < aux; i++){

        printf("Add itens %d: ", i+1);
        scanf("%d",&number);
        item.Chave = number;
        Insere(item, &lista);
        printf("\n");

        }//end for i

      break;

      case 3:

        //Retirar Item

        printf("Digite a chave do item que deseja retirar: ");
        scanf("%d",&number);
        aponta_item = ProcurarItem( &lista, number);
        Retira(aponta_item, &lista, &item);
        printf("Item retirado tem a chave = %d\n", item.Chave );
        printf("\n");

      break;

      case 4:

        //Localiza intens

        printf("Digite a chave do item que deseja procurar: ");
        scanf("%d",&number);
        aponta_item = ProcurarItem( &lista, number);
        printf("Item procurado %d que é precedidido de %d \n", aponta_item->Prox ->Item.Chave, aponta_item->Item.Chave);
        printf("\n");

      break;


      case 5:

        //Particiona a lista

        printf("Digite a chave do item a partir do qual deseja particinar: ");
        scanf("%d",&number);
        aponta_item = ProcurarItem( &lista, number);
        lista2  = particionarLista(&lista, aponta_item);

        printf("Lista 1: ");Imprime(lista);
        printf("Lista 2: ");Imprime(lista2);
        printf("\n");

      break;

      case 6:
        printf("\n");
        printf("Lista: ");Imprime(lista);
        printf("\n");

      break;

      case 7:
        //So para que o 7 não print a mensagem de default
      break;

      default :

      printf("Digite uma opção valida!");

    }//end switch

  }while (opcao != 7);


}//end main
