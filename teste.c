#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//  \n

typedef struct {
	   char	nome[100];
	   char x_O;
}Jogador;

void mostrarMatriz(char matriz[3][3]);
void modificarMatriz(char *posicao_matriz);

void main(){
	Jogador jogadores[2];
	char matriz[3][3];
	matriz[0][0]=' ';matriz[0][1]=' ';matriz[0][2]=' ';
	matriz[1][0]=' ';matriz[1][1]=' ';matriz[1][2]=' ';
	matriz[2][0]=' ';matriz[2][1]=' ';matriz[2][2]=' ';
	
	while(1){
		system("cls");
		fflush(stdin);
		char op;
		printf("----- JODO DA VELHA -----\n");
		printf("1 - Jogar\n");
		printf("0 - Sair\n");
		printf(">> ");
		scanf("%c",&op);
		switch(op)
		{
		case '1':
			system("cls");
			fflush(stdin);
			printf("Informe o nome do jogador 1: ");
			gets(jogadores[0].nome);
			printf("Informe o nome do jogador 2: ");
			gets(jogadores[1].nome);
			printf("%s voce vai querer X ou O?: ",jogadores[0].nome);
			scanf("%c", &jogadores[0].x_O);
			jogadores[0].x_O = toupper(jogadores[0].x_O);
			
			if(jogadores[0].x_O =='X'){
				jogadores[1].x_O = 'O';
			}else{
				jogadores[1].x_O = 'X';
			}
			mostrarMatriz(matriz);
			system("pause");
			break;
		case '0':
			if(op=='0'){
				break;
			}
			break;
		default:
			system("cls");
			printf("Opcao invalida!\nInforme outra posicao\n\n");
			system("pause");
			break;
		}
	}	
}//fim main

void mostrarMatriz(char matriz[3][3]){
	system("cls");
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(j==2){
				printf(" %c ",matriz[i][j]);
				printf("\n");
				if(i!=2){
					printf("-----------");
					printf("\n");
				}
			}else{
				printf(" %c |",matriz[i][j]);
			}//fim else
		}//fim for do J
	}//fim do for do I
}//fim mostrarMatriz

void modificarMatriz(char *posicao_matriz){
	char *p = posicao_matriz;
	*p = 'X';
}//fim modificarMatriz
