#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <math.h>

/* definir variavies */
int destino, origem, vertices = 0;
int custo, *custos = NULL;

typedef struct cidade{

	char nome[21];
	int numero;

}CIDADE;

//Pra ver se cidades e numeros foram associados corretamente

void printarVetorDeCidades(CIDADE * cidaddes, int quantidade){
	
	int i;

	for(i = 0; i < quantidade; i++){
		printf("%s %d\n", cidaddes[i].nome, cidaddes[i].numero);
	}


}//end printarVetorDeCidades

//Pra vez se distancia foi cadastrada corretamente

void printarMatrizQuadrada(int **matriz, int tamanho){
	int i, j;

	for(i = 0; i < tamanho; i++){
		for(j = 0; j < tamanho; j++){
			printf("%04d ", matriz[i][j]);
		}//end for j

		printf("\n");
	}//end for i
			
}//end printarMatrizQuadrada

//função que aloca matriz

int ** Aloca_matriz(int **matriz, int lin, int col){

	// Adaptado de https://www.ime.usp.br/~pf/algoritmos/aulas/aloca.html

	matriz = realloc (matriz, lin * sizeof(int *));

	for(int i = 0; i < lin; i++)
		matriz[i] = realloc (matriz[i], col * sizeof(int));

	return matriz;	
	
}//end Aloca_matriz

int cidadeCadastrada(CIDADE * cidaddes,int numero_de_cidades, char * cidade_lida1){

	int i;

	//Percorre todas as cidades ja existentes

	for(i = 0; i < numero_de_cidades; i++){

		//verifica se a cidade já

		if(strcmp(cidaddes[i].nome, cidade_lida1) == 0){
			
			//Caso cidade encontrada

			return 1;
		}

	}//end for

	//Caso não encontrada
 
	return 0;

}//end cidadeCadastrada

void addCidade(){

}//end addCidade

int NumeroDaCidadeCadastrada(CIDADE * cidaddes,int numero_de_cidades, char * cidade_lida1){

	int i;

	//Percorre todas as cidades ja existentes

	for(i = 0; i < numero_de_cidades; i++){

		//Se for igual a cidade procurada

		if(strcmp(cidaddes[i].nome, cidade_lida1) == 0){
			//printf("Encontrei a cidae\n");
			return cidaddes[i].numero;
		}

	}//end for

	//Caso não encontrado
 
	return -1;

}//end NumeroDaCidadeCadastrada

//Função que le o arquivo nos padroes especificados
//Depois quero simplificar mais a lsita de paramentros dessa função e separala em mais funções para tornal mais legivel
		
