#include<stdio.h>
#define MAXREAD 200

void lerBignNum(int *num);
void printBigNum(int *num);
void printBigNum(int *num);
int *menor(int *num1, int *num2);
int casasDecimaisBigNum(int *num);
int *addZeroEsquerdaBigNum(int *num1, int *num2);
int *maisCasasDecimaisBigNum(int *num1, int *num2);
int *menosCasasDecimaisBigNum(int *num1, int *num2); 
int mesmoNumDeCasasDecimais(int *num1, int *num2);


int main(){
	int *num1 = (int*) malloc(MAXREAD * sizeof(int));
	int *num2 = (int*) malloc(MAXREAD * sizeof(int));

	printf("Digite um numero inteiro qualquer: ");
	lerBignNum(num1);
	
	printf("Digite um segundo numero inteiro qualquer: ");
	lerBignNum(num2);

	printf("\n");

	teste(num1, num2);
	
}//end main

void teste(int *num1, int num2){

	//antes add 0's
	numeroETamanho(num1);
	numeroETamanho(num2);

	//Add 0 no menor número
	if(mesmoNumDeCasasDecimais(num1,num2))
		return 0;
	else if(num1 == menosCasasDecimaisBigNum(num1,num2))
			num1 = addZeroEsquerdaBigNum(num1, num2);
		else 
			num2 = addZeroEsquerdaBigNum(num1, num2);

	//Depois de add 0's
	numeroETamanho(num1);
	numeroETamanho(num2);
}

void numeroETamanho(int *num){
	printf("Número : "); printBigNum(num); printf("\n");
	printf("Tamnaho: %d\n",casasDecimaisBigNum(num));
	printf("\n");	
}


int *addZeroEsquerdaBigNum(int *num1, int *num2){

	int *addZeros = (int*) malloc(MAXREAD * sizeof(int));
	int *menorNum = menor(num1, num2);
	int numerosDeZeros = casasDecimaisBigNum(maisCasasDecimaisBigNum(num1,num2)) - casasDecimaisBigNum(menosCasasDecimaisBigNum(num1,num2));
	int i, j;

	for(i = 0; i < casasDecimaisBigNum(menosCasasDecimaisBigNum(num1, num2)); i++){
		for(j = 0; j < numerosDeZeros; j++){
			addZeros[j] = 0;
		}


		addZeros[i+j] = menorNum[i];  
	}

	addZeros[i+j] = -1;

	return addZeros;
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