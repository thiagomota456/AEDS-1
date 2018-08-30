#include<stdio.h>

void mostrar(int *n);
void printarVetor(int *vetor);
void duplicar(int *v, int *atual);
void zerar_vetor(int *v);
void copiaVetor(int *v1, int *v2);
int excluir_numero_decomposto(int *vetor,int num);
int confirma_decremento_indice1(int *vetor);
int comparaVetor(int *v1, int *v2);
int avaliar_vetor(int *vetor);
void zerar_poscoes_finais(int *v);
int ultimo_numero_decomposto(int *vetor,int n);
int soma_todo_vetor(int *n);
void decrementar_1_posicao(int *vetor);
void decompor(int number);
int vetor_todo_decomposto(int *vetor);

int num = 8;
int indice_atual = 0 , indice_proximo = 1;

int main(){
	printf("Digite um numero inteiro: ");
	scanf("%d", &num);

	printf("Decomposicao:\n");

	//O proprio número printado que sempre acontece
	printf("%d\n",num );

	decompor(num);

	/*int teste[] = {1,3,4, 2, 0, 1, 1, 0};
	zerar_poscoes_finais(teste);
	printarVetor(teste);


	
	int as[] = {1,3,4, 2, 1, 1, 0,1};
	zerar_poscoes_finais(as);
	printarVetor(as);*/

}

void decompor(int number){
	 
	int vetor[num];
	zerar_vetor(vetor);
	int casoQueEstouComProblema[num];
	zerar_vetor(vetor);
	vetor[0] = --number;
 	int atual = 0;

	//Apaguei tudo que estava dentro do While. Acho que não tava suficientemente bom.
	while(!(vetor_todo_decomposto(vetor))){


			//duplico enquanto o valor no vetor for menor
			while(soma_todo_vetor(vetor) < num){

				printf("Atual = %d\n", atual);
				duplicar(vetor, &atual);
				printf("Duplicar");
				printarVetor(vetor);
				getchar();

				atual +=1;
				
			}//end while(soma_todo_vetor(vetor) < num)
			printf("Duplica: ");			
			printarVetor(vetor);				

			
			//Se a soma de todo vetor é maior que o número dígitado
			//E não é o indíce 0, eu decremento ate não ser mais maio
			while(soma_todo_vetor(vetor) > num)
				if(atual > 0)
					vetor[atual]--;
				else
					break;

			printf("Decrementa atual: ");
			printarVetor(vetor);


			/********************TESTAR SE AQUI É ADEQUADO PARA FUNÇÃO MOSTRAR************************/
			mostrar(vetor);


			//Até então acho que colocaria o teste de mostrar aqui.
			//Ver se decremento primira posição
			if(soma_todo_vetor(vetor) == num && confirma_decremento_indice1(vetor) && !(vetor_todo_decomposto(vetor))){
				decrementar_1_posicao(vetor);
				atual = 0;
			}
				
			

			printf("Decrementar primira pos: ");
			printarVetor(vetor);



			


			int i = atual;
			for(; i > 0; i--){
				if(soma_todo_vetor(vetor) == num && vetor[i] == 2){
					vetor[i]--;
				}
			}	



			//Meu vetor é == num e não é o caso de decrementar 1° indice			
			if(soma_todo_vetor(vetor) == num && vetor[atual] != 1)
				if(atual > 0)
					vetor[atual]--;

			int j = atual;
			for(; j > 0; j--){
				if(vetor[j] > 2 && j <  atual && vetor[atual]==1){
					vetor[j]--;
					zerar_poscoes_finais(vetor);
					atual=j;
					break;
				}
			}
			printf("Teste novo: ");
			printarVetor(vetor);

			//Função que volta e decremeta o tltimo que não é um 

	
			printf("teste decrementa  se == : ");
			printarVetor(vetor);
				

		getchar();
	}//end while(!(vetor_todo_decomposto(vetor)))

	//Printa vetor todo decomposto
	//mostrar(vetor);

}//end decompor

int excluir_decompostos(int *v){
	int i;
	
}

void zerar_vetor(int *v){
	int i;
	for(i = 0; i < num; i++)
		v[i] = 0;

}//end zerar_vetor

void zerar_poscoes_finais(int *v){
	int i;
	int j = 0;
	for(i = 1; i < (num-1); i++){

		//printf("Pocição %d = %d\n", i, v[i]);
		if(v[i] >= 1){
			//printf("Ultimo número decomposto = %d\n",ultimo_numero_decomposto(v,i));
			if(ultimo_numero_decomposto(v,i)){
				while(j < (num-i)){
			//		printf("Entrei aqui");
					v[j+i] = 0;
					j++;

				}//end while
			}//end if(ultimo_numero_decomposto(v,i))
		}//end if(v[i] > 1)
	}//end for

}//end zerar_poscoes_finais

int ultimo_numero_decomposto(int *vetor,int n){
	int i = n;

	for(; i < num; i++){
		if( (vetor[i] != 1) && (vetor[i] != 0))
			return 0;
	}

	return 1;
}//end excluir_numero_decomposto

int confirma_decremento_indice1(int *vetor){
	int i = 1;

	for(; i < num; i++){
		if(!(vetor[i] == 1 || vetor[i] == 0)){
			//printf("falso pra decrementar 1 posição: ");
			//printarVetor(vetor);
			//getchar();
			return 0;
		}
		
	}

	return 1;
}//end confirma_decremento_indice1


void duplicar(int *v, int *atual){

	//if((v[*atual+1] == 0) && (soma_todo_vetor(v)<= num)){
	if((v[*atual+1] == 0)){
		v[*atual+1] = v[*atual];

		//Sempre que eu duplica, atualizo o atual
		//*atual+=1;
	}

	//mostrar(v);
	//getchar();

}//end duplicar

int avaliar_vetor(int *vetor){
	if(soma_todo_vetor(vetor) == num)
		return 1;

	return 0;	
}

void copiaVetor(int *v1, int *v2){
	int i;

	for(i = 0; i < num; i++){
		v2[i] = v1[i];
	}

}//end copiaVetor

int comparaVetor(int *v1, int *v2){
	int i;

	for(i = 0; i < num; i++){
		if(v2[i] != v1[i])
			return 0;
	}
	return 1;

}//end comparaVetor


int vetor_todo_decomposto(int *vetor){
	int i;

	for (i = 0; i < num; ++i)
	{
		if(vetor[i] != 1)
		return 0;
	}

	return 1;
}

void decrementar_1_posicao(int *vetor){

	int aux;
	aux = vetor[0];

	//Zero todas as posições do vetor
	//memset(vetor, 0,  num * sizeof(int));
	zerar_vetor(vetor);

	//Decremento 1
	aux--;

	//add a 1° posicao  1 decrementado
	vetor[0] = aux;
}

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

		if(n[i] != 0){//Se não é 0
			printf("%d", n[i]);//printa o número

			//add um + se não é o ulto numero ou se o proxímo não é  
			if( (i+1 != num) && (n[i+1] != 0) )
				printf(" + ");
			else
				printf("\n");
		}
	}//end for
}//end mostrar

void printarVetor(int *vetor){
	int i;

	for(i = 0; i < num; i++){
		printf("%d ",vetor[i] );
	}

	printf("\n");
}//end printarVetor
