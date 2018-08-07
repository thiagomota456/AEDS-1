#include<stdio.h>

int mdc(int a, int b);
int maior(int num1, int num2);
int menor(int num1, int num2);

int main(){

	int a,b;

	printf("Digite dois numeros inteiros: ");
	scanf("%d",&a);
	scanf("%d",&b);

	printf("Resultado: %d", mdc( maior(a,b) , menor(a,b) ) );
}

int mdc(int a, int b){

	if(b == 0)
		return a;

	return 	mdc(b, a%b);


}

int maior(int num1, int num2){

	if(num1 > num2)
		return num1;

	return num2;
}

int menor(int num1, int num2){

	if(num1 < num2)
		return num1;

	return num2;

}

//Link de onde eu achei o algoritimo de euclides que resolve o problema:(Da aula de filotec semestre passado)
//https://drive.google.com/open?id=1B2s6PQlEGUzvUEGYwL6182x7w-QBhGfb
/*1. d) Máximo Divisor Comum
Disciplina: LAED - Laboratório de Algoritmos e Estruturas de Dados I 
Prazo de Entrega: 09/08/2018 23:55:55 Aberto
Implemente uma função recursiva que, dados dois números inteiros a e b, calcula o Máximo Divisor Comum (MDC) entre eles.

Não será permitido utilizar variáveis globais, vetores, listas ou qualquer outra estrutura de dados para armazenar o resultado. O protótipo da função deverá, obrigatoriamente, ser:

int mdc(int a, int b);

O programa deverá conter, além da função recursiva, uma função principal (main) para realização de testes, com o formato de saída de acordo com o exemplo a seguir:

Digite dois numeros inteiros: 25 10
Resultado: 5
*/
