#include<stdio.h>

int i = 0;

int Digitos(int N);
int main(){

	int num;

	printf("Digite um numero inteiro: ");
	scanf("%d", &num);

	printf("Resultado: %d", Digitos(num));

}

int Digitos(int N){

	int retorno = 1;

	if( N >= 10 )
		retorno = Digitos(N/10) + 1;
	
	return retorno;
}


/*1. a) Dígitos

Disciplina: LAED - Laboratório de Algoritmos e Estruturas de Dados I 
Prazo de Entrega: 09/08/2018 23:55:55 Aberto
A função a seguir recebe como parâmetro um número inteiro N e retorna o número de dígitos de N:

int Digitos(int N){
  int cont = 1;

  while(N >= 10){
    N = N /10;
    cont = cont + 1;
  }

  return cont;
}
Reescreva a função Digitos tornando-a recursiva.

Não será permitido utilizar variáveis globais, vetores, listas ou qualquer outra estrutura de dados para armazenar o resultado. O protótipo da função deverá, obrigatoriamente, ser:

int Digitos(int N);

O programa deverá conter, além da função recursiva, uma função principal (main) para realização de testes, com o formato de saída de acordo com o exemplo a seguir:

Digite um numero inteiro: 12345
Resultado: 5
*/
