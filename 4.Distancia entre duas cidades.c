#include<stdio.h>
#include<stdlib.h>

typedef struct cidade{

	char nome[21];
	int * caminhos;

}CIDADE;

//função que aloca matriz

int ** Aloca_matriz(int **matriz, int lin, int col){

	
}

//Função que le o arquivo nos padroes especificados

void lerArquivo(int *numeroDeCidades, CIDADE **matriz, char *nomeDoArquivo){	

	FILE *PonteiroDeArquivo;
	int i = 0;
	int auxiliar;

	//Abri arquivo para leitura

	PonteiroDeArquivo = fopen(nomeDoArquivo, "r");

	//Testa se realizoua a litura correta, 
	
	if(PonteiroDeArquivo == NULL){

		printf("ERRO: NAO FOI POSSIVEL ABRIR O ARQUIVO\n");
		return;
	}

	//Leio mochila

	fscanf( PonteiroDeArquivo, " %d", numeroDeCidades);

	//auxiliar pra cria matriz e ler itens mais facilmente

	auxiliar = *numeroDeCidades;

	printf("%d", auxiliar);
	//Crio matriz de cidades

	*matriz = (CIDADE *) malloc(auxiliar * sizeof(CIDADE *));
	for(i = 0; i < auxiliar; i++){

		(*matriz)[i].caminhos = (int *) malloc(auxiliar * sizeof(int)); 

	}//end for

	fclose(PonteiroDeArquivo);
}//end lerArquivo

int main(){

	int numCidades;
	CIDADE *matriz;

	lerArquivo(&numCidades, &matriz, "file.txt");
}//end main
