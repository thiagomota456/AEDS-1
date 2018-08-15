#include<stdio.h>
#define MAXREAD 200

void lerBignNum(int *num);
void printBigNum(int *num);
void printBigNum(int *num);
int *menor(int *num1, int *num2);
int casasDecimaisBigNum(int *num);
void addZeroEsquerdaBigNum(int *num1, int *num2);
int *maisCasasDecimaisBigNum(int *num1, int *num2);
int *menosCasasDecimaisBigNum(int *num1, int *num2); 
int mesmoNumDeCasasDecimais(int *num1, int *num2);


int main(){
	int num1[MAXREAD];
	int num2[MAXREAD];

	printf("Digite um numero inteiro qualquer: ");
	lerBignNum(num1);
	
	printf("Digite um segundo numero inteiro qualquer: ");
	lerBignNum(num2);

	//Testes
	printf("Número 1: "); printBigNum(num1); printf("\n");
	printf("Tamnaho 1: %d\n",casasDecimaisBigNum(num1));

	printf("\n");
	
	printf("Número 2: "); printBigNum(num2); printf("\n");
	printf("Tamnaho 2: %d\n",casasDecimaisBigNum(num2));

	printf("Mais casas decimais: ");printBigNum(maisCasasDecimaisBigNum(num1,num2)); printf("\n");
	printf("Menos casas decimais: ");printBigNum(menosCasasDecimaisBigNum(num1,num2)); printf("\n");

	addZeroEsquerdaBigNum(num1, num2);
	printf("\n");

	if(!(mesmoNumDeCasasDecimais(num1,num2)))
		printBigNum(menosCasasDecimaisBigNum(num1,num2)); printf("\n");



}//end main


void addZeroEsquerdaBigNum(int *num1, int *num2){

	int addZeros[MAXREAD];
	int *menorNum = menor(num1, num2);
	int numerosDeZeros = casasDecimaisBigNum(maisCasasDecimaisBigNum(num1,num2)) - casasDecimaisBigNum(menosCasasDecimaisBigNum(num1,num2));
	int i, j;

	for(i = 0; i < casasDecimaisBigNum(menosCasasDecimaisBigNum(num1, num2)); i++){
		for(j = 0; j < numerosDeZeros; j++){
			addZeros[j] = 0;
		}


		addZeros[i+j] = menorNum[i];  
	}

	if(menor(num1, num2) == num1)
		num1 = menorNum;
	else
		num2 = menorNum;

}//end addZeroEsquerda

int *menor(int *num1, int *num2){
	int i;

	//Se os numeros tiverem mesmo número de casas decimais
	if(mesmoNumDeCasasDecimais(num1,num2)){
		for(i = 0; i < casasDecimaisBigNum(num1); i++){
			if(num1[i] < num2[i])
				return num1;
			if(num1[i] > num2[i])
				return num2;
		}

	}
	else
		return menosCasasDecimaisBigNum(num1, num2);
		//Consíderando que o usuário não tenha satánas no coração de dígitar zero a esquerda, o menor numero será sempre o de menor número de casas decimais
		//Caso necessário, posso garantir que não haja zeros a esquerda na leitura do número.
		
	//Se forem iguais vai retornar falso
	return 0;
}

int mesmoNumDeCasasDecimais(int *num1, int *num2){
	return ( casasDecimaisBigNum(num1) == casasDecimaisBigNum(num2) );
}

int *maisCasasDecimaisBigNum(int *num1, int *num2){
	//Condição ? verdadeiro : falso
	return (casasDecimaisBigNum(num1) > casasDecimaisBigNum(num2)) ? num1 : num2;
}//end maior

int *menosCasasDecimaisBigNum(int *num1, int *num2){
	//Condição ? verdadeiro : falso
	return (casasDecimaisBigNum(num1) < casasDecimaisBigNum(num2)) ? num1 : num2;
}//end maior

void lerBignNum(int *num){

	char number_srt[MAXREAD];
	int i = 0;

	scanf("%s", number_srt);

	for(i = 0; number_srt[i] != '\0'; i++){
		num[i] = (int)number_srt[i] - 48;
	}

	//Marca o final o número
	num[i] = -1;

}//end lerBignNum

void printBigNum(int *num){

	int i = 0;

	for(i = 0; num[i] != -1; i++){
		printf("%d",num[i]);
	}

}//end printBigNum

/*
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
*/
int casasDecimaisBigNum(int *num){
	int i = 0;

	while(num[i++] != -1)//Compara antes de incrementar. Ao achar, incrementa mais um.
		;

	return i-1;

}//end CasasDecimaisBigNum