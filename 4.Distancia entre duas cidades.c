#include<stdio.h>
#include<stdlib.h>
#include<strig.h>

typedef struct cidade{

	char nome[21];
	int numero;

}CIDADE;

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

	for(i = 0; i < numero_de_cidades; i++)
		if(strcmp(cidaddes[i].nome,cidade_lida1) == 0)
			return cidaddes[i].nome;

	//Retorna 1

	return 1;

}//end cidadeCadastrada

//Função que le o arquivo nos padroes especificados

void * lerArquivo( char *nome_do_arquivo, char cidade_de_origem, char * cidade_de_destino, CIDADE * cidaddes, int numero_de_cidades_lidas){


	//Aprentemente eu não reciso receber número de arrestas
	//Ver isso depois

	FILE * PonteiroDeArquivo;

	PonteiroDeArquivo = fopen(nome_do_arquivo, "r");

	int numero_de_cidades_e_pesos;
	int i = 0;

	fscanf("%d", &numero_de_cidades_e_pesos);

	char cidade_lida1[21];
	char cidade_lida2[21];

	int linha, coluna, distancia;

	//Inicio minha matriz de cidades

	*matriz_de_distancias = malloc( 1 * sizeof(int));

	while(i < numero_de_cidades_e_pesos){

		//leio a linha

		fscanf(PonteiroDeArquivo,"%s %s %d", cidade_lida1, cidade_lida2, &distancia);

		//Caso a cidade não exita

		if( cidadeCadastrada(cidaddes, (*numero_de_cidades_lidas), cidade_lida1) ){

			//Cadastro nova cidade

			strcpy(cidaddes[(*numero_de_cidades_lidas)].nome, cidade_lida1);

			//Add número da cidade
			
			cidaddes[(*numero_de_cidades_lidas)].numero = (*numero_de_cidades_lidas);

			//Atribuo linha da cidade

			linha = (*numero_de_cidades_lidas);

			//Incremento número de cidades

			(*numero_de_cidades_lidas) = (*numero_de_cidades_lidas) + 1;

					 
			

		}else{
			//Se ja foi cadastrado add a linha da cidade que é a mesma que seu numero

			//Depois criar uma função especifica so pra pesquisar cidades por nome			
			linha = cidadeCadastrada(cidaddes, (*numero_de_cidades_lidas), cidade_lida1);

		}


		//Caso cidade não exista			
				

	}//end while(i<numero_de_cidades_e_pesos)

	fclose(PonteiroDeArquivo);

}//end lerArquivo

int main(){

	CIDADE cidaddes[1000];
	int numero_de_cidades= 0;
	int *matriz_de_distancias;

	/***********Criar funções que pesquisa cidade e retorna numero**********/
	
	char nome_do_arquivo[100];
	char cidade_de_origem[21];
	char cidade_de_destino[21];

	//Leitura do arquivo

	printf("Digite o nome do arquivo de entrada: ");
	scanf("%s", nome_do_arquivo);
	lerArquivo(matriz_de_distancias, nome_do_arquivo, &cidade_de_origem, &cidade_de_destino, &cidaddes, &numero_de_cidades);

	
	
}//end main
