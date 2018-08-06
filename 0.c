#include<stdio.h>
int main(){

	int A, B;
	
	printf("Digite os dois numeros: ");
	scanf("%d", &A);
	scanf("%d", &B);

	printf("Resultado = %d", A + B);

	return 0;
}

/*0. Soma de dois números (teste)

Disciplina: LAED - Laboratório de Algoritmos e Estruturas de Dados I 
Prazo de Entrega: 03/08/2018 16:35:00 Fechado
Faça um programa que receba dois números da entrada padrão e imprima a soma deles.

Para fazer a leitura dos números, o programa deverá imprimir na tela uma mensagem com o seguinte comando:

printf("Digite os dois numeros: ");

Após a leitura, o programa deverá somar os números e imprimir a resposta. A saída do programa deve seguir o modelo abaixo, considerando como entrada os números 10 e 5:

Digite os dois numeros: 10 5
Resultado = 15

Observação: não utilize acentuação nas mensagens e nem o comando system("pause") nos programas enviados para o run.codes.

*/
