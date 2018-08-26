#include<stdio.h>

void mostrar(int *n);
void printarVetor(int *vetor);
void copiaVetor(int *v1, int *v2);
int comparaVetor(int *v1, int *v2);
int avaliar_vetor(int *vetor);
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
	int *vetor = (int *) calloc(num, sizeof(int));
	int *ultimo = (int *) calloc(num, sizeof(int));
	vetor[0] = --number;
 	int i;

	while(!(vetor_todo_decomposto(vetor))){//temporario

		//Condiçoes para duplicar
		//Tem mais. Deixa essas por enquanto
		if( ( !(avaliar_vetor(vetor)) && (vetor[indice_proximo] == 0) ) 

			|| ( (indice_atual !=0) && (vetor[indice_proximo] == 0) )

		){
			vetor[indice_proximo] = vetor[indice_atual];
		}//end if(!(avaliar_vetor(vetor))&&(vetor[indice_proximo]==0))

		i = 0;
		while(i < num){
			if(!(avaliar_vetor(vetor)) && (vetor[indice_proximo] > 1) ){
				vetor[indice_proximo]--;
			}else if(indice_atual != 0 && vetor[indice_atual] > 1){
				vetor[indice_atual]--;
			}


			//Caso tenha encontrado
			if(avaliar_vetor(vetor) && !(comparaVetor(vetor, ultimo))){
				mostrar(vetor);
				copiaVetor(vetor, ultimo);
			}//end if avalia


			//printarVetor(vetor);
			i++;
		}//end while(i < num)
	
		//Caso tenha encontrado
		if(avaliar_vetor(vetor) && !(comparaVetor(vetor, ultimo))){
			mostrar(vetor);
			copiaVetor(vetor, ultimo);
		}//end if avalia

		//printf("Incide proximo %d\n", indice_proximo);
		//printf("Incide atual %d\n", indice_atual);

		//condição pra decrementar o primeiro 
		if((avaliar_vetor(vetor)) && (indice_atual == 0) && (vetor[indice_proximo] == 1)){
			decrementar_1_posicao(vetor);		
		}else if(( (vetor[indice_proximo+1] == 0) && (vetor[indice_proximo] != 1)) || ((vetor[indice_proximo+1] == 0) && (soma_todo_vetor(vetor) < num) )){
			indice_atual++;
			indice_proximo++;
		}else if(vetor[indice_proximo] == 1){
			indice_atual--;
			indice_proximo--;			
		}

		//getchar();
	}//end while

	mostrar(vetor);

}//end decompor

int avaliar_vetor(int *vetor){
	if(soma_todo_vetor(vetor) == num)
		return 1;

	return 0;	
}

void copiaVetor(int *v1, int *v2){
	int i;

	for(i = 0; i < num; i++){
		v2[i] = v1[i];
	}

}//end copiaVetor

int comparaVetor(int *v1, int *v2){
	int i;

	for(i = 0; i < num; i++){
		if(v2[i] != v1[i])
			return 0;
	}
	return 1;

}//end comparaVetor


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

	for(i = 0; i < 5; i++){
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
