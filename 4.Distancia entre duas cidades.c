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

	int i;

	//Percorre todas as cidades ja existentes

	for(i = 0; i < numero_de_cidades; i++){

		//printf("Cidade %s de inicide %d\n", cidaddes[i].nome, i);

		if(strcmp(cidaddes[i].nome, cidade_lida1) == 0){
			//printf("Encontrei a cidae\n");
			return cidaddes[i].numero +1;
		}


	}

	//Retorna 0
 
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

	int numero_de_cidades_e_pesos;
	int i = 0;

	fscanf(PonteiroDeArquivo, "%d", &numero_de_cidades_e_pesos);
	//printf("Numero de linhas %d\n", numero_de_cidades_e_pesos);

	//Aux pra ler cidaes, posso sibstitui depois por cidade_de_origem e ciade destino

	char cidade_lida1[21];
	char cidade_lida2[21];

	//variaveis pra add valores a matriz de ciades

	int linha, coluna, distancia;
	
	//Inicio minha matriz de cidades

	matriz_de_distancias = malloc(sizeof(int));

	while(i < numero_de_cidades_e_pesos){

		//leio a linha

		fscanf(PonteiroDeArquivo,"%s %s %d", cidade_lida1, cidade_lida2, &distancia);
		//printf("Lido: %s %s %d\n", cidade_lida1, cidade_lida2, distancia);

		//Cidade Lida 1
		//Caso a cidade não exita

		if( cidadeCadastrada(cidaddes, *numero_de_cidades_lidas, cidade_lida1) == 0){

			//printf("Cadastrando cidade %s\n", cidade_lida1);

			//Cadastro nova cidade

			strcpy(cidaddes[*numero_de_cidades_lidas].nome, cidade_lida1);

			//printf("Guardei %s no meu vetor de vidade com indice %d\n",cidaddes[*numero_de_cidades_lidas].nome,  *numero_de_cidades_lidas);

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

			//Depois criar uma função especifica so pra pesquisar cidades por nome			
			linha = cidadeCadastrada(cidaddes, (*numero_de_cidades_lidas), cidade_lida1) - 1;

		}//end cadastro cidae 1



		//Cidade Lida 2
		//Caso a cidade não exita

		if( cidadeCadastrada(cidaddes, *numero_de_cidades_lidas, cidade_lida2) == 0){

			//printf("Cadastrando cidade %s\n", cidade_lida2);

			//Cadastro nova cidade

			strcpy(cidaddes[*numero_de_cidades_lidas].nome, cidade_lida2);

			//printf("Guardei %s no meu vetor de vidade com indice %d\n",cidaddes[*numero_de_cidades_lidas].nome,  *numero_de_cidades_lidas);

			//Add número da cidade
			
			cidaddes[*numero_de_cidades_lidas].numero = (*numero_de_cidades_lidas);

			//Atribuo linha da cidade

			coluna = *numero_de_cidades_lidas;

			//Incremento número de cidades

			*numero_de_cidades_lidas = *numero_de_cidades_lidas + 1;

			//Aloca Matriz

			matriz_de_distancias = Aloca_matriz(matriz_de_distancias, *numero_de_cidades_lidas,*numero_de_cidades_lidas);

		}else{
			//Se ja foi cadastrado add a linha da cidade que é a mesma que seu numero

			//Depois criar uma função especifica so pra pesquisar cidades por nome			
			coluna = cidadeCadastrada(cidaddes, (*numero_de_cidades_lidas), cidade_lida2) - 1;

		}//end cadastro cidade 2

		//add peso da cidae 1 pra cidade 2  e da cidade 2 pra cidade
	
		matriz_de_distancias[linha][coluna] = distancia;
		matriz_de_distancias[coluna][linha] = distancia;		

		//Incremento

		i++;

	}//end while(i<numero_de_cidades_e_pesos)

	//Leio cidade de origem e cidade de destino

	fscanf(PonteiroDeArquivo,"%s %s", cidade_de_origem, cidade_de_destino);

	//Fecho arquivo

	fclose(PonteiroDeArquivo);

	printarVetorDeCidades( cidaddes, *numero_de_cidades_lidas);

	//Retona matriz de distancia

	return matriz_de_distancias;

}//end lerArquivo

void printarVetorDeCidades(CIDADE * cidaddes, int quantidade){
	
	int i;

	for(i = 0; i < quantidade; i++){
		printf("%s %d\n", cidaddes[i].nome, cidaddes[i].numero);
	}


}//end printarVetorDeCidades

void printarMatrizQuadrada(int **matriz, int tamanho){
	int i, j;

	for(i = 0; i < tamanho; i++)
		for(j = 0; j < tamanho; j++)
			printf
}

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
	//printf("%s\n", nome_do_arquivo);
	matriz_de_distancias = lerArquivo(nome_do_arquivo, cidade_de_origem, cidade_de_destino, cidaddes, &numero_de_cidades);

	
}//end main