int ** lerArquivo( char *nome_do_arquivo, char * cidade_de_origem, char * cidade_de_destino, CIDADE * cidaddes, int * numero_de_cidades_lidas){


	//Aprentemente eu não reciso receber número de arrestas
	//Ver isso depois

	FILE * PonteiroDeArquivo;
	int ** matriz_de_distancias;
	PonteiroDeArquivo = fopen(nome_do_arquivo, "r");

	int numero_de_cidades_e_pesos;
	int i = 0;

	fscanf(PonteiroDeArquivo, "%d", &numero_de_cidades_e_pesos);
 
	//variaveis pra add valores a matriz de ciades

	int linha, coluna, distancia;
	
	//Inicio minha matriz de cidades

	matriz_de_distancias = malloc(sizeof(int));

	while(i < numero_de_cidades_e_pesos){

		//leio a linha

		fscanf(PonteiroDeArquivo,"%s %s %d", cidade_de_destino, cidade_de_origem, &distancia);
 
		//Caso a cidade não exita

		if( cidadeCadastrada(cidaddes, *numero_de_cidades_lidas, cidade_de_destino) == 0){

			//Cadastro nova cidade

			strcpy(cidaddes[*numero_de_cidades_lidas].nome, cidade_de_destino);

			//Add número da cidade
			
			cidaddes[*numero_de_cidades_lidas].numero = (*numero_de_cidades_lidas);

			//Atribuo linha da cidade

			linha = *numero_de_cidades_lidas;

			//Incremento número de cidades

			*numero_de_cidades_lidas = *numero_de_cidades_lidas + 1;

			//Aloca matriz que contem as distancias das cidades

			matriz_de_distancias = Aloca_matriz(matriz_de_distancias, *numero_de_cidades_lidas,*numero_de_cidades_lidas);
			

		}else{
			//Se ja foi cadastrado add a linha da cidade que é a mesma que seu numero
			
			linha = NumeroDaCidadeCadastrada(cidaddes, (*numero_de_cidades_lidas), cidade_de_destino);

		}//end cadastro cidae 1
 
		//Caso a cidade não exita

		if( cidadeCadastrada(cidaddes, *numero_de_cidades_lidas, cidade_de_origem) == 0){

			//Cadastro nova cidade

			strcpy(cidaddes[*numero_de_cidades_lidas].nome, cidade_de_origem);

			//Add número da cidade
			
			cidaddes[*numero_de_cidades_lidas].numero = (*numero_de_cidades_lidas);

			//Atribuo linha da cidade

			coluna = *numero_de_cidades_lidas;

			//Incremento número de cidades

			*numero_de_cidades_lidas = *numero_de_cidades_lidas + 1;

			//Aloca Matriz

			matriz_de_distancias = Aloca_matriz(matriz_de_distancias, *numero_de_cidades_lidas,*numero_de_cidades_lidas);

		}else{
			//Se ja foi cadastrado add a coluna da cidade que é a mesma que seu numero
		
			coluna = NumeroDaCidadeCadastrada(cidaddes, (*numero_de_cidades_lidas), cidade_de_origem);

		}//end cadastro cidade 2

		//add peso da cidae 1 pra cidade 2  e da cidade 2 pra cidade
	
		matriz_de_distancias[linha][coluna] = distancia;
		matriz_de_distancias[coluna][linha] = distancia;		

		//Incremento

		i++;

	}//end while(i<numero_de_cidades_e_pesos)

	//Leio cidade de origem e cidade de destino

	fscanf(PonteiroDeArquivo,"%s %s", cidade_de_origem, cidade_de_destino);

	printf("%s %s", cidade_de_origem, cidade_de_destino);

	//Fecho arquivo

	fclose(PonteiroDeArquivo);

	//Testes pra ver se leitura foi realizada adequadamente

	printarVetorDeCidades( cidaddes, *numero_de_cidades_lidas);

	printarMatrizQuadrada(matriz_de_distancias, *numero_de_cidades_lidas);	

	//Retona matriz de distancia

	return matriz_de_distancias;

}//end lerArquivo


void add(int numero_de_cidades, int **matriz_de_distancias)
{
  int i, j;

	//Vertices são meu número de cidades

	vertices = numero_de_cidades;

	//Não sei exatamente o pq dessa porra, mas deixa por enquanto
	//Mas acho que é pq o algoritimo que éguei podia receber mais d eum grafo por execução

	if (!custos)
		free(custos);

	custos = (int *) malloc(sizeof(int)*vertices*vertices);

	for (i = 0; i <= vertices * vertices; i++)
	custos[i] = -1;

	// Inserir arestas

	for(i = 0; i < vertices; i++){

		//Para todas as vertices possiveis add caminhos

		for(j = 0; j < vertices; j++){
		
			//Recebo origem (indexando de um pq o algoritimmo fonte faz assim)

			origem = i+1;

			//Recebo destino (indexando de um pq o algoritimmo fonte faz assim)

			destino = j+1;

			//Recebo custo armazenado na minha matriz

			custo = matriz_de_distancias[i][j];

			custos[(origem-1) * vertices + destino - 1] = custo;

		}//end for j
			
	}//end for i

}//end add

