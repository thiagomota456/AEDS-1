#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

/*
tenho que alterar essa função
*/

	printf("\n\n\n");

	int i;

	//Percorre todas as cidades ja existentes

	for(i = 0; i < numero_de_cidades; i++){

		printf("Cidade %s de inicide %d\n", cidaddes[i].nome, i);

		if(strcmp(cidaddes[i].nome, cidade_lida1) == 0){
			printf("Encontrei a cidae\n");
			return cidaddes[i].numero +1;
		}


	}

	//Retorna 0
	printf("\n\n\n");

	return 0;

}//end cidadeCadastrada

//Função que le o arquivo nos padroes especificados
		//(nome_do_arquivo, &cidade_de_origem, &cidade_de_destino, &cidaddes, &numero_de_cidades);
int ** lerArquivo( char *nome_do_arquivo, char * cidade_de_origem, char * cidade_de_destino, CIDADE * cidaddes, int * numero_de_cidades_lidas){


	//Aprentemente eu não reciso receber número de arrestas
	//Ver isso depois

	FILE * PonteiroDeArquivo;
	int ** matriz_de_distancias;
	PonteiroDeArquivo = fopen(nome_do_arquivo, "r");

	printf("Declarações ok\n");

	int numero_de_cidades_e_pesos;
	int i = 0;

	fscanf(PonteiroDeArquivo, "%d", &numero_de_cidades_e_pesos);
	printf("Numero de linhas %d\n", numero_de_cidades_e_pesos);

	char cidade_lida1[21];
	char cidade_lida2[21];

	printf("Cheguei aqui ?");

	int linha, coluna, distancia;
	
	//Inicio minha matriz de cidades

	*matriz_de_distancias = malloc( 490 * sizeof(int));
	printf("Alocação da matriz ok\n");

	while(i < numero_de_cidades_e_pesos){

		//leio a linha

		fscanf(PonteiroDeArquivo,"%s %s %d", cidade_lida1, cidade_lida2, &distancia);

		printf("Lido: %s %s %d\n", cidade_lida1, cidade_lida2, distancia);

		//Cidade Lida 1
		//Caso a cidade não exita

		if( cidadeCadastrada(cidaddes, *numero_de_cidades_lidas, cidade_lida1) == 0){

			printf("Cadastrando cidade %s\n", cidade_lida1);

			//Cadastro nova cidade

			strcpy(cidaddes[*numero_de_cidades_lidas].nome, cidade_lida1);

			printf("Guardei %s no meu vetor de vidade com indice %d\n",cidaddes[*numero_de_cidades_lidas].nome,  *numero_de_cidades_lidas);

			//Add número da cidade
			
			cidaddes[*numero_de_cidades_lidas].numero = (*numero_de_cidades_lidas);

			//Atribuo linha da cidade

			linha = *numero_de_cidades_lidas;

			//Incremento número de cidades

			*numero_de_cidades_lidas = *numero_de_cidades_lidas + 1;

			/******************Falta alocar matriz***********/
			

		}else{
			//Se ja foi cadastrado add a linha da cidade que é a mesma que seu numero

			//Depois criar uma função especifica so pra pesquisar cidades por nome			
			linha = cidadeCadastrada(cidaddes, (*numero_de_cidades_lidas), cidade_lida1) - 1;

		}//end cadastro cidae 1



		//Cidade Lida 2
		//Caso a cidade não exita

		if( cidadeCadastrada(cidaddes, *numero_de_cidades_lidas, cidade_lida2) == 0){

			printf("Cadastrando cidade %s\n", cidade_lida2);

			//Cadastro nova cidade

			strcpy(cidaddes[*numero_de_cidades_lidas].nome, cidade_lida2);

			printf("Guardei %s no meu vetor de vidade com indice %d\n",cidaddes[*numero_de_cidades_lidas].nome,  *numero_de_cidades_lidas);

			//Add número da cidade
			
			cidaddes[*numero_de_cidades_lidas].numero = (*numero_de_cidades_lidas);

			//Atribuo linha da cidade

			coluna = *numero_de_cidades_lidas;

			//Incremento número de cidades

			*numero_de_cidades_lidas = *numero_de_cidades_lidas + 1;

			/******************Falta alocar matriz***********/

		}else{
			//Se ja foi cadastrado add a linha da cidade que é a mesma que seu numero

			//Depois criar uma função especifica so pra pesquisar cidades por nome			
			coluna = cidadeCadastrada(cidaddes, (*numero_de_cidades_lidas), cidade_lida2) - 1;

		}//end cadastro cidade 2

		//add peso da cidae 1 pra cidade 2  e da cidade 2 pra cidade 1

					
				

		//Incremento
		i++;

	}//end while(i<numero_de_cidades_e_pesos)


	printarVetorDeCidades(CIDADE * cidaddes, int quantidade);

	fclose(PonteiroDeArquivo);

	return matriz_de_distancias;

}//end lerArquivo

printarVetorDeCidades(){

}//end 

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
	printf("%s\n", nome_do_arquivo);
	matriz_de_distancias = lerArquivo(nome_do_arquivo, cidade_de_origem, cidade_de_destino, cidaddes, &numero_de_cidades);

	

	
	
}//end main
