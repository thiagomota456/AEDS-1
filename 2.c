#include<stdio.h>
#define MAXREAD 15

void printBigNum(int *num);
void printBigNum(int *num);
int tamanhoBigNum(int *num);

int main(){

	int num[MAXREAD];

	printf("Digite um numero inteiro: ");
	lerBignNum(num);

	printBigNum(num);
	printf("Tamnaho %d\n",tamanhoBigNum(num));
}

void lerBignNum(int *num){

	char number_srt[MAXREAD];
	int i = 0;

	scanf("%s", number_srt);

	for(i = 0; number_srt[i] != '\0'; i++){
		num[i] = (int)number_srt[i] - 48;
	}

	//Marca o final o número
	num[i] = -1;

}

void printBigNum(int *num){

	int i = 0;

	for(i = 0; num[i] != -1; i++){
		printf("%d",num[i]);
	}
	printf("\n");
}

void soma(int *resultado, int *num1, int *num2){
	//fazer a soma acessano os elementos de tras pra frente
	for()
}
 
void somar_um_elemento( int *vai_um, int *resultado, int *num1, int *num2){
	int aux = *num1 + *num2;

	if(aux >= 10){
		aux = aux - 10;
		*resultado = aux;
		*vai_um +=1; 
	}
	else{
		*resultado = aux;
	}

}

int tamanhoBigNum(int *num){
	int i = 0;

	while(num[i++] != -1)//Compara antes de incrementar. Ao achar, incrementa mais um.
		;

	return i-1;
}