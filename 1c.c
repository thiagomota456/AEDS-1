#include<stdio.h>

int mult(int base, int exp);

int main(){

	int base, exp;

	printf("Digite a base e o expoente inteiros: ");
	scanf("%d", &base);
	scanf("%d", &exp);

	printf("Resultado: %d", mult( base, exp) );
}

int mult(int base, int exp){

	int resultado = base;

	if(exp == 0)
		return 1;

	return resultado * mult( base, --exp); 
}



/*1. c) Potência

Disciplina: LAED - Laboratório de Algoritmos e Estruturas de Dados I 
Prazo de Entrega: 09/08/2018 23:55:55 Aberto
Implemente uma função recursiva que, dados dois números inteiros x e n, calcula o valor de x^n.

Não será permitido utilizar variáveis globais, vetores, listas ou qualquer outra estrutura de dados para armazenar o resultado. O protótipo da função deverá, obrigatoriamente, ser:

int mult(int base, int exp);

O programa deverá conter, além da função recursiva, uma função principal (main) para realização de testes, com o formato de saída de acordo com o exemplo a seguir:

Digite a base e o expoente inteiros: 2 8
Resultado: 256
*/