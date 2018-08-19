#include<stdio.h>
#include <stdlib.h>
#include <math.h>

//Se passar tiro os códigos comentados antigos e os pra dbug depois
int numerosDeDigitosDoFatorial(int num);
void fatorial(int num, int *vetor);

int main(){
		int resultado[100000];
		int num;

		printf("Digite um numero inteiro: ");
		scanf("%d",&num);		
		

		fatorial(num,resultado);

}//end main

void fatorial(int num, int *vetor){
	int i, j,resultado;
	int numerosQueContei = 1;
	int resto = 0;
	vetor[0]=1;

	//printf("vetor[0] = ");
	//printf("%d\n", vetor[0]);

	for(i=1; i<=num; i++){

			//printf(" I = %d\n\n",i );
		for(j = 0; j < numerosQueContei; j++){
			//printf("J = %d\n", j);
			//printf("numerosQueContei = %d\n\n", numerosQueContei);

			resultado = vetor[j] * i + resto;
			//printf("resultado = vetor[j] * i + resto = %d\n", resultado);			
			vetor[j] = resultado%10;
			//printf("vetor[j] = resultado%10 = %d\n", vetor[j]);			
			resto = resultado / 10;
			//printf("resto = vetor[j] / 10 = %d\n", resto );
		}

		while(resto > 0){

			//printf("numerosQueContei = %d\n\n", numerosQueContei);

			vetor[numerosQueContei] = resto % 10;
			resto = resto / 10;
			numerosQueContei++;		
		}


	}
	
	printf("Resultado: ");
	for(i = numerosQueContei-1; i >= 0 ; i--){
		printf("%d", vetor[i]);
	}

}//end fatorial
