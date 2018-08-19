
#include<stdio.h>
#include <stdlib.h>
#include <math.h>

int numerosDeDigitosDoFatorial(int num);

int main(){

	int i, j = 0;
	int num, tamamhoDoVetor;
	int *resultado;
	int numerosQueContei = 1, resto = 0;
	
	printf("Digite um numero inteiro: ");scanf("%d", &num);
	
	//Add vetor com tamanho depossiçoes adequada
	tamamhoDoVetor = numerosDeDigitosDoFatorial(num);
	resultado = (int *) malloc(tamamhoDoVetor * sizeof(int));
	//um no final
	resultado[tamamhoDoVetor] = 1;
	
	while(num--){
	
		while( j < numerosQueContei){
		
			resultado[tamamhoDoVetor - j] = resultado[tamamhoDoVetor - j] * (num + 1) + resto;
			resto = resultado[tamamhoDoVetor - j] / 10;
			
			if(resto != 0)
				numerosQueContei++;
			
			resultado[tamamhoDoVetor - j] = resultado[tamamhoDoVetor - j] % 10;
			j++;
			
			
		}
		
		numerosQueContei++;
		j = 0;
	}
	
	printf("Resultado:");
	for(i = 0; i < numerosQueContei; i++)
		printf("%d",resultado[i]);
	

}//end main

//Fonte : https://jandersongomes.com/index.php/2017/08/16/calcular-fatorial-de-numeros-maiores-do-que-50-000-em-c/
int numerosDeDigitosDoFatorial(int num){
	//Retorna sempre umdígito a mais
	return round((log(2*3.141592653)+log(num)+2*num*(log(num) - 1))/(2 * log(10))) + 1;
}
