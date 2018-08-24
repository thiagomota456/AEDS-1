#include<stdio.h>

void mostrar(int *n);
int soma_todo_vetor(int *n);
void decrementar_1_posicao(int *vetor);
void decompor(int number);
int vetor_todo_decomposto(int *vetor);

int num;

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
	int vetor[num];
	int i;
	int aux;

	//inicialmente 
	vetor[0] = num;
	decrementar_1_posicao(vetor);

	//While enquando todas as posições do vetor não forem 1
	while(!vetor_todo_decomposto(vetor)){

		if(soma_todo_vetor(vetor) == num){
			mostrar(vetor);
			decrementar_1_posicao(vetor);
		}
		else{

			//duplico
			aux = vetor[0];
			vetor[1] = aux;

			for (i = 0; i < num; ++i)
			{
				//Se não for ==  a num ainda
				if(!testa_se_igual_a_num(vetor))
					vetor[1]--;
				else
					vetor[0]--;
			}//end for i

		}//end else 

	}//end while 

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

int testa_se_igual_a_num(int *vetor){

	if(soma_todo_vetor(vetor) == num){
		mostrar(vetor);
		decrementar_1_posicao(vetor);
		return 1;
	}
	else
		return 0;

}

void decrementar_1_posicao(int *vetor){

	int aux;

	aux = vetor[0];

	//Zero todas as posições do vetor
	memset(vetor, 0,  num * sizeof(vetor));

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