void dijkstra(int vertices,int origem,int destino, int *custos, CIDADE *listaDeCidades){

printf("Declaração de variaveis");

  int i,v, cont = 0;
  int *ant, *tmp; 
  int *z; /* vertices para os quais se conhece o caminho minimo */
  double min;
  double dist[vertices]; /* vetor com os custos dos caminhos */


  /* aloca as linhas da matriz */
  ant = calloc (vertices, sizeof(int *));
  tmp = calloc (vertices, sizeof(int *));

printf("Alocação");

  if (ant == NULL) {
    printf ("** Erro: Memoria Insuficiente **");
    exit(-1);
  }

  z = calloc (vertices, sizeof(int *));

  if (z == NULL) {
    printf ("** Erro: Memoria Insuficiente **");
    exit(-1);
  }

  for (i = 0; i < vertices; i++) {
    if (custos[(origem - 1) * vertices + i] !=- 1) {
      ant[i] = origem - 1;
      dist[i] = custos[(origem-1)*vertices+i];
    }

    else {
      ant[i]= -1;
      dist[i] = HUGE_VAL;
    }
    z[i]=0;
  }
  z[origem-1] = 1;
  dist[origem-1] = 0;

  /* Ciclo principal */
  do {
    /* Encontra o vertice que deve entrar em z */
    min = HUGE_VAL;
    for (i=0;i<vertices;i++)
      if (!z[i])
        if (dist[i]>=0 && dist[i]<min) {
          min=dist[i];v=i;
        }

    /* Calcula distancias dos novos vizinhos de z */
    if (min != HUGE_VAL && v != destino - 1) {
      z[v] = 1;
      for (i = 0; i < vertices; i++)
        if (!z[i]) {
          if (custos[v*vertices+i] != -1 && dist[v] + custos[v*vertices+i] < dist[i]) {
            dist[i] = dist[v] + custos[v*vertices+i];
            ant[i] =v;
          }
        }
    }
  } while (v != destino - 1 && min != HUGE_VAL);

  /* Mostra o Resultado da procura */
  
    i = destino;
    i = ant[i-1];
    while (i != -1) {
      
      tmp[cont] = i+1;
      cont++;
      i = ant[i];

    }
 
    for (i = cont; i > 0 ; i--) {
      printf("%s ", listaDeCidades[tmp[i-1]].nome);
    }

    printf("%s ", listaDeCidades[destino-1].nome);
 
    printf("\nDistancia total: %d Km",(int) dist[destino-1]);
 
}//end dijkstra

int main(){

	CIDADE cidaddes[1000];
	int numero_de_cidades= 0;
	int **matriz_de_distancias;

	/***********Criar funções que pesquisa cidade e retorna numero**********/
	
	char nome_do_arquivo[100];
	char cidade_de_origem[21];
	char cidade_de_destino[21];

	//Leitura do arquivo

	printf("Digite o nome do arquivo de entrada: ");
	scanf("%s", nome_do_arquivo);
	
	matriz_de_distancias = lerArquivo(nome_do_arquivo, cidade_de_origem, cidade_de_destino, cidaddes, &numero_de_cidades);


	//Add a estrutura que o alg. que peguei da net trabalha
	add(numero_de_cidades, matriz_de_distancias);

	//Passo pro alg. Achar o menor percurso

	int origemDeProcura = NumeroDaCidadeCadastrada(cidaddes,numero_de_cidades, cidade_de_origem) + 1;
	int destinoDeProcura = NumeroDaCidadeCadastrada(cidaddes,numero_de_cidades, cidade_de_destino)+ 1;

	printf("origem: %d\n", origemDeProcura);
	printf("Destino: %d\n", destinoDeProcura);

	//dijkstra(vertices, i,j, custos)

	dijkstra(numero_de_cidades, origemDeProcura, destinoDeProcura, custos, cidaddes);

	
}//end main

