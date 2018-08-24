#include<stdio.h>

void mostrar(int *n);
int soma_todo_vetor(int *n);


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

	//Zero todas as posições do vetor
	memset(vetor, 0,  number * sizeof(vetor));

	//Decremento
	//number = number--;
	//1° posição do vetor igual a número decrementado
	vetor[0] = number;

	//for(i = 1; i <= number; i++){

		//if( soma_todo_veto(vetor) == num ) //vetor[i] = number;
		//	mostrar(vetor);
	//}

}//end decompor

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

		if(n[i] != 0)//Se não é 0
			printf("%d", n[i]);//printa o número

		if(i+1 != num)
			printf(" + ");
		else
			printf("\n");
	}//end for

}//end mostrar