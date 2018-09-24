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

//Recebe uma lista como parametro e retorna a quantidade de itens

int size(TipoLista * lista){

  return (int) ((lista -> Ultimo) -1);

}//end size



void particionarLista(TipoLista * listaOriginal, TipoLista * novaLista, TipoApontador item){

    TipoItem ItemAuxiliar;
    int quantidadeDeLacosLoop = (size(listaOriginal) - (item));

    //Crio nova lista Vazia

    FLVazia(novaLista);

    //Copio item indicado para novaLista e o retiro da listaOriginal

    for(int i = 0; i < quantidadeDeLacosLoop ; i++){

      //Add item indicado a nova lista

      Insere(listaOriginal->Item[item], novaLista);

      //Retiro item add a lista 2

      Retira(item, listaOriginal, &ItemAuxiliar);

    }//end for


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

  for (int i = 0; i < 6; i++){

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

  //printf("\nTamanho: %d->Item.Chave\n",size(&lista));

}//end main


/*
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

        //Procuro item e Retiro
        aponta_item = procurarItem(&lista, number);
        //void Retira(TipoApontador p, TipoLista *Lista, TipoItem *Item)
        Retira(aponta_item, &lista, &item);
        printf("Item retirado tem a chave = %d\n", item.Chave );
        printf("\n");

      break;

      case 4:

        //Localiza intens

        printf("Digite a chave do item que deseja procurar: ");
        scanf("%d",&number);
        aponta_item = procurarItem( &lista, number);
        printf("Item procurado tem chave %d e indice %d \n", lista.Item[aponta_item].Chave, aponta_item);
        printf("\n");

      break;


      case 5:

        //Particiona a lista

        printf("Digite a chave do item a partir do qual deseja particionar: ");
        scanf("%d",&number);
        aponta_item = procurarItem( &lista, number);
        particionarLista(&lista, &lista2, aponta_item);

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
*/
