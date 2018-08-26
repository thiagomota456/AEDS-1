#include<stdio.h>

void mostrar(int *n);
void printarVetor(int *vetor);
int soma_todo_vetor(int *n);
void decrementar_1_posicao(int *vetor);
void decompor(int number);
int vetor_todo_decomposto(int *vetor);

int num;
int indice_atual = 0 , indice_proximo = 1;

int main(){

	printf("Digite um numero inteiro: ");
	scanf("%d", &num);

	printf("Decomposicao:\n");

	//O proprio número printado que sempre acontece
	printf("%d\n",num );

	decompor(num);
}

void decompor(int number){


	//O máximo de posiçoes que preciso é igual ao número de  
	int *vetor = (int *) calloc(num, sizeof(int));
	int aux;
	//int indice_atual = 0 , indice_proximo = 1;

	//inicialmente 
	vetor[indice_atual] = num-1;


	//While enquando todas as posições do vetor não forem 1
	while(!vetor_todo_decomposto(vetor)){

		printf("Vetor antes de ser avaliado: "); printarVetor(vetor);

		if(soma_todo_vetor(vetor) == num){
			mostrar(vetor);

			/*//Pra que eu depremente do indice 0 o depois dele == 1, ele != de 1.(E tem que ser ele o atual)
			if((vetor[indice_proximo] == 1) && (vetor[indice_atual] != 1) && (indice_atual == 0)){
				decrementar_1_posicao(vetor);
			}
			else */if( (vetor[indice_proximo] != 1) && (vetor[indice_atual] != 1)){
			//if((vetor[indice_atual] != 1){
				indice_atual = indice_proximo;

				//Tenho que garantir que o inicice proximo seja <= a num -1
				if(indice_proximo < (num-1))
					indice_proximo++;

			}else if(indice_atual != 0){
				indice_atual--;
				indice_proximo--;
			}

		}

		
			printf("Indice atual = %d\n", indice_atual);
			printf("Indice proximo= %d\n", indice_proximo);

		if( (vetor[indice_proximo] != 0) && (vetor[indice_proximo] != 1) )
			vetor[indice_proximo]--;
		else if( (vetor[indice_proximo]==1) && (vetor[indice_atual]!=1) && (indice_atual != 0))
			vetor[indice_atual]--;

		printf("Vetor decremntado: "); printarVetor(vetor);		

		//condição para duplicar
		if((vetor[indice_atual] != 1) && (vetor[indice_proximo] == 0)){
			aux = vetor[indice_atual];
			vetor[indice_proximo] = aux;

			printf("Indice duplicado: "); printarVetor(vetor);			

		}else if((vetor[indice_atual] != 1) && (vetor[indice_proximo] == 1)){

			if((indice_atual == 0) && vetor[indice_proximo] == 1){
				printf("1° posição decremntada: "); printarVetor(vetor);
				decrementar_1_posicao(vetor);
			}
			else{
				vetor[indice_proximo]--;
			}

		}else if(indice_atual != 0){
			if((vetor[indice_atual-1] != 1) && (vetor[indice_proximo] == 0)){

				aux = vetor[indice_atual];
				vetor[indice_proximo] = aux;
				vetor[indice_atual-1]--;

			}else if((vetor[indice_atual] == 1) && (vetor[indice_proximo] == 1) && (indice_atual-1 == 0)){
				decrementar_1_posicao(vetor);
			}
		}

		getchar();

	}		 

}//end decompor

int vetor_todo_decomposto(int *vetor){
	int i;

	for (i = 0; i < num; ++i)
	{
		if(vetor[i] != 1)
		return 0;
	}

	return 1;
}

void decrementar_1_posicao(int *vetor){

	int aux;

	//Reseto os indices
	indice_atual = 0; 
	indice_proximo = 1;

	aux = vetor[0];

	//Zero todas as posições do vetor
	memset(vetor, 0,  num * sizeof(int));

	//Decremento 1
	aux--;

	//add a 1° posicao  1 decrementado
	vetor[0] = aux;
}

//Funcionando
int soma_todo_vetor(int *n){
	int aux = 0;
	int i;

	for(i = 0; i < num; i++){
		aux += n[i];
	}

	return aux;
}//end soma_todo_vetor


//Funcionando
void mostrar(int *n){
	int i;

	for (i = 0; i < num; ++i){

		if(n[i] != 0){//Se não é 0
			printf("%d", n[i]);//printa o número

			//add um + se não é o ulto numero ou se o proxímo não é  
			if( (i+1 != num) && (n[i+1] != 0) )
				printf(" + ");
			else
				printf("\n");
		}
	}//end for
}//end mostrar

void printarVetor(int *vetor){
	int i;

	for(i = 0; i < num; i++){
		printf("%d ",vetor[i] );
	}

	printf("\n");
}//end printarVetor